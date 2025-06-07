#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H
#include "customer.h"
#include "hotel.h"
#include "booking.h"
#define MAX_CUSTOMERS 100
#define MAX_HOTELS 50
#define MAX_BOOKINGS 200
typedef struct {
    Customer customerList[MAX_CUSTOMERS];
    int customerCount;
    Hotel hotelList[MAX_HOTELS];
    int hotelCount;
    Booking bookingList[MAX_BOOKINGS];
    int bookingCount;
} DataController;
extern DataController dataController;
Hotel* findHotel(const char *hotelNo);
#endif
