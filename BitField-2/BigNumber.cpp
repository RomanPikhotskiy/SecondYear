#include "BigNumber.h"

BigNumber::BigNumber(std::string str): _set(str.size() * 4 + 1), _str(str){}

void BigNumber::InSet(){
    _maxPower = _str.size() * 4 + 1;
    for (size_t i = 0 ; i < 30 ; i ++ ){
        int number = std::stoi(i, nullptr, 10);

        _set.GetNum(i + 1, _str[i].stoi())
    }
}

void BigNumber::readInput(){
        std::cout << ": ";
        std::getline(std::cin, _str);
        InSet();
}

