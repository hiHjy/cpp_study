#include <iostream>

using namespace std;
/**
 * 测试引用和new
 * 
 */
void New_Test() {
    int *p = new int (10);
    int *p_arr = new int[5]{1, 5, 2, 3, 4};  
    int *tmp = p_arr;
    int *&b = p;
    cout << *b << endl;
    for (int i = 0; i < 5; i++) {
       cout << *tmp++ << endl;
    }
    delete p;
    delete [] p_arr;
}



int main() {
    //new test
    New_Test();
    
    return 0;
}

