const express = require("express");
const ejs = require("ejs");
const fs = require("fs");
const app = express();

const config = require("./config.json");
app.locals.nextRestaurantId = Object.keys(config).length;
for(key in config){
	app.locals[key] = {};
	app.locals[key].nextItemId = config[key].nextID;
}
// app.locals.aragorn.nextItemId = config[0].nextID;
// app.locals.legolas.nextItemId = config[1].nextID;
// app.locals.frodo.nextItemId = config[2].nextID;

function send404(response){
	response.statusCode = 404;
	response.write("Unknown resource.");
	response.end();
}

function send500(response){
	response.statusCode = 500;
	response.write("Server error.");
	response.end();
}

app.set("view engine", "ejs");
app.set("views", "./views");

app.use(express.static("./"))

let restRouter = require("./restaurant-router");
app.use("/restaurants", restRouter);

app.get("/", function(req,res,next){
	res.render("pages/index", {});
});

app.get("/addrestaurant", function(req,res,next){
	res.render("pages/addRestaurant");
});

app.listen(3000);
console.log("Server listening at http://localhost:3000");