#include <iostream>
#include "package.h"


int main(){
    /*
    std::set<int> ass;
    ass.insert(1);
    ass.insert(3);
    ass.insert(2);
    ass.erase(2);
    auto tmp = ass.begin();
    ass.erase(*tmp);
    for(auto i = ass.begin(); i != ass.end(); i++){
        std::cout << *i << std::endl;
    }
    */
    Package paczka1;
    Package paczka2;
    paczka1 = paczka2;
    Package paczka3;
    std::cout << paczka1.get_id() << " " << paczka2.get_id() << " " << paczka3.get_id();

    return 1;
}
