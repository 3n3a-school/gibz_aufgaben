param (
$uhrzeit = (Get-Date  -Format HH)
)

if($uhrzeit -gt 18){
Write-Host "Good Evening"
}
elseif($uhrzeit -gt 12){
Write-Host "Good Afternoon"
}
elseif($uhrzeit -gt 0){
Write-Host "Good Morning"
}