#ifndef CRITTER_H_
#define CRITTER_H_
#include <iostream>
using namespace std;

/**
 * Задания:
 * 1. Реализовать меню для взаимодействия с тамагочи (выбор действия в main)
 * 2. Реализовать описанные функции
 * 3. Добавить статическую переменную для хранения количества созданных сущностей
 * 4. Добавить функцию выводящую информацию о текущем уровне голода и активности
 * 5. Добавить в функцию passTime предупреждения если уровень голода или активности критичные
 * 6. Создать перегруженные функции feed и play, которые будут принимать один аргумент типа int,
 * т.е.  void feed(int amount) и изменять уровень голода/активности ровно на значение аргумента
 */
class Critter
{
public:
    /**
     * @brief Critter
     * Вывод приветствие
     */
    Critter();
    Critter(int hunger);
    Critter(int hunger,int active,bool live,bool sleep){
    hunger_=hunger;
    active_=active;
    live_=live;
    sleep_=sleep;
    };
  //  ~Critter();

	/**
     * @brief set_live функция устанавливает состояние животного
     * если уровень голода >30 живность сдохла
      */
	void set_live(int hunger) {
                 if (hunger>30) {
                     this->live_=false;
                     cout<<"DIE! RIP!"<<endl;
                 }
                 else this->live_=true;
	};


    /**
     * @brief getHungerLevel функция возвращает текущий уровень
     * оголодалости животного и проверяет живо ли животное
     * @return уровень голода
     */

    int getHungerLevel(){
		int hungerLevel;
                hungerLevel=this->hunger_;
                //set_live(hungerLevel);
		return hungerLevel;
	};
	
    /**
     * @brief passTime функция эмуляция прошедшего времени
     * При вызове увеличивает уровень голода,
     * если уровень голода превысил допустимый порог,
     * то живность умирает
     */
    void passTime(int times){
                 this->hunger_+=times;
             set_live(this->hunger_);
	};

    /**
     * @brief set_live функция устанавливает состояние животного
     * если уровень активности <5 живность хочет спать
      */
	void set_sleep(int active) {
                 if (active<5) {
                     this->sleep_=true;
                 cout<<"ZZZZZZZZZZZzzzzzzzzzzzzz........"<<endl;
                 }
                 else this->sleep_=false;
	};
	/**
     * @brief getActiveLevel функция возвращает уровень
     * питомца к активности, при низком уровене хочется спать
     * ZZZZZZZZZZZzzzzzzzzzzzz.....
     * @return
     */
    int getActiveLevel(){
		int activeLevel;
                activeLevel=this->active_;
                //set_sleep(activeLevel);
		return activeLevel;
	};

    /**
     * @brief sleep
     * Повышает уровень активности
     */
    void sleep(int times){
                 this->active_+=times;
                 set_sleep(this->active_);
	};

    /**
     * @brief feed
     * Понижает уровень голода
     */
    void feed(int times){
                 this->hunger_-=times;
             set_live(this->hunger_);
	};
    /**
     * @brief play
     * Понижает уровень активности, утомляет
     */
    void play(int times){
                 this->active_-=times;
                 set_sleep(this->active_);
	};

private:
    int hunger_;
    int active_;
    bool live_;
    bool sleep_;
};

#endif
