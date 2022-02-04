param(
[int] $vara = $null,
[int] $varb = $null,
[int] $varc = $null,
[int] $vard = $null,
[int] $vare = $null
)

$number = [array]($vara,$varb,$varc,$vard,$vare)
$biggestNumber = ($number | Measure-Object -Maximum).Maximum
Write-Host([string]$biggestNumber+","+$number.IndexOf($biggestNumber))