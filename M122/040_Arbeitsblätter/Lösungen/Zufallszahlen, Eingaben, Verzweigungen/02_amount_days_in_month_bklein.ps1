param(
    [string]$month = (Get-Date -Format MMM).Substring(0,3)
)

switch ($month) {
    "Jan" { $month = 1 }
    "Feb" { $month = 2 }
    "Mar" { $month = 3 }
    "Apr" { $month = 4 }
    "May" { $month = 5 }
    "Jun" { $month = 6 }
    "Jul" { $month = 7 }
    "Aug" { $month = 8 }
    "Sep" { $month = 9 }
    "Oct" { $month = 10 }
    "Nov" { $month = 11 }
    "Dec" { $month = 12 }
    default { 
        Write-Host "Unknown month... Month will be set to January."
        $month = 1 
    }
}

[int]$year = (Get-Date -Format yyyy)
[int]$amountDays = [datetime]::DaysInMonth($year, $month)
[string]$monthName = (Get-Culture).DateTimeFormat.GetMonthName($month)

Write-Host "$monthName has $amountDays days."