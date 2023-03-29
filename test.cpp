// #include<iostream>
// using namespace std;
// template<typename T>
// class shared_ptr{   //智能指针 构造 拷贝构造 拷贝赋值 函数操作符重载 析构
//     private:
//         T *m_res;
//         int *m_cnt;
//     public:
//         shared_ptr(T* res){ //构造
//             if(res==nullptr){
//                 m_res = res;
//                 m_cnt = new int(0);
//             }else{
//                 m_res = res;
//                 m_cnt = new int(1);
//             }
//         }
//         shared_ptr(const shared_ptr& ptr){
//             if(this!=ptr){
//                 this->m_res = ptr->m_res;
//                 this->m_cnt = ptr->m_cnt;
//                 *this->m_cnt++;
//             }
//         }
//         shared_ptr& operator=(const shared_ptr& ptr){
//             if(this==ptr){
//                 return *this;
//             }
//             if(*this->m_cnt!=0){
//                 *this->m_cnt--;
//                 if(*this->m_cnt==0){
//                     delete this->m_cnt;
//                     delete this->m_res;
//                 }
//             }
//             this->m_res = ptr->m_res;
//             this->m_cnt = ptr->m_cnt;
//             *this->m_cnt++;
//             return *this;
//         }
//         T* operator&(){
//             if(this->m_res){
//                 return this->m_res;
//             }
//         }
//         T& operator*(){
//             if(this->m_res){
//                 return *(this->m_res);
//             }
//         }
//         ~shared_ptr(){
//             *this->m_cnt--;
//             if (*this->m_cnt == 0)
//             {
//                 delete this->m_cnt;
//                 delete this->m_res;
//             }
//         }
// };
// template<typename T>
// class unique_ptr{   //禁止拷贝赋值 拷贝构造
//     private:
//         T *m_res;
//         unique_ptr(const unique_ptr &p) = delete;
//         unique_ptr &operator=(const unique_ptr &p) = delete;

//     public:
//         unique_ptr(T* res):m_res(res){
            
//         }
//         void del(){
//             if(m_res==nullptr){
//                 return;
//             }
//             delete m_res;
//             m_res = nullptr;
//         }
//         ~unique_ptr(){
//             del();
//         }
//         void reset(T* r){
//             del();
//             m_res = r;
//         }
// };
// #include<iostream>
// #include<assert.h>
// using namespace std;
 
// char* strcpy(char* des,char* res){
//     assert(des != NULL && res != NULL);
//     char *ans = des;
//     while((*des++)=(*res++)!='\0')
//         ;
//     return ans;
// }
// int strlen(char* str){
//     assert(str != NULL);
//     char *res = str;
//     int len = 0;
//     while (*str++ != '\0')
//     {
//         len++;
//     }
//     return len;
// }

// char* strcat(char* dest, const char* source){
// 	if (dest == NULL || source == NULL){		//合法性校验
// 		return dest;
// 	}
// 	char* p = dest;			//将目的数组赋给p
// 	while (*p != '\0'){		//循环看大小
// 		p++;
// 	}
// 	while (*source != '\0'){			//注意指针的用法
// 		*p = *source;
// 		p++;			//依次加加进行连接
// 		source++;
// 	}
// 	*p = '\0';
// 	return dest;
// }
// int strcmp(char* s1,char* s2){
//     assert(s1 && s2);
//     while(*s1&&*s2&&(*s1==*s2)){
//         s1++;
//         s2++;
//     }
//     return *s1 - *s2;
// }

// int main(){
//     char a[1024] = "acawerr";
//     char *b = "aaaa";
//     cout << a << endl;
//     strcat(a, b);
//     cout << a << endl;
//     return 0;
// }
// #include<iostream>
// using namespace std;
// class a{
//     public:
//     a(){
//         cout << "a" << endl;
//     }
//     ~a(){
//         cout << "da" << endl;
//     }
// };
// class b:public a{
//     public:
//     b(){
//         cout << "b" << endl;
//     }
//     ~b(){
//         cout << "db" << endl;
//     }
// };
// int main(){
//     a *k = new b;
//     return 0;
// }
// #include<iostream>
// class Single{   //懒汉式 线程不安全
//     private:
//         static Single *m_ptr;
//         Single(){}
//         Single(const Single *ptr) = delete;
//         Single &operator=(const Single **ptr) = delete;
//     public:
//         Single* get(){
//             if(m_ptr==nullptr){
//                 m_ptr = new Single();
//             }
//             return m_ptr;
//         }
// };
#include<memory>
#include<mutex>
#include<thread>
// class Single{   //懒汉式(线程安全)                            优点：延迟实例化，线程安全    缺点：加锁开销大
//     private:
//         typedef std::shared_ptr<Single> Ptr;
//         static Ptr m_ptr;
//         static std::mutex m_mutex;
//         Single(){};
//         Single(Single &) = delete;
//         Single operator=(const Single &) = delete;

//     public:
//         Ptr get(){  
//             if(m_ptr==nullptr){
//                 std::lock_guard<std::mutex> lk(m_mutex);
//                 if (m_ptr == nullptr)
//                 {
//                     m_ptr = std::shared_ptr<Single>(new Single);
//                 }
//             }
//             return m_ptr;
//         }
// };
// Single::Ptr Single::m_ptr = nullptr;
#include<bits/stdc++.h>
using namespace std;
// class Strategy{
//     public:
//         Strategy(){};
//         virtual ~Strategy(){};
//         virtual void algo() = 0;
// };
// class StrategyX:public Strategy{
//     public:
//         StrategyX(){};
//         virtual ~StrategyX(){};
//         void algo() { cout << "X" << endl; };
// };
// class Context{
//     private:
//         Strategy *m;
//     public:
//         Context(Strategy *p) : m(p){};
//         void oper(){
//             m->algo();
//         }
// };
// int main(){
//         Context *p = new Context(new StrategyX());
//         p->oper();
//         return 0;
// }
class Subject{
    public:
        virtual void add(Observer *a) = 0;
        virtual void detach(Observer *a) = 0;
        virtual void notify() = 0;
};
class Observer{
    public:
        virtual void update(int val) = 0;
};
class conSubject:public Subject{
    private:
        list<Observer *> res;
        int v;
    public:
        void add(Observer* a){
            res.push_back(a);
        }
        void detach(Observer* b){
            res.remove(b);
        }
        void notify(){
            for(auto a:res){
                a->update(v);
            }
        }
};
