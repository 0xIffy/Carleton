function switchPrivacy(){
	let privacy = document.getElementById("privacy").value;
	
	console.log(privacy);
	let xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		if(this.readyState == 4){
			alert(this.responseText)
		}
	}
	xhttp.open("POST","https://localhost:3000/session",true);
	xhttp.setRequestHeader("Content-Type","application/json");
	xhttp.send(JSON.stringify({session: Boolean(privacy)}));
}