<?php
    $ip = $_SERVER['REMOTE_ADDR'];
?>

<h1>You are logged in. Putin is invading your home RIGHT NOW!</h1>
<label for="file">Hacking in progress:</label>
<progress id="file" value="0" max="100"></progress>
<script>
    let progFile = document.getElementById("file");
    function updateProgress(amount = 1) {
        progFile.value += amount;
        progFile.innerHTML = `${progFile.value}%`
        if (progFile.value == 100) {
            progFile.parentElement.innerHTML = "<?= "Your IP Address: " . $ip ?>"
        }
    }
    setInterval(() => {
        updateProgress()
    }, 300);
</script>