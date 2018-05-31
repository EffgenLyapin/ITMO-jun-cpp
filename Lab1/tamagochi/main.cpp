#include <QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include "critter.h"

using namespace std;
int Critter::tam_count=0;
int main()
{

    Critter cr1(10,20,1,1);

    cout<<cr1.getActiveLevel()<<endl;
    cout<<cr1.getHungerLevel()<<endl;
    //cr1.sleep(20);
    cr1.play(16);
    Critter cr2(10,20,1,1);
    cout<<Critter::tam_count<<endl;

    //cout<<cr1.getActiveLevel()<<endl;
   // cr1.play(16);


}
