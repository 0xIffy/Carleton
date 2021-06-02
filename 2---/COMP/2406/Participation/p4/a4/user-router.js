let express = require("express");
let router = express.Router();
let User = require("./userModel");
let Purchase = require("./purchaseModel");
let mongoose = require("mongoose");
let ObjectId = require("mongoose").Types.ObjectId;

router.get("/", loadUsers, respondUsers);

router.get("/:uid", findUser, sendSingleUser);

function findUser(req,res,next){
	User.findById(req.params.uid).exec(function(err,result){
		if(err){
			console.log(err);
			res.status(500).send("Cannot load user");
			return;
		}
		if(req.session.userId == req.params.uid || !result.privacy){
			Purchase.find().where({user: ObjectId(req.params.uid)}).exec(function(err2,results){
				res.user = result;
				res.user.orders = [];
				results.forEach(r => {
					res.user.orders.push(r.order);
				});
				next();
			});
		} else{
			res.status(403).send("You are not authorized to access this profile.");
		}
	});
}

function sendSingleUser(req,res,next){
	res.format({
		"text/html": () => { res.render("pages/user", {user: res.user, session: req.session}); },
		"application/json": () => { res.status(200).json(user); }
	});
}

function loadUsers(req,res,next){
	let name = req.query.name ? req.query.name : "";
	
	User.find()
	.where("username").regex(new RegExp(".*"+name+".*", "i"))
	.where("privacy").equals(false)
	.exec(function(err,results){
		if(err){
			console.log(err);
			res.status(500).send("Could not load users");
			return;
		}
		
		res.users = results;
		next();
	});
}

function respondUsers(req,res,next){
	res.format({
		"text/html": () => { res.render("pages/users", {users: res.users, session: req.session}); },
		"application/json": () => { res.status(200).json({users: res.users}); }
	});
}

module.exports = router;