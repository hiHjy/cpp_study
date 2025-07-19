# 基础语法

## new

> **类似malloc，在堆区开辟一块空间，返回指针**

```c++
int *p = new int(10);	
int *p_arr = new int[10];
int *p_arr1 = new int [3]{1, 2, 3};

delete p;
delete [] p_arr;
delete [] p_arr1;
```

## 引用&

> **给变量起别名**

```c++
int b = 10;
int &a = b; //a是b的别名， 别名一旦初始化，无法更改
int &c;  	//错误！！引用必须初始化
		 	
```

> **引用的本质**

```c++
int a = 10;

int &ref = a;		// 自动转换为int * const ref = a;所以指针的指向不可改变
ref = 20; 			//内部发现是引用，自动转换为：*ref = 20;
```

> 常量引用 

```C++
void int(const int a, const int b){...} //因为形参为引用，所以加const防止实参被修改
```

