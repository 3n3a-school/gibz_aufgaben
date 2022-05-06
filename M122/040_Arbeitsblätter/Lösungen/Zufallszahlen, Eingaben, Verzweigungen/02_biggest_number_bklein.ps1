param(
    #[int[]]$numbers
    [int]$firstNumber = 1,
    [int]$secondNumber = 2,
    [int]$thirdNumber = 3,
    [int]$fourthNumber = 4,
    [int]$fifthNumber = 5
)

[int[]]$numbers = $firstNumber, $secondNumber, $thirdNumber, $fourthNumber, $fifthNumber
[int]$biggestNumber = $null;
[int]$position = 0;

for($i = 0; $i -lt $numbers.Count; $i++) {
    if($numbers[$i] -gt $biggestNumber) {
        $biggestNumber = $numbers[$i];
        $position =  $i + 1
    }
}

Write-Host "Die grösste Nummer ist $biggestNumber an der Stelle $position"
