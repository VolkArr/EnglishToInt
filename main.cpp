#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <iostream>


std::string Delimiter(std::string del) {
    std::vector<std::string> deli = { "hundred","thousand","million"};
    for (size_t i = 0; i < deli.size(); i++) {
        if (del == deli[i]) return del;
    }
    return " ";
}

long parse_int(std::string number) {
    long sum = 0;
    std::vector<std::string> numbers;
    // our database
    std::map<std::string, int> standartnumbers = { {"zero",0},
                                         {"one",1},
                                         {"two",2},
                                         {"three",3},
                                         {"four",4},
                                         {"five",5},
                                         {"six",6},
                                         {"seven",7},
                                         {"eight",8},
                                         {"nine",9},
                                         {"ten",10},
                                         {"eleven",11},
                                         {"twelve",12},
                                         {"thirteen",13},
                                         {"fourteen",14},
                                         {"fifteen",15},
                                         {"sixteen",16},
                                         {"seventeen",17},
                                         {"eighteen",18},
                                         {"nineteen",19},
                                         {"twenty",20},
                                         {"thirty",30},
                                         {"forty",40},
                                         {"fifty",50},
                                         {"sixty",60},
                                         {"seventy",70},
                                         {"eighty",80},
                                         {"ninety",90},
                                         {"hundry",100} };
    std::map<std::string, int> delimiter = { {"hundred",100},
                                   {"thousand",1000},
                                   {"million",1000000} };
    for (size_t i = 0; i < number.length() - 1; i++) {
        if (number[i] == '-') {
            number[i] = ' ';
        }
    }

    //number into vector
    std::stringstream ss;
    ss << number;
    std::string buffer;
    while (ss >> buffer) {
        if (buffer == "and")continue;
        numbers.push_back(buffer);
    }



       int cursum = 0;
    for (size_t i = 0; i < numbers.size(); i++) {
        cursum += standartnumbers[numbers[i]];
        if (numbers[i] == Delimiter(numbers[i])) {
            cursum *= delimiter[numbers[i]];
            if(numbers[i] == "hundred"){
              continue;
            }
            else{
              sum += cursum;
              cursum = 0;
            }
        }
    }
    sum += cursum;

    return sum;
}


int main(){
    std::cout << parse_int("six thousand eighty four") << std::endl;
    return 0;
}