#include <iostream>
#include <map>


int calc_length(int i, std::map<int, int> letters){
    int total = 0;
    if (letters.contains(i)){
            return letters[i];
        }
        //If not calculate the number
        else{
            if (i > 100){
                int hundred = i - i % 100;

                //Remove the "and"
                if (i % 100 == 0){
                    total -= 3;
                }

                if (i % 100 < 20){
                    total += letters[hundred/100] + letters[i % 100] + letters[100];
                }else{
                    int tens = (i - hundred) - i % 10;
                    total += letters[hundred/100] + letters[tens] + letters[i % 10] + letters[100];
                }
            }else{
                int tens = i - i % 10;
                total += letters[tens] + letters[i%10];
            }
        }
    return total;
}

int main(){
    int limit = 1000;
    std::map<int, int> letters;

    //Define the needed letter lenghts
    letters[1] = 3;
    letters[2] = 3;
    letters[3] = 5;
    letters[4] = 4;
    letters[5] = 4;
    letters[6] = 3;
    letters[7] = 5;
    letters[8] = 5;
    letters[9] = 4;
    letters[10] = 3;
    letters[11] = 6;
    letters[12] = 6;
    letters[13] = 8;
    letters[14] = 8;
    letters[15] = 7;
    letters[16] = 7;
    letters[17] = 9;
    letters[18] = 8;
    letters[19] = 8;
    letters[20] = 6;
    letters[30] = 6;
    letters[40] = 5;
    letters[50] = 5;
    letters[60] = 5;
    letters[70] = 7;
    letters[80] = 6;
    letters[90] = 6;
    //One Hundred or hundred and
    letters[100] = 10;
    letters[1000] = 11;

    //Loop through and add up letter totals
    long long total = 0;

    for (int i = 1; i <= limit; i++){
        int length = calc_length(i, letters);
        total += length;
        //std::cout << i << ":" << length << std::endl;
    }

    std::cout << "The number of letters in digits under 1000: " << total << std::endl;

    return 0;
}