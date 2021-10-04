var type = document.getElementById("type");
var pricesTable = document.getElementById("prices");
var infobox = document.getElementById("infobox");
var desc = document.getElementById("desc");
var ordermodal = document.getElementById("ordermodal");
var kebabimg = document.getElementById("kebabimg");
var typeSelector = document.getElementById("kebab-type");
var sizeSelector = document.getElementById("kebab-size");
var countSelector = document.getElementById("kebab-count");
var interval = null;
var lastType = null;
var imagesCount = 3;
var pricesCount = 4;

var kebabs =
{
    piadina:
    {
        description: "Succulento kebab avvolto da una soffice piadina. (Ingredienti e grandezza a scelta)",
        type: "Piadina",
        imageTemplate: "img/piadina$.png",

        prices:
            [
                5,
                7,
                8,
                10,
            ]
    },

    panino:
    {
        description: "Delizioso kebab ricoperto da due fette di squisito pane. (Ingredienti e grandezza a scelta)",
        type: "Panino",
        imageTemplate: "img/panino$.png",

        prices:
            [
                6,
                7.5,
                9,
                12,
            ]
    },

    piatto:
    {
        description: "Mangia come se fossi a tavola, con il kebab nel piatto puoi usare le posate e gustare il vero e proprio kebab senza aggiunta di pane. (Ingredienti a scelta)",
        type: "Piatto",
        imageTemplate: "img/piatto$.png",

        prices:
            [
                5,
                7,
                10,
                12,
            ]
    },

    pizza:
    {
        description: "La specialità Italiana combinata a quella Turca, questa prelibatezza è capace di soddisfare qualsiasi palato, provare per credere. (Ingredienti a scelta)",
        type: "Pizza",
        imageTemplate: "img/pizza$.png",

        prices:
            [
                5,
                7,
                9,
                11,
            ]
    }
}

function paymentdone() {
    ordermodal.style.display = "none";
    document.getElementById("paybox").style.display = "inline-block";

    setTimeout(() => {
        document.getElementById("paymentspinner").style.display = "none";
        document.getElementById("paymenttip").innerHTML = "Pagamento processato. Il suo kebab sarà consegnato in meno di 30 minuti.";
        document.getElementById("paymentsuccess").style.display = "inline-block";
    }, 3000);
}

function info(key) {
    if (document.getElementById("paybox").style.display = "inline-block") {
        document.getElementById("paybox").style.display = "none";
    }

    const kebab = kebabs[key];

    if (lastType == kebab.type)
        return;

    lastType = kebab.type;
    clearInterval(interval);
    if (infobox.style.display = "none")
        infobox.style.display = "inline-block";

    desc.innerHTML = kebab.description;
    type.innerHTML = kebab.type;

    for (let i = 1; i <= pricesCount; i++)
        pricesTable.children[i].children[1].innerHTML =
            kebab.prices[i - 1] + " €";

    ordermodal.style.display = "none";
    switchimgloop(kebab);
    interval = setInterval(switchimgloop, imagesCount * 100000, kebab);
}

function switchimgloop(kebab) {
    switchimg(kebab, 1);
    for (let i = 2; i <= imagesCount; i++)
        setTimeout(switchimg, 1000 * (i - 1), kebab, i);
}

function switchimg(kebab, imgIndex) {
    if (lastType == kebab.type)
        kebabimg.src =
            kebab.imageTemplate.replace("$", imgIndex);
}

function closeinfobox() {
    infobox.style.display = "none";
}

function closelistaordini() {
    ordermodal.style.display = "none";
}

function orderpopup() {
    setTimeout(function () {
        ordermodal.style.display = "inline-block";
        infobox.style.display = "none";
    }, 200)
}

function addToCart() {
    var row = 1;
    var cartproducttype = document.getElementById("kebab-type").value;
    var cartproductsize = document.getElementById("kebab-size").value;
    var cartproductcount = document.getElementById("kebab-count").value;
    var ordertable = document.getElementById("ordertable");
    var newRow = ordertable.insertRow(row);
    var cell1 = newRow.insertCell(0); // Tipo
    var cell2 = newRow.insertCell(1); // Qta
    var cell3 = newRow.insertCell(2); // Grandezza
    var cell4 = newRow.insertCell(3); // Prezzo
    var price = 0;

    cell1.innerHTML = cartproducttype;
    cell2.innerHTML = cartproductcount;
    cell3.innerHTML = cartproductsize;

    switch (cartproducttype) {
        case "Piadina":
            {
                switch (cartproductsize) {
                    case "S":
                        {
                            price = (5 * cartproductcount);
                            break;
                        }

                    case "M":
                        {
                            price = (7 * cartproductcount);
                            break;
                        }

                    case "L":
                        {
                            price = (8 * cartproductcount);
                            break;
                        }

                    case "XL":
                        {
                            price = 10 * cartproductcount;
                            break;
                        }
                }
                break;
            }

        case "Panino":
            {
                switch (cartproductsize) {
                    case "S":
                        {
                            price = 6 * cartproductcount;
                            break;
                        }

                    case "M":
                        {
                            price = 7.5 * cartproductcount;
                            break;
                        }

                    case "L":
                        {
                            price = 9 * cartproductcount;
                            break;
                        }

                    case "XL":
                        {
                            price = 12 * cartproductcount;
                            break;
                        }
                }
            }

        case "Piatto":
            {
                switch (cartproductsize) {
                    case "S":
                        {
                            price = 5 * cartproductcount;
                            break;
                        }

                    case "M":
                        {
                            price = 7 * cartproductcount;
                            break;
                        }

                    case "L":
                        {
                            price = 10 * cartproductcount;
                            break;
                        }

                    case "XL":
                        {
                            price = 12 * cartproductcount;
                            break;
                        }
                }
            }

        case "Pizza":
            {
                switch (cartproductsize) {
                    case "S":
                        {
                            price = 5 * cartproductcount;
                            break;
                        }

                    case "M":
                        {
                            price = 7 * cartproductcount;
                            break;
                        }

                    case "L":
                        {
                            price = 9 * cartproductcount;
                            break;
                        }

                    case "XL":
                        {
                            price = 11 * cartproductcount;
                            break;
                        }
                }
            }
    }


    cell4.innerHTML = price + " €";
}

function popupCart() {
    if (ordermodal.style.display = "none") {
        ordermodal.style.display = "inline-block";
    }
    else {
        ordermodal.style.display = "none";
    }
}