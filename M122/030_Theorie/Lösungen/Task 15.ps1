#a)
#get-service | Foreach {write-host $_.Name, $_.Status} 

#b)
get-service | Foreach { if( $_.status -eq "stopped") { write-host $_.status, $_.name -ForegroundColor red}  else {write-host $_.status, $_.name -ForegroundColor green}}

get-service | Select-Object status,name | ForEach-Object {if ($_.Status -like "stopped") {write-host $_ -BackgroundColor Red}
else { write-host $_ -BackgroundColor Green}}