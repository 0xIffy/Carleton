let express = require("express");
let router = express.Router();
let Order = require("./orderModel");
let Purchase = require("./purchaseModel");
let mongoose = require("mongoose");
const { response } = require("express");
let ObjectId = require("mongoose").Types.ObjectId;

router.get("/", respondOrderForm);
router.post("/", express.json(), createOrder);

router.get("/:oid", findOrder, respondOrder);

function findOrder(req,res,next){
	Purchase.findOne().where({order: ObjectId(req.params.oid)}).exec(function(err,result){
		if(err){
			console.log(err);
			res.status(500).send("Could not find order");
			return;
		}

		mongoose.connection.db.collection("users").findOne({_id: result.user}, function(err2,user){
			if(err2){
				console.log(err2);
				res.status(500).send("Something went wrong.");
				return;
			}

			if(req.session.userId == String(user._id) || !user.privacy){
				Order.findOne().where({_id: result.order}).exec(function(err3,order){
					if(err3){
						console.log(err3);
						res.status(500).send("Could not find order.");
						return;
					}

					console.log(order);
					res.order = order;
					res.order.user = user;
					next();
				});
			} else{
				res.status(403).send("You are not authorized to view this order.");
			}
		});
	});
}

function respondOrder(req,res,next){
	res.format({
		"text/html": () => { res.render("pages/order", {order: res.order, session: req.session}); },
		"application/json": () => { res.json({order: res.order}); }
	});
}

function respondOrderForm(req,res,next){
	if(req.session.loggedin){
		res.render("pages/orderform", {session: req.session});
	} else{
		res.status(403).send("You must login to place an order.");
	}
}

function createOrder(req,res,next){
	let order = req.body;
	let o = new Order();
	
	o.total = order.total;
	o.restaurant = order.restaurantName;
	o.subtotal = order.subtotal;
	o.fee = order.fee;
	o.tax = order.tax;
	o.items = order.order;

	o.save(function(err, result){
		if(err){
			console.log(err);
			res.status(500).send("Could not create order.");
			return;
		}

		let p = new Purchase();
		p.order = result._id;
		p.user = ObjectId(req.session.userId);

		p.save(function(err2,result2){
			if(err2){
				console.log(err2);
				res.status(500).send("Purchase failed.");
				return;
			}

			res.status(200).send("Yay!");
		});
	});
}

module.exports = router;