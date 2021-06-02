// const ejs = require("ejs");
let restaurant = {};
let nextID;

function getRestaurant(restaurantID){
	let xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		if(this.readyState == 4 && this.status == 200){
			let data = JSON.parse(this.responseText);
			restaurant = data.restaurant;
			nextID = data.nextID
		}
	}
	xhttp.open("GET","http://localhost:3000/restaurants/"+restaurantID,true);
	xhttp.setRequestHeader("Accept","application/json");
	xhttp.send();
}

function updateRestaurant(){
	let name = document.getElementById("name").value;
	let minOrder = document.getElementById("min-order").value;
	let deliveryFee = document.getElementById("delivery-fee").value;

	restaurant.name = name ? name : restaurant.name;
	restaurant.min_order = (minOrder && !(isNaN(minOrder))) ? minOrder : restaurant.min_order;
	restaurant.delivery_fee = (deliveryFee && !(isNaN(deliveryFee)))? deliveryFee : restaurant.delivery_fee;

	let xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		if(this.readyState == 4 && this.status == 200){
			alert("Data has been saved");
		}
	}
	xhttp.open("PUT","http://localhost:3000/restaurants/"+restaurant.id,true);
	xhttp.setRequestHeader("Content-Type","application/json");
	xhttp.send(JSON.stringify({ restaurant, nextID }));
}

function addCategory(){
	let category = document.getElementById("new-cat").value;
	document.getElementById("new-cat").value = "";
	if(!(category === "" || category in restaurant.menu)){
		restaurant.menu[category] = {};
		// ejs.renderFile("./views/pages/restaurant.ejs", { restaurant: restaurant });
		let div = document.createElement("div");
		div.id = category;
		div.innerHTML = "<h3 style='margin-bottom: 5px; margin-top: 0px'>"+category+"</h3>";

		document.getElementById("menu").appendChild(div);
		let option = document.createElement("option");
		option.text = category;
		document.getElementById("cats").add(option);
	} else{
		alert("Category already exists or empty string input");
	}
}

function addItem(){
	let cat = document.getElementById("cats").value;
	let name = document.getElementById("new-item").value;
	let desc = document.getElementById("item-desc").value;
	let price = document.getElementById("item-price").value;

	if(!(name === "" || price === "" || desc === "" || isNaN(price))){
		document.getElementById("cats").selectedIndex = "0";
		document.getElementById("new-item").value = "";
		document.getElementById("item-desc").value = "";
		document.getElementById("item-price").value = "";
		
		let item = {};
		item.name = name;
		item.description = desc;
		item.price = price;

		restaurant.menu[cat][nextID] = item;

		let div = document.getElementById(cat);
		div.innerHTML += "<p style='margin: 0px; padding: 0px;'>" + nextID + ": " + name + " (" + price + ")</p><p style='margin: 0px; padding: 0px;'>" + desc + "</p><br/>";

		nextID++;
	} else{
		alert("Failure adding item.");
	}
}

function addRestaurant(){
	let name = document.getElementById("name").value;
	let minOrder = document.getElementById("min-order").value;
	let deliveryFee = document.getElementById("delivery-fee").value;

	if(name && (minOrder && !(isNaN(minOrder))) && (deliveryFee && !(isNaN(deliveryFee)))){
		restaurant.name = name;
		restaurant.min_order = Number(minOrder);
		restaurant.delivery_fee = Number(deliveryFee);

		let xhttp = new XMLHttpRequest();
		xhttp.onreadystatechange = function(){
			if(this.readyState == 4 && this.status == 200){
				window.location.href = "http://localhost:3000/restaurants/" + JSON.parse(this.responseText).id;
			}
		}
		xhttp.open("POST","http://localhost:3000/restaurants",true);
		xhttp.setRequestHeader("Content-Type","application/json");
		xhttp.send(JSON.stringify(restaurant));
	}
}