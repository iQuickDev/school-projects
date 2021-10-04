function calc()
{
    var val = document.getElementById('val').value;
    var res = document.getElementById('res');
    var prime = document.getElementById('prime');
    var circle = document.getElementById('loading');
    var cnt = 0;
    var total = 0;

    if (val == 0) {
        res.innerHTML = "il numero 0 non ha divisori";
    }
    for (let i = 0; i < val; i++)
    {
        cnt++;
        if (val % cnt == 0) {
            total++;
        }
    }
    if (total >= 1)
    {
        res.innerHTML = "divisori sono " + total;
        if (total == 2) {
            prime.style.display = "block";
            prime.innerHTML = "il numero è primo";
        } 
        else 
        {
            prime.style.display = "none";
        }
    }
    circle.style.display = "none";
    res.style.display = "block";
}

var guessednumfield = document.getElementById("guessednum");
var tooltip = document.getElementById("tooltip");
var checkbtn = document.getElementById("checkbtn");

function setnum()
{
    var numfield = document.getElementById("num");
    var btn = document.getElementById("numfieldbtn");
    var guessinput = document.getElementById("guessinput");
    if (numfield.value >= 0 && numfield.value <= 50)
    {
    numfield.style.display = "none";
    btn.style.display = "none";
    guessinput.style.backgroundColor = "#ffbc00";
    guessednumfield.style.display = "block";
    checkbtn.style.display = "block";
    }
}

var tries = 5;

function guess()
{
    var num = document.getElementById("num").value;
    var guessednum = document.getElementById("guessednum").value;

    if (num == guessednum)
    {
        tooltip.innerHTML = "GRANDE BOMBER...\n YOU WIN";
        tooltip.style.display = "block";
    }
    else if (num != guessednum && tries > 1)
    {
        tries--;
        tooltip.innerHTML = "ERRORE... Il numero non è " + guessednum + "<br>" + tries + " rimanenti<br> <u><b>Riprova<b><u>";
        tooltip.style.display = "block";
    }
    else
    {
        guessednumfield.style.display = "none";
        checkbtn.style.display = "none";
        tooltip.innerHTML = "YOU LOSE";
        tooltip.style.fontSize = "40px";
        tooltip.style.display = "block";
    }
}