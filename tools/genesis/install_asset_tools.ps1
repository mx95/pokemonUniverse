$ErrorActionPreference = "Stop"

# SpriteCook local Cursor plugin
Write-Host "=== SpriteCook plugin ==="
New-Item -ItemType Directory -Force -Path "$env:USERPROFILE\.cursor\plugins\local" | Out-Null
try {
    Invoke-WebRequest -UseBasicParsing -Uri "https://spritecook.ai/install-cursor.ps1" -OutFile "$env:TEMP\install-spritecook.ps1"
    & powershell -NoProfile -ExecutionPolicy Bypass -File "$env:TEMP\install-spritecook.ps1"
    Write-Host "SpriteCook installer finished."
} catch {
    Write-Host "SpriteCook install failed: $_"
}

# Porymap (Gen 3 map editor)
Write-Host "=== Porymap ==="
$dest = Join-Path $env:USERPROFILE "Downloads\Porymap"
New-Item -ItemType Directory -Force -Path $dest | Out-Null
$headers = @{ "User-Agent" = "PokemonGenesis-AssetSetup" }
$rel = Invoke-RestMethod -Uri "https://api.github.com/repos/huderlem/porymap/releases/latest" -Headers $headers
Write-Host ("Latest release: " + $rel.tag_name)
$asset = $rel.assets | Where-Object { $_.name -match "(?i)win|windows" -and $_.name -like "*.zip" } | Select-Object -First 1
if (-not $asset) {
    $asset = $rel.assets | Where-Object { $_.name -like "*.zip" } | Select-Object -First 1
}
if (-not $asset) {
    throw "No zip asset found on latest Porymap release"
}
Write-Host ("Downloading: " + $asset.name)
$zip = Join-Path $dest $asset.name
Invoke-WebRequest -Uri $asset.browser_download_url -OutFile $zip -Headers $headers
Expand-Archive -Path $zip -DestinationPath $dest -Force
Write-Host "Extracted to $dest"
Get-ChildItem $dest -Recurse -Filter "*.exe" | ForEach-Object { Write-Host ("EXE: " + $_.FullName) }

# Simple Image Editor VS Code/Cursor extension (Open VSX / marketplace id)
Write-Host "=== Image editor extension ==="
$cursorCmd = Get-Command cursor -ErrorAction SilentlyContinue
if ($cursorCmd) {
    & cursor --install-extension addios4u.simple-image-editor
} else {
    Write-Host "cursor CLI not on PATH; skip VS Code extension install"
}

Write-Host "=== Done ==="
