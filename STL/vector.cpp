// #include<iostream>
// #include<memory>
// #include<string.h>
// using namespace std;
// template<typename T>
// class vector{
//     public:
//         typedef T* iterator;
//         typedef const T *const_iterator;
//     private:
//         iterator _start;
//         iterator _finish;
//         iterator _endofstorage;
//     public:
//         vector() : _start(nullptr), _finish(nullptr), _endofstorage(nullptr){}; //构造函数
//         const iterator cbegin(){
//             return _finish;
//         }
//         const iterator cend(){
//             return _start;
//         }
//         const iterator begin(){
//             return _start;
//         }
//         const iterator end(){
//             return _finish;
//         }
//         T& operator[](size_t pos){
//             return _start[pos];
//         }
//         size_t size() const{
//             return _finish - _start;
//         }
//         size_t capacity() const{
//             return _endofstorage - _start;
//         }
//         void reserve(size_t n){
//             if(n>capacity()){
//                 size_t sz = size();
//                 T *tmp = new T[2 * sz];
//                 if(_start){
//                     memcpy(tmp, _start, sizeof(T) * size());
//                     delete _start;
//                 }
//                 _start = tmp;
//                 _finish = tmp + sz;
//                 _endofstorage = _start + n;
//             }
//         }
//         void resize(size_t n){
//             if(n<capacity()){
//                 _finish = _start + n;
//             }else{
//                 if(n>capacity()){
//                     reserve(n);
//                 }
//                 while(_finish!=_start+n){
//                     *_finish = 0;
//                     _finish++;
//                 }
//             }
//         }
//         void push_back(const T& val){
//             if(_finish==_endofstorage){
//                 reserve(capacity() == 0 ? 4 : 2 * capacity());
//             }
//             *_finish = val;
//             ++_finish;
//         }
// };
// int main(){
//         vector<int> arr;
//         arr.reserve(3);
//         arr.push_back(1);
//         cout << arr[0];
//         return 0;
// }
template <typename T>
class vector {
private:
    T* arr;
    size_t cap;
    size_t sz;

public:
    // 构造函数
    vector() : arr(nullptr), cap(0), sz(0) {}
    vector(size_t n) : arr(new T[n]), cap(n), sz(n) {}
    vector(size_t n, const T& val) : arr(new T[n]), cap(n), sz(n) {
        for (size_t i = 0; i < sz; i++) {
            arr[i] = val;
        }
    }
    // 拷贝构造函数
    vector(const vector& other) : arr(new T[other.sz]), cap(other.sz), sz(other.sz) {
        for (size_t i = 0; i < sz; i++) {
            arr[i] = other.arr[i];
        }
    }
    // 移动构造函数
    vector(vector&& other) : arr(other.arr), cap(other.cap), sz(other.sz) {
        other.arr = nullptr;
        other.cap = 0;
        other.sz = 0;
    }
    // 析构函数
    ~vector() {
        delete[] arr;
    }

    // 下标操作符重载
    T& operator[](size_t i) {
        return arr[i];
    }
    const T& operator[](size_t i) const {
        return arr[i];
    }

    // 获取元素数量
    size_t size() const {
        return sz;
    }

    // 获取容器容量
    size_t capacity() const {
        return cap;
    }

    // 在末尾添加元素
    void push_back(const T& val) {
        if (sz >= cap) {
            size_t new_cap = (cap == 0) ? 1 : cap * 2;
            T* new_arr = new T[new_cap];
            for (size_t i = 0; i < sz; i++) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
            cap = new_cap;
        }
        arr[sz] = val;
        sz++;
    }

    // 删除末尾元素
    void pop_back() {
        if (sz > 0) {
            sz--;
        }
    }
};
