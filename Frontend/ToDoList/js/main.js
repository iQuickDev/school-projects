var activities = document.querySelector("#activities").children[1]

document.querySelector("#add").onclick = () =>
{
    let activity = prompt("Cosa devi fare ?")
    let newRow = document.createElement("tr")
    let newCell = document.createElement("td")

    newCell.textContent = activity
    newRow.appendChild(newCell)
    activities.appendChild(newRow)
}

document.querySelector("#delete").onclick = () =>
{   
    let deletionPos = activities.children.length == 0 ? alert("Non ci sono attività da eliminare") : prompt("Eliminare la riga... da 1 a " + activities.children.length)

    activities.children[deletionPos - 1].remove()
}
