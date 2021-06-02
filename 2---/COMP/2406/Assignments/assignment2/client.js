let order = {};
let restaurants = {};
let xhttp;

function getRestaurants(){
	xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		if(this.readyState==4 && this.status==200){
			restaurants = JSON.parse(this.responseText);
			loadOptions();
		}
	}
	xhttp.open("GET","http://127.0.0.1:3000/restaurants",true);
	xhttp.send();
}

let select = document.getElementById('restaurants');
let selIndex; 

function loadOptions(){
    for(key in restaurants){
        select.innerHTML += "<option id='" + key + "' value='" + key + "'>" + restaurants[key].name + "</option>";
	}
	selIndex = select.value;
	
	selectRestaurant();
}

function selectRestaurant(){
	if(Object.keys(order).length !== 0){
		let r = confirm("Are you sure you would like to change restaurant (will reset order)?");
		if(r == true){
			order = {};
		} else{
			select.value = selIndex;
		}
	}
	
	if(Object.keys(order).length === 0){
		selIndex = select.value;
		let restaurant = restaurants[selIndex];

		mainDiv = document.getElementById("title");
		mainDiv.setAttribute("style", "text-align: center");
		mainDiv.innerHTML = "<h2>" + restaurant.name + "</h2><h3>Minimum Order: " + restaurant.min_order + "</h3><h3>Delivery Fee: " + restaurant.delivery_fee + "</h3>";

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
				div.innerHTML += "<p>"+c[item].name+" ("+c[item].price+")<img id='"+item+"' src='add.jpg' width='20px' onclick='addToOrder("+item+","+selIndex+")'></p><p>"+c[item].description+"</p> <br/>";
			}
			menu.appendChild(div);
		}
		
		renderOrder(restaurant);
	} 
}

function addToOrder(num,restaurantHTML){
	if(Object.keys(order).includes(String(num))){
		order[num] += 1;
	} else{
		order[num] = 1;
	}
	renderOrder(restaurants[restaurantHTML.value]);
}

function remFromOrder(num,restaurantHTML){
	order[num] -= 1;
	if(order[num] == 0){
		delete order[num];
	}

	renderOrder(restaurants[restaurantHTML.value]);
}

function renderOrder(restaurant){
	let orderDiv = document.getElementById('order');
	orderDiv.innerHTML = "";
	let price = 0;

	for(key in order){
		for(cat in restaurant.menu){
			let c = restaurant.menu[cat];
			if(Object.keys(c).includes(key)){
				orderDiv.innerHTML += "<p>"+c[key].name+" x "+order[key]+" ("+c[key].price*order[key]+")<img src='remove.jpg' width='20px' onclick='remFromOrder("+key+","+selIndex+")'></p>";
				price+=c[key].price*order[key];
			}
		}
	}
	let tax = price*0.1;
	let total = (price*1.1+restaurant.delivery_fee);

	orderDiv.innerHTML += "<p>Subtotal: $"+price+"</p><p>Tax: $"+tax+"</p><p>Delivery Fee: $"+restaurant.delivery_fee+"</p><p>Total: $"+total+"</p>";

	if(price >= restaurant.min_order){
		orderDiv.innerHTML += "<button type='button' onclick='submitOrder("+selIndex+","+total+")'>Submit Order</button>";
	} else{
		orderDiv.innerHTML += "<p>You must add another $"+(restaurant.min_order-price)+" to your order to submit.";
	}
}

function submitOrder(restaurantHTML,orderTotal){
	xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		if(this.readyState==4 && this.status==200){
			order = {};
			alert("Order has been submit.");
			selectRestaurant();
		}
	}
	xhttp.open("POST","http://127.0.0.1:3000/order",true);
	xhttp.send(JSON.stringify({order,orderTotal,restaurant: restaurantHTML.value}));
}
