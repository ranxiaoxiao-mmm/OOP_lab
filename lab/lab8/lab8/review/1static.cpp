/*
purpose:演示类的静态成员（函数和变量）的申明、定义，以及
使用规则。
*/

#include <iostream>
using namespace std;  

class csample { 
public:       
	csample(); 
	void display(); 
	static void report(); //类的静态成员函数
public:
	static int count_;  //类的静态成员变量的申明(不分配内存！)
private:       
	int i;      
};  

//类的静态成员变量的初始化（或者说是类的静态成员变量的定义）
int csample::count_=0; 

csample::csample():i(0){
	count_++;
}  

void csample::display(){
	cout << "i = " << i ;
	cout << " count = "<< count_ <<"\n"; //正确：非静态成员函数中可以使用静态成员变量
	report();							 //正确：非静态成员函数中可以调用静态成员函数
} 

void csample::report(){
	cout << " count = " <<count_<<"\n";
	// cout << " i = " << i; //错误：静态成员函数中不能使用非静态成员变量
	// display(); 			 //错误：静态成员函数中不能调用非静态成员函数
}


int main()  { 
	csample a,b; 
	a.display(); 
	b.display(); 
	a.report();  			//正确：可以通过对象名.形式调用静态成员函数
	csample::report();  	//正确：可以通过类名::形式调用静态成员函数
	//csample::display();   	//错误：不能通过类名::形式调用非静态成员函数
	return 0;
} 