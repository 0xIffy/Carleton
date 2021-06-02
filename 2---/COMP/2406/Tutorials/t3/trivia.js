let req = null;
let score = document.getElementById("score");
let btn = document.getElementById("submit");
let a = null;

function loadQ(){
    req = new XMLHttpRequest();
    req.onreadystatechange = function() {
        if(this.readyState==4 && this.status==200){
            question = document.getElementById("question");
            let response = JSON.parse(this.responseText).results;

            let answers = [...response[0].incorrect_answers];
            answers.push(response[0].correct_answer);


            question.innerHTML = response[0].question + "<br>";
            
            let input = null;
            let count = 0;
            while(answers.length > 0){
                num = random(0,answers.length);

                input = document.createElement("input");
                input.setAttribute("type", "radio");
                input.setAttribute("name", "answer");
                input.setAttribute("value", `${answers[num]}`);
                input.setAttribute("id", `${count}`);

                label = document.createElement("label");
                label.setAttribute("for", `${count}`);
                label.innerHTML = answers[num];

                question.appendChild(input);
                question.appendChild(label);

                answers.splice(num,1);
                count++;
            }

            
            btn.addEventListener("click", function(){
                a = document.getElementsByName("answer");
                for(let i = 0;i<a.length;i++){
                    if(a[i].checked){
                        if(a[i].value == response[0].correct_answer){
														document.getElementById("result").innerHTML = "Correct!!";
                            score.innerHTML = Number(score.innerHTML) + 1;
                        } else{
                            // alert(a[i].value);
														document.getElementById("result").innerHTML = "Incorrect :(";
                            break;
                        }
                        
                    } else{
                        continue;
                    }
                }
                loadQ();
            });
        }
    }

    req.open("GET", "https://opentdb.com/api.php?amount=1&type=multiple", true);
    req.send();
}

function newQ(){
    loadQ();
}

function random(min, max){
    return Math.floor(Math.random() * (max - min)) + min;
}