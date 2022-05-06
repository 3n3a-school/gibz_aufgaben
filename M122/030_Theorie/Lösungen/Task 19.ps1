#Get-ChildItem | get-member
Get-ChildItem * | select-object name, length, lastaccesstime | sort-object length  
Get-ChildItem * | select-object name, length, lastaccesstime | sort-object lastaccesstime 

#http://help.migraven.com/last-access-time/ 
