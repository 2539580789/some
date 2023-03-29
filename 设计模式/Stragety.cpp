#include<iostream>
using namespace std;
class Strategy{
    public:
        Strategy(){};
        virtual ~Strategy(){};
        virtual void algo() = 0;
};
class StrategyX:public Strategy{
    public:
        StrategyX(){};
        virtual ~StrategyX(){};
        void algo() { cout << "X" << endl; };
};
class Context{
    private:
        Strategy *m;
    public:
        Context(Strategy *p) : m(p){};
        void oper(){
            m->algo();
        }
};
int main(){
        Context *p = new Context(new StrategyX());
        p->oper();
        return 0;
}