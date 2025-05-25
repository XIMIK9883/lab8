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
        cerr << "������ �������� �����: " << file_name << endl;
        return;
    }

    size = 0;
    while (!file.eof() && size < MAX_FILE_ROWS_COUNT)
    {
        array[size] = new bank;
        file >> array[size]->name >> array[size]->buy_rate >> array[size]->sell_rate;
        file.ignore();  // ������������ ������ ����� �������
        file.getline(array[size]->address, MAX_STRING_SIZE);
        size++;
    }
    file.close();
}

// ������� ������ ������ ������ �� ���� ���������� "�����������"
void print_belarusbank_rates(bank* array[], int size)
{
    cout << "����� ������ � ���������� �����������:\n";
    for (int i = 0; i < size; i++)
    {
        if (strcmp(array[i]->name, "�����������") == 0)
        {
            cout << array[i]->name << " | �������: " << array[i]->buy_rate
                << " | �������: " << array[i]->sell_rate << " | �����: " << array[i]->address << endl;
        }
    }
}

// ������� ������ ������, ��� ���� ������� ������ 2.5
void print_low_sell_rate(bank* array[], int size)
{
    cout << "��������� ������ � ������ ������� < 2.5:\n";
    for (int i = 0; i < size; i++)
    {
        if (array[i]->sell_rate < 2.5)
        {
            cout << array[i]->name << " | �������: " << array[i]->buy_rate
                << " | �������: " << array[i]->sell_rate << " | �����: " << array[i]->address << endl;
        }
    }
}
