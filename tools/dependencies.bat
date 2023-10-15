@echo off
setlocal

:: Navigate to vcpkg directory
pushd vcpkg

:: Check if vcpkg.exe exists
if not exist vcpkg.exe (
    echo Bootstrapping vcpkg...
    call bootstrap-vcpkg.bat
    if errorlevel 1 (
        echo Error bootstrapping vcpkg. Exiting.
        exit /b 1
    )
) else (
    echo vcpkg already bootstrapped.
)

:: Install dependencies
echo Installing dependencies...
vcpkg install
if errorlevel 1 (
    echo Error installing dependencies. Exiting.
    exit /b 1
)

:: Integrate vcpkg with Visual Studio
echo Integrating vcpkg with Visual Studio...
vcpkg integrate install
if errorlevel 1 (
    echo Error integrating vcpkg with Visual Studio. Exiting.
    exit /b 1
)

echo Dependencies installed!
popd
endlocal
exit /b 0
