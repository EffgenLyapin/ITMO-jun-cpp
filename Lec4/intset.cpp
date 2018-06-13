#include <assert.h>
#include "intset.h"

using namespace std;

IntSet::IntSet()
    : elts_size(0) { }

void IntSet::insert(int v) {
    assert(size() < ELTS_CAPACITY);
    if (contains(v)) {
        return;
    }
    elts[elts_size] = v;
    ++elts_size;
}

void IntSet::remove(int v) {
    if (!contains(v)) {
        return;
    }
    elts[indexOf(v)] = elts[elts_size - 1];
    --elts_size;
}

bool IntSet::contains(int v) const {
    for (int i = 0; i < elts_size; ++i) {
        if (elts[i] == v) {
            return true;
        }
    }
    return false;
}

int IntSet::size() const
{
    return elts_size;
}

void IntSet::print(std::ostream &os) const
{

    for (int i = 0; i < elts_size; ++i) {
    os << elts[i] << " ";
    }
    os << std::endl;
}


int IntSet::indexOf(int v) const {
    for (int i = 0; i < elts_size; ++i) {
        if (elts[i] == v) {
            return i;
        }
    }
    return -1;
}


ostream &operator<<(ostream &os, const IntSet &s) {
    s.print(os);
    return os;
}

bool IntSet::operator[](int v) const {
    return contains(v);
}


