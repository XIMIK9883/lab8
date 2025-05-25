#ifndef FILE_READER_H
#define FILE_READER_H

#include "bank_subscription.h"

void read(const char* file_name, bank* array[], int& size);
void print_belarusbank_rates(bank* array[], int size);
void print_low_sell_rate(bank* array[], int size);

#endif
