let aragorn = {
	name: "Aragorn's Orc BBQ", //The name of the restaurant
	min_order: 20, //The minimum order amount required to place an order
	delivery_charge: 5, //The delivery charge for this restaurant
	//The menu
	menu: {
		//First category
		"Appetizers": {
			//First item of this category
			0: {
				name: "Orc feet",
				description: "Seasoned and grilled over an open flame.", //
				price: 5.50
			},
			1: {
				name: "Pickled Orc fingers",
				description: "Served with warm bread, 5 per order.",
				price: 4.00
			},
			2: { //Thank you Kiratchii
				name: "Sauron's Lava Soup",
				description: "It's just really spicy water.",
				price: 7.50
			},
			3: {
				name: "Eowyn's (In)Famous Stew",
				description: "Bet you can't eat it all.",
				price: 0.50
			},
			4: {
				name: "The 9 rings of men.",
				description: "The finest of onion rings served with 9 different dipping sauces.",
				price: 14.50
			}
		},
		"Combos": {
			5: {
				name: "Buying the Farm",
				description: "An arm and a leg, a side of cheek meat, and a buttered biscuit.",
				price: 15.99
			},
			6: {
				name: "The Black Gate Box",
				description: "Lots of unidentified pieces. Serves 50.",
				price: 65.00
			},
			7: {//Thanks to M_Sabeyon
				name: "Mount Doom Roast Special with Side of Precious Onion Rings.",
				description: "Smeagol's favorite.",
				price: 15.75
			},
			8: { //Thanks Shar[TA]
				name: "Morgoth's Scorched Burgers with Chips",
				description: "Blackened beyond recognition.",
				price: 13.33
				
			},
			10: {
				name: "Slab of Lurtz Meat with Greens.",
				description: "Get it while supplies last.",
				price: 17.50
			},
			11: {
				name: "Rangers Field Feast.",
				description: "Is it chicken? Is it rabbit? Or...",
				price: 5.99
			}
		},
		"Drinks": {
			12: {
				name: "Orc's Blood Mead",
				description: "It's actually raspberries - Orc's blood would be gross.",
				price: 5.99
			},
			13: {
				name: "Gondorian Grenache",
				description: "A fine rose wine.",
				price: 7.99
			},
			14: {
				name: "Mordor Mourvedre",
				description: "A less-fine rose wine.",
				price: 5.99
			}
		}	
	}
};

let legolas = {
	name: "Lembas by Legolas",
	min_order: 15,
	delivery_charge: 3.99,
	menu: {
		"Lembas": {
			0: {
				name: "Single",
				description: "One piece of lembas.",
				price: 3
			},
			1: {
				name: "Double",
				description: "Two pieces of lembas.",
				price: 5.50
			},
			2: { 
				name: "Triple",
				description: "Three pieces, which should be more than enough.",
				price: 8.00
			}
		},
		"Combos": {
			3: {
				name: "Second Breakfast",
				description: "Two pieces of lembas with honey.",
				price: 7.50
			},
			4: {
				name: "There and Back Again",
				description: "All you need for a long journey - 6 pieces of lembas, salted pork, and a flagon of wine.",
				price: 25.99
			},
			5: {
				name: "Best Friends Forever",
				description: "Lembas and a heavy stout.",
				price: 6.60
			}
		}
	}
};

let frodo = {
	name: "Frodo's Flapjacks",
	min_order: 35,
	delivery_charge: 6,
	menu: {
		"Breakfast": {
			0: {
				name: "Hobbit Hash",
				description: "Five flapjacks, potatoes, leeks, garlic, cheese.",
				price: 9.00
			},
			1: {
				name: "The Full Flapjack Breakfast",
				description: "Eight flapjacks, two sausages, 3 eggs, 4 slices of bacon, beans, and a coffee.",
				price: 14.00
			},
			2: { 
				name: "Southfarthing Slammer",
				description: "15 flapjacks and 2 pints of syrup.",
				price: 12.00
			}
			
		},
		"Second Breakfast": {
			3: {
				name: "Beorning Breakfast",
				description: "6 flapjacks smothers in honey.",
				price: 7.50
			},
			4: {
				name: "Shire Strawberry Special",
				description: "6 flapjacks and a hearty serving of strawberry jam.",
				price: 8
			},
			5: {
				name: "Buckland Blackberry Breakfast",
				description: "6 flapjacks covered in fresh blackberries. Served with a large side of sausage.",
				price: 14.99
			}
		},
		"Elevenses": {
			6: {
				name: "Lembas",
				description: "Three pieces of traditional Elvish Waybread",
				price: 7.70
			},
			7: {
				name: "Muffins of the Marish",
				description: "A variety of 8 different types of muffins, served with tea.",
				price: 9.00
			},
			8: {
				name: "Hasty Hobbit Hash",
				description: "Potatoes with onions and cheese. Served with coffee.",
				price: 5.00
			}
		},
		"Luncheon": {
			9: {
				name: "Shepherd's Pie",
				description: "A classic. Includes 3 pies.",
				price: 15.99
			},
			10: {
				name: "Roast Pork",
				description: "An entire pig slow-roasted over a fire.",
				price: 27.99
			},
			11: {
				name: "Fish and Chips",
				description: "Fish - fried. Chips - nice and crispy.",
				price: 5.99
			}
		},
		"Afternoon Tea": {
			12: {
				name: "Tea",
				description: "Served with sugar and cream.",
				price: 3
			},
			13: {
				name: "Coffee",
				description: "Served with sugar and cream.",
				price: 3.50
			},
			14: {
				name: "Cookies and Cream",
				description: "A dozen cookies served with a vat of cream.",
				price: 15.99
			},
			15: {
				name: "Mixed Berry Pie",
				description: "Fresh baked daily.",
				price: 7.00
			}
		},
		"Dinner": {
			16: {
				name: "Po-ta-to Platter",
				description: "Boiled. Mashed. Stuck in a stew.",
				price: 6
			},
			17: {
				name: "Bree and Apple",
				description: "One wheel of brie with slices of apple.",
				price: 7.99
			},
			18: {
				name: "Maggot's Mushroom Mashup",
				description: "It sounds disgusting, but its pretty good",
				price: 6.50
			},
			19: {
				name: "Fresh Baked Bread",
				description: "A whole loaf of the finest bread the Shire has to offer.",
				price: 6
			},
			20: {
				name: "Pint of Ale",
				description: "Yes, it comes in pints.",
				price: 5
			}
		},
		"Supper": {
			21: {
				name: "Sausage Sandwich",
				description: "Six whole sausages served on a loaf of bread. Covered in onions, mushrooms and gravy.",
				price: 15.99
			},
			22: {
				name: "Shire Supper",
				description: "End the day as you started it, with a dozen flapjacks, 5 eggs, 3 sausages, 7 pieces of bacon, and a pint of ale.",
				price: 37.99
			}
		}
	}
};

