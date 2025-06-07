#include <stdio.h>
#include <string.h>
#include "booking.h"
#include "datacontroller.h"
#include "customer.h"
#include "utility.h"
#include "color_utils.h"
#include "hotel.h"

int isRoomBooked(const char* hotelNo, const char* roomNo) {
    for (int i = 0; i < dataController.bookingCount; i++)
        if (!strcmp(dataController.bookingList[i].hotelNo, hotelNo)
            && !strcmp(dataController.bookingList[i].roomNo, roomNo))
            return 1;
    return 0;
}

void inputBooking(Booking* b) {
    printf("Nhap ma khach san: ");
    readLine(b->hotelNo, sizeof(b->hotelNo));
    while (!findHotel(b->hotelNo)) {
        printError("Khach san khong ton tai. Nhap lai: ");
        readLine(b->hotelNo, sizeof(b->hotelNo));
    }
    printf("Nhap ma phong: ");
    readLine(b->roomNo, sizeof(b->roomNo));
    if (isRoomBooked(b->hotelNo, b->roomNo)) {
        printError("Phong nay da co nguoi dat. Chon phong khac.");
        b->roomNo[0] = '\0';
        return;
    }
    printf("Nhap CCCD: ");
    readLine(b->cmtnd, sizeof(b->cmtnd));
    printf("Nhap ngay nhan (yyyy-MM-dd): ");
    readLine(b->checkIn, sizeof(b->checkIn));
    printf("Nhap ngay tra  (yyyy-MM-dd): ");
    readLine(b->checkOut, sizeof(b->checkOut));
}

void displayBooking(const Booking* b) {
    printf("| %-10s | %-10s | %-12s | %-19s | %-19s |\n",
        b->hotelNo, b->roomNo, b->cmtnd, b->checkIn, b->checkOut);
}

void printInvoice(const Booking* b) {
    Hotel* h = findHotel(b->hotelNo);
    if (!h) { printError("Khong tim thay KS."); return; }
    Room* r = findRoomInHotel(h, b->roomNo);
    if (!r) { printError("Khong tim thay phong."); return; }
    int days = calculateDays(b->checkIn, b->checkOut);
    int total = r->price * days;
   //In hoa don
    printf("\n========= HOA DON =========\n");
    printf("Khach san: %s\n", h->name);
    printf("Phong     : %s\n", r->roomNo);
    printf("Don gia   : %d VND/ngay\n", r->price);
    printf("So ngay   : %d\n", days);
    printf("Thanh tien: %d VND\n", total);
    // Luu file
    char fn[100];
    sprintf(fn, "hoadon_%s_%s.txt", b->hotelNo, b->roomNo);
    FILE* f = fopen(fn, "w");
    if (f) {
        fprintf(f, "========= HOA DON =========\n");
        fprintf(f, "Khach san: %s\n", h->name);
        fprintf(f, "Phong     : %s\n", r->roomNo);
        fprintf(f, "Don gia   : %d VND/ngay\n", r->price);
        fprintf(f, "So ngay   : %d\n", days);
        fprintf(f, "Thanh tien: %d VND\n", total);
        fclose(f);
        printf(">> Da luu hoa don: %s\n", fn);
    }
}
