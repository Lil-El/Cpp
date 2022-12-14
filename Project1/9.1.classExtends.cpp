#include<iostream>
#include<cassert>
using namespace std;

class Shape_9_1 {
private:
	char type[10];
protected:
	float width;
	float height;

public:
	Shape_9_1() {}

	void setWidth(float w) {
		width = w;
	};
	void setWidth() {
		width = 100;
	};
	void setHeigth(float h) {
		height = h;
	};
} s1, s2;

/*
	同一个类中：可以访问public、private、protected成员
	子类，可以访问父类的public、protected成员
	外部类，可以访问public
*/
/*
继承方式：
	public：父类的public就是子类的public，protected就是子类的protected，private不能访问
	protected：父类的public、protected成员是子类的protected成员
	private：父类的public、protected成员是子类的private成员
*/
// 继承不会继承父类的构造函数、拷贝构造函数、友元函数、重载运算符
// 多继承：clss Rectangle_9_1: public Shape_9_1, public classB, protected classC {}
class Rectangle_9_1 : public Shape_9_1 {
public:
	float getArea() {
		return width * height;
	}
};

class : public Shape_9_1 {
public:
	float getArea() {
		return width * height;
	}
} circle;

// 继承方式private，父级的public、protected变为private
// 使用using可以重新声明访问权限
// 使用using可以直接重载父级的对应的全部版本的函数
class myShape : private Shape_9_1 {
public:
	using Shape_9_1::width;
	using Shape_9_1::setWidth;
protected:
	using Shape_9_1::height;
};

#define Q_PROPERTY(arg) static_assert(static_cast<bool>("Q_PROPERTY"), #arg);

void extend_main() {
	Rectangle_9_1 rect;
	// 静态断言 -> Shape_9_1是否是另一个的基类
	cout << is_base_of<Shape_9_1, Rectangle_9_1>::value << endl;
	assert(sizeof(1) == sizeof(int));
	static_assert(is_base_of<Shape_9_1, Rectangle_9_1>::value, "template params MUST be Point!");
	Q_PROPERTY(1);
	cout << "判断一个实例是否继承自某个类：" << boolalpha << (typeid(s1) == typeid(Shape_9_1)) << endl;
	rect.setWidth(10);
	rect.setHeigth(10);
	cout << "Area is: " << rect.getArea() << endl;
	cout << "circle Area is: " << circle.getArea() << endl;
}