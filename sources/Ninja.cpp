#include "Ninja.hpp"
#include "Character.hpp"
#include <iostream>
namespace ariel{}
using namespace std;
    void Ninja::slash(Character* enemy){
        if(this->distance(enemy) <= 1 && this->isAlive() && enemy->isAlive()){
            enemy->hit(40);
        }
    }
    Ninja::Ninja(string name, Point point) : Character(name,point){}
    string Ninja::print() const
    {
      if(!this->isAlive())
        return "N ("+this->name_+")" +"("+to_string(this->loaction_.x)+", "+to_string(this->loaction_.y)+")" ;
      return "N "+this->name_+ to_string(this->life)+"("+to_string(this->loaction_.x)+", "+to_string(this->loaction_.y)+")" ;}
    void Ninja::move(Character* enemy){
      this->loaction_.moveTowards(this->loaction_,enemy->loaction_,this->speed);
    }

    void Ninja::attackEnemy(Character* enemy){
      this->slash(enemy);
    }