#pragma once
#include<iostream>
class MyDayTime{
private:
    static int monthes[];

    int year;
    int month;
    int day;
    int hour;
    int minute;
    int seconds;


    void incrtime();
    void decrtime();
public:
    MyDayTime(); // конструктор по умолчанию
    MyDayTime(int year, int month, int day);
    MyDayTime(int year, int month,int day,int hour,int minute,int second);
    MyDayTime(long long);
    MyDayTime(const MyDayTime& other);
    ~MyDayTime();
    int GetYear();
    int GetMonth();
    int GetDay();
    int GetHour();
    int GetMinute();
    int GetSeconds();
    void SetYear(int num);
    void SetMonth(int num);
    void SetDay(int num);
    void SetHour(int num);
    void SetMinute(int num);
    void SetSeconds(int num);
    MyDayTime& operator= (const MyDayTime& other);
    MyDayTime operator+ (const MyDayTime& date);
    MyDayTime operator- (const MyDayTime& date);
    MyDayTime& operator+= (const MyDayTime& other);
    MyDayTime& operator-= (const MyDayTime& other);
    MyDayTime& operator++ ();
    MyDayTime operator++(int);
    MyDayTime& operator-- ();
    MyDayTime operator--(int);
    bool operator>(const MyDayTime& other);
    bool operator<(const MyDayTime& other);
    bool operator>=(const MyDayTime& other);
    bool operator<=(const MyDayTime& other);
    friend std::ostream& operator<<(std::ostream& os, const MyDayTime& time);
    friend std::istream& operator>>(std::istream& is, MyDayTime& time);

    int compr(const MyDayTime& date1) {
        if (year > date1.year) {
            return 1;
        }
        if (year < date1.year) {
            return -1;
        }
        else {
            if (month > date1.month) {
                return 1;
            }
            if (month < date1.month) {
                return -1;
            }
            else {
                if (day > date1.day) {
                    return 1;
                }
                if (day < date1.day) {
                    return -1;
                }
                else {
                    return 0;
                }
            }
        }
    }
    void printDate() {
        printf("%02d.%02d.%02d  %02d:%02d:%02d\n", day, month, year, hour, minute, seconds);
    };

};

