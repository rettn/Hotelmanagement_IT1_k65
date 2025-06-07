#ifndef BOOKING_H
#define BOOKING_H

typedef struct {
    char hotelNo[20];
    char roomNo[20];
    char cmtnd[20];
    char checkIn[30];
    char checkOut[30];
} Booking;

void inputBooking(Booking* b);
void displayBooking(const Booking* b);
void printInvoice(const Booking* b);

#endif
