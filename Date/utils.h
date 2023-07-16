#pragma once

#include <string>
#include <format>
#include <ctime>

using namespace std;


// Taking day of year from string date 
int getDayOfYear(string date) {
    int day, month, year;

    // Parsing data
    int index1 = date.find(".");
    int index2 = date.find(".", index1 + 1);
    day = stoi(date.substr(0, index1));
    month = stoi(date.substr(index1 + 1, index2));
    year = stoi(date.substr(index2 + 1, 4));

    int daysInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        daysInMonth[2] = 29;
    }

    int dayOfYear = 0;

    for (int i = 0; i < month; i++) {
        dayOfYear += daysInMonth[i];
    }
    dayOfYear += day;

    return dayOfYear;
}


// Taking current date
string getCurrentDate() {
    time_t t = time(nullptr);
    struct tm now;
    localtime_s(&now, &t);

    return format("{}.{}.{}", now.tm_mday, now.tm_mon + 1, now.tm_year + 1900);
}


// Comparator for userlist by difference between current day and user`s birthday
bool CompareUsersByDate(const User& user1, const User& user2)
{
    int currentDay = getDayOfYear(getCurrentDate());
    int day1 = currentDay - getDayOfYear(user1.birthday);
    int day2 = currentDay - getDayOfYear(user2.birthday);

    // Regular sort
    if (day1 > 0 and day2 > 0)
    {
        return day1 < day2;
    }
    // Positive number always goes to first part of list
    else if (day1 >= 0 and day2 < 0)
    {
        return false;
    }
    // Negative number always goes to second part of list
    else if (day1 < 0 and day2 >= 0)
    {
        return true;
    }
    // Reverse sort
    else
    {
        return day1 > day2;
    }
}