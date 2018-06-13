#pragma once

#include <iostream>
#include <assert.h>

template <typename T>
class UnsortedSet {
public:

    UnsortedSet():
        elts_size(0)
    {}

  static const int ELTS_CAPACITY = 10;

  void insert(T v) {
    assert(size() < ELTS_CAPACITY);
    if (contains(v)) {
      return;
    }
    elts[elts_size] = v;
    ++elts_size;
  }

  void remove(T v) {
      if (!contains(v)) {
        return;
      }
      elts[indexOf(v)] = elts[elts_size - 1];
      --elts_size;
  }

  bool contains(T v) const {
      for (int i = 0; i < elts_size; ++i) {
        if (elts[i] == v) {
          return true;
        }
      }
      return false;
  }

  int size() const
  {
      return elts_size;
  }

  void print(std::ostream &os) const
  {

      for (int i = 0; i < elts_size; ++i) {
        os << elts[i] << " ";

      }

      os << std::endl;

  }


private:
  T elts[ELTS_CAPACITY];
  int elts_size;

};

template <typename T>
void fillFromArray(UnsortedSet<T> &set, const T *arr, int n) {
  for (int i = 0; i < n; ++i) {
    set.insert(arr[i]);
  }
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const UnsortedSet<T> &s)
{
    s.print(os);
    return os;
}
