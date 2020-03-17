//
// Created by abdullahdeliogullari
//

#include "CaesarCipher.h"

using namespace std;

CaesarCipher::CaesarCipher(int key) {
    this->key = key;
}

char CaesarCipher::characterShift(char character, int shift) {
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

string CaesarCipher::encrypt(string plainText) {
    char currentCharacter;
    char encryptedCharacter;
    string cipherText(plainText.size(),' ');
    for(int i = 0; i < plainText.size(); i = i + 1) {
        currentCharacter = plainText[i];
        encryptedCharacter = characterShift(currentCharacter, this->key);
        cipherText[i] = encryptedCharacter;
    }
    return cipherText;
}

string CaesarCipher::decrypt(string cipherText) {
    char currentCharacter;
    char decryptedCharacter;
    string plainText(cipherText.size(),' ');
    for(int i = 0; i < cipherText.size(); i = i + 1) {
        currentCharacter = cipherText[i];
        decryptedCharacter = characterShift(currentCharacter, -this->key);
        plainText[i] = decryptedCharacter;
    }
    return plainText;
}


