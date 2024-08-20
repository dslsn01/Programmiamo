param(
  [string]$Path=""
)

if ($Path -eq "") {
  $Path = "$env:userprofile\mingw64\bin"
}

$UserPath = [Environment]::GetEnvironmentVariable("Path", [EnvironmentVariableTarget]::User)
[Environment]::SetEnvironmentVariable("Path", "$Path;$UserPath", [EnvironmentVariableTarget]::User);

Write-Output "La cartella `"$Path`" è stata aggiunta alla PATH dell'utente $Env:UserName."
