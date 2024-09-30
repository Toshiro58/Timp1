#include "TableCipher.h"
#include <iostream>
#include <locale>
#include <string>

using namespace std;

TableCipher::TableCipher(int key) : key(key) {}

std::wstring TableCipher::encrypt(const std::wstring& text) {
    int rows;
    if (text.length() % key != 0) {
        rows = text.length() / key + 1;
    } else {
        rows = text.length() / key;
    }
    
    wchar_t table[rows][key];
    int index = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
            if (index < text.length()) {
                table[i][j] = text[index++];
            } else {
                table[i][j] = L' ';
            }
        }
    }
    
    std::wstring encrypted_text;
    for (int i = key - 1; i >= 0; i--) {
        for (int j = 0; j < rows; j++) {
            encrypted_text += table[j][i];
        }
    }
    
    return encrypted_text;
}

std::wstring TableCipher::decrypt(const std::wstring& encrypted_text) {
    int rows;
    if (encrypted_text.length() % key != 0) {
        rows = encrypted_text.length() / key + 1;
    } else {
        rows = encrypted_text.length() / key;
    }
    
    wchar_t table[rows][key];
    int index = 0;
    
    for (int i = key - 1; i >= 0; i--) {
        for (int j = 0; j < rows; ++j) {
            if (index < encrypted_text.length()) {
                table[j][i] = encrypted_text[index++];
            } else {
                table[j][i] = L' ';
            }
        }
    }
    
    wstring decrypted_text;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
            decrypted_text += table[i][j];
        }
    }
    
    return decrypted_text;
}



