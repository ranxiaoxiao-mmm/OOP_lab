#include <iostream>
#include <vector>
#include <cmath>
#include <string>

//定义全局变量
int l = 1000;
bool is_prime;
int* primes;
int cnt = 0;
int b = 5;

//初始化primes数组
void initialize(int* &primes, int &cnt) {
    primes = new int[l];
    primes[cnt++] = 2;
}

//判断是否为质数
bool isprime(int no, int* primes) {
    for (int primecount=0; primes[primecount] <= std::sqrt(no); ++primecount) {
        if (no % primes[primecount] == 0) {
            return false;
        } 
    }
    return true;
}

//计算数字位数
int countDigits(int num) {
    std::string str = std::to_string(num);  
    return str.size();                    
}

//打印质数
void print_primes(bool is_prime, int no, int* &primes, int &cnt, int b) {
    if (is_prime) {
        if(cnt%b == 1 && cnt != 1){
            std::cout << '\n';
        }
        int space = 3-countDigits(no);
        const std::string s(space, ' ');
        std::cout << no << s << ' ';
        primes[cnt++] = no;
    }
}


//主函数
int main()
{
    initialize(primes, cnt);
    for (int no = 3; no < l; no += 2) {
        is_prime = isprime(no, primes);
        print_primes(is_prime, no, primes, cnt, b);
    }
    std::cout << "\n";
}