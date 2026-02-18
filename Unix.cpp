#include <iostream>
using namespace std;

struct DATE {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int seconds;
    void printLn() {
        printf("%02d.%02d.%02d  %02d:%02d:%02d",day,month,year,hour,minute,seconds);
    }
};

DATE convertTime(long long time) {
    DATE res = {0,0,0,0,0,0}; int monthes[12] = { 31, 28, 31,30,31,30,31,31,30,31,30,31 };
    res.year = 1970+(time / 31536000);
    if (res.year > 2000) res.day++;
    int addicDays = (res.year - 1969) / 4;
    int days = (time/86400)-addicDays;
    int daysInCurYear = days % 365;
    for (int i=0;daysInCurYear>monthes[i];res.month++) {
         daysInCurYear -= monthes[i]; i++;
    }
    res.day += daysInCurYear; res.month += 1;
    int seconds = time - (86400 * (time / 86400));
    res.hour = seconds/3600;
    res.minute = (seconds - (res.hour*3600))/60;
    res.seconds = seconds - (res.hour * 3600) - (res.minute * 60);
    return res;
}


int main(){
    setlocale(LC_ALL, "RUS");
    long long UnixTime = time(NULL);
    DATE time = convertTime(UnixTime);
    time.printLn();
}
