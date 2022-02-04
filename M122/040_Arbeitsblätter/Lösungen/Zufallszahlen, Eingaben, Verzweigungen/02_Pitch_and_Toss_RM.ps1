param ($Choice)
$Coin = (Get-Random -Minimum 1 -Maximum 3)
if ($Coin -eq 1) {
$Coin = "pitch"
}
else {
$Coin = "toss"
}

if ($Choice -eq $Coin) {
write-host "You win, it was $Coin"
}
else {
write-host "You loose, it was $Coin"
}