#include <iostream>
#include <memory>
#include <vector>
#include <functional>
using namespace std;
void test_fun(int x);
 using fun_ptr = void(*)(int);
class A {
public:
    int *int_ptr;
    // A(A &&a) {
        
    //     cout << "---移动构造函数调用----" << endl;
    //     cout << "要转移对象在堆内存的首地址：" << a.int_ptr << endl;
    //     int_ptr = a.int_ptr;
    //     a.int_ptr = nullptr;
    // }
    A(A &&) = default;
    A() : int_ptr(new int(10)) {cout << "无参构造----在堆内存申请的首地址为" << int_ptr << endl;}

    ~A() {
        cout << "析构函数调用" << endl;
        if (int_ptr != nullptr) {
            delete [] int_ptr;
        }
    }

};

//移动语义move
void test01() {
    int c = 5;
    int &&d = move(c);//左值转右值
    cout << d << endl;
    cout << c << endl;

    // A a;
    // A b = move(a);
    A b = move(A());
    cout << "新创建对象b的首地址" << b.int_ptr<< endl;
}
class B : public enable_shared_from_this<B> {
public:
    B() {
        cout << "gouzao" << endl;
    }
    ~B() {
        cout << "析构" << endl;
    }
    int a;  
    B(int arg) {
        cout << arg << "构造" << endl;
    }
    shared_ptr<B> getObjptr() {
        return shared_from_this();
    }
    void operator() () {
        cout << "仿函数调用" << endl;
    }
    static void test_fun02(int x){
        cout << "用于将类对象转化为函数指针\n";
    }
    void class_ptr_test(int x, string msg) {
        cout << "类的成员指针指向:class_ptr_test函数调用\n";
    }
    operator fun_ptr() { //将类对象转化为函数指针
        return B::test_fun02;
    }
};




//智能指针
void test02() {
    // shared_ptr<int> ptr1(new int);
    // cout << "地址:" << ptr1.get() << "的引用计数:" << ptr1.use_count()<< endl;
    // shared_ptr<int> ptr2 = ptr1;
    // cout << "地址:" << ptr1.get() << "的引用计数:" << ptr1.use_count()<< endl;
    // shared_ptr<int> ptr3 = move(ptr2);
    // cout << "地址:" << ptr1.get() << "的引用计数:" << ptr1.use_count()<< endl;
    // ptr3.reset(new int);
    // cout << "地址:" << ptr1.get() << "的引用计数:" << ptr1.use_count()<< endl;
   
    // cout << "地址:" << ptr3.get() << "的引用计数:" << ptr3.use_count()<< endl;
    // shared_ptr<B> b(new B); //自动调用析构
    // shared_ptr<B> b1 = make_shared<B>();
    // // shared_ptr<B> b2 = make_shared<B>();
    // cout << "-------------------------------------" << endl;
    // //shared_ptr<vector<B>> ptr4(new vector<B>(5));
    // shared_ptr<vector<B>> ptr5 = make_shared<vector<B>> (2);
    // cout << (ptr5).get() << endl;
    // cout << (*ptr5)[0].a << endl;
    // cout << &ptr5->emplace_back(123123) << endl;
    // cout << "-------------unique_ptr-------------------------------" << endl;
    
    // unique_ptr<B, function<void(B*)>> uptr(new B, [](B* b){
    //     printf("你好你好\n");
    //     delete b;
    // });
    // printf("addr:%p\n",uptr.get());
    // B *arr = new B[10]{1, 2, 3};
    // // uptr.reset(new B());
    // // printf("addr:%p\n",uptr.get());
    // unique_ptr<B, function<void(B*)>> uptr1 = move(uptr);
    
    // printf("addr:%p\n",uptr.get());
    // printf("移动构造:addr:%p\n",uptr1.get());
    
    // unique_ptr<vector<B>> uptr3(new vector<B> {1123,333,323432});
    /*  --- --- --------------weak_ptr------------------- */
    ;
    shared_ptr<B> ptr0(new B());
   
    shared_ptr<B> ptr = ptr0->getObjptr();
    cout << ptr.use_count() << endl;
 
}
void test_fun(int x) {
    cout << "函数指针调用成功\n";
}
//可调用对象
void test03() {
    //1,函数指针
   
    fun_ptr fun1 = test_fun;
    fun1(5);

    //2,仿函数
    B b;
    b();

    //3,可被转化为函数指针的类对象(静态成员函数)
    b(55555);
    
    //4,类的成员指针
    B d;
    using class_ptr_fun = void(B::*)(int, string); //类的成员函数指针
    class_ptr_fun f1 = B::class_ptr_test;
    (d.*f1)(1,"jj");

    using class_ptr_arg = int B::*;
    class_ptr_arg arg1 = &B::a;

    
}


int main() {
   
    //test01();//移动语义
    // test02();//智能指针
    test03();
    return 0;
}
