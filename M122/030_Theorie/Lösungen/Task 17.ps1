New-PSDrive -name Testfile -psprovider FileSystem -root C:\Powershell\Testfiles


Set-location Testfile: #The ":" is important, otherwise the directory will not be found