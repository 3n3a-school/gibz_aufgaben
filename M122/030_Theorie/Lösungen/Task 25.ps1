#get-childitem|Get-Member
#get-childitem|Select-Object Name, Mode 
Get-ChildItem | where-object {$_.mode –notmatch "d"} | foreach-object {move-item (".\" + $_.name) (".\" + $_.extension + "\")}

Get-ChildItem -file | ForEach-Object {Move-Item $_.name -Destination $_.Extension} 