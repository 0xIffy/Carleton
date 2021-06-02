//Create express app
const express = require('express');
let app = express();

//Database variables
let mongo = require('mongodb');
let MongoClient = mongo.MongoClient;
let db;

//View engine
app.set("view engine", "pug");

app.use(express.static("./"));

//Set up the routes
app.use(express.static("public"));
app.get("/", loadClasses, sendIndex);
app.get("/cards", getCards);
app.get("/cards/:cardID", sendCard);

function getCards(req,res,next){
	console.log(req.query);
	
	let arr = [{attack: {$gte: Number(req.query.minAttack), $lte: Number(req.query.maxAttack)}}, {health: {$gte: Number(req.query.minHealth), $lte: Number(req.query.maxHealth)}}];

	if(req.query.name){
	arr.push({name: {$regex: new RegExp("^"+req.query.name+"$","i")}});
	} else if(req.query.artist){
		arr.push({artist: {$regex: new RegExp("^"+req.query.artist+"$","i")}});
	}
	console.log(arr);

	db.collection("cards").find({rarity: req.query.rarity, cardClass: req.query.class, $and: arr}).toArray(function(err,result){
		if(err) throw err;

		res.status(200).json({result});
	});
}

function loadClasses(req,res,next){
	db.collection("cards").distinct("cardClass", function(err, result){
		if(err) throw err;

		res.cardClasses = result;
	});
	db.collection("cards").distinct("rarity", function(err, result){
		if(err) throw err;
		
		res.rarities = result;

		next();
	});
}

function sendIndex(req, res, next){
	res.render("index", { cardClasses: res.cardClasses, rarities: res.rarities });
}

function sendCard(req, res, next){
	let oid;
	try{
		oid = new mongo.ObjectID(req.params.cardID);
	}catch{
		res.status(404).send("Unknown ID");
		return;
	}
	
	db.collection("cards").findOne({"_id":oid}, function(err, result){
		if(err){
			res.status(500).send("Error reading database.");
			return;
		}
		if(!result){
			res.status(404).send("Unknown ID");
			return;
		}
		res.status(200).render("card", result);
	});
}

// Initialize database connection
MongoClient.connect("mongodb://localhost:27017/", function(err, client) {
  if(err) throw err;

  //Get the t8 database
  db = client.db('t8');
  
  // Start server once Mongo is initialized
  app.listen(3000);
  console.log("Listening on port 3000");
});