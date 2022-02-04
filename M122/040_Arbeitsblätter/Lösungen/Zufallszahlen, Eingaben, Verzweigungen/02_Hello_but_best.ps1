param(
$uhrzeit = (Get-Date -Format HH)
)
if($uhrzeit -lt (Get-Date -Format HH -Hour 10))
{
    Write-Host "Guten Morgen"
}
elseif($uhrzeit -lt (Get-Date -Format HH -Hour 17))
{
    Write-Host "Guten Tag"
}
else
{
    Write-Host "Guten Abend"
}