#include <iostream>
#include <locale>
using namespace std;

void dataType_main() {

	// 数据类型
	bool isOk = false; // 1字节
	int age = 25; // 4字节 使用=定义
	int age1(25); // 使用()定义
	int age1_1{ 25 }; // 使用{}定义
	int age1_1_1 = {25};
	// 类型收窄其实就是新类型不可以表示原来类型的情况，在类型转换的过程中数据丢失。
	int g = 2.0f;
	//int g2{ 2.0f }; 使用{}初始化，可以防止类型收窄
	int num11[]{ 1997, 11 }; // C++11特性，可以省略=号
	float size = 13.3; // 4字节
	double peopel = 14.44; // 8字节
	__int8 i8 = 97;
	__int32 i32 = 12;
	cout << i8 << endl;
	cout << static_cast<int>(i32) << endl; // TODO: 类型转换 https://blog.csdn.net/liranke/article/details/5295133

	// ''单引号是字符，""双引号是字符串
	char str[] = "ABB";
	char rec[9] = "hello";

	// 两个都是字符数组，只有第二个是字符串; 在不给定长度时可以看出两者的区别（string.cpp）
	char rec1[9]{ 'h', 'i', 'k' }; // 字符数组
	char rec2[9]{ 'h', 'i', 'k', '\0' }; // 字符数组-字符串
	wchar_t wc = L'你'; // _T() 同等于 L (string.cpp)  单引号是字符
	setlocale(LC_ALL, "chs");

	// 常量
	const int age3 = 11;
	#define MAX_AGE 12

	// 枚举
	enum OBJ {
		name,
		age2 = 100,
		sex
	} obj;

	// 修饰符
	unsigned int us_age = 10; // 无符号4字节
	signed int si_age = 10; // 有符号4字节
	short int s_age = 10; // 2字节
	long int l_age = 10; // 8字节
	unsigned long long ll_age = 10;
	signed long int sli_age = 10; // 8
	float f_age = (float)age; // 强制类型转换
	float f_age1 = float(age); // 强制类型转换 C11: 为了像函数一样

	cout << "sizeof ll_age is:" << sizeof(ll_age) << endl;

	obj = name;
	cout << obj << endl;
	OBJ obj2 = age2;
	cout << obj2 << endl;
	cout << name << age2 << sex << endl;

	typedef OBJ myEnum;
	myEnum my_enum = sex;
	cout << "my_enum:" << my_enum << endl;

	using mInt = int;
	mInt mIAge = 31;
	cout << "mIAge: " << mIAge << endl;

	// 常量 static存储类
	age = 22;
	const static int myAge = 18; // static变量，多个函数直接共享一个值；用于class成员时，所以class对象都共享一个对象

	/*
	* 存储期：
	* auto（11以前可用，11之后不可用），register（17废弃）
	* static：静态或者 "线程存储期" 的内部链接
	* extern：静态或者线程存储期的外部链接
	* thread_local：线程存储期 - https://zhuanlan.zhihu.com/p/340201634
	*				对象的存储在线程开始时分配，而在线程结束时解分配。每个线程拥有其自身的对象实例
	*/

	return ;
}