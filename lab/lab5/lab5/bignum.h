#pragma once

#include <iostream>
#include <string>

namespace EXP5 {
class Bignum {
   public:
    Bignum(std::string s);
    Bignum(long v = 0);

   public:
    void assign(long v);
    void assign(std::string s);

   public:
    char sign() const {
        return sign_;
    }
    char& sign() {
        return sign_;
    }
    std::string value() const {
        return value_;
    }
    std::string& value() {
        return value_;
    }
    size_t size() const{ //保护成员变量不被修改
        return 1 + value_.size();
    }

   private:
    char sign_;  // 0 for +, 1 for -
    std::string value_;
};

std::ostream& operator<<(std::ostream& os, const Bignum& num); //num对象是只读的常量引用，防止引用修改
std::istream& operator>>(std::istream& is, Bignum& num);

Bignum operator+(Bignum const& left, Bignum const& right);
Bignum operator-(Bignum const& left, Bignum const& right);
Bignum operator*(Bignum const& left, Bignum const& right);
Bignum operator/(Bignum const& left, Bignum const& right);


inline namespace literals
{
    Bignum operator""_bn(const char* num,std::size_t); //添加std::size_t参数，以严格遵循C++标准定义自定义字面量运算符
}

}  // namespace EXP5