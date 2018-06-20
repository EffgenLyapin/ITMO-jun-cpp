#pragma once

#include <iostream>

class DynamicIntArray {
private:
  int *arr;
  int elts_size;

public:
  DynamicIntArray(int size_in)
    : arr(new int[size_in]), elts_size(size_in) {
      std::cout << "массив создан \n";
  }

  ~DynamicIntArray() {
    delete[] arr;
    std::cout << "массив уничтожен \n";
  }

  int size() const {
    return elts_size;
  }

  int & operator[](int i) { return arr[i]; }
  const int & operator[](int i) const { return arr[i]; }

};
