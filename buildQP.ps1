# Builds a .qmod file for loading with QP
& $PSScriptRoot/build.ps1

Compress-Archive -Path "./libs/arm64-v8a/libPlay3rdPer.so", ".\extern\libbeatsaber-hook_2_3_0.so", ".\mod.json" -DestinationPath "./Play3rdPer.zip" -Update
Remove-Item "./Play3rdPer.qmod"
Rename-Item "./Play3rdPer.zip" "./Play3rdPer.qmod"