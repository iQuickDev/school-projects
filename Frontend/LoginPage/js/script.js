var utenti = ["ciccioGamer", "icardi", "khaby", "rocco", "anna"]
var password = ["ciccio1", "wandanara", "tiktok", "siffredi33" , "tatangelo"]

if (localStorage.getItem("userdata") == null || localStorage.getItem("userdata") == undefined)
Save()

Import()

document.querySelector("#loginbtn").onclick = () =>
{
    for (let i = 0; i < utenti.length; i++)
    {
        if (document.querySelector("#username").value == utenti[i] && document.querySelector("#password").value == password[i])
        {
            document.querySelector("#alert").textContent = "Login Successful"
            document.querySelector("#alert").classList.remove("alert-danger")
            document.querySelector("#alert").classList.add("alert-success")
            return
        }
    }

    document.querySelector("#alert").textContent = "Login Failed, please try again."
    document.querySelector("#alert").classList.remove("alert-success")
    document.querySelector("#alert").classList.add("alert-danger")
}

document.querySelector("#createaccount").onclick = () =>
{
    let newUsername = prompt("Nuovo Username")
    let newPassword = prompt("Scegli Password")

    if (newPassword.length < 6)
    {
        alert("Password più corta di 6 caratteri")
        return
    }

    for (let i = 0; i < utenti.length; i++)
    {
        if (newUsername == utenti[i])
        {
            alert("utente già esistente ")
            return
        }
    }

    utenti.push(newUsername)
    password.push(newPassword)

    Save()

    return
}

// questi due dati li salvo in localStorage sennò è una poverata

function Save()
{
    let data = 
    {
        "usernames": utenti,
        "passwords": password
    }

    localStorage.setItem("userdata", JSON.stringify(data))
}

function Import()
{
    let data = JSON.parse(localStorage.getItem("userdata"))

    for (let i = 5; i < data.usernames.length; i++)
    {
        utenti.push(data.usernames[i])
        password.push(data.passwords[i])
    }
}


