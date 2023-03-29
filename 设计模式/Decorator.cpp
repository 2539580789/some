#include<iostream>
#include<string>
using namespace std;
class Phone
{
public:
    Phone(){};
    virtual ~Phone(){};
    virtual void show(){};
};
class iPhone:public Phone{
    private:
        string name;
    public:
        iPhone(string _name) : name(_name){};
        ~iPhone(){};
        void show(){
            cout << name << "的装饰" << endl;
        }
};
class DecotatorPhone:public Phone{
    private:
        Phone *m_phone;
    public:
        DecotatorPhone(Phone* pho):m_phone(pho){}
        virtual void showde(){
            m_phone->show();
        }
};
class DPA:public DecotatorPhone{
    public:
    DPA(Phone* a):DecotatorPhone(a){}
};