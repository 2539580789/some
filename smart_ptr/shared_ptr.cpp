#include<iostream>
namespace my
{
    template<typename T>
    class Smart{
        private:
            T *m_ptr;
            int *m_cnt;
        public:
            Smart(T* ptr=nullptr):m_pre(ptr){   //构造函数
                if(m_pre){
                    m_cnt = new int(1);
                }else{
                    m_cnt = new int(0);
                }
            }
            Smart(const Smart& a){  //拷贝构造
                if(this!=a){
                    this->m_ptr = a->m_ptr;
                    this->m_cnt = a->m_cnt;
                    (*this->m_cnt)++;
                }
            }
            Smart& operator=(const Smart& a){   //拷贝赋值
                if(this->m_ptr==a->m_ptr){
                    return *this;
                }
                if(this->m_ptr){
                    (*this->m_cnt)--;
                    if(*this->m_cnt==0){
                        delete m_cnt;
                        delete m_ptr;
                    }
                }
                this->m_ptr = a->m_ptr;
                this->m_cnt = a->m_cnt;
                (*this->m_cnt)++;
                return *this;
            }
            T& operator*(){
                if(this->m_ptr){
                    return *(this->m_ptr);
                }
            }
            T* operator&(){
                if(this->m_ptr){
                    return this->m_ptr;
                }
            }
            ~Smart(){
                (*this->m_cnt)--;
		        if (*this->m_cnt == 0)
		        {
			        delete this->m_ptr;
			        delete this->m_cnt;
		        }
            }
            int use(){
                return (*this->m_cnt);
            }
    };
}