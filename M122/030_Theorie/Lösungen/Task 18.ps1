getSet-location Testfile:
Get-ChildItem * -exclude *.jpg |select-object Name, length

#2. Variante 
get-childitem | where-object {$_.extension -notlike ".jpg"} | select-object name, length