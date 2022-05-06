[int[]] $temperature = 12,14,9,12,15,16,15,15,11,8,13,13,15,12;
$temperature | Measure-Object -Average 
$temperature | Measure-Object -Maximum
write-host('start')
[int] $difference = 0;
[int] $biggestdifference=0;
[int] $position = 0;
for($i = 0; $i -lt 13; $i++){    
    $difference = ([Math]::Abs($temperature[$i] - $temperature[$i+1]))

    
    if(  $difference -gt $biggestdifference) {
        $biggestdifference = $difference;
        $position = $i;

        

    }
}
write-host( ($position+1), ($position+2))