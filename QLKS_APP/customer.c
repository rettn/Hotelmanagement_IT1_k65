#include <stdio.h>
#include "utility.h"
#include "customer.h"
#include "color_utils.h"

void inputCustomer(Customer* c) {
    printf("Nhap CCCD: ");
    readLine(c->cmtnd, sizeof(c->cmtnd));
    inputCustomerWithoutCMTND(c);
}

void inputCustomerWithoutCMTND(Customer* c) {
    printf("Nhap ten: ");
    readLine(c->fullname, sizeof(c->fullname));
    c->age = readInt("Nhap tuoi: ");
    printf("Nhap gioi tinh: ");
    readLine(c->gender, sizeof(c->gender));
    printf("Nhap dia chi: ");
    readLine(c->address, sizeof(c->address));
}

void displayCustomer(const Customer* c) {
    printf("Ten: %s | Tuoi: %d | CCCD: %s | GT: %s | DC: %s\n",
        c->fullname, c->age, c->cmtnd, c->gender, c->address);
}