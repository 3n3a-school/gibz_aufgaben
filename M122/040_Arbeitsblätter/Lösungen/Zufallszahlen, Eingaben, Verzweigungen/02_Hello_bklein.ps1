param(
    [int]$hour = (Get-Date -Format HH)
)

if($hour -ge 18 -and $hour -le 23) {
    Write-Host "Guten Abend"
} elseif ($hour -ge 0 -and $hour -le 12) {
    Write-Host "Guten Morgen"
} else {
    Write-Host "Guten Tag"
}