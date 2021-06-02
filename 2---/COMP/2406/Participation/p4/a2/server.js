const http = require("http");
const ejs = require("ejs");
const fs = require("fs");

let restaurants = {};
let restaurantNames = [];
let orders = {};

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

fs.readdir("./restaurants",function(err,files){
	if(err){
		console.log(err);
		return;
	}
	files.forEach(file => {
		fs.readFile("./restaurants/"+file,function(e,data){
			if(e){
				console.log(err);
				return;
			}
			let name = file.slice(0,-5);
			restaurants[name] = JSON.parse(data);
			restaurantNames.push(restaurants[name].name);
			orders[name] = { orderTotals: [] };
		});
	});
});

const server = http.createServer(function(request, response){
	if(request.method === "GET"){
		if(request.url === "/" || request.url === "/index.html"){
			ejs.renderFile("ejs/views/pages/index.ejs",{},function(err,data){
				if(err){
					console.log(err);
					send500(response);
					return;
				}
				response.statusCode = 200;
				response.setHeader("Content-Type","text/html");
				response.write(data);
				response.end();
			});
		}else if(request.url === "/style.css"){
			fs.readFile("./style.css",function(err,data){
				if(err){
					console.log(err);
					send500(response);
					return;
				}
				response.statusCode = 200;
				response.setHeader("Content-Type","text/css");
				response.write(data);
				response.end();
			});
		}else if(request.url === "/order"){
			ejs.renderFile("ejs/views/pages/order.ejs",{},function(err,data){
					if(err){
						console.log(err);
						send500(response);
						return;
					}
					response.statusCode = 200;
					response.setHeader("Content-Type","text/html");
					response.write(data);
					response.end();
				});
		}else if(request.url === "/client.js"){
			fs.readFile("./client.js",function(err,data){
				if(err){
					console.log(err);
					send500(response);
					return;
				}
				response.statusCode = 200;
				response.setHeader("Content-Type","application/javascript");
				response.write(data);
				response.end();
				});
		}else if(request.url === "/restaurants"){
			response.statusCode = 200;
			response.write(JSON.stringify(restaurants));
			response.end();
		}else if(request.url === "/add.jpg"){
			fs.readFile("./add.jpg",function(err,data){
				if(err){
					console.log(err);
					send500(response);
					return;
				}
				response.statusCode = 200;
				response.setHeader("Content-Type","image/jpeg");
				response.write(data);
				response.end();
				});
		}else if(request.url === "/remove.jpg"){
			fs.readFile("./remove.jpg",function(err,data){
				if(err){
					console.log(err);
					send500(response);
					return;
				}
				response.statusCode = 200;
				response.setHeader("Content-Type","image/jpeg");
				response.write(data);
				response.end();
				});
		}else if(request.url === "/stats"){
			ejs.renderFile("ejs/views/pages/stats.ejs",{orders,restaurantNames,restaurants},function(err,data){
				if(err){
					console.log(err);
					send500(response);
					return;
				}
				response.statusCode = 200;
				response.setHeader("Content-Type","text/html");
				response.write(data);
				response.end();
			});
		}else{
			send404(response);
			return;
		}
	}else if(request.method === "POST"){
		if(request.url === "/order"){
			let body = "";
			request.on('data', (chunk) => {
				body+=chunk;
			});
			request.on('end', () => {
				let data = JSON.parse(body);
				Object.keys(data.order).forEach((key) =>{
					if(orders[data.restaurant].hasOwnProperty(key)){
						orders[data.restaurant][key]+= data.order[key];
					}
					else{
						orders[data.restaurant][key] = data.order[key];
					}
				});
				orders[data.restaurant].orderTotals.push(data.orderTotal);

				response.statusCode = 200;
				response.end();
			});
		}
	}else{
		send404(response);
		return;
	}
});

server.listen(3000);
console.log('Server running at http://127.0.0.1:3000/');