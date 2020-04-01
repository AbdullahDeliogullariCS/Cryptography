//
// Created by abdullahdeliogullari on 4/1/20.
//

#include "PolyalphabeticCipher.h"

#include <iostream>
#include <string>

PolyalphabeticCipher::PolyalphabeticCipher(string key) {
    this->key = key;
}

char PolyalphabeticCipher::characterShift(char character, int shift) {
    char shiftedCharacter;

    if(isalpha(character) && isupper(character)) {
        shiftedCharacter = ((((character - 65) + shift) + 26) % 26) + 65;
    }

    else if(isalpha(character) && islower(character)) {
        shiftedCharacter = ((((character - 97) + shift) + 26) % 26) + 97;
    }

    else {
        shiftedCharacter = character;
    }

    return shiftedCharacter;
}

string PolyalphabeticCipher::encrypt(string plainText) {
    int shift;
    int shiftIndex = 0;
    string cipherText(plainText.size(),' ');
    for(int i = 0; i < plainText.size(); i = i + 1) {
        char currentCharacter = plainText[i];
        if(!isalpha(currentCharacter)){
            continue;
        }
        shift = this->key[shiftIndex] % 26;
        char encryptedCharacter = characterShift(currentCharacter, shift);
        cipherText[i] = encryptedCharacter;
        if(shiftIndex < this->key.size() - 1){
            shiftIndex = shiftIndex + 1;
            continue;
        }
        shiftIndex = 0;
    }
    return cipherText;
}

string PolyalphabeticCipher::decrypt(string cipherText) {
    int shift;
    string plainText(cipherText.size(),' ');
    int shiftIndex = 0;
    for (int i = 0; i < cipherText.size(); i = i + 1) {
        char currentCharacter = cipherText[i];
        if(!isalpha(currentCharacter)){
            continue;
        }
        shift = this->key[shiftIndex] % 26;
        char decryptedCharacter = characterShift(currentCharacter, -shift);
        plainText[i] = decryptedCharacter;
        if(shiftIndex < this->key.size() - 1){
            shiftIndex = shiftIndex + 1;
            continue;
        }
        shiftIndex = 0;
    }
    return plainText;
}