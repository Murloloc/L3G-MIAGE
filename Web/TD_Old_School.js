console.log()
const button = document.getElementById("Theme_Button")
const stylesheet = document.getElementById("stylesheet")
button.addEventListener("click", function () {
    if (stylesheet.href.includes("Dark_Mode.css")) {
        stylesheet.href = "White_Mode.css"
    } else {
        stylesheet.href = "Dark_Mode.css"
    }
})
