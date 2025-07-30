#include <iostream>
#include <string.h>
using namespace std;
/**
 * 测试引用和new
 * 
 */
void Test(int a, int c = 2, int d = 4) {
    int *p = new int (10);
    int *p_arr = new int[5]{1, 5, 2, 3, 4};  
    int *tmp = p_arr;
    int *&b = p;
    cout << &b << endl;
    // for (int i = 0; i < 5; i++) {
    //    cout << *tmp++ << endl;
    // }
    delete p;
    delete [] p_arr;
    cout << a + d + c << endl;
}

//test(100,100)
void test(int a, int b = 2, int c =5) {
    cout << a + b + c << endl;
}
void fun(int a = 10);	//正确
void fun(int a) {	
   	cout <<  a + 5 << endl;
}

void fun1(int a, int) {
    //
}

class A {
    public:
    int age;
    A(int age) : age(age){
       
    }
    A(){}
  	// A(const A &a) { //拷贝构造函数
    //     age = a.age;
    // }  

    
};

class Student {
public:
    string name;
public:
    static int age;
public:
    static int getAge() {
        int tmp = age;
        return tmp;
    }
private:
    Student& get_this() {
        cout << this << sizeof(this) << endl;
        return *this;
    }

};
int Student::age = 5;
class B {
    /*常函数不能修改成员变量*/
    void fun() const { /* this 指针本质是 B *const this 如果函数参数后加const，那么就变成const B *const this*/
        
    }
};

























class Gay;
class Gay {
public:
    void Gay_fun1();
};
class Friend_Test;
class Friend_Test {
public:   
    friend void Gay::Gay_fun1();
    friend void frient_fun();
    string str;
private:
    int a;
    int b;
};


void Gay::Gay_fun1() {
        Friend_Test ft;
        cout << ft.a << endl;
        cout << ft.b << endl;
        cout << ft.str << endl;
    }




void frient_fun() {
    Friend_Test ft;
    cout << ft.a << endl;
    cout << ft.b << endl;
    cout << ft.str << endl;
}



int main() {
    //new test
    //Test(100);
   // test(100,100);
   //fun1(10, 11111);
    // A* arg = new A(100);
    // cout << arg->a << endl;
    // delete(arg);
    // int arr[10];
    // char *arr1[10];
    // char *arr2;
    // cout << sizeof(arr) << endl;
    // cout << sizeof(arr1) <<endl;
    // cout << sizeof(arr2) << endl;
    // A a(5);
    // A b(a);
    // cout << b.age << endl;
    //test03();
    // Student s;
    // cout << " " << sizeof(Student) << endl;
    // Student a;
    // Student b;
    // Student c;
    //a.get_this().get_this().get_this().get_this();
    // int a;
    // int &b = a;
    // cout << &a << endl;
    // cout << &b << endl;
    // Student *student = NULL;
    // string name = "jjjjj";
    // student->name = name;
    // student = new Student();
    // cout << student->name <<endl;
    // Student s;
    // cout << Student::age << endl; //可以直接用类名访问
    // cout << s.age << endl;
    // B b;
    // cout << sizeof(b) << endl;
    
    return EXIT_SUCCESS;
}

