#include <iostream>
#include <typeinfo>
#include <vector>

#include "config.hpp"

int main(){

    Config cfg("config.cfg");

    int int1 = cfg.getValue<int>("int1", 0);
    int int2 = cfg.getValue<int>("int2", 10); // Note int2 doesn't exist in the config file
    std::cout << "int1 type: " << typeid(int1).name() << ", int2 type: " << typeid(int2).name() << '\n';
    std::cout << "int1 = " << int1 << ", int2 = " << int2 << '\n';
    std::cout <<  "int1 + int2 = " << int1 + int2 << "\n\n";

    double double1 = cfg.getValue<double>("double1", 0.0);
    double double2 = cfg.getValue<double>("double2", 0.0);
    std::cout << "double1 type: " << typeid(double1).name() << ", double2 type: " << typeid(double2).name() << '\n';
    std::cout << "double1 = " << double1 << ", double2 = " << double2 << '\n';
    std::cout <<  "double1 + double2 = " << double1 + double2 << "\n\n";
    
    std::string string1 = cfg.getValue<std::string>("string1", "");
    std::cout << "string1 type: " << typeid(string1).name() << '\n' << "string1 = " << string1 << "\n\n";

    bool bool1 = cfg.getValue<bool>("bool1", false);
    std::cout << "bool1 type: " << typeid(bool1).name() << '\n' << "bool1 = " << bool1 << '\n';

    return 0;
}