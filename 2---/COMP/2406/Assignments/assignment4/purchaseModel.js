const mongoose = require("mongoose");
const Schema = mongoose.Schema;

let purchaseSchema = Schema({
	order: Schema.Types.ObjectId,
	user: Schema.Types.ObjectId
});

module.exports = mongoose.model("Purchase", purchaseSchema);