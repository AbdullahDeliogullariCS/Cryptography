//
// Created by abdullahdeliogullari on 4/18/20.
//

#include <gtest/gtest.h>

#include "../CaesarCipher/CaesarCipher.h"
#include "../MonoalphabeticCipher/MonoalphabeticCipher.h"
#include "../PolyalphabeticCipher/PolyalphabeticCipher.h"
#include "../DataEncryptionStandard/DataEncryptionStandard.h"
#include "../DiffieHellmanKeyExchange/DiffieHellmanKeyExchange.h"

using namespace std;

int caesarRandomKey = rand() % 24;
int monoalphabeticRandomSeed = rand() % 100;
string polyalphabeticRandomKey = "secretKey";
string desRandomKey = "secretKey";

CaesarCipher caesarCipherEncryption = CaesarCipher(caesarRandomKey);
CaesarCipher caesarCipherDecryption = CaesarCipher(caesarRandomKey);

MonoalphabeticCipher monoalphabeticCipherEncryption = MonoalphabeticCipher(monoalphabeticRandomSeed);
MonoalphabeticCipher monoalphabeticCipherDecryption = MonoalphabeticCipher(monoalphabeticRandomSeed);

PolyalphabeticCipher polyalphabeticCipherEncryption = PolyalphabeticCipher(polyalphabeticRandomKey);
PolyalphabeticCipher polyalphabeticCipherDecryption = PolyalphabeticCipher(polyalphabeticRandomKey);

DataEncryptionStandard dataEncryptionStandardEncryption = DataEncryptionStandard(desRandomKey);
DataEncryptionStandard dataEncryptionStandardDecryption = DataEncryptionStandard(desRandomKey);

DiffieHellmanKeyExchange diffieHellmanKeyExchangeAlice = DiffieHellmanKeyExchange();
DiffieHellmanKeyExchange diffieHellmanKeyExchangeBob = DiffieHellmanKeyExchange();

TEST(CaesarCipherTest, EncryptDecryptProcess){

    srand((unsigned int)time(NULL));
    string plainText = "exampleText";
    string cipherText = caesarCipherEncryption.encrypt(plainText);
    ASSERT_EQ(plainText, caesarCipherDecryption.decrypt(cipherText));

}

TEST(MonoalphabeticCipherTest, EncryptDecryptProcess){

    srand((unsigned int)time(NULL));
    string plainText = "exampleText";
    string cipherText = monoalphabeticCipherEncryption.encrypt(plainText);
    ASSERT_EQ(plainText, monoalphabeticCipherDecryption.decrypt(cipherText));

}

TEST(PolyalphabeticCipherTest, EncryptDecryptProcess){

    string plainText = "exampleText";
    string cipherText = polyalphabeticCipherEncryption.encrypt(plainText);
    ASSERT_EQ(plainText, polyalphabeticCipherDecryption.decrypt(cipherText));

}

TEST(DataEncryptionStandardTest, EncryptDecryptProcess){

    string plainText = "example1";
    string cipherText = dataEncryptionStandardEncryption.encrypt(plainText);
    ASSERT_EQ(plainText, dataEncryptionStandardDecryption.decrypt(cipherText));

}

TEST(DiffieHellmanKeyExchangeTest, EncryptDecryptProcess){

    int alice_public_key = diffieHellmanKeyExchangeAlice.generatePublicKey(9,4,167);
    int bob_public_key = diffieHellmanKeyExchangeBob.generatePublicKey(9,3,167);
    int alice_shared_key = diffieHellmanKeyExchangeAlice.generateSharedKey(bob_public_key,4,167);
    int bob_shared_key = diffieHellmanKeyExchangeBob.generateSharedKey(alice_public_key,3,167);
    ASSERT_EQ(alice_shared_key, bob_shared_key);

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}