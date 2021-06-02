const mongoose = require("mongoose");
const Schema = mongoose.Schema;

let bookSchema = Schema({
	title: {
		type: String,
		required: true
	},
	authors: {
		type: String,
		required: true
	},
	isbn: {
		type: String,
		validate: {
			validator: function(isbn){
				let pass = /[0-9]{9}X{1}|[0-9]{1}/.test(isbn);
				let sum = 0;

				if(pass){
					for(let i = 0; i < 10; i++){
						if(isbn.charAt(i) === 'X'){
							sum += 10;
						} else{
							sum += Number(isbn.charAt(i)) * (10 - i);
						}
					}
				}

				return pass && sum % 11 == 0;
			}
		},
		required: true
	},
	ratings: [Number]
});

bookSchema.statics.getTopBooks = function(callback){
	this.find().exec(function(err, result){
		if(err){
			console.log(err);
			callback("An error occured");
			return;
		}

		let top10 = [];
		// let 
		result.forEach(book => {
			let sum;
			if(book.ratings.length > 10){
				sum = book.ratings.reduce((total, n) => {
					return total + n;
				}, 0);

				let avg = sum / book.ratings.length;
				let obj = {
					book: book.title,
					avg: avg
				};

				if(top10.length < 10){
					top10.push(obj);
				} else{
					if(avg > top10[9].avg){
						top10[9] = obj;
					}
				}

				top10.sort((a,b) => {
					return  b.avg - a.avg;
				});
			}
		});

		callback("",top10);
		return;
	});
}

module.exports = mongoose.model("Book", bookSchema);
