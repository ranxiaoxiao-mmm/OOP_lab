/*
purpose:演示多重继承下的函数可见性
特别注意：类C中对类B的继承方式private。
详细的描述参见 “修正-可见性列表”
*/

#include <iostream>
using namespace std;

class A{
public:
	void seta(int x){a=x;}
	void showa(){cout<<a<<endl;}
private:
	int a;
};

class B{
public:
	void setb(int x){b=x;}
	void showb(){cout<<b<<endl;}
private:
	int b;
};

class C:public A, private B{
public:
	void setc(int x,int y,int z){
		c=z;
		seta(x); //公有继承A，方法seta在class C中的访问标识为“public”
		setb(y); //私有继承B，方法setb在class C中的访问标识为“private”，可以调用
		//b=y; 	 //错误：b在类B中为private，已经被隐藏--不可见。
		//a=x;	 //错误：a在类A中为private，已经被隐藏--不可见。	
	} 
	void showc(){cout<<c<<endl;} 
private:
	int c;
};

int main() { 
	C c;        
	c.seta(1);
	c.showa();
	c.setc(1,2,3);
	c.showc();

	return 0;
} 