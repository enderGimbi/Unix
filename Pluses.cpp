#include <iostream>
#include<clocale>
#include"MyDayTime.h"
using namespace std;

void myPrint(MyDayTime& time) {
    time.printDate();
}

//struct DATE {
//    int year;
//    int month;
//    int day;
//    int hour;
//    int minute;
//    int seconds;
//    void printLn() {
//        printf("%02d.%02d.%02d  %02d:%02d:%02d", day, month, year, hour, minute, seconds);
//    }
//};

//bool third(DATE date1,DATE date2) {
//    return((date1.year == date2.year && date1.month == date2.month && date1.day > date2.day)||(date1.year > date2.year)||(date1.year == date2.year && date1.month > date2.month));
//}

//int compr(MyDayTime date1,MyDayTime date2) {
//    if (date1.year > date2.year) {
//        return 1;
//    }
//    if (date1.year < date2.year) {
//        return -1;
//    }
//    else {
//        if (date1.month>date2.month) {
//            return 1;
//        }
//        if (date1.month < date2.month) {
//            return -1;
//        }
//        else {
//            if (date1.day > date2.day) {
//                return 1;
//            }
//            if (date1.day < date2.day) {
//                return -1;
//            }
//            else {
//                return 0;
//            }
//        }
//    }
//}

//DATE convertTime(long long time) {
//    DATE res = { 0,0,0,0,0,0 }; int monthes[12] = { 31, 28, 31,30,31,30,31,31,30,31,30,31 };
//    res.year = 1970 + (time / 31536000);
//    if (res.year > 2000) res.day++;
//    int addicDays = (res.year - 1969) / 4;
//    int days = (time / 86400) - addicDays;
//    int daysInCurYear = days % 365;
//    for (int i = 0; daysInCurYear > monthes[i]; res.month++) {
//        daysInCurYear -= monthes[i]; i++;
//    }
//    res.day += daysInCurYear; res.month += 1;
//    int seconds = time - (86400 * (time / 86400));
//    res.hour = seconds / 3600;
//    res.minute = (seconds - (res.hour * 3600)) / 60;
//    res.seconds = seconds - (res.hour * 3600) - (res.minute * 60);
//    return res;
//}

int main(){
    setlocale(LC_ALL, "rus");
    MyDayTime date1 = MyDayTime(2027,2,1); // Дата 1
    MyDayTime date2 = MyDayTime(2026,2,1); // Дата 2
    date1.printDate(); 
    date2.printDate();
    //cout << third(date1, date2) << endl;
    int res = date1.compr(date2);
    switch (res){
    case(- 1):
        cout << "Правая дата больше\n" << endl;
        break;
    case(0):
        cout << "Даты совпадают\n" << endl;
        break;
    case(1):
        cout << "Левая дата больше\n" << endl;
        break;
    default:
        break;
    }
    MyDayTime myTime = MyDayTime(time(NULL));
    date1 += date2;
    date1.printDate();
    myTime.printDate();

    MyDayTime date3; 
    date3 = date2 + date1;
    MyDayTime time = date3++;
    myPrint(time);
    date3.printDate();

    cin >> date3;
    cout << date3;
}

