Set-Location build
cmake ..
cmake --build . --config Debug
Set-Location ..
If (!(test-path rtype_client.lnk)) {
    $ShortcutFile = Join-Path -Path $PWD -ChildPath "/rtype_client.lnk"
    $TargetFile = Join-Path -Path $PWD -ChildPath "/build/bin/rtype_client.exe"
    $WScriptShell = New-Object -ComObject WScript.Shell
    $Shortcut = $WScriptShell.CreateShortcut($ShortcutFile)
    $Shortcut.TargetPath = $TargetFile
    $Shortcut.Save()
}
If (!(test-path rtype_server.lnk)) {
    $ShortcutFile = Join-Path -Path $PWD -ChildPath "/rtype_server.lnk"
    $TargetFile = Join-Path -Path $PWD -ChildPath "/build/bin/rtype_server.exe"
    $WScriptShell = New-Object -ComObject WScript.Shell
    $Shortcut = $WScriptShell.CreateShortcut($ShortcutFile)
    $Shortcut.TargetPath = $TargetFile
    $Shortcut.Save()
}