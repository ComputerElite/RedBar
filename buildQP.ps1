# Builds a .qmod file for loading with QP
& $PSScriptRoot/build.ps1

Compress-Archive -Path "./libs/arm64-v8a/libRedBar.so", ".\mod.json" -DestinationPath "./RedBar.zip" -Update
Remove-Item "./RedBar.qmod"
Rename-Item "./RedBar.zip" "./RedBar.qmod"