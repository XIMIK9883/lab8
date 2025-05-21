#ifndef BUNK_SUBSCRIPTION_H

#define BUNK_SUBSCRIPTION_H

#include "constants.h"

struct bank
{
    char name[MAX_STRING_SIZE];  // Название банка
    double buy_rate;             // Курс покупки
    double sell_rate;            // Курс продажи
    char address[MAX_STRING_SIZE]; // Адрес отделения
};
#endif