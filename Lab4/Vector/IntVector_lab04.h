#include <iostream>

class IntVector {
  // IntVector, контейнер, который содержит целочисленные значения и 
  // обеспечивает произвольный доступ к любому элементу по индексу.
  // Идексы начинаются с 0.
  // Максимальный размер IntVector 100 элементов.
  
public:


  // Максимальный размер IntVector должен быть постоянным
  // для всех экземпляров, поскольку используется статическая память для хранения
  // массива. 

  static const int CAPACITY = 100;

  //РЕЗУЛЬТАТ:  Конструктор по умолчанию.  Создает пустой IntVector.
  IntVector();

  //ТРЕБОВАНИЕ: IntVector не переполнен
  //ИЗМЕНЕНИЯ:  IntVector
  //РЕЗУЛЬТАТ:  Добавляет элемент в конец IntVector.
  void push_back(int value);
  
  //ТРЕБОВАНИЕ: IntVector не пустой
  //ИЗМЕНЕНИЯ:  IntVector
  //РЕЗУЛЬТАТ:  Удаляет последний элемент из IntVector.
  void pop_back();
  
  //ТРЕБОВАНИЕ: 0 <= index < количества элементов IntVector
  //РЕЗУЛЬТАТ:  Возвращает (по ссылке) элемент с заданным индексом.
  int &at(int index);

  //ТРЕБОВАНИЕ: 0 <= index < количества элементов IntVector
  //РЕЗУЛЬТАТ:  Возвращает (по ссылке) элемент с заданным индексом.
  const int &at(int index) const;

  //ТРЕБОВАНИЕ: 0 <= index < количества элементов IntVector
  //РЕЗУЛЬТАТ:  Возвращает (по ссылке) элемент с заданным индексом.
  int &operator[](int index);

  //ТРЕБОВАНИЕ: 0 <= index < количества элементов IntVector
  //РЕЗУЛЬТАТ:  Возвращает (по ссылке) элемент с заданным индексом.
  const int &operator[](int index) const;
  
  //РЕЗУЛЬТАТ:  Возвращает количества элементов IntVector.
  int size() const;
  
  //РЕЗУЛЬТАТ: Возвращает true если IntVector пустой, false в противном случае.
  bool empty() const;
  
  //РЕЗУЛЬТАТ: Возвращает true если IntVector заполнен, false в противном случае.
  //          Добавить элемент можно только в случае когда full() возвращает false.
  bool full() const;
  
  //РЕЗУЛЬТАТ: Выводит все элементы IntVector
  //          в следующем формате:
  //          [ elem0, elem1, elem2, ... ]
  void print(std::ostream &os) const;

  
private:

  // Массив для хранения элементов вектора
  int data[CAPACITY];

  //Текущее количество элементов.
  //Invariant:  0 <= numElements <= CAPACITY
  int numElements;

  //РЕЗУЛЬТАТ: Возвращает true в случае если инвариант представления выполняется.
  //           Для IntVector только один инвариант представления 0 <= numElements <= CAPACITY.
  bool check_invariant() const;

};

//РЕЗУЛЬТАТ: Выводит все элементы IntVector
//          в следующем формате:
//          [ elem0, elem1, elem2, ... ]

std::ostream &operator<<(std::ostream &os, const IntVector &v);
