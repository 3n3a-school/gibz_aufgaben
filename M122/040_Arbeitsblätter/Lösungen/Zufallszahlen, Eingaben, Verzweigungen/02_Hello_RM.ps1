param ($h)
write-host "arg => " $h
if ( ! $h) {$h = $(Get-Date).Hour ; write-host "no args"}
write-host "h ===> " $h
if ( ($h -lt 12) -and ($h -gt 3)) {$s = "morning"}
elseif ($h -lt 16) {$s = "day"}
else {$s = "evening"}
write-host "Good $s"