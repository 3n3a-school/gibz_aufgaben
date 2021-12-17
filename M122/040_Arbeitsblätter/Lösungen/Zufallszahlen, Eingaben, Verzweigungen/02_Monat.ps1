Param(
$Month = (Get-Date -Format MM)
)

[int] $days
switch($Month){
    Jan {$days = 31}
    Feb {$days = 28}
    Mar {$days = 31}
    Apr {$days = 30}
    Mai {$days = 31}
    Jun {$days = 30}
    Jul {$days = 31}
    Aug {$days = 31}
    Sept {$days = 30}
    Oct {$days = 31}
    Nov {$days = 30}
    Dez {$days = 31}
}

Write-host "This Month has $days days"

