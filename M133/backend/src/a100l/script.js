let last_msgs;

async function fetchNewMsgs() {
    let msgs_hash = CryptoJS.MD5(last_msgs).toString()
    let res = await fetch(`./?gimme_msg=${msgs_hash}`)
    let text = await res.text()
    return [res.status,text]
}

async function updateMessages() {
    let msg = await fetchNewMsgs()
    if (msg[0] == 200) {
        last_msgs = msg[1];
        document.getElementsByClassName("board")[0].innerHTML = msg[1];
    }
}

document.getElementById("msg-form").addEventListener('submit', (e) => {
    e.preventDefault();
    let msg_content = document.getElementById('msg').value;

    document.getElementById('msg').value = "";

    let formData = new FormData();
    formData.append("msg", msg_content);

    let request = new XMLHttpRequest();
    request.open("POST", "./");
    request.send(formData);

    updateMessages()
})

setInterval(() => {
    console.log("Reloaded page...")
    updateMessages()
}, 5000);