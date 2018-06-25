#include <iostream>
#include <cassert>
#include <cstring>
#include "IntVector_lab06.h"

using namespace std;

//РЕЗУЛЬТАТ:  Конструктор по умолчанию.  Создает пустой IntVector.
IntVector::IntVector()
  : numElements(0) {}

//ТРЕБОВАНИЕ: IntVector не переполнен
//ИЗМЕНЕНИЯ:  IntVector
//РЕЗУЛЬТАТ:  Добавляет элемент в конец IntVector.
void IntVector::push_back(int value){
  //реализация
}

//ТРЕБОВАНИЕ: IntVector не пустой
//ИЗМЕНЕНИЯ:  IntVector
//РЕЗУЛЬТАТ:  Удаляет последний элемент из IntVector.
void IntVector::pop_back(){
 //реализация
}

//ТРЕБОВАНИЕ: 0 <= index < количества элементов IntVector
//РЕЗУЛЬТАТ:  Возвращает (по ссылке) элемент с заданным индексом.
int &IntVector::at(int index) {
  assert(false); 
  //реализация
}

//ТРЕБОВАНИЕ: 0 <= index < количества элементов IntVector
//РЕЗУЛЬТАТ:  Возвращает (по ссылке) элемент с заданным индексом.
const int &IntVector::at(int index) const {
  assert(false);
  //реализация
}

//ТРЕБОВАНИЕ: 0 <= index < количества элементов IntVector
//РЕЗУЛЬТАТ:  Возвращает (по ссылке) элемент с заданным индексом.
int &IntVector::operator[](int index) {
  assert(false); 
  //реализация
}

//ТРЕБОВАНИЕ: 0 <= index < количества элементов IntVector
//РЕЗУЛЬТАТ:  Возвращает (по ссылке) элемент с заданным индексом.
const int &IntVector::operator[](int index) const {
  assert(false); 
  //реализация
}

//РЕЗУЛЬТАТ:  Возвращает количества элементов IntVector.
int IntVector::size() const{
  return 0; 
  //реализация
}

//РЕЗУЛЬТАТ: Возвращает true если IntVector пустой, false в противном случае.
bool IntVector::empty() const{
  return true; 
  //реализация
}

//РЕЗУЛЬТАТ: Возвращает true если IntVector заполнен, false в противном случае.
//          Добавить элемент можно только в случае когда full() возвращает false.
bool IntVector::full() const{
  return true;
  //реализация
}

//РЕЗУЛЬТАТ: Выводит все элементы IntVector
//          в следующем формате:
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

//РЕЗУЛЬТАТ: Возвращает true в случае если инвариант представления выполняется.
//           Для IntVector только один инвариант представления 0 <= numElements <= CAPACITY.
bool IntVector::check_invariant() const{
  return false; 
  //реализация
}

//РЕЗУЛЬТАТ: Выводит все элементы IntVector
//          в следующем формате:
//          [ elem0, elem1, elem2, ... ]
ostream &operator<<(ostream & os, const IntVector &v) {

  //реализация

  return os; 
}
