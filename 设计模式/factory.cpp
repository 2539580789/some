#include<iostream>
class Product{
    virtual int operation(int a, int b) = 0;
};
class Pro_add:public Product{ 
    public:
    int operation(int a,int b){
        return a + b;
    }
};
class Pro_mul:public Product{
    public:
    int operation(int a,int b){
        return a * b;
    }
};
// class Factory{                      //简单工厂：实现了对象的创建和使用的分类，但是工厂职责过重，新增一个产品需要修改工厂类，违背“开闭原则”
//     public:
//     Product* create(int i){
//         switch (i)
//         {
//         case 1:
//             return new Pro_add;
//             break;

//         default:
//             return new Pro_mul;
//             break;
//         }
//     }
// };
// class Factory{      //工厂方法 将简单工厂中的工厂变为抽象类，
// //不同工厂负责不同的产品，通过多态解决了简单工厂分支过多的问题，但新增一个产品还需要新增对应的子工厂，比简单工厂更符合开闭原则
//     public:
//         virtual Product *create() = 0;
// };
// class Factoryadd:public Factory{
//     public:
//         Product* create(){
//             return new Pro_add;
//         }
// };
// class Factorymul:public Factory{
//     public:
//         Product* create(){
//             return new Pro_mul;
//         }
// };
class ProductP{
    public:
    virtual int operation(int a, int b) = 0;
};
class ProductP_add:public ProductP{
    public:
    int operation(int a,int b){
        return a + b;
    }
};
class ProductF{
    public:
    virtual int operation(int a, int b) = 0;
};
class ProductF_add:public ProductF{
    public:
    int operation(int a,int b){
        return (-a) + (-b);
    }
};
class Factory{
    public:
    virtual ProductP* createP() = 0;
    virtual ProductF* createF() = 0;
};
class Factory_add:public Factory{
    public:
    ProductP_add* createP(){
        return new ProductP_add;
    }
    ProductF_add* createF(){
        return new ProductF_add;
    }
};
