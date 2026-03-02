#include <iostream>

bool endofmonth(int day, int month, int year){
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30){
        return true;
    }else if (month != 2 && day == 31){
        return true;
    }else if (month == 2){
        //Leap year
        if ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) && day == 29){
            return true;
        }else if (!(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) && day == 28){
            return true;
        }
    }
    return false;
}

int main(){
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

    std::cout << "There have been: " << count << " number of sundays that are the first of the month" << std::endl;
    return 0;
}