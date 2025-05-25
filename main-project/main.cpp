#include <iostream>
#include "file_reader.h"


using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    
    const char* filename = "data.txt";  // ��� ����� � ������� �����
    bank* banks[MAX_FILE_ROWS_COUNT];   // ������ ���������� �� �����
    int size = 0;

    // ������ ������ �� �����
    read(filename, banks, size);

    // ���� ������ ��������
    int choice;
    cout << "�������� ��������:\n";
    cout << "1. ������� ����� ������ �� ���� ���������� '�����������'\n";
    cout << "2. ������� ����� ������ � ������ ������, ��� ������� < 2.5\n";
    cout << "������� ����� ��������: ";
    cin >> choice;

    if (choice == 1) {
        print_belarusbank_rates(banks, size);
    }
    else if (choice == 2) {
        print_low_sell_rate(banks, size);
    }
    else {
        cout << "������������ �����!" << endl;
    }

    // ������� ���������� ������
    for (int i = 0; i < size; i++) {
        delete banks[i];
    }

    return 0;
}
