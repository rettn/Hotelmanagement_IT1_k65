#ifndef UTILITY_H
#define UTILITY_H
#include <time.h>
int readInt(const char* prompt);
void readLine(char* buf, int sz);
int convertStringToDateTime(const char*, struct tm*);
void convertDateTimeToString(const struct tm*, char*, int);
int calculateDays(const char*, const char*);
#endif