//
// Created by abdullahdeliogullari on 4/18/20.
//

#include <cstdlib>
#include "gtest/gtest.h"

#include "../CaesarCipher/CaesarCipher.h"
#include "../MonoalphabeticCipher/MonoalphabeticCipher.h"
#include "../PolyalphabeticCipher/PolyalphabeticCipher.h"
#include "../DataEncryptionStandard/DataEncryptionStandard.h"

using namespace std;

int caesarRandomKey = rand() % 24;
int monoalphabeticRandomSeed = rand() % 100;
string polyalphabeticRandomKey = "secretKey";
string desRandomKey = "secureKey";

CaesarCipher caesarCipher = CaesarCipher(caesarRandomKey);
MonoalphabeticCipher monoalphabeticCipher = MonoalphabeticCipher(monoalphabeticRandomSeed);
PolyalphabeticCipher polyalphabeticCipher = PolyalphabeticCipher(polyalphabeticRandomKey);
DataEncryptionStandard dataEncryptionStandard = DataEncryptionStandard(desRandomKey);
DataEncryptionStandard dataEncryptionStandardPermutation = DataEncryptionStandard(desRandomKey);

TEST(CaesarCipherTest, EncryptDecryptProcess){

    string plainText = "exampleText";
    string cipherText = caesarCipher.encrypt(plainText);
    ASSERT_EQ(plainText, caesarCipher.decrypt(cipherText));

}

TEST(MonoalphabeticCipherTest, EncryptDecryptProcess){

    string plainText = "exampleText";
    string cipherText = monoalphabeticCipher.encrypt(plainText);
    ASSERT_EQ(plainText, monoalphabeticCipher.decrypt(cipherText));

}

TEST(PolyalphabeticCipherTest, EncryptDecryptProcess){

    string plainText = "exampleText";
    string cipherText = polyalphabeticCipher.encrypt(plainText);
    ASSERT_EQ(plainText, polyalphabeticCipher.decrypt(cipherText));

}

TEST(DataEncryptionStandardTest, EncryptDecryptProcess){

    // 8 bytes long plain-text
    string plainText = "example1";
    string cipherText = dataEncryptionStandard.encrypt(plainText);
    ASSERT_EQ(plainText, dataEncryptionStandard.decrypt(cipherText));

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}