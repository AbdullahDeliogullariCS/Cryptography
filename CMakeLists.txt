cmake_minimum_required(VERSION 3.14)
project(Cryptography)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cryptography main.cpp
               CaesarCipher/CaesarCipher.cpp CaesarCipher/CaesarCipher.h
               MonoalphabeticCipher/MonoalphabeticCipher.cpp MonoalphabeticCipher/MonoalphabeticCipher.h
               FileOperations/FileOperations.cpp FileOperations/FileOperations.h
               PolyalphabeticCipher/PolyalphabeticCipher.cpp PolyalphabeticCipher/PolyalphabeticCipher.h)
