#ifndef ENCRYPT_H_
#define ENCRYPT_H_

#define CIPHER_KEY_SIZE 16
#define CIPHER_IV_SIZE  12
#define CIPHER_TAG_SIZE 16
#define SHA_DIGEST_SIZE 32
#define CIPHER_PK_SIZE 512
#define SIG_ALLOC_SIZE 1024

#include <iostream> 
#include <map>
#include <vector>
#include <string>
#include <string.h>
#include <stdio.h>
#include "serialization.h"
#include "crypto.h"

#include "mbedtls/config.h"
#include "mbedtls/gcm.h"
#include "mbedtls/entropy.h"    // mbedtls_entropy_context
#include "mbedtls/ctr_drbg.h"   // mbedtls_ctr_drbg_context
#include "mbedtls/cipher.h"     // MBEDTLS_CIPHER_ID_AES
#include "mbedtls/gcm.h"        // mbedtls_gcm_context
#include "mbedtls/pk.h"
#include "mbedtls/rsa.h"
#include "mbedtls/sha256.h"
#include "mbedtls/x509_crt.h"
#include "mbedtls/error.h"

static int print_bytes_(uint8_t* data, size_t len) {
  for (int i = 0; i < len; i++)
    std::cout << (int) data[i] << " ";
  std::cout << std::endl;
}

void encrypt_bytes(uint8_t* model_data, size_t data_len, uint8_t** ciphertext) {

    mbedtls_gcm_context gcm;
    mbedtls_gcm_init(&gcm);

    unsigned char key[] = "abcdefghijklmnop";

    unsigned char* output = ciphertext[0];
    unsigned char* iv = ciphertext[1];
    unsigned char* tag = ciphertext[2];

    int ret = encrypt_symm(
        key,
        model_data,
        data_len,
        NULL,
        0,
        output,
        iv,
        tag
    );
}

void decrypt_bytes(uint8_t* model_data, uint8_t* iv, uint8_t* tag, size_t data_len, uint8_t** text) {
    mbedtls_gcm_context gcm;
    mbedtls_gcm_init(&gcm);

    unsigned char key[] = "abcdefghijklmnop";

    decrypt_symm(
        key,
        model_data,
        data_len,
        iv,
        tag,
        NULL,
        0,
        *text
    );
}

#endif
