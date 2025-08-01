#include <iostream>
using namespace std;
class Animal {
public:
    int a = 5;
    string str = "nihao";
    Animal() {
        cout << "父类animal的无参构造调用" << endl;
    }

    ~Animal() {
        cout << "父类animal的析构函数调用" << endl;
    }

    // void dog_fun() {
    //     cout << "父亲的成员函数调用" << endl;
    // }
    // void dog_fun(int a) {
    //     cout << "父亲的成员函数调用" << a << endl;
    // }
    virtual void speak() {
        cout << "动物说话" << endl;
    }
};

class Dog : public Animal {
public:
    int a = 777;

    Dog() {
         cout << "子类Dog的无参构造调用" << endl;
    }

    ~Dog() {
        cout << "子类Dog的析构函数调用" << endl;
    }
    void speak() {
        cout << "小狗说话" << endl;
    }

};

void test(Animal &animal) {
    animal.speak();
}
int main() {
    
    Dog dog;
    // cout << sizeof(dog) << sizeof(Animal) << endl;
    // cout << dog.a << dog.str << endl;
    test(dog);
    
    // dog.dog_fun();
    // dog.Animal::dog_fun(100000);
    return 0;
}

