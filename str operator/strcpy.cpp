#include<iostream>
#include<string>
#include<cassert>
using namespace std;
char* strcpy(char* des,char* src){
    assert((des != NULL) && (src != NULL));
    char *add = des;
    while((*des++=*src++)!='\0');
    return add;
}
int strlen(char* str){
    assert(str != NULL);
    int len = 0;
    while((*str++)!='\0'){
        len++;
    }
    return len;
}
char* strcat(char* des,char* src){
    assert(des && src);
    char *ret = des;
    while(*des){
        des++;
    }
    while(*des++=*src++!='\0')
        ;
    return ret;
}
int strcmp(char* des,char* src){
    assert(des && src);
    while(*des&&*src&&(*des==*src)){
        des++;
        src++;
    }
    return *des - *src;
}
int main(){
    string a(5, '.');
    string b = "11111";
    cout << a << endl;
    char c[5] = {'1', '1', '1', '1', '1'};
    cout << strlen(c) << endl;
    return 0;
}