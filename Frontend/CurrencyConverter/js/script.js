var isDark = false
var USDinEUR
var GBPinEUR
var JPYinEUR

function FetchValues()
{
    var xmlHttp = new XMLHttpRequest()
    xmlHttp.open( "GET", "https://api.frankfurter.app/latest", false)
    xmlHttp.send( null )
    return xmlHttp.responseText;
}

window.onload = () =>
{
    let response = JSON.parse(FetchValues())

    USDinEUR = response.rates.USD
    GBPinEUR = response.rates.GBP
    JPYinEUR = response.rates.JPY
}

document.querySelector("#togglebase").onclick = () =>
{
    isDark = !isDark
    
    document.querySelector("#togglehandle").classList.toggle("togglehandleoff")
    document.querySelector("#togglehandle").classList.toggle("togglehandleon")

    if (isDark)
    {
        document.querySelector("body").classList.toggle("bg-dark")
        document.querySelector("body").classList.toggle("text-light")

        for (let i = 0; i < document.getElementsByClassName("valuebox").length; i++) document.getElementsByClassName("valuebox")[i].style.color = "#fff"
    }
    else
    {
        document.querySelector("body").classList.remove("bg-dark")
        document.querySelector("body").classList.toggle("text-light")

        for (let i = 0; i < document.getElementsByClassName("valuebox").length; i++) document.getElementsByClassName("valuebox")[i].style.color = "#000"
    }
}

setInterval(() =>
{
    if (document.querySelector("#eurvalue").value != null || document.querySelector("#eurvalue").value != undefined)
    {
        document.querySelector("#usdvalue").value = `${(document.querySelector("#eurvalue").value * USDinEUR).toFixed(2)} $`
        document.querySelector("#gbpvalue").value = `${(document.querySelector("#eurvalue").value * GBPinEUR).toFixed(2)} £`
        document.querySelector("#jpyvalue").value = `${(document.querySelector("#eurvalue").value * JPYinEUR).toFixed(2)} ¥`
    }

}, 1)


