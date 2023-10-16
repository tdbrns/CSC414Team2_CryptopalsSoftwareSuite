# Project Description
This software project simulate Crypto Challenge Set 1 of The Cryptopals Crypto Challenges using a Windows Form Application front end and a back end written in C++.

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

## 2. Run dependencies installation

Use the included tools/dependencies.bat script:
```cmd
tools/dependencies.bat
```

You can also install dependencies manually by creating vcpkg.exe with the bootstrap script and then running:
```cmd
vcpkg install
```

# Installing new dependencies

Update vcpkg.json
