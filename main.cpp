#include <iostream>
#include "package.h"
#include "helpers.h"


int main(){
    for (int i=0;i<=9;i++) std::cout << get_random() << "\n";
    return 1;
}