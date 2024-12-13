#pragma once
#include <iostream>
#include <unordered_set>
#include <vector>
#include <stdint.h>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stdexcept>
#include <limits>
using namespace std;


class BitField {
private:
    size_t _sizeBit;
    uint16_t* _mem;
    size_t _memSize;

    size_t GetMemIndex(size_t n) const;
    uint16_t GetMask(size_t n) const;
public:
    BitField(size_t len);
    BitField(const BitField& tmp);
    BitField& operator=(const BitField& tmp);
    uint16_t GetCh(size_t n, uint16_t mask);
    
    size_t GetLength() const;
    void SetBit(size_t n);
    void ClrBit(size_t n);
    uint8_t GetBit(size_t n) const;
    BitField summ(BitField& tmp);


    BitField operator|(const BitField& tmp);
    BitField operator&(const BitField& tmp);
    BitField operator^(const BitField& tmp);
    bool operator==(const BitField& tmp) const;
    BitField operator~();

    ~BitField(){
    }
};