#pragma once
#include "Set.h"
#include "BitField.h"

class BigNumber
{
private:
  std::string _str ;
  size_t _maxPower;       // максимальная мощность множества 
  Set _set;
public:
    BigNumber (std::string str);
    BigNumber BigSumm(const BigNumber& b1, const BigNumber& b2);
    void readInput();
    void InSet();
    ~BigNumber(){};
};