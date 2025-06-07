#ifndef HOTEL_H
#define HOTEL_H
#include "room.h"
#include "booking.h"
#define MAX_ROOMS 50
typedef struct {
    char hotelNo[20], name[50], address[100], type[30];
    Room roomList[MAX_ROOMS];
    int roomCount;
} Hotel;
void inputHotel(Hotel* h);
void showRoomAvailable(const Hotel* h, const Booking* bks, int bkCnt);
int calculateRevenue(const Hotel* h, const Booking* bookings, int bookingCount);
Room* findRoomInHotel(Hotel*, const char*);
#endif