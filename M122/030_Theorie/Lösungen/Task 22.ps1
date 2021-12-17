Get-ChildItem * -include *.tmp, *.temp | remove-Item

#22  1. Version remove-item -path C:\PS\M122\Testfiles\* -include *.tmp, *.temp
#22  2. Version Get-ChildItem | where-object {$_.Extension -eq ".tmp" -or $_.Extension -eq ".temp"} | Remove-Item
remove-item * -include *.t*mp 