Set-Location "C:\Users\Benjamin\Documents\M122\TextEinfügen"

$fileExtensions = (Read-Host "Please enter the file extension for the file you want to add the copyright and seperate with comma (ex. c, txt)").Split(",")

$copyright = @( Get-Content .\config.ini )

ForEach($extension in $fileExtensions) {
    Get-ChildItem -Recurse -Include *.$extension | ForEach-Object { $copyright + (Get-Content $_.FullName) | Set-Content $_.FullName }
}