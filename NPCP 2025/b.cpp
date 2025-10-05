#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

int main() {
    string start_time_weekday, end_time_weekday; 
    string start_time, end_time;

    cin >> start_time_weekday >> start_time;
    cin >> end_time_weekday >> end_time;

    int statweek = 0;

    if (start_time_weekday == "Mon") statweek = 0;
    if (start_time_weekday == "Tue") statweek = 1;
    if (start_time_weekday == "Wed") statweek = 2;
    if (start_time_weekday == "Thu") statweek = 3;
    if (start_time_weekday == "Fri") statweek = 4;
    if (start_time_weekday == "Sat") statweek = 5;
    if (start_time_weekday == "Sun") statweek = 6;


    int endweek = 0;

    if (end_time_weekday == "Mon") endweek = 0;
    if (end_time_weekday == "Tue") endweek = 1;
    if (end_time_weekday == "Wed") endweek = 2;
    if (end_time_weekday == "Thu") endweek = 3;
    if (end_time_weekday == "Fri") endweek = 4;
    if (end_time_weekday == "Sat") endweek = 5;
    if (end_time_weekday == "Sun") endweek = 6;

    int start_time_hour = 0;
    int start_time_min = 0;
    string tempt = "";
    for (int i = 0; i < start_time.size(); i++) {
        if (i == start_time.size() - 1) {
            tempt += start_time[i];
            start_time_min = atoi(tempt.c_str());
        }
        else if (start_time[i] == ':') {
        start_time_hour = atoi(tempt.c_str());
        tempt = "";
        } 
        else {
        tempt += start_time[i]; 
        }
    }

    int end_time_hour = 0;
    int end_time_min = 0;
    string tempt2 = "";
    for (int i = 0; i < end_time.size(); i++) {
        if (i == end_time.size() - 1) {
            tempt2 += end_time[i];
            end_time_min = atoi(tempt2.c_str());
        }
        else if (end_time[i] == ':') {
        end_time_hour = atoi(tempt2.c_str());
        tempt2 = "";
        } 
        else {
        tempt2 += end_time[i]; 
        }
    }

    //cout << statweek << ' ' << endweek << endl;
    int weekday = endweek - statweek;

    //cout << start_time_hour << ' ' << end_time_hour << endl;
    int hour = end_time_hour - start_time_hour;

    //cout << "Minute: " << start_time_min << ' ' << end_time_min << endl;
    int minute = end_time_min - start_time_min;

    if (weekday == 0 and hour == 0 and minute == 0) {
        cout << "7 days";
        return 0;
    }
    
    if (minute < 0) {
        hour--;
        minute += 60; 
    }

     if (hour < 0) {
        weekday--;
        hour += 24; 
    }

    if (weekday < 0) {
        weekday += 7;
    }

    string daystring = weekday == 1 ? "day" : "days";
    string hestring = hour == 1 ? "hour" : "hours";
    string mistring = minute == 1 ? "minute" : "minutes";

    if (weekday != 0) {
        cout << weekday << ' ' << daystring;
    }

    if ((weekday and hour and minute)) {
        cout << ", ";
    }

    if ((weekday and hour and !minute)) {
        cout << " and ";
    }

    if (hour != 0) {
        cout << hour << ' ' << hestring;
    }

     if ((weekday and hour and minute)) {
        cout << ", ";
    }

    if ((!weekday and hour and minute)) {
        cout << " and ";
    }

     if (minute != 0) {
        cout << minute << ' ' << mistring;
    }

  return 0;
}
