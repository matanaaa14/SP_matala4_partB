#include "YoungNinja.hpp"
#include <iostream>
namespace ariel{}
    YoungNinja::YoungNinja(string name, Point point) : Ninja(name,point){
        this->life = 120;
        this->speed = 12;
    }
