#include <iostream>
#include "package.hpp"
#include "helpers.hpp"


int main(){
    for (int i=0;i<=9;i++) std::cout << get_random() << "\n";
    return 1;
}