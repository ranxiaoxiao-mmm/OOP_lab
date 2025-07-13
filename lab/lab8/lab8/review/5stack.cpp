/*
purpose: 1)演示模板类的书写方法；2）演示转换操作的书写
方法“operator()()”；3）重载操作符<<（流输出操作符）的
正确书写方法。
problem: 仔细阅读operator<<的实现，输出之后，改变了top_
的值，这个行为是不当的。如何保证输出之后，top_的值保持
不变？
答：使用const参数和临时复制
*/

#include <iostream>
using namespace std;

template<class T>
class Stack{
public:
	Stack(int n):size_(n),top_(n){ 
		space_ = new T[n];
	};
	~Stack(){ 
		delete [] space_;
	}
	void push(T t){
		if(!isfull()) space_[--top_] = t;
	}
	friend ostream& operator<<(ostream& out, Stack & st){
		while(!(st.operator()())){
			out << st.space_[st.top_++] << "\n";
		}
		return out;
	}

	// friend ostream& operator<<(ostream& out, const Stack & st){
    // 		Stack temp = st;  // 创建临时副本
    // 		while(!(temp.operator()())){
    //     		out << temp.space_[temp.top_++] << "\n";
    // }
    // 		return out;
	// }

	bool operator()() const{
		return top_ == size_;
	}
	
	bool isfull() const{
		return top_==0;
	}
private:
	int size_;
	int top_;
	T* space_;
};


int main() { 
	Stack<int> s(20);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	
	cout << s;
	return 0;
} 