#include "bignum.h"

#include <algorithm>

namespace EXP5 {
Bignum::Bignum(std::string s) {
    assign(s);
}
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

void Bignum::assign(long v) {
    sign_ = v >= 0 ? 0 : 1;
    value_ = std::to_string(std::abs(v));
}

std::ostream& operator<<(std::ostream& os, const Bignum& num) {
    num.sign() == 1 ? (os << '-') : (os << '+');
    for (auto const& ch : num.value()) os << ch;
    return os;
}

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

static std::string addStrings(const std::string& a, const std::string& b) {
    std::string result;
    // TODO: implement the method
    int carry = 0;
    int i = a.empty() ? -1 : static_cast<int>(a.size()) - 1;
    int j = b.empty() ? -1 : static_cast<int>(b.size()) - 1;

    while (i >= 0 || j >= 0 || carry) {
        int digitA = i >= 0 ? a[i--] - '0' : 0;
        int digitB = j >= 0 ? b[j--] - '0' : 0;
        int sum = digitA + digitB + carry;
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    std::reverse(result.begin(), result.end());

    return result;
}

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

static std::string mulStrings(const std::string& a, const std::string& b) {
    if (a == "0" || b == "0") return "0";

    std::string result(a.size() + b.size(), '0');
    // TODO: implement the method

    for (int i = a.size() - 1; i >= 0; --i) {
        int carry = 0;
        for (int j = b.size() - 1; j >= 0; --j) {
            int mul = (a[i] - '0') * (b[j] - '0') + carry + (result[i + j + 1] - '0');
            carry = mul / 10;
            result[i + j + 1] = (mul % 10) + '0';
        }
        result[i] += carry;
    }

    // Normalize the result
    size_t pos = result.find_first_not_of('0');
    if (pos != std::string::npos) {
        result = result.substr(pos);
    } else {
        result = "0";  //all 0
    }


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
        } else {
            result.value() = subStrings(rval, lval);
            result.sign() = rsign ^ 1;  // change sign
        }
    } else {  // negative-positive or positive-nagetive
        result.value() = addStrings(lval, rval);
        result.sign() = lsign;
    }

    // Normalize the result
    normalize(result);

    return result;
}

// Multiplication operator
Bignum operator*(const Bignum& left, const Bignum& right) {
    Bignum result;
    // TODO: implement the method

    const std::string& lval = left.value();
    const std::string& rval = right.value();
    char lsign = left.sign();
    char rsign = right.sign();
    result.sign() = lsign ^ rsign;  // pos*pos=0, neg*neg=0, pos*neg=1
    result.value() = mulStrings(lval, rval);

    // Normalize the result
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
    Bignum operator"" _bn(const char* num,std::size_t)
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