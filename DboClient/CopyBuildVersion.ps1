param (    
[Parameter(Mandatory=$true)][string]$filename,
[Parameter(Mandatory=$true)][string]$path
)

$newPath = (Get-Item -path $path\dbo.exe).VersionInfo.FileVersion
New-Item -ItemType File -Path $path\$newPath\$filename -Force
Copy-Item $path\$filename $path\$newPath\$filename -verbose -Force
Copy-Item $path\dbo.exe $path\$newPath\dbo.exe -verbose -Force