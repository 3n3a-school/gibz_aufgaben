Get-ChildItem * -Recurse -include *.xls| foreach-object {$_.Isreadonly = 0}
#oder
#Get-ChildItem * -Recurse -file | where-object {$_.extension –eq ".xls"} | foreach-object {$_.Isreadonly = 0}

