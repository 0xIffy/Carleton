function init(){
	let count = 0;
    let items = []

    let addBtn = document.getElementById("add");
    addBtn.addEventListener("click", function(){
		item = document.getElementById("items").value;

		if(item !== ""){
			document.getElementById("items").value = "";

			items.push({ name: item, checked: false, highlighted: false})
			count+=1;

			renderList(items);
		} else{
			alert("Please enter task");
		}
	});
	
	let remBtn = document.getElementById("remove");
	remBtn.addEventListener("click", function(){
		for(let i = 0; i < count; i++){
			if(items[i].checked){
				items.splice(i,1);
				count-=1;
				for(let j = i; j < count; j++){
					items[j].order-=1;
				}
			}
		}
		renderList(items);
	});

	let highBtn = document.getElementById("highlight");
	highBtn.addEventListener("click", function(){
		for(let i = 0; i < count; i++){
			if(items[i].checked){
				items[i].highlighted = !(items[i].highlighted);
			}
		}
		renderList(items);
	});

	let sortBtn = document.getElementById("sort");
	sortBtn.addEventListener("click", function(){
		items.sort(function(a, b){
			if(a.name < b.name){
				return -1
			} else if(a.name > b.name){
				return 1;
			} else{
				return 0;
			}
		});
		renderList(items);
	});

    renderList(items);
}

function renderList(items){
	list = document.getElementById("list");
	list.innerHTML = "";

    items.forEach(function(item) {
        let div = document.createElement("div");
        let input = document.createElement("input");
        
        input.setAttribute("type","checkbox");
		input.setAttribute("id", item.name);

        div.innerHTML = item.name;
		div.insertBefore(input,div.firstChild);
		
		if(item.highlighted){
			div.style.backgroundColor = "cornsilk";
		}

		if(item.checked){
			input.checked = true;
		}

		list.appendChild(div);
		
		document.getElementById(item.name).addEventListener("change", function(){
			item.checked = !(item.checked);
		})
    })
}