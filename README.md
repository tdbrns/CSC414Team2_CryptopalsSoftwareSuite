# Overview

This software project simulates Crypto Challenge Set 1 of The Cryptopals Crypto Challenges by using a Visual Studio 2022 CLR Empty Project template for backend and front end development with C++.

# Dependencies

Three third-party software components are used in the project: GoogleTest, OpenSSL, and vcpkg. 
- A GoogleTests suite is implemented as the primary QA testing software and for the project.
- The OpenSSL v1.1.1 library is integrated into the project mainly for its _aes.h_ file, which provides features for AES encryption and decryption that are essential in solving Cryptopal challenges 7 and 8.
- vcpkg is used as a git submodule that manages the integration of software packages for OpenSSL and GoogleTest into the project.

### Documentation for dependencies

* [GoogleTest documentation](https://google.github.io/googletest/primer.html)
* [GoogleTest repository](https://github.com/google/googletest)
* [OpenSSL documentation](https://www.openssl.org/)
* [OpenSSL repository](https://github.com/openssl/openssl)
* [vcpkg documentation](https://learn.microsoft.com/en-us/vcpkg/)
* [vcpkg Repository](https://github.com/microsoft/vcpkg)

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
