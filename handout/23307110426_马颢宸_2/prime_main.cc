#include "prime.h"

#include <iostream>
#include <string>
#include <format>
#include <algorithm>


auto get_user_inputInt(std::string msg)
{
    size_t result;

    std::cout << msg << ":";
    std::cin >> result;

    return result;
}

void out_nums(std::vector<size_t>& nums)
{
	auto max_value{*std::max_element(nums.begin(), nums.end())};
    auto s{std::to_string(max_value)};
    auto width{s.size()};

	for(size_t idx=0; idx<nums.size(); ++idx){
		std::cout << std::format("{:} ", nums[idx]);
		if((idx+1) % 6 == 0)
			std::cout << "\n";
	}
}

int main()
{
	auto start = get_user_inputInt("请输入起始值(start)");
	auto count = get_user_inputInt("请输入个数(count)");
	auto primes = find_primes(start, count);

	out_nums(primes);
}