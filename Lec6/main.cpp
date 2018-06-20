#include <iostream>
#include "intlist.h"
#include "list.h"

using namespace std;

template <typename Iter_type>
Iter_type max_element(Iter_type begin, Iter_type end) {

  Iter_type maxIt = begin;

  for (Iter_type it = begin; it != end; ++it) {
    if (*it > *maxIt) {
      maxIt = it;
    }
  }
  return maxIt;
}



int main()
{

    IntList list;
    list.push_front(1);
    list.push_front(2);
    list.print(cout);


//    IntList list;         // ( )
//    list.push_front(1);   // ( 1 )
//    list.push_front(2);   // ( 2 1 )
//    list.push_front(3);   // ( 3 2 1 )

//    cout << list.front(); // 3

//    list.front() = 4;     // ( 4 2 1 )

//    list.pop_front();     // ( 2 1 )
//    list.pop_front();     // ( 1 )
//    list.pop_front();     // ( )

//    cout << list.empty(); // true (or 1)

    return 0;
}
