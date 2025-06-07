#ifndef CUSTOMER_H
#define CUSTOMER_H
typedef struct {
    char fullname[50];
    int age;
    char cmtnd[20];
    char gender[10];
    char address[100];
} Customer;
void inputCustomer(Customer* c);
void inputCustomerWithoutCMTND(Customer* c);
void displayCustomer(const Customer* c);
#endif