function login(){
	let username = document.getElementById("username").value;
	let password = document.getElementById("password").value;

	let xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		if(this.readyState == 4 && this.status == 200){
			let id = JSON.parse(this.responseText).id;
			window.location.href = "https://localhost:3000/users/"+id;
		}
	}
	xhttp.open("POST","https://localhost:3000/login",true);
	xhttp.setRequestHeader("Content-Type", "application/json");
	xhttp.send(JSON.stringify({username,password}));
}

function register(){
	let username = document.getElementById("username").value;
	let password = document.getElementById("password").value;
	let confirm = document.getElementById("confirm").value;

	let xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		if(this.readyState == 4){
			if(this.status == 200){
				let id = JSON.parse(this.responseText).id;
				window.location.href = "https://localhost:3000/users/"+id;
			} else if(this.status == 403){
				document.getElementById("error").innerHTML = this.responseText;
				document.getElementById("password").value = "";
				document.getElementById("confirm").value = "";
				document.getElementById("username").value = "";
			}
		}
	}
	xhttp.open("POST","https://localhost:3000/register",true);
	xhttp.setRequestHeader("Content-Type", "application/json");
	xhttp.send(JSON.stringify({username,password,confirm}));
}