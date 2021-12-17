
$ServiceList = get-service | sort-object name -Descending | select-object   -first 3 -skip 2
$ServiceList

#$ServiceList = get-service | sort-object name -Descending | select-object -first 5 | select-object -last 3 
#$ServiceList

#$ServiceList = get-service | sort-object name -Descending | select-object -index 2,3,4 
#$ServiceList

get-service |sort-object -property name -descending| Select-Object -first 10
$i= 1
get-service |sort-object -property name -descending| ForEach-Object {if ($i -eq 3){$ServiceList = $_.ServiceName + " "}
if ($i -eq 4){$ServiceList = $ServiceList + $_.ServiceName + " "}
if ($i -eq 5){$ServiceList = $ServiceList + $_.ServiceName + " "}
$i++}
$ServiceList