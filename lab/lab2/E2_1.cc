// Author: Vincent Wang
// Date  : 2025/3/12
// Purpose:
//	理解函数重载(overload)的含义和相关规则


#include <iostream>
#include <iomanip>

using namespace std;

//float reckon(int a, float b){
//   cout << "\n" <<__FUNCTION__ << " @ line " << __LINE__ << "\n";
//   return (a+b)/4;
//}

//float reckon(float b, int a){
//   cout << "\n" <<__FUNCTION__ << " @ line " << __LINE__ << "\n";
//   return (a+b)/3;
//}

float reckon(float a, float b){
   cout << "\n" <<__FUNCTION__ << " @ line " << __LINE__ << "\n";
   return (a+b) /2;
}


int main(){
   cout << reckon(3.0f,4) << "  " << reckon(3,4.0f) << "   " << reckon(3.0f,4.0f)<< endl;

   return 0;
}