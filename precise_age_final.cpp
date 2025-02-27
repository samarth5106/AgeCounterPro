#include <bits/stdc++.h>
using namespace std;

int main() {
    int birth_month, birth_yr, birth_day, birth_hr;
    int age_yr, age_mon, age_day, age_hr;
    char alive;
    string country;

    map<string, int> timeZoneOffsets = {
        {"India", 5}, {"USA", -5}, {"UK", 0}, {"Germany", 1}, 
        {"Australia", 10}, {"Japan", 9}, {"China", 8}, {"Russia", 3}
    };

    time_t currentTime = time(0);
    tm* localTime = gmtime(&currentTime);
    int currnt_yr = localTime->tm_year + 1900;
    int currnt_month = localTime->tm_mon + 1;
    int currnt_day = localTime->tm_mday;
    int currnt_hr = localTime->tm_hour;

    cout << "Enter country name: ";
    cin >> country;

    if (timeZoneOffsets.find(country) != timeZoneOffsets.end()) {
        currnt_hr += timeZoneOffsets[country];

        if (currnt_hr >= 24) {
            currnt_hr -= 24;
            currnt_day++;
        } else if (currnt_hr < 0) {
            currnt_hr += 24;
            currnt_day--;
        }
    } else {
        cout << "Country not found in database! Using UTC time.\n";
    }

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((currnt_yr % 4 == 0 && currnt_yr % 100 != 0) || (currnt_yr % 400 == 0)) {
        daysInMonth[1] = 29;
    }

    cout << "Enter birth year: ";
    cin >> birth_yr;
    cout << "Enter birth month: ";
    cin >> birth_month;
    cout << "Enter birth day: ";
    cin >> birth_day;
    cout << "Enter birth hour (24-hour format): ";
    cin >> birth_hr;
    cout << "Is the person still alive (y/n): ";
    cin >> alive;

    if (alive == 'n') {
        int death_yr, death_month, death_day, death_hr;
        cout << "Enter death year: ";
        cin >> death_yr;
        cout << "Enter death month: ";
        cin >> death_month;
        cout << "Enter death day: ";
        cin >> death_day;
        cout << "Enter death hour (24-hour format): ";
        cin >> death_hr;

        currnt_yr = death_yr;
        currnt_month = death_month;
        currnt_day = death_day;
        currnt_hr = death_hr;
    }

    age_yr = currnt_yr - birth_yr;
    age_mon = currnt_month - birth_month;
    age_day = currnt_day - birth_day;
    age_hr = currnt_hr - birth_hr;

    if (age_hr < 0) {
        age_hr += 24;
        age_day--;
    }
    
    if (age_day < 0) {
        age_mon--;
        int prevMonth;
        if (currnt_month == 1) {
            prevMonth = 12;
        } else {
            prevMonth = currnt_month - 1;
        }
        age_day += daysInMonth[prevMonth - 1];
    }

    if (age_mon < 0) {
        age_yr--;
        age_mon += 12;
    }

    cout << "\nThe person is " << age_yr << " years, "
         << age_mon << " months, "
         << age_day << " days, and "
         << age_hr << " hours OLD in " << country << ".\n";

    return 0;
}
