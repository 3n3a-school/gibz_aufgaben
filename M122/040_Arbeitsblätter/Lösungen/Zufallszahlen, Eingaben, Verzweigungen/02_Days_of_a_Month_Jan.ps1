param(
[string]$month = (Get-Date -Format MMMM).Substring(0,3)
)

$days= $null

Switch($month)
{
Jan {$days = "31"}
Feb {$days = "28"}
Mar {$days = "31"}
Apr {$days = "30"}
Mai {$days = "31"}
Jun {$days = "30"}
Jul {$days = "31"}
Aug {$days = "31"}
Sep {$days = "30"}
Okt {$days = "31"}
Nov {$days = "30"}
Dez {$days = "31"}
default {Write-Host "This wasn't a valid input!"}
}
if($days -notlike $null)
{
    Write-Host "$month has $days days."
}