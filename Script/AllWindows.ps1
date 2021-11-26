If(!(test-path build)) {
    mkdir build
}
Set-Location build
conan install --build missing ..
cmake ..
cmake --build . --config Release
Set-Location ..
If (!(test-path rtype_client.exe)) {
    If (-NOT ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator))
    {
        $rootClientPath = Join-Path -Path $PWD -ChildPath "/rtype_client.exe"
        $clientPath = Join-Path -Path $PWD -ChildPath "/build/bin/rtype_client.exe"
        Start-Process powershell -Verb runAs "New-Item -ItemType SymbolicLink -Path $rootClientPath -Target $clientPath"
    }
}
If (!(test-path rtype_server.exe)) {
    If (-NOT ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator))
    {
        $rootServerPath = Join-Path -Path $PWD -ChildPath "/rtype_server.exe"
        $serverPath = Join-Path -Path $PWD -ChildPath "/build/bin/rtype_server.exe"
        Start-Process powershell -Verb runAs "New-Item -ItemType SymbolicLink -Path $rootServerPath -Target $serverPath" 
    }
}