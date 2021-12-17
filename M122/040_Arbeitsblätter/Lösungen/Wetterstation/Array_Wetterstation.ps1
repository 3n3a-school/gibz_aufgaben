[int[]] $Temperatur = 12, 14, 9, 12, 15, 16, 15, 15, 11, 8, 13, 13, 15, 12


#Average
Write-Host "Durchschnittstemperatur: " ($Temperatur | Measure-Object -Average).Average

#MAX
Write-Host "maximale Temperatur: " ($Temperatur | Measure-Object -Maximum).Maximum

#MIN
Write-Host "minimale Temperatur: " ($Temperatur | Measure-Object -Minimum).Minimum