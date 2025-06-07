#include <stdio.h>
#include <string.h>
#include "hotel.h"
#include "utility.h"
#include "color_utils.h"
void inputHotel(Hotel *h) {
    printf("Nhap ma khach san: ");
    readLine(h->hotelNo, sizeof(h->hotelNo));
    
    printf("Nhap ten khach san: ");
    readLine(h->name, sizeof(h->name));
    
    printf("Nhap dia chi: ");
    readLine(h->address, sizeof(h->address));
    
    printf("Nhap loai: ");
    readLine(h->type, sizeof(h->type));
    
    char temp[10];
    printf("Nhap so phong: ");
    readLine(temp, sizeof(temp));
    h->roomCount = atoi(temp);
    for (int i = 0; i < h->roomCount; i++) {
        printf("--- Phong %d ---\n", i + 1);
        inputRoom(&h->roomList[i]);
    }
}

int isRoomAvailable(const Hotel *h, const Booking *bookings, int bookingCount, const Room *room) {
    for (int i = 0; i < bookingCount; i++) {
        if (strcmp(bookings[i].hotelNo, h->hotelNo) == 0 &&
            strcmp(bookings[i].roomNo, room->roomNo) == 0) {
            return 0;
        }
    }
    return 1;
}

void showRoomAvailable(const Hotel *h, const Booking *bookings, int bookingCount) {
    setColor(14);
    printf("Khach san: %s | Ma: %s | Dia chi: %s | Loai: %s\n",
           h->name, h->hotelNo, h->address, h->type);
    resetColor();
    printf("| %-10s | %-15s |   Tang   | So nguoi     |      Gia      |\n", "Ma phong", "Ten phong");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < h->roomCount; i++) {
        if (isRoomAvailable(h, bookings, bookingCount, &h->roomList[i])) {
            displayRoom(&h->roomList[i]);
        }
    }
}
Room* findRoomInHotel(Hotel* h, const char* roomNo) {
    for (int i = 0; i < h->roomCount; i++) {
        if (strcmp(h->roomList[i].roomNo, roomNo) == 0) {
            return &h->roomList[i];
        }
    }
    return NULL;
}
int calculateRevenue(const Hotel* h, const Booking* bookings, int bookingCount) {
    int revenue = 0;
    for (int i = 0; i < bookingCount; i++) {
        if (strcmp(bookings[i].hotelNo, h->hotelNo) == 0) {
            Room* r = findRoomInHotel((Hotel*)h, bookings[i].roomNo);
            if (r) {
                int days = calculateDays(bookings[i].checkIn, bookings[i].checkOut);
                revenue += r->price * days;
            }
        }
    }
    return revenue;
}
