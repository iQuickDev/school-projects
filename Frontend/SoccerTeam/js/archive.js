document.querySelector("#registra").onclick = () =>
{
    let goals = document.querySelector("#goalfatti").value
    let takenGoals = document.querySelector("#goalsubiti").value

    let archiveEntry = document.createElement("p")

    goals > takenGoals ? archiveEntry.innerHTML = "vittoria -> " + goals + " - " + takenGoals :
    goals < takenGoals ? archiveEntry.innerHTML = "sconfitta -> " + goals + " - " + takenGoals :
    archiveEntry.innerHTML = "pareggio -> " + goals + " - " + takenGoals

    archiveEntry.classList.add("archiveentry")

    document.querySelector("#archivio").appendChild(archiveEntry)

    let registeredGoals = document.querySelector("#goalfattivalue").textContent
    let registeredTakenGoals = document.querySelector("#goalsubitivalue").textContent
    let points = document.querySelector("#puntivalue").textContent

    document.querySelector("#goalfattivalue").textContent = Number(registeredGoals) + Number(goals)
    document.querySelector("#goalsubitivalue").textContent = Number(registeredTakenGoals) + Number(takenGoals)

    let newPoints = 0;

    goals > takenGoals ? newPoints = Number(points) + 3 :
    goals < takenGoals ? newPoints = Number(points) :
    newPoints = Number(points) + 1

    document.querySelector("#puntivalue").textContent = Number(newPoints) 
}