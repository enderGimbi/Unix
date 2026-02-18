#include "MyDayTime.h"

int MyDayTime::monthes[] = {31, 28, 31,30,31,30,31,31,30,31,30,31};

void MyDayTime::incrtime() {
	if (day > monthes[month]) {
		++month;
		if (month > 12) {
			month = 1;
			year += 1;
		}
		day -= monthes[month - 1];
	}
}

void MyDayTime::decrtime() {
	day -= 1;
	if (day < 1) {
		--month;
		if (month < 1) {
			month = 12;
			year -= 1;
		}
		day -= monthes[month - 1];
	}
}

MyDayTime::MyDayTime(){
	year = 1970;
	month = 1;
	day = 1;
	hour = 0;
	minute = 0;
	seconds = 0;
}

MyDayTime::MyDayTime(int year, int month, int day){
	this->day = day;
	this->month = month;
	this->year = year;
	minute = 0;
	seconds = 0;
	hour = 0;
}



MyDayTime::MyDayTime(int year, int month, int day, int hour, int minute, int seconds){
	this->day = day;
	this->month = month;
	this->year = year;
	this->hour = hour;
	this->minute = minute;
	this->seconds = seconds;
}

// Перевод из Unix системы
MyDayTime::MyDayTime(long long time){
	this->day = 0;
	this->month = 0;
	this->year = 0;
	this->hour = 0;
	this->minute = 0;
	this->seconds = 0;
	
	this->year = 1970 + (time / 31536000);
	if (this->year > 2000) this->day++;
	int addicDays = (this->year - 1969) / 4;
	int days = (time / 86400) - addicDays;
	int daysInCurYear = days % 365;
	for (int i = 0; daysInCurYear > monthes[i]; this->month++) {
		daysInCurYear -= monthes[i]; i++;
	}
	this->day += daysInCurYear; 
	this->month += 1;
	int seconds = time - (86400 * (time / 86400));
	this->hour = seconds / 3600;
	this->minute = (seconds - (this->hour * 3600)) / 60;
	this->seconds = seconds - (this->hour * 3600) - (this->minute * 60);
}

MyDayTime::MyDayTime(const MyDayTime& other){
	year = other.year;
	month = other.month;
	day = other.day;
	hour = other.hour;
	minute = other.minute;
	seconds = other.seconds;
}

MyDayTime::~MyDayTime() {}

int MyDayTime::GetYear() {
	return year;
}

int MyDayTime::GetMonth() {
	return month;
}

int MyDayTime::GetDay() {
	return day;
}

int MyDayTime::GetHour() {
	return hour;
}

int MyDayTime::GetMinute() {
	return minute;
}

int MyDayTime::GetSeconds() {
	return seconds;
}

void MyDayTime::SetYear(int num) {
	year = num;
}

void MyDayTime::SetMonth(int num) {
	month = num;
}

void MyDayTime::SetDay(int num) {
	 day = num;
}

void MyDayTime::SetHour(int num) {
	hour = num;
}

void MyDayTime::SetMinute(int num) {
	minute = num;
}

void MyDayTime::SetSeconds(int num) {
	seconds = num;
}

MyDayTime MyDayTime::operator+ (const MyDayTime& date) {
	MyDayTime res;
	res.year = year + date.year;
	res.month = month + date.month;
	res.day = day + date.day;
	res.hour = hour + date.hour;
	res.minute = minute + date.minute;
	res.seconds = seconds + date.seconds;
	return res;
}
MyDayTime MyDayTime::operator- (const MyDayTime& date) {
	MyDayTime res;
	res.year = year - date.year;
	res.month = month - date.month;
	res.day = day - date.day;
	res.hour = hour - date.hour;
	res.minute = minute - date.minute;
	res.seconds = seconds - date.seconds;
	return res;
}
MyDayTime& MyDayTime::operator= (const MyDayTime& other) {
	if (this == &other) 
		return *this;
	year = other.year;
	month = other.month;
	day = other.day;
	hour = other.hour;
	minute = other.hour;
	seconds = other.seconds;
	return *this;
}
MyDayTime& MyDayTime::operator+= (const MyDayTime& other) {
	day += other.day;
	year += other.year;
	month = other.month;
	hour += other.hour;
	minute += other.minute;
	seconds += other.seconds;
	return *this;
}

MyDayTime& MyDayTime::operator-=(const MyDayTime& other) {
	day -= other.day;
	year -= other.year;
	month = other.month;
	hour -= other.hour;
	minute -= other.minute;
	seconds -= other.seconds;
	return *this;
}

MyDayTime& MyDayTime::operator++() {
	day += 1;
	incrtime();
	return *this;
}

MyDayTime MyDayTime::operator++(int) {
	MyDayTime old = *this;
	day += 1;
	incrtime();
	return old;
}

MyDayTime& MyDayTime::operator--() {
	day -= 1;
	decrtime();
	return *this;
}

MyDayTime MyDayTime::operator--(int) {
	MyDayTime old = *this;
	day -= 1;
	decrtime();
	return old;
}

bool MyDayTime::operator>(const MyDayTime& other) {
	return this->compr(other)>0;
}

bool MyDayTime::operator<(const MyDayTime& other)
{
	return this->compr(other)<0;
}

bool MyDayTime::operator>=(const MyDayTime& other)
{
	return this->compr(other)>=0;
}

bool MyDayTime::operator<=(const MyDayTime& other)
{
	return this->compr(other)<=0;
}

std::ostream& operator<<(std::ostream& os, const MyDayTime& time){
	os << time.day << "." << time.month << "." << time.year << " " << time.hour << ":" << time.minute << ":" << time.seconds;
	return os;
}

std::istream& operator>>(std::istream& is, MyDayTime& time) {
	is >> time.day;
	is >> time.month;
	is >> time.year;
	is >> time.hour;
	is >> time.minute;
	is >> time.seconds;
	return is;
}
