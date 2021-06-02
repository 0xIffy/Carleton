const express = require("express");
const ejs = require("ejs");
const fs = require("fs");

let restaurants = [];
let names = {};

const config = require("./config.json");

let router = express.Router();

loadRests();

// List of restaurants
router.get("/", respondRests);
router.post("/", express.json(), addRest);


// Single restaurant
router.get("/:rid", getRest);
router.put("/:rid", express.json(), saveRest);

// router.param("rid", function(req,res,next,para){
// 	loadRests(req,res,next);
// 	res.restaurants.forEach(restaurant => {
// 		if(restaurant.id == para){
// 			res.r = restaurant;
// 		}
// 	});

// 	next();
// })

function addRest(req,res,next){
	let restaurant = req.body;

	if(restaurant.name && restaurant.delivery_fee && restaurant.min_order){
		restaurant.menu = {};
		restaurant.id = req.app.locals.nextRestaurantId;
		req.app.locals[restaurant.id] = {};
		req.app.locals[restaurant.id].nextItemId = 0;
		req.app.locals.nextRestaurantId++;

		restaurants.push(restaurant);

		res.status(200).send(JSON.stringify(restaurant));
	} else{
		res.status(404).send("Invalid restaurant parametres.");
	}
}

function saveRest(req,res,next){
	let id = req.params.rid;
	let fileName = "./restaurants/" + names[id] + ".json";
	let data = JSON.stringify(req.body.restaurant);

	if(fs.existsSync(fileName)){
		fs.writeFile(fileName, data, () => {
			req.app.locals[id].nextItemId = req.body.nextID;
			res.status(200).send("Restaurant Saved");
		});
		
	} else{
		res.status(404).send("No such file");
	}
}

function getRest(req,res,next){
	res.format({
		"text/html": () => { 
			res.r = findRestaurant(req, restaurants);
			res.render("pages/restaurant", { restaurant: res.r }); },
		"application/json": () => { 
			res.r = findRestaurant(req, restaurants);
			res.json({ restaurant: res.r, nextID: req.app.locals[res.r.id].nextItemId });
		}
	});
}

function respondRests(req,res,next){
	res.format({
		"text/html": () => { res.render("pages/restaurants", { restaurants: restaurants }); },
		"application/json": () => { 
			let restaurantIDs = [];
			restaurants.forEach((restaurant) => {
				restaurantIDs.push(restaurant.id);
			});
			res.json({ restaurants: restaurantIDs })}
	});
}

function loadRests(req,res,next){
	// res.restaurants = [];
	
	fs.readdir("./restaurants", function(err,files){
		if(err){
			send500(res);
			return;
		}
		readCount = 0;
		files.forEach((file) => {
			fs.readFile("./restaurants/"+file, function(err,data){
				if(err){
					send500(res);
					return;
				}
				let restaurant = JSON.parse(data);
				// res.restaurants.push(restaurant);
				restaurants.push(restaurant);
				names[restaurant.id] = file.slice(0,-5);
				readCount++;
				// if(readCount == files.length){
				// 	next();
				// }
			});
		});
	});
}

function findRestaurant(req, restaurants){
	let r;
	restaurants.forEach(restaurant => {
		if(restaurant.id == req.params.rid){
			r = restaurant;
		}
	});
	return r;
}

module.exports = router;