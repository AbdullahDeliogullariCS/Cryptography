cmake_minimum_required(VERSION 3.13)

project(Cryptography)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})

enable_testing()

add_subdirectory(library/googletest-master)

set(HEADERS
        CaesarCipher/CaesarCipher.h
        MonoalphabeticCipher/MonoalphabeticCipher.h
        PolyalphabeticCipher/PolyalphabeticCipher.h
        DataEncryptionStandard/DataEncryptionStandard.h
        DiffieHellmanKeyExchange/DiffieHellmanKeyExchange.h RivestShamirAdleman/RivestShamirAdleman.cpp RivestShamirAdleman/RivestShamirAdleman.h)

set(SOURCES
        CaesarCipher/CaesarCipher.cpp
        MonoalphabeticCipher/MonoalphabeticCipher.cpp
        PolyalphabeticCipher/PolyalphabeticCipher.cpp
        DataEncryptionStandard/DataEncryptionStandard.cpp
        DiffieHellmanKeyExchange/DiffieHellmanKeyExchange.cpp RivestShamirAdleman/RivestShamirAdleman.cpp RivestShamirAdleman/RivestShamirAdleman.h)

add_library(core ${HEADERS} ${SOURCES})

target_include_directories(core PUBLIC)

add_executable(Cryptography main.cpp)

target_link_libraries(Cryptography core)

add_subdirectory(test)