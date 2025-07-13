/*
purpose:
  1）演示通过静态成员变量构造每个对象唯一id_的方法；
  2）演示使用动态方法创建对象和静态方法创建对象的差异；
problem:
  1) 分析test_static_create()的输出，为什么析构和创建
  不匹配？为什么出现了两个一样id_值的对象？
  答：同下

  2) 分析test_dynamic_create的输出，为什么析构和创建
  不匹配？为什么删除了两个id_值一样的对象？
  答：在数组析构时，对象按照与创建相反的顺序被析构，而不是按照ID顺序。在sample类中，没有显式定义复制构造函数，所以编译器生成了一个默认的复制构造函数。默认的复制构造函数会执行成员变量的浅拷贝，包括id_变量。
  当执行sample B = A[0];时，发生了以下情况：
	默认复制构造函数被调用
	B的所有成员变量直接从A[0]复制过来，包括id_值
	因此B的id_与A[0]相同，都是1
	count值没有增加
	这导致了两个对象(A[0]和B)拥有相同的id_值1，这就是为什么最后析构B时显示的是~sample : 1而不是~sample : 4。

  3) test_static_create() 与 test_dynamic_create() 析构顺序差异分析
  答：1. 静态创建情况 (test_static_create())
在静态创建情况下：

数组 A 和变量 B 都是局部变量，在栈上创建
它们在同一作用域（函数内部）
C++ 标准规定：同一作用域内的局部变量析构顺序与创建顺序相反
创建顺序是：A[0]、A[1]、A[2]、B
所以预期析构顺序应该是：B、A[2]、A[1]、A[0]
但实际输出的析构顺序是：B、A[2]、A[1]、A[0]，符合预期，只是由于 B 复制了 A[0] 的 ID 值（都是1），所以看起来像是另一种顺序。

2. 动态创建情况 (test_dynamic_create())
在动态创建情况下：

数组 A 是在堆上动态分配的
变量 B 是栈上的局部变量
delete[] A 会主动释放 A 数组中的对象
而 B 会在函数结束时由于离开作用域自动析构
执行顺序：

首先执行 delete[] A，释放 A[2]、A[1]、A[0]（数组析构是从后向前）
然后函数结束，B 离开作用域自动析构
这就导致了输出顺序：A[2]、A[1]、A[0]、B。
*/

#include <iostream>
using namespace std;

class sample{
public:
	sample(){
		count_++; 
		id_=count_;
		std::cout << "sample : "<<id_ << "\n";}
	~sample(){ 
		std::cout << " ~sample : " << id_ << "\n";
	}
	//new
	// sample(const sample& other) {
    // count_++;
    // id_ = count_;  // 分配新ID
    // x_ = other.x_; // 复制其他成员
    // std::cout << "sample(copy) : " << id_ << "\n";
	// }

	void setx(int i){x_=i;}
	int getx(){return x_;}
	int getid(){return id_;}
	int getcount(){return count_;}
private:
	int x_;
	int id_;
	static int count_;
};

int sample::count_ = 0;


void test_dynamic_create(){
	const int N = 3;
	sample* A =new sample[N]; //动态创建 必须手动释放内存，否则会导致内存泄漏
	//sample A[3];			  //静态创建
	for(int j=0;j<N;j++)
		A[j].setx(5+j);
	
	sample B=A[0];
	B.setx(8);
	cout << "B x: " << B.getx() << "B id:" << B.getid() << endl; // 输出B的x值
	cout << "B count: " << B.getcount() << endl; // 输出B的count值
	cout << "A0 count: " << A[0].getcount() << endl; // 输出A[0]的count值
	cout << "A2 count: " << A[2].getcount() << endl; // 输出A[2]的count值

	for(int j=0;j<N;j++){
		sample *p = &A[j];
		cout << p->getx() << "  ";
	}
	cout << endl;	
	delete[] A;		//正确：删除了以A为首地址的一组对象。
	//delete A;		//错误：只删除了A[0]对象
}

void test_static_create(){
	const int N = 3;
	//sample* A =new sample[N]; //动态创建
	sample A[3];			  //静态创建 创建了一个静态数组，它在栈上分配内存
	for(int j=0;j<N;j++)
		A[j].setx(5+j);
	
	sample B=A[0];
	B.setx(8);
	cout << "B x: " << B.getx() << "B id:" << B.getid() << endl; // 输出B的x值
	cout << "B count: " << B.getcount() << endl; // 输出B的count值
	cout << "A0 count: " << A[0].getcount() << endl; // 输出A[0]的count值
	cout << "A2 count: " << A[2].getcount() << endl; // 输出A[2]的count值
	
	for(int j=0;j<N;j++){
		sample *p = &A[j];
		cout << p->getx() << "  ";
	}
	cout << endl;		
	//delete[] A; //delete[]运算符只应该用于删除动态分配（使用new[]创建）的数组，对栈上分配的对象使用delete[]是未定义行为，可能导致程序崩溃
	//delete A;
	//正确：不需要手动删除A，因为它是静态分配的，生命周期由作用域决定。
	//当函数返回时，A数组的内存会自动释放。
}

int main() { 
	test_dynamic_create();
	//test_static_create();
	return 0;
} 