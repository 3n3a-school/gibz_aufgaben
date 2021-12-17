param(
[string]$month = (Get-Date -Format MMMM).Substring(0,3)
)

switch($month)
{
"Jan"{Write-Host $month "hat 31 days"}
"Feb"{Write-Host $month "hat 28 days"}
"Mar"{Write-Host $month "hat 31 days"}
"Apr"{Write-Host $month "hat 30 days"}
"Mai"{Write-Host $month "hat 31 days"}
"Jun"{Write-Host $month "hat 30 days"}
"Jul"{Write-Host $month "hat 31 days"}
"Aug"{Write-Host $month "hat 31 days"}
"Sep"{Write-Host $month "hat 30 days"}
"Okt"{Write-Host $month "hat 31 days"}
"Nov"{Write-Host $month "hat 30 days"}
"Dez"{Write-Host $month "hat 31 days"}
}