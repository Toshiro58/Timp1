#include <TableCipher.h>
#include <iostream>
#include <limits>
#include <locale>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    int key;
    wstring text;
    
    // Ввод ключа с ограничением на длину
    while (true) {
        wcout << L"Введите ключ (1-10): ";
        if (wcin >> key) {
            if (key < 1 || key > 10) { // ограничение длины ключа
                wcout << L"Ключ должен быть от 1 до 10. Попробуйте снова.\n";
                wcin.clear();
                wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
                continue;
            }
            wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
            break;
        } else {
            wcout << L"Неверный ввод ключа. Ключ - число больше нуля.\n";
            wcin.clear();
            wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
        }
    }
    
    TableCipher cipher(key);
    wcout << L"Ключ загружен\n";
    
    unsigned op;
    do {
        wcout << L"Шифр готов. Выберите операцию (0-выход, 1-зашифровать, 2-расшифровать): ";
        if (wcin >> op) {
            wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
            if (op > 2) {
                wcout << L"Неправильная операция\n";
            } else if (op > 0) {
                wcout << L"Введите текст: ";
                getline(wcin, text);
                if (op == 1) {
                    wcout << L"Зашифрованный текст: " << endl;
                    wcout << cipher.encrypt(text) << endl;
                } else {
                    wcout << L"Расшифрованный текст: " << cipher.decrypt(text) << endl;
                }
            }
        }
    } while (op != 0);
    
    return 0;
}
