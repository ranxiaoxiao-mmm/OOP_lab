/*
purpose: 演示类的正确书写方法，包括构造函数（默认构造函数），操作符
重载。
problem: 
  1）days数组只在date中使用，更确切地说只在操作符+中出现，按照OOP的
  理念（信息隐藏），需要把days放在date中，如何放置比较好？
 答：作为静态私有成员变量（推荐）。这是最佳选择，因为days数组对所有date对象都是相同的，不需要每个对象都保存一份副本：
    或者使用私有静态方法获取，或作为类内常量数组

  2）如何重载操作符<<，使得程序支持 cout << d2形式的调用，而不用使用
  d2.display()形式？
  答：1. 使用友元函数（推荐），这种方式允许函数访问类的私有成员
  2. 使用公有成员函数。可以添加一个公有的getter方法，然后在全局重载函数中使用

*/

#include <iostream>
using namespace std;

static int days[] = {31,28,31,30,31,30,31,31,30,31,30,31,30,31};

class date{
public:
	date(int m, int d, int y): mo(m),da(d),yr(y){}
	date() {}
	void display(){cout << yr << "/"<< mo <<"/"<< da << "\n";}
	// 声明为友元函数
    friend ostream& operator<<(ostream& os, const date& dt);
	date operator+(int day){
		date dt = *this;
		day+=dt.da;
		while(day>days[dt.mo-1]){
			day-=days[dt.mo-1];
			if(++dt.mo==13){
				dt.mo=1;
				dt.yr++;
			}
		}
		dt.da = day;
		return dt;
	}

	// 添加获取日期组件的方法，全局重载函数
    // int getMonth() const { return mo; }
    // int getDay() const { return da; }
    // int getYear() const { return yr; }

private :
	int mo,da,yr;
};

// 在类外定义友元函数
ostream& operator<<(ostream& os, const date& dt) {
    os << dt.yr << "/" << dt.mo << "/" << dt.da;
    return os;
}

// 全局重载函数
// ostream& operator<<(ostream& os, const date& dt) {
//     os << dt.getYear() << "/" << dt.getMonth() << "/" << dt.getDay();
//     return os;
// }

int main() { 
	date d1(12,20,2001),d2;
	d2 = d1 + 20;
	d2.display();
	// 使用友元函数输出
	cout << d2 << "\n"; // 使用重载的<<操作符输出日期
	return 0;
} 