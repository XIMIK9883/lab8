#include <iostream>
#include "file_reader.h"


using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    
    const char* filename = "data.txt";  // Имя файла с курсами валют
    bank* banks[MAX_FILE_ROWS_COUNT];   // Массив указателей на банки
    int size = 0;

    // Чтение данных из файла
    read(filename, banks, size);

    // Меню выбора операции
    int choice;
    cout << "Выберите операцию:\n";
    cout << "1. Вывести курсы валюты во всех отделениях 'Беларусбанк'\n";
    cout << "2. Вывести курсы валюты и адреса банков, где продажа < 2.5\n";
    cout << "Введите номер операции: ";
    cin >> choice;

    if (choice == 1) {
        print_belarusbank_rates(banks, size);
    }
    else if (choice == 2) {
        print_low_sell_rate(banks, size);
    }
    else {
        cout << "Некорректный выбор!" << endl;
    }

    // Очистка выделенной памяти
    for (int i = 0; i < size; i++) {
        delete banks[i];
    }

    return 0;
}
