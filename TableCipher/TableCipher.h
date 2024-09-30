#pragma once
#include <string>

class TableCipher {
private:
    int key;
public:
    TableCipher() = delete; 
    TableCipher(int key);   
    std::wstring encrypt(const std::wstring& text);
    std::wstring decrypt(const std::wstring& encrypted_text);
};
