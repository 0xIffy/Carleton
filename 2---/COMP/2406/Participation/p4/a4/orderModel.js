const mongoose = require("mongoose");
const Schema = mongoose.Schema;

let orderSchema = Schema({
	subtotal: {
		type: Number,
		required: true
	},
	total: {
		type: Number,
		required: true
	},
	fee: {
		type: Number,
		required: true
	},
	tax: {
		type: Number,
		required: true
	},
	restaurant: {
		type: String,
		required: true
	},
	items: {
		type: Object,
		required: true
	},
});

module.exports = mongoose.model("Order", orderSchema);