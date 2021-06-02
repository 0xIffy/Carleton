let refresh = document.getElementById("refresh");

refresh.onclick = queryCards;

function queryCards(){
	let clas = document.getElementById("Class").value;
	let rarity = document.getElementById("Rarity").value;

	let queries = {};
	queries.artist = document.getElementById("artist").value;
	queries.name = document.getElementById("name").value;
	queries.minHealth = document.getElementById("minhealth").value;
	queries.maxHealth = document.getElementById("maxhealth").value;
	queries.minAttack = document.getElementById("minattack").value;
	queries.maxAttack = document.getElementById("maxattack").value;

	let url = "http://localhost:3000/cards?class="+clas+"&rarity="+rarity;

	for(key in queries){
		if(queries[key]){
			url += "&"+key+"="+queries[key];
		} else{
			if(key.includes("min")){
				url += "&"+key+"=0";
			} else if(key.includes("max")){
				url += "&"+key+"=99";
			}
		}
	}

	let xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		if(this.readyState == 4 && this.status == 200){
			let cards = JSON.parse(this.responseText).result;
			listCards(cards);
		}
	}
	xhttp.open("GET",url,true);
	xhttp.setRequestHeader("Content-Type", "application/json");
	xhttp.send();
}

function listCards(cards){
	let resultDiv = document.getElementById("results");
	resultDiv.innerHTML = "";

	cards.forEach(card => {
		resultDiv.innerHTML += "<a href='/cards/"+card._id+"'>"+card.name+"</a><br/>";
	});
}