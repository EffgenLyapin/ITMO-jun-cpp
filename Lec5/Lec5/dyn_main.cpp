#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include "intset.h"
#include "unsortedset.h"

#include "dyn_array.h"


using namespace std;


//int *pointerToThree() {
//  int x = 3;
//  return &x;
//}

//void func() {
//  int y = 5;
//}

//int main() {
//  int *z = pointerToThree();
//  func();
//  if (*z != 3) {
//    cout << "EXPLODE!" << endl;
//  }
//}

//class MyClass {
//public:
//  MyClass (string s_in)
//    : s(s_in) {
//    cout << "MyClass конструктор "
//         << s << endl;
//  }

//  ~MyClass() {
//    cout << "MyClass деструктор "
//         << s << endl;
//  }

//private:
//  string s;
//};


//void func() {
//  MyClass m3("local in func");
//}

//int main() {
//  MyClass *mPtr;
//  func();
//  mPtr = new MyClass("dynamic");
//  MyClass m4("local in main");
//  delete mPtr;
//  func();
//}


//void example4() {
//  int x = 0;
//  int *ptr = new int(42);
//  cout << *ptr << endl;
//  delete ptr;

//  int *ptr1 = new int(3);
//  cout << *ptr << endl;
//  delete ptr1;
//}


//void example5() {
//  int x = 0;
//  int *ptr = new int(42);
//  cout << *ptr << endl;
//  delete ptr; ptr = nullptr;

//  int *ptr1 = new int(3);
//  cout << *ptr << endl;
//  delete ptr1;
//}


//int main() {

//    example4();
//    example5();
//}


int main()
{
    DynamicIntArray dArr(rand()%100 + 1);

    for(int i = 0; i < dArr.size(); i++)
    {
        dArr[i] = rand()%100 + 1;
    }

    cout << "завершение программы\n";
}
