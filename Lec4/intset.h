#pragma once

#include <iostream>

class IntSet {
public:
    IntSet();

    // Максимальный размер множества.
    static const int ELTS_CAPACITY = 10;
    // ТРЕБОВАНИЕ: size() < ELTS_CAPACITY
    // РЕЗУЛЬТАТ:  добавление v в мн-во
    void insert(int v);

    // РЕЗУЛЬТАТ: удаление v из мн-ва
    void remove(int v);

    // РЕЗУЛЬТАТ: возвращает true в случае v содержится
    // в множестве
    bool contains(int v) const;

    // РЕЗУЛЬТАТ: возвращает количество элементов
    int size() const;

    // РЕЗУЛЬТАТ: выводит мн-во на экран
    void print(std::ostream &os) const;

    bool operator[](int v) const;

    private:

    int indexOf(int v) const;

    int elts[ELTS_CAPACITY];
    int elts_size;
};

std::ostream &operator<<(std::ostream &os, const IntSet &s);
