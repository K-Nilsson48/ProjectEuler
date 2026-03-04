#include <iostream>
#include <chrono> //Used for comparing approaches
#include <array>

bool endofmonth(int day, int month, int year){
    static const std::array<int, 13> days_in_month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int max_days = days_in_month[month];

    if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
        max_days = 29;
    }
    
    return day == max_days;


}

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    int day = 1;
    //1 is january
    int month = 1;
    int year = 1900;
    //1 is monday, 7 is sunday
    int day_name = 1;
    int count = 0;

    while (year != 2001){
        //Check if we need to add to count
        if (year >= 1901 && day == 1 && day_name == 7){
            count++;
        }

        //Check if it is the end of the month
        if (endofmonth(day, month, year)){
            if (month != 12){
                month++;
                day = 1;
            }else{
                month = 1;
                day = 1;
                year++;
            }
        }else{
            day++;
            }

        if (day_name != 7){
                day_name++;
            }else{
                day_name = 1;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);


    std::cout << "The amount of time was: " << duration << std::endl;

    std::cout << "There have been: " << count << " number of sundays that are the first of the month" << std::endl;
    return 0;
}