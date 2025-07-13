#include <iostream>
#include <cmath>

#include "prime.h"


bool is_prime(size_t n){
    if (n==2) return true;
	  if (n>2 && n%2==0) return false;
    for(size_t i = 3; i < std::sqrt(n)+1; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

std::vector<size_t> find_primes(size_t start, size_t count){
    std::vector<size_t> primes;
    size_t i = start;
    while(primes.size() < count){
        if(is_prime(i)){
            primes.push_back(i);
        }
        i++;
    }
    return primes;
}




