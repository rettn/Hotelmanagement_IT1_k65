#include <stdio.h>
#include <string.h>
#include "room.h"
#include "color_utils.h"
void inputRoom(Room *r) {
    printf("Nhap ma phong: ");
    fgets(r->roomNo, sizeof(r->roomNo), stdin);
    r->roomNo[strcspn(r->roomNo, "\n")] = 0;
    
    printf("Nhap ten phong: ");
    fgets(r->roomName, sizeof(r->roomName), stdin);
    r->roomName[strcspn(r->roomName, "\n")] = 0;
    
    printf("Nhap tang: ");
    while (scanf("%d", &r->floor) != 1) {
        printError("Loi nhap tang! Nhap lai: ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    
    printf("Nhap so nguoi toi da: ");
    while (scanf("%d", &r->numMax) != 1) {
        printError("Loi nhap so nguoi! Nhap lai: ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    
    printf("Nhap gia: ");
    while (scanf("%d", &r->price) != 1) {
        printError("Loi nhap gia! Nhap lai: ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
}
void displayRoom(const Room *r) {
    printf("| %-10s | %-15s | Tang: %-2d | So nguoi: %-2d | Gia: %-7d |\n",
           r->roomNo, r->roomName, r->floor, r->numMax, r->price);
}
