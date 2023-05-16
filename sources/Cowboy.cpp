#include "Cowboy.hpp"
#include "Character.hpp"
#include <iostream>
namespace ariel{}
    void Cowboy::shoot(Character* enemy){
      if(!enemy->isAlive() && this->isAlive()){
        return;
      }
      enemy->hit(10);
      this->numOfBullets--;
    }
    bool Cowboy::hasboolets(){
      if(this->numOfBullets > 0)
        return true;
      return false;
    
    }
    void Cowboy::reload(){
      this->numOfBullets = 6;
    }
    string Cowboy::print() const{
      if(!this->isAlive())
        return "C ("+this->name_+")" +"("+to_string(this->loaction_.x)+", "+to_string(this->loaction_.y)+")" ;
      return "C "+this->name_+ to_string(this->life)+"("+to_string(this->loaction_.x)+", "+to_string(this->loaction_.y)+")" ;}

    Cowboy::Cowboy(string name, Point point) : Character(name,point){
      this->numOfBullets = 6;
      this->life = 110;
    }
    ostream& operator<<(ostream& output,const Cowboy& other){
        return output << "nothing";
      }