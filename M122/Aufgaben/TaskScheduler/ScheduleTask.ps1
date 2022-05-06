$action = New-ScheduledTaskAction -Execute "Notepad.exe"
$trigger = New-ScheduledTaskTrigger -AtLogon
$principal = "Administrators"
$settings = New-ScheduledTaskSettingsSet
$task = New-ScheduledTask -Action $action -Principal $principal -Trigger $trigger -Settings $settings
Register-ScheduledTask T1 -InputObject $task