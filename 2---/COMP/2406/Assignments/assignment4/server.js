const express = require("express");
const fs = require("fs");
const https = require("https");
const mongoose = require("mongoose");

const session = require("express-session");
const MongoDBStore = require("connect-mongodb-session")(session);
const store = new MongoDBStore({
	uri: "mongodb://localhost:27017/tokens",
	collection: "sessions"
});
const app = express();

const User = require("./userModel");

app.set("view engine", "ejs");
app.set("views", "./views");

app.use(session({
	secret: "Tdw6CZOSJp",
	store: store,
	resave: true,
	saveUninitialized: true
}));
app.use(express.static("./public"));
let userRouter = require("./user-router");
app.use("/users", userRouter);
let orderRouter = require("./order-router");
app.use("/orders", orderRouter);

app.get("/", function(req,res){
	// req.session.loggedin = false;
	res.render("pages/index", {session: req.session});
});

app.get("/login", function(req,res){
	res.render("./pages/login",{session: req.session});
});
app.post("/login", express.json(), function(req,res,next){
	if(req.session.loggedin){
		res.status(200).json({id: req.session.userId});
		return;
	}

	let username = req.body.username;
	let password = req.body.password;
	mongoose.connection.db.collection("users").findOne({username: username}, function(err, result){
		if(err) throw err;

		if(result && password === result.password){
			req.session.loggedin = true;
			req.session.userId = result._id;
			req.session.accountType = result.privacy;
			res.status(200).json({id: result._id});
		} else{
			res.status(401).send("Unauthorized. Invalid username or password");
		}
	})
});

app.get("/register", function(req,res){
	res.render("./pages/register",{session: req.session});
});
app.post("/register", express.json(), function(req,res,next){
	if(req.session.loggedin){
		res.status(200).json({id: req.session.userId});
		return;
	}

	let username = req.body.username;
	let password = req.body.password;
	let rePassword = req.body.confirm;
	if(password === rePassword){
		mongoose.connection.db.collection("users").findOne({username: username}, function(err,result){
			if(err){
				console.log(err);
				res.status(500).send("Error connecting to database.");
			}

			if(!result){
				let u = new User();
				u.username = username;
				u.password = password;
				u.privacy = false;

				u.save(function(err2,result2){
					if(err2){
						console.log(err2);
						res.status(500).send("Error creating user.");
						return;
					}
					
					req.session.loggedin = true;
					req.session.userId = result2._id;
					req.session.accountType = result2.privacy;
					res.status(200).json({id: result2._id});
				});
			} else{
				res.status(403).send("A user with that username already exists");
			}
		})
	}	
});

app.get("/logout", function(req,res,next){
	req.session.loggedin = false;
	res.redirect("/");
});

app.post("/session", express.json(), function(req,res,next){
	User.findById(req.session.userId).exec(function(err,result){
		if(err){
			console.log(err);
			res.status(404).send("Could not find user.");
			return;
		}

		console.log(req.body.session);
		result.privacy = req.body.session;
		result.save(function(err2,result2){
			if(err2){
				console.log(err2);
				res.status(500).send("Server Error, could not set privacy.");
				return;
			}

			req.session.accountType = req.body.session;
			res.status(200).send("Privacy Saved.");
		})
	});
});

mongoose.connect("mongodb://localhost/a4", { useNewUrlParser: true});

let db = mongoose.connection;
db.on("error", console.error.bind(console, "connection error: "));
db.on("open", function(){

	https.createServer({
		key: fs.readFileSync("./server.key"),
		cert: fs.readFileSync("./server.cert")
	}, app).listen(3000, function(){
		console.log("Server listening at https://localhost:3000/");
	});
});