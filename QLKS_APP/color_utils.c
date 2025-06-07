#include "color_utils.h"

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resetColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void printSuccess(const char* msg) {
    setColor(10);
    printf("%s\n", msg);
    resetColor();
}

void printError(const char* msg) {
    setColor(12);
    printf("%s\n", msg);
    resetColor();
}
