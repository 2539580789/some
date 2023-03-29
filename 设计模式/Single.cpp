#include<iostream>  //单例模式
//全局只有一个实例，并提供一个全局访问该实例的接口
//优点：避免频繁的创建和销毁，浪费系统资源
// class Single{   //懒汉式(线程不安全)
//                                              优点:延迟实例化，避免不必要的实例浪费系统资源
//                                              缺点：线程不安全，多线程同时调用接口会进行多次实例化
//     private:
//         static Single* m_ptr;
//         Single(){};
//         Single(Single &) = delete;
//         Single operator=(const Single &) = delete;

//     public:
//         Single* get(){  
//             if(m_ptr==nullptr){
//                 m_ptr = new Single();
//             }
//             return m_ptr;
//         }
// };
// class Single{   //饿汉式                            优点：提前实例化对象，需要调用时直接调用，线程安全    缺点：会造成不必要的资源浪费
//     private:
//         static Single* m_ptr;
//         Single(){};
//         Single(Single &) = delete;
//         Single operator=(const Single &) = delete;

//     public:
//         Single* get(){  
//             return m_ptr;
//         }
// };
// Single *Single::m_ptr = new Single();
// #include<memory>
// #include<mutex>
// #include<thread>
// class Single{   //懒汉式(线程安全)                            优点：延迟实例化，线程安全    缺点：加锁开销大
//     private:
//         typedef std::shared_ptr<Single> Ptr;
//         static Ptr *m_ptr;
//         static std::mutex m_mutex;
//         Single(){};
//         Single(Single &) = delete;
//         Single operator=(const Single &) = delete;

//     public:
//         Ptr* get(){  
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
// Single::Ptr *Single::m_ptr = nullptr;
class Single{
    public:
    static Single& get(){
        static Single m;
        return m;
    }
};
