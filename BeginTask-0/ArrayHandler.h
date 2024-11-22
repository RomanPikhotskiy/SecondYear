#pragma once
#include <iostream>
#include <algorithm>
#include <stdexcept>

template<typename T>
class ArrayHandler
{
private:
    T* _array;
    size_t _size;
    size_t _count;

    void Resize(size_t new_size) {
        T* new_array = new T[new_size];
        std::copy(_array, _array + _count, new_array);
        delete[] _array;
        _array = new_array;
        _size = new_size;
    }

public:
    ArrayHandler() : _size(5), _count(0), _array(new T[_size]) {};
    
    ArrayHandler(size_t size) : _size(size), _count(0), _array(new T[_size]) {};

    void AppendElem(T elem) {
        if (_count == _size) {
            Resize(_size * 2);
        }
        _array[_count++] = elem;
    };

    bool IsContains(T elem){
        return std::find(_array, _array + _count, elem) != (_array + _count);
    };

    T GetMax() {
        if (_count == 0) throw std::out_of_range("Array is empty");
        return *std::max_element(_array, _array + _count);
    };

    T GetMin() {
        if (_count == 0) throw std::out_of_range("Array is empty");
        return *std::min_element(_array, _array + _count);
    };

    ~ArrayHandler() {
        delete[] _array;
    };
};
