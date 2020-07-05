//
// Created by abdullahdeliogullari on 4/23/20.
//

#include "DataEncryptionStandard.h"

#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

DataEncryptionStandard::DataEncryptionStandard(string key) {
    this->key = key;
}

string DataEncryptionStandard::convertCharacterToBinary(char character) {
    std::bitset<8> characterToBinary(character);
    string characterBinaryToString = characterToBinary.to_string();
    return characterBinaryToString;
}

char DataEncryptionStandard::convertBinaryToCharacter(string binary) {
    char binaryToCharacter = static_cast<char>(std::stoi(binary, nullptr, 2));
    return binaryToCharacter;
}

string DataEncryptionStandard::convertStringToBinary(string stringText) {
    char character;
    string binaryText;

    for(int i = 0; i < stringText.size(); i = i + 1){
        character = stringText[i];
        binaryText.append(convertCharacterToBinary(character));
    }
    return binaryText;
}

string DataEncryptionStandard::convertBinaryToString(string binaryText) {
    string characterBinary;
    string stringText;
    for(int i = 0; i < binaryText.length(); i += 8){
        characterBinary = convertBinaryToCharacter(binaryText.substr(i, 8));
        stringText.append(characterBinary);
    }
    return stringText;
}

void DataEncryptionStandard::convertKeyStringToBinary() {
    this->key64bit.clear();
    this->key64bit = convertStringToBinary(this->key);
}

void DataEncryptionStandard::splitKeyInto2Halves() {
    this->key28bitLeftHalve = this->key56bit.substr(0, this->key56bit.length()/2);
    this->key28bitRightHalve = this->key56bit.substr(this->key56bit.length()/2);
}

void DataEncryptionStandard::concatenate2KeyHalves() {
    this->key56bit = this->key28bitLeftHalve + this->key28bitRightHalve;
}

void DataEncryptionStandard::permutedChoice1() {
    this->key56bit.clear();
    for(int i = 0; i < this->PC1.size(); i = i + 1){
        char shiftedBinary = this->key64bit[this->PC1[i] - 1];
        this->key56bit.push_back(shiftedBinary);
    }
}

void DataEncryptionStandard::leftShift(int shiftAmount) {
    std::rotate(
            this->key28bitLeftHalve.begin(),
            this->key28bitLeftHalve.begin()+shiftAmount,
            this->key28bitLeftHalve.end());

    std::rotate(
            this->key28bitRightHalve.begin(),
            this->key28bitRightHalve.begin()+shiftAmount,
            this->key28bitRightHalve.end());
}

void DataEncryptionStandard::permutedChoice2() {
    this->key48bit.clear();
    for(int i = 0; i < this->PC2.size(); i = i + 1){
        char shiftedBinary = this->key56bit[this->PC2[i] - 1];
        this->key48bit.push_back(shiftedBinary);
    }
}

void DataEncryptionStandard::convertPlainTextStringToBinary() {
    this->plainText64bit = convertStringToBinary(this->plainText);
}

void DataEncryptionStandard::initialPermutation() {
    this->permutedPlainText64bit.clear();
    for(int i = 0; i < this->IP.size(); i = i + 1){
        char shiftedBinary = this->plainText64bit[this->IP[i] - 1];
        this->permutedPlainText64bit.push_back(shiftedBinary);
    }
}

void DataEncryptionStandard::splitPlainTextInto2Halves() {
    this->plainText32bitLeftHalve = this->permutedPlainText64bit.substr(0, this->plainText64bit.length()/2);
    this->plainText32bitRightHalve = this->permutedPlainText64bit.substr(this->plainText64bit.length()/2);
}

void DataEncryptionStandard::expansionPermutation() {
    this->plainText48bit.clear();
    for(int i = 0; i < this->E.size(); i = i + 1){
        char shiftedBinary = this->plainText32bitRightHalve[this->E[i] - 1];
        this->plainText48bit.push_back(shiftedBinary);
    }
}

void DataEncryptionStandard::plainTextKeyExclusiveDisjunction() {
    auto xoredBinary = std::bitset<48>(this->plainText48bit) ^ std::bitset<48>(this->key48bit);
    this->exclusiveDisjunction48bit = xoredBinary.to_string();
}

