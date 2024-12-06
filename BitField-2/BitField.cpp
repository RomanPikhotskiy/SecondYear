#include "BitField.h"


size_t BitField::GetMemIndex(size_t n) const{
    if (n < _sizeBit) return n / 16;
    throw "Error";
}
uint16_t BitField::GetMask(size_t n) const {
    uint16_t mask = 1;
    return (mask << (n & 15));
}

BitField::BitField(size_t len) {
    _sizeBit = len;
    _memSize = (_sizeBit / 16) + (_sizeBit % 16 != 0);
    _mem = new uint16_t[_memSize];
    for (size_t i = 0; i < _memSize; i++)
        _mem[i] = 0;
}

BitField::BitField(const BitField& tmp) {
    _sizeBit = tmp._sizeBit;
    _memSize = tmp._memSize;
    _mem = new uint16_t[tmp._memSize];
    for (int i = 0; i < _memSize; i++)
        _mem[i] = tmp._mem[i];
}

BitField& BitField::operator=(const BitField& tmp) {
    if (_sizeBit != tmp._sizeBit) {
        _sizeBit = tmp._sizeBit;
        _memSize = tmp._memSize;
        delete[] _mem;
        _mem = nullptr;
        _mem = new uint16_t[tmp._memSize];
    }
    for (size_t i = 0; i < tmp._memSize; i++)
        _mem[i] = tmp._mem[i];
    return *this;
}
    
size_t BitField::GetLength() const {
    return _sizeBit;
}
void BitField::SetBit(size_t n) {
    if (n <= _sizeBit){
        _mem[GetMemIndex(n)] |= GetMask(n);
    }
    else 
        throw "Error";
}
void BitField::ClrBit(size_t n) {
    _mem[GetMemIndex(n)] &= ~GetMask(n);
}

uint8_t BitField::GetBit(size_t n) const {
    if ((n > _sizeBit) || (n < 0)) 
        throw "Error";
    uint16_t tmp = _mem[GetMemIndex(n)] & GetMask(n);;
    if(tmp != 0)
        return 1;
    else
        return 0;
}

BitField BitField::operator|(const BitField& tmp) {
    BitField result(max(_sizeBit, tmp._sizeBit));
    int i = 0; 
    while (i < min(_memSize, tmp._memSize)) {
        result._mem[i] = _mem[i] | tmp._mem[i];
        i++;
    }
    if (_sizeBit > tmp._sizeBit) {
        while (i < _memSize) {
            result._mem[i] = _mem[i];
            i++;
        }
    }
    else if (_sizeBit > tmp._sizeBit) {
        while (i < tmp._memSize) {
            result._mem[i] = _mem[i];
            i++;
        }
    }
    return result;
}

BitField BitField::operator&(const BitField& tmp) {
    BitField result(min(_sizeBit, tmp._sizeBit));
    for (int i = 0; i < min(_sizeBit, tmp._sizeBit); i++)
        result._mem[i] = _mem[i] & tmp._mem[i];
    return result;
}

BitField BitField::operator^(const BitField& tmp) {
    BitField result(_sizeBit);
    for (int i = 0; i < _memSize; i++)
        result._mem[i] = _mem[i] ^ tmp._mem[i];
    return result;
}

bool BitField::operator==(const BitField& tmp) const{
    for (int i = 0; i < _memSize; i++)
        if (_mem[i] != tmp._mem[i])
            return false;
    return true;
}
BitField BitField::operator~(){
    BitField result(_sizeBit);
    for (int i = 0; i < _sizeBit; i++) {
        if (this->GetBit(i) == 0)
            result.SetBit(i);
        else
            result.ClrBit(i);
    }

    return result;
}