[int[]] $array1 = 1 .. 14
[int[]] $array2 = 12,14,9,12,15,16,15,15,11,8,13,13,15,12

$result = ($array2 | Measure-Object -Average -Minimum -Maximum)

$result.Average
$result.Maximum
$result.Minimum

$difference = 0
$index = 0
for($i = 0; $i -lt $array2.Length; $i++)
{
    if($i+1 -ge $array2.Length) { break }
    $currentDiff = $array2[$i] - $array2[$i+1]

    if($currentDiff -gt $difference)
    {
        $difference = $currentDiff
        $index = $i
    }
}

Write-Host "Grösster Temperaturunterschied: $difference, vom Tag "$array1[$index]" auf Tag "$array1[$index + 1]


