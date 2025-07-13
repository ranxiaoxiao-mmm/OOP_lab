#include "bignum.h"

#include <algorithm>

namespace EXP5 {
Bignum::Bignum(std::string s) {
    assign(s);
}

// 初始化 string 类型输入，赋值并确定符号位
void Bignum::assign(std::string s) {
    if (s.size() == 0) {
        assign(0);
        return;
    };

    sign_ = s[0] == '-' ? 1 : 0;
    if (s[0] == '-' || s[0] == '+') { s = s.substr(1); }
    if (s.size() == 0) {
        assign(0);
        return;
    }
    value_ = s;
}

Bignum::Bignum(long v) {
    assign(v);
}

// 初始化 long 类型输入
void Bignum::assign(long v) {
    sign_ = v >= 0 ? 0 : 1;
    value_ = std::to_string(std::abs(v));
}

// cout
std::ostream& operator<<(std::ostream& os, Bignum& num) {
    num.sign() == 1 ? (os << '-') : (os << '+');
    for (auto const& ch : num.value()) os << ch;
    return os;
}

// cin
std::istream& operator>>(std::istream& is, Bignum& num) {
    std::string value;
    is >> value;
    num.assign(value);

    return is;
}

// Normalize: remove leading zeros and normalize the number
static void normalize(Bignum& num) {
    std::string& val = num.value();
    // Remove leading zeros
    val.erase(0, val.find_first_not_of('0'));
    if (val.empty()) {
        val = "0";
        num.sign() = 0;  // Zero is always positive
    }
}

// Helper function to compare absolute values (|left| > |right|)
static bool absGreater(const std::string& left, const std::string& right) {
    if (left.size() != right.size()) { return left.size() > right.size(); }
    return left > right;
}

// string 加
static std::string addStrings(const std::string& a, const std::string& b) {
    std::string result;

    // TODO: implement the method
    int carry = 0;
    int i = a.empty() ? -1 : static_cast<int>(a.size()) - 1;
    int j = b.empty() ? -1 : static_cast<int>(b.size()) - 1;

    while (i >= 0 || j >= 0) {
        int digitA = i >= 0 ? a[i--] - '0' : 0;
        int digitB = j >= 0 ? b[j--] - '0' : 0;
        digitA += carry;
        if (digitA + digitB > 9) {
            digitA -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result.push_back((digitA + digitB) + '0');
    }

    std::reverse(result.begin(), result.end());

    return result;
}

// string 减
static std::string subStrings(const std::string& a, const std::string& b) {
    std::string result;
    int borrow = 0;
    int i = a.empty() ? -1 : static_cast<int>(a.size()) - 1;
    int j = b.empty() ? -1 : static_cast<int>(b.size()) - 1;

    while (i >= 0 || j >= 0) {
        int digitA = i >= 0 ? a[i--] - '0' : 0;
        int digitB = j >= 0 ? b[j--] - '0' : 0;
        digitA -= borrow;
        if (digitA < digitB) {
            digitA += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back((digitA - digitB) + '0');
    }

    std::reverse(result.begin(), result.end());
    return result;
}

static void normalizeString(std::string& s) {
    s.erase(0, s.find_first_not_of('0'));
    if (s.empty()) s = "0";
}

// string 乘
static std::string mulStrings(const std::string& a, const std::string& b) {
    if (a == "0" || b == "0") return "0";

    std::string result(a.size() + b.size(), '0');

    // TODO: implement the method
    for (int i = a.size() - 1; i >= 0; --i) {
        int carry = 0;
        int digitA = a[i] - '0';
        std::string mul_res;

        // 计算 a 的一位和 b 的乘积，将结果存入 mul_res
        for (int j = b.size() - 1; j >= 0; --j) {
            int digitB = b[j] - '0';
            int mul_res_1digit = digitA * digitB;
            mul_res_1digit += carry;
            // std::cout << mul_res_1digit << std::endl;
            if (mul_res_1digit > 9) {
                carry = mul_res_1digit / 10;
                mul_res_1digit %= 10;
            } else {
                carry = 0;
            }
            mul_res.push_back(mul_res_1digit + '0');
            // std::cout << mul_res << std::endl;
        }

        // 处理最高位进位
        if (carry != 0) {
            mul_res.push_back(carry + '0');
        }

        std::reverse(mul_res.begin(), mul_res.end());

        // 给 mul_res 末位补 0
        for (int k = a.size() - 1 - i; k > 0; --k) {
            mul_res.push_back('0');
        }
        // std::cout << mul_res << std::endl;

        result = addStrings(result, mul_res);
    }

    normalizeString(result);
    // std::cout << result << std::endl;

    return result;
}

static char divStep(std::string& current, const std::string& divisor) {
    char quotient_digit = 0;
    while (absGreater(current, divisor) || current == divisor) {
        current = subStrings(current, divisor);
        current.erase(0, current.find_first_not_of('0'));  // Remove leading zeros
        if (current.empty()) current = "0";
        quotient_digit++;
    }
    return quotient_digit;
}

static std::string divStrings(const std::string& dividend, const std::string& divisor) {
    if (!absGreater(dividend, divisor) && dividend != divisor) { return "0"; }

    std::string quotient;
    std::string current;
    size_t dividend_idx = 0;

    // Build initial current
    while (dividend_idx < dividend.size() &&
           (current.size() < divisor.size() || !absGreater(current, divisor))) {
        current.push_back(dividend[dividend_idx++]);
        current.erase(0, current.find_first_not_of('0'));
        if (current.empty()) current = "0";
    }

    // Main division loop
    while (dividend_idx <= dividend.size()) {
        char q_digit = divStep(current, divisor) + '0';
        quotient.push_back(q_digit);

        // Append next digit if available
        if (dividend_idx >= dividend.size()) break;

        current.push_back(dividend[dividend_idx++]);
        current.erase(0, current.find_first_not_of('0'));
        if (current.empty()) current = "0";
    }

    return quotient.empty() ? "0" : quotient;
}

// Addition operator
Bignum operator+(const Bignum& left, const Bignum& right) {
    Bignum result;
    const std::string& lval = left.value();
    const std::string& rval = right.value();
    char lsign = left.sign();
    char rsign = right.sign();

    if (lsign == rsign) {
        result.value() = addStrings(lval, rval);
        result.sign() = lsign;
    } else {  // negative+positive or positive+nagetive
        if (absGreater(lval, rval)) {
            result.value() = subStrings(lval, rval);
            result.sign() = lsign;
        } else {
            result.value() = subStrings(rval, lval);
            result.sign() = rsign;
        }
    }

    normalize(result);
    return result;
}

// Subtraction operator
Bignum operator-(const Bignum& left, const Bignum& right) {
    Bignum result;

    // TODO: implement the method
    const std::string& lval = left.value();
    const std::string& rval = right.value();
    char lsign = left.sign();
    char rsign = right.sign();

    if (lsign == rsign) {
        if (absGreater(lval, rval)) {
            result.value() = subStrings(lval, rval);
            result.sign() = lsign;
        } else if (lval == rval) {
            result.value() = '0';
            result.sign() = 0;
        } else {
            result.value() = subStrings(rval, lval);
            result.sign() = ~lsign;
        }
    } else {
        result.value() = addStrings(lval, rval);
        result.sign() = lsign;
    }

    normalize(result);

    return result;
}

// Multiplication operator
Bignum operator*(const Bignum& left, const Bignum& right) {
    Bignum result;

    // TODO: implement the method
    // std::cout << "In operator *" << std::endl;
    result.value() = mulStrings(left.value(), right.value());
    result.sign() = left.sign() ^ right.sign();
    normalize(result);
    
    return result;
}

// Division operator
Bignum operator/(const Bignum& left, const Bignum& right) {
    // Check for division by zero
    if (right.value() == "0") { throw std::runtime_error("Division by zero"); }

    Bignum result;
    const std::string& dividend = left.value();
    const std::string& divisor = right.value();

    // Handle zero dividend
    if ((dividend == "0") || (!absGreater(dividend, divisor) && dividend != divisor)) {
        result.value() = "0";
        result.sign() = 0;
        return result;
    }

    // Perform division on absolute values
    result.sign() = left.sign() ^ right.sign();
    result.value() = divStrings(left.value(), right.value());

    // Finalize quotient
    normalize(result);
    return result;
}

inline namespace literals
{
    Bignum operator"" _bn(const char* num, std::size_t)
    {
    // TODO: implement the method
        if (num == nullptr || *num == '\0')
        {
            return Bignum();
        }
        return Bignum(std::string(num));
    }

}

}  // namespace EXP5