#ifndef BUNK_SUBSCRIPTION_H

#define BUNK_SUBSCRIPTION_H

#include "constants.h"

struct bank
{
    char name[MAX_STRING_SIZE];  // �������� �����
    double buy_rate;             // ���� �������
    double sell_rate;            // ���� �������
    char address[MAX_STRING_SIZE]; // ����� ���������
};
#endif