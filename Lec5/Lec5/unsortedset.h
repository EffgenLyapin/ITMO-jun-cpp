#pragma once

#include <iostream>
#include <assert.h>

template <typename T>
class UnsortedSet {
public:

    static const int DEFAULT_CAPACITY = 1;

    UnsortedSet()
      : elts(new T[DEFAULT_CAPACITY]),
        capacity(DEFAULT_CAPACITY),
        elts_size(0) {}

    ~UnsortedSet() {
      delete[] elts;
    }



//    UnsortedSet(const UnsortedSet &other)
//        : elts(new T[other.capacity]),
//          capacity(other.capacity),
//          elts_size(other.elts_size) {

//        for (int i = 0; i < elts_size; ++i) {
//            elts[i] = other.elts[i];
//        }

//    }


//    UnsortedSet & operator=(const UnsortedSet &rhs) {
//      if (this == &rhs) { return *this; }

//      delete[] elts;
//      elts = new T[rhs.capacity];
//      capacity = rhs.capacity;
//      elts_size = rhs.elts_size;

//      for (int i = 0; i < elts_size; ++i) {
//        elts[i] = rhs.elts[i];
//      }

//      return *this;
//    }

    void insert(T v) {
        if (contains(v)) { return; }
        if (elts_size == capacity) { grow(); }

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
    T *elts;
    int capacity;
    int elts_size;

    // Функция увеличения массива в два раза
    void grow() {

        T *newArr = new T[2 * capacity];
        for (int i = 0; i < elts_size; ++i) {
            newArr[i] = elts[i];
        }
        capacity *= 2;
        delete[] elts;
        elts = newArr;
    }


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
