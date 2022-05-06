$days = 14
[int[]] $temp = 12,14,9,12,15,16,15,15,11,8,13,13,15,12

Write-Host Average Temperature: ($temp | Measure-Object -Average).Average°
Write-Host Hottest Temperature: ($temp | Measure-Object -Maximum).Maximum°
Write-Host Coolest Temperature: ($temp | Measure-Object -Minimum).Minimum°

$greatestspanat = 0;
$greatestspan = 0;

for($i=1;$i -lt $days; $i++)
{
    if($temp[$i]-$temp[$i-1] -gt $greatestspan)
    {
        $greatestspan = $temp[$i]-$temp[$i-1]
        $greatestspanat = $i
    }
    if($temp[$i-1]-$temp[$i] -gt $greatestspan)
    {
        $greatestspan = $temp[$i-1]-$temp[$i]
        $greatestspanat = $i
    }
}
Write-Host Greatest Temperature diffrence of successive days was between day $greatestspanat and day ($greatestspanat+1)