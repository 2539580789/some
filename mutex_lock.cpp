#include<iostream>
#include<pthread.h>
pthread_mutex_t mutexl;
pthread_rwlock_t prwl;
pthread_cond_t cond;
int item = 0;
int read1()
{
    int p=pthread_rwlock_rdlock(&prwl);
    if(p==0){
        std::cout << "read1" << std::endl;
    }
    else{
        std::cout << "fail read1" << std::endl;
    }
}
int read2()
{
    int p=pthread_rwlock_rdlock(&prwl);
    if(p==0){
        std::cout << "read2" << std::endl;
    }
    else{
        std::cout << "fail read2" << std::endl;
    }
}
int write(){
    int p=pthread_rwlock_wrlock(&prwl);
    if(p==0){
        std::cout << "write" << std::endl;
    }
    else{
        std::cout << "fail" << std::endl;
    }
}
int consumer(){
    pthread_mutex_lock(&mutexl);
    while(!item){
        pthread_cond_wait(&cond, &mutexl);
    }
    item--;
}
int main(){
    // read1();
    
    // write();
    // read2();
    return 0;
}