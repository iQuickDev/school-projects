document.querySelector("#searchcontent").onkeyup = () =>
{
    let searchBox = document.querySelector("#searchcontent")
    let contacts = document.querySelector("#contacts").children[1].children

    for (let i = 0; i < contacts.length; i++)
    {
        contacts[i].children[0].textContent.toLowerCase().indexOf(searchBox.value.toLowerCase()) > -1 ?
        contacts[i].style.display = "" : contacts[i].style.display = "none"
    }

}
