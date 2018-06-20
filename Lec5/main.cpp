#include <iostream>
#include "unsortedset.h"

using namespace std;


int main() {
    UnsortedSet<int> s1;
    UnsortedSet<int> s2;
    s1.insert(2);
    s1.insert(3);

    s2 = s1;
    cout << s1 << endl; // выведет {2, 3}
    cout << s2 << endl; // выведет {2, 3}

    s2.insert(4);

    cout << s2 << endl;
    // выведет {2, 3, 4}, ок

    cout << s1 << endl;



}
