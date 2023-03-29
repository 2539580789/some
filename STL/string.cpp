#include<iostream>
#include<string.h>
using namespace std;
class String{
    private:
        char *m_data;
    public:
    String(char* str){  //构造函数
        if(str==nullptr){
            m_data = new char[1];
            *m_data = '\0';
        }else{
            m_data = new char[strlen(str) + 1];
            strcpy(m_data, str);
        }
    }
    String(const String& s){    //拷贝构造
        int len = strlen(s.m_data);
        m_data = new char[len + 1];
        strcpy(m_data, s.m_data);
    }
    String& operator=(const String& s){ //拷贝赋值
        if(this==&s){
            return *this;
        }
        delete[] m_data;
        int len = strlen(s.m_data);
        m_data = new char[len + 1];
        strcpy(m_data, s.m_data);
        return *this;
    }
};