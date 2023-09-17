# Project setup

### 1. Clone the repository with submodules
Clone the repo:
```cmd
git clone --recursive https://github.com/tdbrns/CSC414Team2_CryptopalsSoftwareSuite.git
```

If you already have the source without submodules, run in root dir:
```cmd
git submodule update --init
```

### 2. Run dependencies installation
Use the included tools/dependencies.bat script:
```cmd
tools/dependencies.bat
```

# Managing new dependencies
### Installing a new dependency with vcpkg:
vcpkg does not include a traditional package lock system, so new dependencies must be appended to the bat script manually.
```cmd
./vcpkg install [dependency] --triplet x64-windows
```
