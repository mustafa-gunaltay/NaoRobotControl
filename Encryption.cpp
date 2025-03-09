/**
 * Bu sınıf Oğuzhan Sarıgöl ve Kübra Nur Durak tarafından yazıldı ve düzenlendi.
 * Tarih : 26/12/2023
 */
#include"Encryption.h"
#include<iostream>
#include<string>
using namespace std;

Encryption::Encryption() {}


int Encryption::encrypt(int numToEncrypt) {
    if (numToEncrypt < 0 || numToEncrypt > 9999) {
        std::cerr << "Input must be a positive four-digit number." << std::endl;
        return -1; // Error code for invalid input
    }

    int encrypted = numToEncrypt;

    int first = encrypted / 1000;
    int second = (encrypted / 100) % 10;
    int third = (encrypted / 10) % 10;
    int fourth = encrypted % 10;

    // Encryption process
    first = (first + 7) % 10;
    second = (second + 7) % 10;
    third = (third + 7) % 10;
    fourth = (fourth + 7) % 10;

    // Swapping digits
    int temp = first;
    first = third;
    third = temp;

    temp = second;
    second = fourth;
    fourth = temp;

    // Forming the encrypted number
    encrypted = (first * 1000) + (second * 100) + (third * 10) + fourth;

    return encrypted;
}

int Encryption::decrypt(int numToDecrypt) {
    if (numToDecrypt < 0 || numToDecrypt > 9999) {
        std::cerr << "Input must be a positive four-digit number." << std::endl;
        return -1; // Error code for invalid input
    }

    int decrypted = numToDecrypt;

    int first = decrypted / 1000;
    int second = (decrypted / 100) % 10;
    int third = (decrypted / 10) % 10;
    int fourth = decrypted % 10;

    // Reversing the encryption process
    // Swapping digits back
    int temp = first;
    first = third;
    third = temp;

    temp = second;
    second = fourth;
    fourth = temp;

    // Decryption process
    // Subtracting 7 and handling negative values
    first = (first >= 7) ? (first - 7) : (first + 10 - 7);
    second = (second >= 7) ? (second - 7) : (second + 10 - 7);
    third = (third >= 7) ? (third - 7) : (third + 10 - 7);
    fourth = (fourth >= 7) ? (fourth - 7) : (fourth + 10 - 7);

    // Forming the decrypted number
    decrypted = (first * 1000) + (second * 100) + (third * 10) + fourth;

    return decrypted;
}

