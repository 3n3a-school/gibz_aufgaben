$length = 14;
[int[]] $arrTemp = 12, 14, 9, 12, 15, 16, 15, 15, 11, 8, 13, 13, 15, 12;

[int]$dif = 0;
[int]$newDif = 0;
[int]$dayOne = 0;
[int]$dayTwo = 0;

for($i = 0; $i -lt $length-1; $i++){
    $newDif = [Math]::abs($arrTemp[$i] - $arrTemp[$i+1]);
    
    if($newDif -gt $dif){
    $dayOne = $i+1;
    $dayTwo = $i+2;
    $dif = $newDif;
    }


}

Write-Host "Der grösste Unterschied ist zwischen " + $dayOne + " und " + $dayTwo