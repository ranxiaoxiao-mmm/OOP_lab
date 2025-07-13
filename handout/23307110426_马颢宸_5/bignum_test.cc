#include "minitest.h"

#include "bignum.h"

using namespace EXP5;
using namespace EXP5::literals;

std::pair<Bignum, Bignum> Get()
{
    auto a= "2341341293479123479123749123794"_bn;
    auto b= "123947913749132749213491239414"_bn;

    return {a, b};
}

std::pair<Bignum, Bignum> Get_n_n()
{
    auto a= "-2341341293479123479123749123794"_bn;
    auto b= "-123947913749132749213491239414"_bn;

    return {a, b};
}

std::pair<Bignum, Bignum> Get_p_n()
{
    auto a= "2341341293479123479123749123794"_bn;
    auto b= "-123947913749132749213491239414"_bn;

    return {a, b};
}

std::pair<Bignum, Bignum> Get_n_p()
{
    auto a= "-2341341293479123479123749123794"_bn;
    auto b= "123947913749132749213491239414"_bn;

    return {a, b};
}

TEST(Bignum, create_zero)
{
    auto num= "0"_bn;
    ASSERT_EQ(num.sign(), 0);
    ASSERT_EQ(num.value(), "0");
}

TEST(Bignum, assign_normal)
{
    Bignum num;
    num.assign("123");

    ASSERT_EQ(num.sign(), 0);
    ASSERT_EQ(num.value(), "123");
}

//p-p
TEST(Bignum, add_normal)
{
    auto [a, b] = Get();
    Bignum c;

    c = a + b;

    ASSERT_EQ(c.sign(), 0);
    ASSERT_EQ(c.value(), "2465289207228256228337240363208");
}

TEST(Bignum, sub_normal)
{
    auto [a, b] = Get();
    Bignum c;

    c = a - b;

    ASSERT_EQ(c.sign(), 0);
    ASSERT_EQ(c.value(), "2217393379729990729910257884380");
}

TEST(Bignum, mul_normal)
{
    auto [a, b] = Get();
    Bignum c;
    
    c = a * b;

    ASSERT_EQ(c.sign(), 0);
    ASSERT_EQ(c.value(), "290204368701433304337775173292299221908617484827177578016716");
}

TEST(Bignum, div_normal)
{
    auto [a, b] = Get();
    Bignum c;
    
    c = a / b;

    ASSERT_EQ(c.sign(), 0);
    ASSERT_EQ(c.value(), "18");
}

//n-n
TEST(Bignum, add_n_n)
{
    auto [a, b] = Get_n_n();
    Bignum c;

    c = a + b;

    ASSERT_EQ(c.sign(), 1);
    ASSERT_EQ(c.value(), "2465289207228256228337240363208");
}

TEST(Bignum, sub_n_n)
{
    auto [a, b] = Get_n_n();
    Bignum c;

    c = a - b;

    ASSERT_EQ(c.sign(), 1);
    ASSERT_EQ(c.value(), "2217393379729990729910257884380");
}

TEST(Bignum, mul_n_n)
{
    auto [a, b] = Get_n_n();
    Bignum c;
    
    c = a * b;

    ASSERT_EQ(c.sign(), 0);
    ASSERT_EQ(c.value(), "290204368701433304337775173292299221908617484827177578016716");
}

TEST(Bignum, div_n_n)
{
    auto [a, b] = Get_n_n();
    Bignum c;
    
    c = a / b;

    ASSERT_EQ(c.sign(), 0);
    ASSERT_EQ(c.value(), "18");
}

//p-n
TEST(Bignum, add_p_n)
{
    auto [a, b] = Get_p_n();
    Bignum c;

    c = a + b;

    ASSERT_EQ(c.sign(), 0);
    ASSERT_EQ(c.value(), "2217393379729990729910257884380");
}

TEST(Bignum, sub_p_n)
{
    auto [a, b] = Get_p_n();
    Bignum c;

    c = a - b;

    ASSERT_EQ(c.sign(), 0);
    ASSERT_EQ(c.value(), "2465289207228256228337240363208");
}

TEST(Bignum, mul_p_n)
{
    auto [a, b] = Get_p_n();
    Bignum c;
    
    c = a * b;

    ASSERT_EQ(c.sign(), 1);
    ASSERT_EQ(c.value(), "290204368701433304337775173292299221908617484827177578016716");
}

TEST(Bignum, div_p_n)
{
    auto [a, b] = Get_p_n();
    Bignum c;
    
    c = a / b;

    ASSERT_EQ(c.sign(), 1);
    ASSERT_EQ(c.value(), "18");
}

//n-p
TEST(Bignum, add_n_p)
{
    auto [a, b] = Get_n_p();
    Bignum c;

    c = a + b;

    ASSERT_EQ(c.sign(), 1);
    ASSERT_EQ(c.value(), "2217393379729990729910257884380");
}

TEST(Bignum, sub_n_p)
{
    auto [a, b] = Get_n_p();
    Bignum c;

    c = a - b;

    ASSERT_EQ(c.sign(), 1);
    ASSERT_EQ(c.value(), "2465289207228256228337240363208");
}

TEST(Bignum, mul_n_p)
{
    auto [a, b] = Get_n_p();
    Bignum c;
    
    c = a * b;

    ASSERT_EQ(c.sign(), 1);
    ASSERT_EQ(c.value(), "290204368701433304337775173292299221908617484827177578016716");
}

TEST(Bignum, div_n_p)
{
    auto [a, b] = Get_n_p();
    Bignum c;
    
    c = a / b;

    ASSERT_EQ(c.sign(), 1);
    ASSERT_EQ(c.value(), "18");
}


TEST_MAIN()