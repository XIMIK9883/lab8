#include "file_reader.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void read(const char* file_name, bank* array[], int& size)
{
    ifstream file(file_name);
    if (!file)
    {
        cerr << "Ошибка открытия файла: " << file_name << endl;
        return;
    }

    size = 0;
    while (!file.eof() && size < MAX_FILE_ROWS_COUNT)
    {
        array[size] = new bank;
        file >> array[size]->name >> array[size]->buy_rate >> array[size]->sell_rate;
        file.ignore();  // Игнорировать пробел перед адресом
        file.getline(array[size]->address, MAX_STRING_SIZE);
        size++;
    }
    file.close();
}

// Функция вывода курсов валюты во всех отделениях "Беларусбанк"
void print_belarusbank_rates(bank* array[], int size)
{
    cout << "Курсы валюты в отделениях Беларусбанк:\n";
    for (int i = 0; i < size; i++)
    {
        if (strcmp(array[i]->name, "Беларусбанк") == 0)
        {
            cout << array[i]->name << " | Покупка: " << array[i]->buy_rate
                << " | Продажа: " << array[i]->sell_rate << " | Адрес: " << array[i]->address << endl;
        }
    }
}

// Функция вывода банков, где курс продажи меньше 2.5
void print_low_sell_rate(bank* array[], int size)
{
    cout << "Отделения банков с курсом продажи < 2.5:\n";
    for (int i = 0; i < size; i++)
    {
        if (array[i]->sell_rate < 2.5)
        {
            cout << array[i]->name << " | Покупка: " << array[i]->buy_rate
                << " | Продажа: " << array[i]->sell_rate << " | Адрес: " << array[i]->address << endl;
        }
    }
}
