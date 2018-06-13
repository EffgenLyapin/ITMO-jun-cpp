#include <assert.h>
#include "sortedintset.h"

SortedIntSet::SortedIntSet()
    : elts_size(0) { }

void SortedIntSet::insert(int v) {
    assert(size() < ELTS_CAPACITY);
    if (!contains(v)) {
        int index = elts_size;
        while (index > 0 && elts[index - 1] > v) {
          elts[index] = elts[index - 1];
          --index;
        }
        elts[index] = v;
        ++elts_size;
      }

}

void SortedIntSet::remove(int v) {
    if (!contains(v)) {
        return;
    }
    for (int i = indexOf(v); i < elts_size - 1; ++i) {
        elts[i] = elts[i + 1];
    }
    --elts_size;
}

bool SortedIntSet::contains(int v) const {
    for (int i = 0; i < elts_size; ++i) {
        if (elts[i] == v) {
            return true;
        }
    }
    return false;
}

int SortedIntSet::size() const
{
    return elts_size;
}

void SortedIntSet::print(std::ostream &os) const
{

    for (int i = 0; i < elts_size; ++i) {
        os << elts[i] << " ";
    }
    os << std::endl;

}


int SortedIntSet::indexOf(int v) const {
  for (int i = 0; i < elts_size; ++i) {
      if (elts[i] == v) {
          return i;
      }
  }
  return -1;
}
