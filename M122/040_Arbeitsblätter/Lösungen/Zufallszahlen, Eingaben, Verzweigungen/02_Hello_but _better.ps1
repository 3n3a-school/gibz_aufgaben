Param(
    [int]$Uhrzeit = (Get-Date -Format HH)
)
if ($Uhrzeit -lt 13) {Write-Host ("Guten Morgen")}
else {Write-Host("Guten Abend")}
