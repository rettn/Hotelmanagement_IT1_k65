#include <string.h>
#include "datacontroller.h"
DataController dataController = {0};
Hotel* findHotel(const char *hotelNo) {
    for (int i = 0; i < dataController.hotelCount; i++) {
        if (strcmp(dataController.hotelList[i].hotelNo, hotelNo) == 0) {
            return &dataController.hotelList[i];
        }
    }
    return NULL;
}
