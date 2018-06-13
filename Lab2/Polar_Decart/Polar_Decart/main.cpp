#include <QCoreApplication>
#include <iostream>
#include <math.h>

#define PI 3.14159265
using namespace std;

class PolarCoordinates {
private:
    float r;
    float phi;
    float x;
    float y;

public:
    PolarCoordinates();
    PolarCoordinates(float r_in,float phi_in)
        : r(r_in), phi(phi_in)
      {
          cout << "Create Class" << endl;
      }
    float get_phi()
    {
        return this->phi;
    }

    float get_r()
    {
        return r;
    }

    void set_phi(float phi_in)
    {
        this->phi=phi_in;
    }

    void set_r(float r_in)
    {
        this->r=r_in;
    }

    float get_x()
    {
        return this->x;
    }

    float get_y()
    {
        return this->y;
    }

    void set_x(float x_in)
    {
        this->x=x_in;
    }

    void set_y(float y_in)
    {
        this->y=y_in;
    }

    void polarToDecart()
    {

        set_x(get_r()*cos(get_phi()*PI/180.0));
        set_y(get_r()*sin(get_phi()*PI/180.0));
    }

    void shiftX(float phi_in)
    {
        float x,y;
        x=(this->x*cos(phi_in*PI/180))-(this->y*sin(phi_in*PI/180));
        y=(this->y*cos(phi_in*PI/180))-(this->x*sin(phi_in*PI/180));
        set_x(x);
        set_y(y);
    }



};
int main()
{
    PolarCoordinates pc(2.5,60.0);
    cout<<"r="<<pc.get_r()<<"; phi="<<pc.get_phi()<<endl;
    pc.polarToDecart();
    cout<<"x="<<fixed<<pc.get_x()<<"; y="<<fixed<<pc.get_y()<<endl;
    pc.shiftX(90.0);
    cout<<"x="<<pc.get_x()<<"; y="<<pc.get_y()<<endl;
}
