//
// Created by abdullahdeliogullari
//

#include "MonoalphabeticCipher.h"

#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <random>

using namespace std;

MonoalphabeticCipher::MonoalphabeticCipher(int seed) {
    this->seed = seed;
}

void MonoalphabeticCipher::shuffleAlphabet() {
    default_random_engine defaultRandomEngine;
    defaultRandomEngine.seed(this->seed);
    shuffle(this->alphabet.begin(), this->alphabet.end(), defaultRandomEngine);
}

char MonoalphabeticCipher::characterMap(char character) {
    char mappedCharacter;

    if(isalpha(character) && isupper(character)) {
        int indexOfCharacterInAlphabet = character - 65;
        int mapLength = this->alphabet[indexOfCharacterInAlphabet];
        mappedCharacter = 'A' + mapLength;
    }

    else if(isalpha(character) && islower(character)) {
        int indexOfCharacterInAlphabet = character - 97;
        int mapLength = this->alphabet[indexOfCharacterInAlphabet];
        mappedCharacter = 'a' + mapLength;
    }

    else {
        mappedCharacter = character;
    }

    return mappedCharacter;
}

char MonoalphabeticCipher::characterRecover(char mappedCharacter) {
    char recoveredCharacter;

    if(isalpha(mappedCharacter) && isupper(mappedCharacter)) {
        int recoverLength = mappedCharacter - 65;
        vector<int>::iterator itr = find(this->alphabet.begin(), this->alphabet.end(), recoverLength);
        int indexOfCharacterInAlphabet = distance(this->alphabet.begin(), itr);
        recoveredCharacter = 'A' + indexOfCharacterInAlphabet;
    }

    else if(isalpha(mappedCharacter) && islower(mappedCharacter)) {
        int recoverLength = mappedCharacter - 97;
        vector<int>::iterator itr = find(this->alphabet.begin(), this->alphabet.end(), recoverLength);
        int indexOfCharacterInAlphabet = distance(this->alphabet.begin(), itr);
        recoveredCharacter = 'a' + indexOfCharacterInAlphabet;
    }

    else {
        recoveredCharacter = mappedCharacter;
    }

    return recoveredCharacter;
}

string MonoalphabeticCipher::encrypt(string plainText) {
    char currentCharacter;
    char encryptedCharacter;
    string cipherText(plainText.size(),' ');
    shuffleAlphabet();
    for(int i = 0; i < plainText.size(); i = i + 1) {
        currentCharacter = plainText[i];
        encryptedCharacter = characterMap(currentCharacter);
        cipherText[i] = encryptedCharacter;
    }
    return cipherText;
}

string MonoalphabeticCipher::decrypt(string cipherText) {
    char currentCharacter;
    char decryptedCharacter;
    string plainText(cipherText.size(),' ');
    shuffleAlphabet();
    for(int i = 0; i < cipherText.size(); i = i + 1){
        currentCharacter = cipherText[i];
        decryptedCharacter = characterRecover(currentCharacter);
        plainText[i] = decryptedCharacter;
    }
    return plainText;
}

