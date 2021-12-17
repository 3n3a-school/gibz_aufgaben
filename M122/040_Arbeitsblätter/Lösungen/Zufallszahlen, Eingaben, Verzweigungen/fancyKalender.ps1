Param(
    $Monat = (Get-Date -Format MM)
)
switch ($Monat){
    Jan{$AnzahlTage = 31}
    Feb{$AnzahlTage = 28}
    Mar{$AnzahlTage = 31}
    Apr{$AnzahlTage = 30}
    Mai{$AnzahlTage = 31}
    Jun{$AnzahlTage = 30}
    Jul{$AnzahlTage = 31}
    Aug{$AnzahlTage = 31}
    Sep{$AnzahlTage = 30}
    Okt{$AnzahlTage = 31}
    Nov{$AnzahlTage = 30}
    Dez{$AnzahlTage = 31}
    1{$AnzahlTage = 31}
    2{$AnzahlTage = 28}
    3{$AnzahlTage = 31}
    4{$AnzahlTage = 30}
    5{$AnzahlTage = 31}
    6{$AnzahlTage = 30}
    7{$AnzahlTage = 31}
    8{$AnzahlTage = 31}
    9{$AnzahlTage = 30}
    10{$AnzahlTage = 31}
    11{$AnzahlTage = 30}
    12{$AnzahlTage = 31}
    default{$AnzahlTage = 77}
}
Write-Host ("Der Monat hat $AnzahlTage Tage")
Write-Host $Monat