void DataEncryptionStandard::substitutionProcedure() {
    this->substituted32bit.clear();
    int substitutionTableIndex = 0;
    for(int i = 0; i < this->exclusiveDisjunction48bit.length(); i += 6){
        string rowNumber2bit;
        string columnNumber4bit;
        int rowIndex;
        int columnIndex;
        string chunk6bit = this->exclusiveDisjunction48bit.substr(i, 6);

        rowNumber2bit.push_back(chunk6bit[0]);
        rowNumber2bit.push_back(chunk6bit[5]);

        columnNumber4bit.push_back(chunk6bit[1]);
        columnNumber4bit.push_back(chunk6bit[2]);
        columnNumber4bit.push_back(chunk6bit[3]);
        columnNumber4bit.push_back(chunk6bit[4]);

        rowIndex = std::stoi(rowNumber2bit, nullptr, 2);
        columnIndex = std::stoi(columnNumber4bit, nullptr, 2);

        int substitutedChunk = this->S[substitutionTableIndex][rowIndex][columnIndex];

        std::bitset<4> substitutedChunk4bit(substitutedChunk);
        string substitutedChunkString = substitutedChunk4bit.to_string();
        this->substituted32bit.append(substitutedChunkString);
        substitutionTableIndex = substitutionTableIndex + 1;
    }
}

void DataEncryptionStandard::permutationOperation() {
    this->permuted32bit.clear();
    for(int i = 0; i < this->P.size(); i = i + 1){
        char shiftedBinary = this->substituted32bit[this->P[i] - 1];
        this->permuted32bit.push_back(shiftedBinary);
    }
}

void DataEncryptionStandard::plainTextChunksExclusiveDisjunction() {
    auto xoredBinary = std::bitset<32>(this->plainText32bitLeftHalve) ^ std::bitset<32>(this->permuted32bit);
    this->exclusiveDisjunction32bit = xoredBinary.to_string();
}

void DataEncryptionStandard::plainTextChunksSwap() {
    this->swaped64bit.clear();
    this->plainText32bitLeftHalve = this->plainText32bitRightHalve;
    this->plainText32bitRightHalve = this->exclusiveDisjunction32bit;
    this->swaped64bit = plainText32bitRightHalve + plainText32bitLeftHalve;
}

void DataEncryptionStandard::finalPermutation() {
    this->cipherText64bit.clear();
    for(int i = 0; i < this->FP.size(); i = i + 1){
        char shiftedBinary = this->swaped64bit[this->FP[i] - 1];
        this->cipherText64bit.push_back(shiftedBinary);
    }
}

void DataEncryptionStandard::convertCipherTextBinaryToString() {
    this->cipherText = convertBinaryToString(this->cipherText64bit);
}

string DataEncryptionStandard::encrypt(string plainText) {
    convertKeyStringToBinary();
    permutedChoice1();
    splitKeyInto2Halves();

    this->plainText = plainText;
    convertPlainTextStringToBinary();
    initialPermutation();
    splitPlainTextInto2Halves();

    for(int shiftIndex = 0; shiftIndex < this->ShiftTable.size(); shiftIndex = shiftIndex + 1){
        int shiftAmount = this->ShiftTable[shiftIndex];
        leftShift(shiftAmount);
        concatenate2KeyHalves();
        permutedChoice2();

        expansionPermutation();

        plainTextKeyExclusiveDisjunction();
        substitutionProcedure();
        permutationOperation();
        plainTextChunksExclusiveDisjunction();
        plainTextChunksSwap();
    }

    finalPermutation();
    convertCipherTextBinaryToString();
    return this->cipherText;
}

string DataEncryptionStandard::decrypt(string cipherText) {
    convertKeyStringToBinary();
    permutedChoice1();
    splitKeyInto2Halves();

    this->plainText = cipherText;
    convertPlainTextStringToBinary();
    initialPermutation();
    splitPlainTextInto2Halves();

    this->key48bitContainer.clear();
    for(int shiftIndex = 0; shiftIndex < this->ShiftTable.size(); shiftIndex = shiftIndex + 1){
        int shiftAmount = this->ShiftTable[shiftIndex];
        leftShift(shiftAmount);
        concatenate2KeyHalves();
        permutedChoice2();
        this->key48bitContainer.push_back(this->key48bit);
    }

    for(int shiftIndex = this->ShiftTable.size() - 1; shiftIndex >= 0; shiftIndex = shiftIndex - 1){
        this->key48bit = this->key48bitContainer.at(shiftIndex);

        expansionPermutation();

        plainTextKeyExclusiveDisjunction();
        substitutionProcedure();
        permutationOperation();
        plainTextChunksExclusiveDisjunction();
        plainTextChunksSwap();
    }

    finalPermutation();
    convertCipherTextBinaryToString();
    return this->cipherText;
}