let restaurants = { "aragorn": aragorn, "legolas": legolas, "frodo": frodo };
let order = {};

let select = document.getElementById('restaurants');

function loadOptions(){
    for(key in restaurants){
        select.innerHTML += "<option id='" + key + "' value='" + key + "'>" + restaurants[key].name + "</option>";
	}
	
	selectRestaurant(select.selectedIndex);
}

function selectRestaurant(s){
	if(Object.keys(order).length !== 0){
		let r = confirm("Are you sure you would like to change restaurant (will reset order)?");
		if(r == true){
			order = {};
		} else{
			select.selectedIndex = s;
		}
	}
	
	if(Object.keys(order).length === 0){
		let restaurant = restaurants[select.value];

		mainDiv = document.getElementById("title");
		mainDiv.setAttribute("style", "text-align: center");
		mainDiv.innerHTML = "<h2>" + restaurant.name + "</h2><h3>Minimum Order: " + restaurant.min_order + "</h3><h3>Delivery Fee: " + restaurant.delivery_charge + "</h3>";

		let cats = document.getElementById('categories');
		let menu = document.getElementById('menu');
		menu.innerHTML = "";

		cats.innerHTML = "<h3 style='margin: 0px'>Categories</h3>";
		for(key in restaurant.menu){
			cats.innerHTML += "<h3 style='margin: 0px'><a href='#"+key+"'>"+key+"</a></h3>";
		}

		let div = null;
		for(cat in restaurant.menu){
			div = document.createElement("div");
			div.setAttribute("id",`${cat}`);
			div.setAttribute("style","margin-top: 0px;");
			
			div.innerHTML = "<h3 style='margin-bottom: 5px; margin-top: 0px'>"+cat+"</h3>";
			let c = restaurant.menu[cat];
			for(item in c){
				div.innerHTML += "<p>"+c[item].name+" ("+c[item].price+")<img id='"+item+"' src='add.jpg' width='20px' onclick='addToOrder("+item+","+select.value+")'></p><p>"+c[item].description+"</p> <br/>";
			}
			menu.appendChild(div);
		}
		
		renderOrder(restaurant);
	} 
}

function addToOrder(num,restaurant){
	if(Object.keys(order).includes(String(num))){
		order[num] += 1;
	} else{
		order[num] = 1;
	}
	renderOrder(restaurant);
}

function remFromOrder(num,restaurant){
	order[num] -= 1;
	if(order[num] == 0){
		delete order[num];
	}

	renderOrder(restaurant);
}

function renderOrder(restaurant){
	let orderDiv = document.getElementById('order');
	orderDiv.innerHTML = "";
	let price = 0;

	for(key in order){
		for(cat in restaurant.menu){
			let c = restaurant.menu[cat];
			if(Object.keys(c).includes(key)){
				// console.log(order);
				orderDiv.innerHTML += "<p>"+c[key].name+" x "+order[key]+" ("+c[key].price*order[key]+")<img src='remove.jpg' width='20px' onclick='remFromOrder("+key+","+select.value+")'></p>";
				price+=c[key].price*order[key];
			}
		}
	}
	orderDiv.innerHTML += "<p>Subtotal: $"+price+"</p><p>Tax: $"+price*0.1+"</p><p>Delivery Fee: $"+restaurant.delivery_charge+"</p><p>Total: $"+(price*1.1+restaurant.delivery_charge)+"</p>";

	if(price >= restaurant.min_order){
		orderDiv.innerHTML += "<button type='button' onclick='submitOrder()'>Submit Order</button>";
	} else{
		orderDiv.innerHTML += "<p>You must add another $"+(restaurant.min_order-price)+" to your order to submit.";
	}
}

function submitOrder(){
	order = {};
	alert("Order has been submit");
	selectRestaurant(select.selectedIndex);
}
