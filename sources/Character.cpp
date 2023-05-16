#include "Character.hpp"
#include <iostream>
using namespace std;
namespace ariel{}
    bool Character::isAlive()const{
      if(this->life > 0)
        return false;
      return true;
    }
    double Character::distance(Character* other)const{return other->loaction_.distance(this->loaction_);}
    void Character::hit(int num){
      this->life = this->life - num;
    }
    string Character::getName()const{return this->name_;}
    Point Character::getLocation()const{return this->loaction_;}
    Character::Character(string name, Point point) : name_(name), loaction_(point){}
    ostream& operator<<(ostream& output,const Character& other){
        return output << "nothing";
      }
    Character::Character(const Character& other): name_(other.name_), loaction_(other.loaction_){}
    Character::Character(Character&& other) noexcept : name_(other.name_), loaction_(other.loaction_){
      other.name_ = nullptr;
      other.loaction_.x = 0;
      other.loaction_.y = 0;
    }
    Character::~Character(){}
    Character& Character::operator=(const Character& other){
      this->name_ = other.name_;
      this->loaction_ = other.loaction_;
      this->life = other.life;
      return *this;
    }
    Character& Character::operator=(Character&& other) noexcept {
      return *this;
    }