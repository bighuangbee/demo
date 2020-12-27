#include "../include/simple.h"

std::string SimpleClass::hello(){
    return "go world";
}

std::string SimpleClass::say(std::string key){
    return "say " + key;
}