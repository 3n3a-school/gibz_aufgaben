Get-ChildItem |  where-object {$_.length –gt 500000} | foreach-object { remove-Item $_.FullName}

#23  1. Version Get-ChildItem | Where-Object length -gt 500kB | Remove-Item