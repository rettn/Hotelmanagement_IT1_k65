#ifndef ROOM_H
#define ROOM_H
typedef struct {
    char roomNo[20], roomName[50];
    int floor, numMax, price;
} Room;
void inputRoom(Room* r);
void displayRoom(const Room* r);
#endif