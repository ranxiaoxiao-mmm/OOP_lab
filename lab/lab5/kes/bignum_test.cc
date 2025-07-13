#include "minitest.h"

#include "bignum.h"

using namespace EXP5;

std::pair<Bignum, Bignum> Get() {
    auto a = "2341341293479123479123749123794"_bn;
    auto b = "123947913749132749213491239414"_bn;
    return {a, b};
}

// 不同符号的 Get 实现
std::pair<Bignum, Bignum> Get_posi_nega() {
    auto a = "2341341293479123479123749123794"_bn;
    auto b = "-123947913749132749213491239414"_bn;
    return {a, b};
}

std::pair<Bignum, Bignum> Get_nega_posi() {
    auto a = "-2341341293479123479123749123794"_bn;
    auto b = "123947913749132749213491239414"_bn;
    return {a, b};
}

std::pair<Bignum, Bignum> Get_nega_nega() {
    auto a = "-2341341293479123479123749123794"_bn;
    auto b = "-123947913749132749213491239414"_bn;
    return {a, b};
}

TEST(Bignum, create_zero) {
    auto num = "0"_bn;
    ASSERT_EQ(num.sign(), 0);
    ASSERT_EQ(num.value(), "0");
}

TEST(Bignum, assign_normal) {
    Bignum num;
    num.assign("123");

    ASSERT_EQ(num.sign(), 0);
    ASSERT_EQ(num.value(), "123");
}

TEST(Bignum, add_normal) {
    auto [a, b] = Get();
    Bignum c = a + b;

    ASSERT_EQ(c.sign(), 0);
    ASSERT_EQ(c.value(), "2465289207228256228337240363208");
}

// 不同符号的 add
TEST(Bignum, add_posi_nega) {
    auto [a, b] = Get_posi_nega();
    Bignum c = a + b;

    ASSERT_EQ(c.sign(), 0);
    ASSERT_EQ(c.value(), "2217393379729990729910257884380");
}

TEST(Bignum, add_nega_posi) {
    auto [a, b] = Get_nega_posi();
    Bignum c = a + b;

    ASSERT_EQ(c.sign(), 1);
    ASSERT_EQ(c.value(), "2217393379729990729910257884380");
}

TEST(Bignum, add_nega_nega) {
    auto [a, b] = Get_nega_nega();
    Bignum c = a + b;

    ASSERT_EQ(c.sign(), 1);
    ASSERT_EQ(c.value(), "2465289207228256228337240363208");
}

TEST(Bignum, sub_normal) {
    auto [a, b] = Get();
    Bignum c = a - b;

    ASSERT_EQ(c.sign(), 0);
    ASSERT_EQ(c.value(), "2217393379729990729910257884380");
}

// 不同符号的 sub
TEST(Bignum, sub_posi_nega) {
    auto [a, b] = Get_posi_nega();
    Bignum c = a - b;

    ASSERT_EQ(c.sign(), 0);
    ASSERT_EQ(c.value(), "2465289207228256228337240363208");
}

TEST(Bignum, sub_nega_posi) {
    auto [a, b] = Get_nega_posi();
    Bignum c = a - b;

    ASSERT_EQ(c.sign(), 1);
    ASSERT_EQ(c.value(), "2465289207228256228337240363208");
}

TEST(Bignum, sub_nega_nega) {
    auto [a, b] = Get_nega_nega();
    Bignum c = a - b;

    ASSERT_EQ(c.sign(), 1);
    ASSERT_EQ(c.value(), "2217393379729990729910257884380");
}

TEST(Bignum, mul_normal) {
    auto [a, b] = Get();
    Bignum c = a * b;

    ASSERT_EQ(c.sign(), 0);
    ASSERT_EQ(c.value(), "290204368701433304337775173292299221908617484827177578016716");
}

// 不同符号的 mul
TEST(Bignum, mul_posi_nega) {
    auto [a, b] = Get_posi_nega();
    Bignum c = a * b;

    ASSERT_EQ(c.sign(), 1);
    ASSERT_EQ(c.value(), "290204368701433304337775173292299221908617484827177578016716");
}

TEST(Bignum, mul_nega_posi) {
    auto [a, b] = Get_nega_posi();
    Bignum c = a * b;

    ASSERT_EQ(c.sign(), 1);
    ASSERT_EQ(c.value(), "290204368701433304337775173292299221908617484827177578016716");
}

TEST(Bignum, mul_nega_nega) {
    auto [a, b] = Get_nega_nega();
    Bignum c = a * b;

    ASSERT_EQ(c.sign(), 0);
    ASSERT_EQ(c.value(), "290204368701433304337775173292299221908617484827177578016716");
}

TEST(Bignum, div_normal) {
    auto [a, b] = Get();
    Bignum c = a / b;

    ASSERT_EQ(c.sign(), 0);
    ASSERT_EQ(c.value(), "18");
}

// 不同符号的 div
TEST(Bignum, div_posi_nega) {
    auto [a, b] = Get_posi_nega();
    Bignum c = a / b;

    ASSERT_EQ(c.sign(), 1);
    ASSERT_EQ(c.value(), "18");
}

TEST(Bignum, div_nega_posi) {
    auto [a, b] = Get_nega_posi();
    Bignum c = a / b;

    ASSERT_EQ(c.sign(), 1);
    ASSERT_EQ(c.value(), "18");
}

TEST(Bignum, div_nega_nega) {
    auto [a, b] = Get_nega_nega();
    Bignum c = a / b;

    ASSERT_EQ(c.sign(), 0);
    ASSERT_EQ(c.value(), "18");
}

TEST_MAIN()
