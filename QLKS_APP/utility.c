#include <stdio.h>
#include <string.h>
#include <time.h>
#include "utility.h"

void readLine(char* buf, int sz) {
    if (!buf || sz <= 0)return;
    if (fgets(buf, sz, stdin)) buf[strcspn(buf, "\n")] = 0;
}

int readInt(const char* pr) {
    char tmp[64]; int v;
    printf("%s", pr);
    readLine(tmp, sizeof(tmp));
    if (sscanf(tmp, "%d", &v) != 1) {
        printf("Nhap so nguyen khong hop le!\n");
        v = 0; // hoặc return lỗi
    }

    return v;
}

//int convertStringToDateTime(const char* s, struct tm* t) {
//    return sscanf(s, "%d-%d-%d %d:%d:%d",
//        &t->tm_year, &t->tm_mon, &t->tm_mday,
//        &t->tm_hour, &t->tm_min, &t->tm_sec) == 6;
//}
//
//void convertDateTimeToString(const struct tm* t, char* b, int sz) {
//    snprintf(b, sz, "%04d-%02d-%02d %02d:%02d:%02d",
//        t->tm_year, t->tm_mon, t->tm_mday,
//        t->tm_hour, t->tm_min, t->tm_sec);
//}
//
//int calculateDays(const char* in, const char* out) {
//    struct tm ti = { 0 }, to = { 0 };
//    if (!convertStringToDateTime(in, &ti) || !convertStringToDateTime(out, &to))
//        return 0;
//    time_t t1 = mktime(&ti), t2 = mktime(&to);
//    int d = (int)difftime(t2, t1) / (60 * 60 * 24);
//    return d > 0 ? d : 1;
//}

int convertStringToDate(const char* s, struct tm* t) {
    // Khởi tạo sạch và gán giá trị
    memset(t, 0, sizeof(struct tm));
    int year, month, day;
    if (sscanf(s, "%d-%d-%d", &year, &month, &day) != 3) {
        return 0; // lỗi định dạng
    }
    t->tm_year = year - 1900;
    t->tm_mon = month - 1;
    t->tm_mday = day;
    return 1;
}

void convertDateToString(const struct tm* t, char* buffer, int bufferSize) {
    snprintf(buffer, bufferSize, "%04d-%02d-%02d",
        t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
}

int calculateDays(const char* fromDateStr, const char* toDateStr) {
    struct tm from = { 0 }, to = { 0 };
    if (!convertStringToDate(fromDateStr, &from) || !convertStringToDate(toDateStr, &to)) {
        return 0;
    }
    time_t t1 = mktime(&from);
    time_t t2 = mktime(&to);
    int diffDays = (int)difftime(t2, t1) / (60 * 60 * 24);
    return diffDays > 0 ? diffDays : 1; // ít nhất 1 ngày
}