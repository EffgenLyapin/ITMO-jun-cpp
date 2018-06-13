#include <iostream>


using namespace std;

class Bird {
private:
  int age;
  string name;



public:
  Bird(string name_in)
    : age(0), name(name_in)
  {
      cout << "Bird ctor" << endl;
  }
  string getName() const {return name;}

  int getAge() const { return age; }

  void haveBirthday() { ++age; }

  void talk() const {
    cout << "tweet" << endl;
  }

  //нужно для динамического кастования
//   virtual ~Bird() {}

};


class Chicken : public Bird {
private:
  int roadsCrossed;

public:
  Chicken(string name_in)
    : Bird(name_in), roadsCrossed(0) {
    cout << "Chicken ctor" << endl;
  }

  void crossRoad() { ++roadsCrossed; }

  void talk() const {
    cout << "bawwk" << endl;
  }
};


class Duck : public Bird {
private:
  int numDucklings;

public:
  Duck(string name_in)
    : Bird(name_in), numDucklings(0) {
    cout << "Duck ctor" << endl;
  }

  void babyDucklings() {
    numDucklings += 7;
  }
  void talk() const {
    cout << "quack" << endl;
  }
};

//int main() {

//    //downcast
////    Chicken c("Myrtle");
////    Chicken *cPtr = &c;
////    Bird *bPtr = cPtr;

//    //upcast
////    Chicken c("Myrtle");
////    Bird *bPtr = &c;
////    Chicken *cPtr = bPtr;

//    return 0;
//}


//class Base {
//public:
//  int x;

//  void foo(int a)
//  {
//      cout << "int"<< endl;
//      return;
//  }


//  int foo(string b)
//  {
//      return 1;
//  }
//  void bar(Duck *c);
//};


//class Derived : public Base {
//public:
//  void x(int b);
//  int foo(int a)
//  {
//      return 2;
//  }
//  void bar(bool c);
//};


//int main() {
//  Base b;
//  b.foo(42);
//  b.foo("test");
//}


// полиморфизм подтипов

//int main() {
//  Chicken c("Myrtle");
//  c.crossRoad();
//  Duck d("Scrooge");


//  Bird b = c;

////  Chicken c1("1Myrtle");
////  c1 = b;

//  cout << "---";

////  Chicken c("Myrtle");
////  Chicken *cPtr = &c;
////  Bird *bPtr = cPtr;

//  cout << "---";
//}


//void allTalk(Bird * birds[], int length) {
//  for(int i = 0; i < length; ++i) {
//    birds[i]->talk();
//  }
//}

//int main()
//{

//    Chicken c("Myrtle");
//    Duck d("Scrooge");
//    Bird *ptr;
//    if (random() < 0.5) {
//        ptr = &c;
//    }
//    else {
//        ptr = &d;
//    }

//}




//int main() {
//  Chicken c("Myrtle");
//  Duck d("Scrooge");
//  Bird *ptr;
//  if (random() < 0.5) {
//    ptr = &c;
//  }
//  else {
//    ptr = &d;
//  }
//  ptr->talk();
//всегда будет tweet
//}


//int main() {
//  Chicken c("Myrtle");
//  Bird *bPtr = &c;
//  Chicken *cPtr = dynamic_cast<Chicken *>(bPtr);
//  if (cPtr != nullptr) {
//    // something chicken-specific
//  }
//}


//void allTalk(Bird * birds[], int length) {
//  for(int i = 0; i < length; ++i) {
//    Chicken *cPtr = dynamic_cast<Chicken*>(cPtr);
//    if(cPtr) {
//      cPtr->talk();
//    }
//    Duck *dPtr = dynamic_cast<Duck*>(dPtr);
//    if(dPtr) {
//      dPtr->talk();
//    }
//    Eagle *ePtr = dynamic_cast<Duck*>(ePtr);
//    if(ePtr) {
//      cPtr->talk();
//    }
//  }
//}


//int main() {
//  Chicken c("Myrtle");
//  Duck d("Scrooge");
//  Bird *ptr;
//  if (random() < 0.5) {
//    ptr = &c;
//  }
//  else {
//    ptr = &d;
//  }
//  // нужно сделать функцию talk виртуальной
//  ptr->talk();
//}


//int main() {
//  Chicken c("Myrtle");
//  Duck d("Scrooge");
//  Bird *ptr;
//  if (random() < 0.5) {
//    ptr = &c;
//  }
//  else {
//    ptr = &d;
//  }
//  ptr->talk();
//}

