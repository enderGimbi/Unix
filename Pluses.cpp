#include <iostream>
#include<clocale>
#include"MyDayTime.h"
using namespace std;

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
    cout << myTime;
}

