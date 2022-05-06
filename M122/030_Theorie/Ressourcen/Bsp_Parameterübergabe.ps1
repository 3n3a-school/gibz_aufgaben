# Input in Grad Celsius
param(
[decimal]$Temperatur = 18.0,
[string]$Ort = "Zug")
 
Write-Host "Es sind $Temperatur °C in $Ort."
$TemperaturF = ($Temperatur * 1.8 + 32)
Write-Host "Es sind $TemperaturF °F in $Ort."