#include <iostream>

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
    
    A(){}
  	A(const A &a) { //拷贝构造函数
        age = a.age;
    }  
    
};

int main() {
    //new test
    //Test(100);
   // test(100,100);
   //fun1(10, 11111);
    // A* arg = new A(100);
    // cout << arg->a << endl;
    // delete(arg);
      A a;
    a.age = 6;
    A b(a);
    cout << b.age << endl;
  
    return 0;
    return 0;
}

