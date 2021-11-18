document.querySelector("#tutto").onclick = () =>
{
    document.querySelector("#listatitolare").classList.remove("hidden")
    document.querySelector("#listapanchina").classList.remove("hidden")
}

document.querySelector("#titolari").onclick = () =>
{
    document.querySelector("#listapanchina").classList.add("hidden")
    document.querySelector("#listatitolare").classList.remove("hidden")
}

document.querySelector("#riserve").onclick = () =>
{
    document.querySelector("#listatitolare").classList.add("hidden")
    document.querySelector("#listapanchina").classList.remove("hidden")
}

document.querySelector("#risultati").onclick = () =>
{
    window.location.href = "pages/risultati.html"
}
