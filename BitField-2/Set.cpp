#include "Set.h"

Set::operator BitField() {
    return BitField(this->_bitField);
}

Set::Set(const BitField& tmp) : _maxPower(tmp.GetLength()), _bitField(tmp) {}

Set::Set(const Set& tmp):_maxPower(tmp.GetMaxPower()), _bitField(tmp._bitField) {
}

Set::Set(const size_t maxPower) :_bitField(maxPower) { _maxPower = maxPower; }

void Set::InsElem(uint64_t elem) {
    if (elem < _maxPower)
        _bitField.SetBit(elem);
    else {
        throw "Elem out of range";
    }
}

uint16_t Set::GetNum(size_t n, uint16_t mask){
    return _bitField.GetCh(n, mask);
}

vector<uint64_t> Set::GetPrimary(){
    vector <uint64_t> res;
    unordered_set<int> used;
    size_t tmp = _maxPower;
    res.push_back(1);
    for (int i = 2; i < tmp + 1; i++){
    
        if (used.find(i) != used.end()) continue;
    
        else{
            res.push_back(i);
            for (int j = i + 1; j < tmp + 1; j++)
                if (j % i == 0) used.insert(j);
            
       }
    }
    return res;
}

void Set::DelElem(uint64_t elem) {
    _bitField.ClrBit(elem);
}
size_t Set::GetMaxPower() const {
    return _maxPower;
}

bool Set::IsMember(uint64_t elem) const{
    if (elem < _maxPower && elem >= 0){
        if (_bitField.GetBit(elem) == 1) return true;
        }
        return false;
}

bool Set::operator==(const Set& tmp) const{
    if (_bitField == tmp._bitField)
        return true;
    return false;
}

bool Set::operator!=(const Set& tmp) const{
    if (_bitField == tmp._bitField)
        return false;
    return true;
}

Set& Set::operator= (const Set& tmp) {
    _maxPower = tmp._maxPower;
    _bitField = tmp._bitField;
    return *this;
}
Set Set::operator+(const Set& tmp) {
    Set result(max(tmp._maxPower, _maxPower));
    result._bitField = _bitField | tmp._bitField;
    return result;
}


Set Set::operator+(uint64_t elem) {
    InsElem(elem);
}

Set Set::operator-(uint64_t elem) {
    DelElem(elem);
}

Set Set::operator*(const Set& tmp) {
    Set result(max(tmp._maxPower, _maxPower));
    result._bitField = _bitField & tmp._bitField;
    return result;
}
Set Set::operator~() {
    Set result(_maxPower);
    result._bitField = ~_bitField;
    return result;
}