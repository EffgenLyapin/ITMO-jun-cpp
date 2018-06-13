#include <iostream>
#include <cassert>
#include <cstring>
#include "IntVector_lab06.h"

using namespace std;

//EFFECTS:  Default constructor.  Constructs an empty IntVector.
IntVector::IntVector()
  : numElements(0) {}

//REQUIRES: this IntVector is not full
//MODIFIES: this IntVector
//EFFECTS:  Adds value to the end of this IntVector.
void IntVector::push_back(int value){
  //TASK 1 - YOUR CODE HERE
}

//REQUIRES: this IntVector is not empty
//MODIFIES: this IntVector
//EFFECTS:  Removes the last element in this IntVector.
void IntVector::pop_back(){
  //TASK 1 - YOUR CODE HERE
}

//REQUIRES: 0 <= index < number of elements in this IntVector
//EFFECTS:  Returns (by reference) the element at the given index.
int &IntVector::at(int index) {
  assert(false); //TASK 1 - REPLACE WITH YOUR CODE
}

//REQUIRES: 0 <= index < number of elements in this IntVector
//EFFECTS:  Returns (by reference) the element at the given index.
const int &IntVector::at(int index) const {
  assert(false); //TASK 1 - REPLACE WITH YOUR CODE
}

//REQUIRES: 0 <= index < number of elements in this IntVector
//EFFECTS:  Returns (by reference) the element at the given index.
int &IntVector::operator[](int index) {
  assert(false); //TASK 1 - REPLACE WITH YOUR CODE
}

//REQUIRES: 0 <= index < number of elements in this IntVector
//EFFECTS:  Returns (by reference) the element at the given index.
const int &IntVector::operator[](int index) const {
  assert(false); //TASK 1 - REPLACE WITH YOUR CODE
}

//EFFECTS:  Returns the number of elements of this IntVector.
int IntVector::size() const{
  return 0; //TASK 1 - REPLACE WITH YOUR CODE
}

//EFFECTS:  Returns true if this IntVector is empty, false otherwise.
bool IntVector::empty() const{
  return true; //TASK 1 - REPLACE WITH YOUR CODE
}

//EFFECTS:  Returns true if this IntVector is at capacity, false otherwise.
//          That is, you may add elements if and only if full() is false.
bool IntVector::full() const{
  return true; //TASK 1 - REPLACE WITH YOUR CODE
}

//EFFECTS:  Prints to os all elements in this IntVector
//          in the format (all on one line, followed by newline):
//          [ elem0, elem1, elem2, ... ]
void IntVector::print(ostream &os) const{
  os << "[ ";
  const int *ptr = data;
  for(const int *end = data + (numElements-1); ptr < end; ++ptr){
    os << *ptr << ", ";
  }
  if (numElements != 0){
    os << *ptr << " ";
  }
  os << "]";
}

//EFFECTS: Returns true if the representation invariant holds.
//         For IntVector, the only invariant is 0 <= numElements <= CAPACITY.
bool IntVector::check_invariant() const{
  return false; //TASK 3 - REPLACE WITH YOUR CODE
}

//EFFECTS:  Prints to os all elements in this IntVector
//          in the format (all on one line, followed by newline):
//          [ elem0, elem1, elem2, ... ]
ostream &operator<<(ostream & os, const IntVector &v) {

  // TASK 1 - ADD YOUR CODE HERE

  return os; // always do this at end of << operator
}
