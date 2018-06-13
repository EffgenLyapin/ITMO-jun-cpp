#include <iostream>
#include "intset.h"
#include "unsortedset.h"

using namespace std;


int main() {
    IntSet set;
    set.insert(7);
    set.insert(32);

    cout << "Size: " << set.size() << endl;
    set.print(cout);

    cout << "Contains 32? " << set.contains(32) << endl;
    cout << "Contains 42? " << set.contains(42) << endl;

    set.insert(42);
    set.remove(32);

    cout << "Size: " << set.size() << endl;
    set.print(cout);

    cout << "Contains 32? " << set.contains(32) << endl;
    cout << "Contains 42? " << set.contains(42) << endl;


    cout << set << endl;
    cout << "Contains 32? " << set[32] << endl;


    UnsortedSet<int> is;
    is.insert(3);
    is.insert(7);
    is.insert(8);
    cout << is; // { 3, 7, 8 }

    UnsortedSet<char> cs;
    cs.insert('a');
    cs.insert('e');
    cs.insert('i');
    cout << is; // { a, e, i }


//    UnsortedSet<Duck> ds;

    UnsortedSet<int> set1;
    int arr1[4] = { 1, 2, 3, 2 };
    fillFromArray(set1, arr1, 4);

    cout << set1 << endl;

    UnsortedSet<char> set2;
    char arr2[3] = { 'a', 'b', 'a' };
    fillFromArray(set2, arr2, 3);

    cout << set2 << endl;



}
