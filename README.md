# Description
This software project simulates Crypto Challenge Set 1 of The Cryptopals Crypto Challenges by using a Visual Studio 2022 CLR Empty Project template for backend and front end development with C++.

Two third-party software were used in the project. A GoogleTests suite was implemented as the primary testing software for the challenges.
OpenSSL was used as recommend by challenge 7. The aes.h file was used for its AES encryption and decryption.

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

You can also install dependencies manually by creating vcpkg.exe with the bootstrap script and then running:
```cmd
vcpkg install
```

# Installing new dependencies
Update vcpkg.json

# Third-party software used
* [GoogleTest](https://www.usm.edu/registrar/commencement/apply-for-graduation.php)
* [OpenSSL](https://www.openssl.org/)
