#include<iostream>
#include<list>
using namespace std;
class Observer{
    public:
        virtual void update(int val) = 0;
};
class Subject{
    public:
        virtual void attach(Observer *) = 0;
        virtual void detach(Observer *) = 0;
        virtual void notify(Observer *) = 0;
};
class concreteObserver:public Observer{
    private:
        Subject *m_subject;
    public:
        concreteObserver(Subject *a) : m_subject(a){};
        void update(int val){
            cout << "update!" << val << endl;
        }
};
class concreteSubject:public Subject{
    private:
        list<Observer *> m_list;
        int m_state;
    public:
        void attach(Observer* p){
            m_list.push_back(p);
        }
        void detach(Observer* p){
            m_list.remove(p);
        }
        void notify(Observer* p){
            for(auto a:m_list){
                a->update(m_state);
            }
        }
};
