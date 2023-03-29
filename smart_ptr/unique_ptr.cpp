#include<iostream>
//unique_ptr没有拷贝构造和拷贝赋值函数
namespace wow{
    template<typename T>
    class unique{
        private:
            T *m_ptr;
            unique(const unique &a) = delete;
            unique &operator=(const unique &a) = delete;
        public:
            unique(T* ptr==nullptr):m_ptr(ptr){

            }
            ~unique(){
                del();
            }
            void reset(T* ptr){
                del();
                m_ptr = ptr;
            }
            T* get(){
                return *m_ptr;
            }
            
            void del(){
                if(m_ptr==nullptr)
                    return;
                delete m_ptr;
                m_ptr = nullptr;
            }
    };
}