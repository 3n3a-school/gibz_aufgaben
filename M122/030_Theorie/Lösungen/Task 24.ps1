Get-ChildItem | sort-object extension –unique | foreach-object {New-item (".\" + $_.extension) -type directory }
#oder
#Get-ChildItem | sort-object extension –unique | foreach-object {New-item (".\" + $_.extension) -type directory }
