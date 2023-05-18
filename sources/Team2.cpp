#include "Team2.hpp"
#include "Character.hpp"
#include <iostream>
namespace ariel{}
    void Team2::print(){
      for(unsigned long i = 0; i < this->arr.size(); i++){
        if(this->arr[i] != nullptr ){
          Character* Character = this->arr[i];
          if(typeid(Character) == typeid(Cowboy))
            this->arr[i]->print();
          }
        }
      for(unsigned long i = 0; i < this->arr.size(); i++){
        if(this->arr[i] != nullptr ){
          Character* Character = this->arr[i];
          if(typeid(Character) == typeid(Ninja))
            this->arr[i]->print();
          }
        }
    }
    //construcotr
   void Team2::attack(Team* enemy){
      if(enemy == nullptr)
        __throw_invalid_argument  ("can't attack null pointer\n");
      if(enemy->stillAlive() <= 0)
        __throw_runtime_error("can't attack a dead team\n");
      unsigned long index = 0;
      while(index < this->stillAlive()){
        if(!this->leader_->isAlive()){
        if(this->newLeader() == 11)
          return;
      }

      //there is alive leader old or new
        unsigned long j = this->whoToAttack(enemy);
        if(j == 11)
          return;

      //there is a member to attack
        bool flag = false;
        unsigned long index2 = 0;
       
        while( index2 < this->arr.size() && enemy->arr[j]->isAlive()){

          if(this->arr[index] != nullptr && this->arr[index2]->isAlive() ){

          if(Cowboy* cowboy = dynamic_cast<Cowboy*>(this->arr[index2]) ){

          flag = true;                    
             if(cowboy->hasboolets())
              cowboy->shoot(enemy->arr[j]);
              else{
                cowboy->reload();
              }
              index++;
          }}
          index2++;
        }
        index2 = 0;
        while(index2 < this->arr.size() && enemy->arr[j]->isAlive()){
          if(this->arr[index2] != nullptr && this->arr[index2]->isAlive() ){
          if(Ninja* ninja = dynamic_cast<Ninja*>(this->arr[index2]) ){         
             if(ninja->distance(enemy->arr[j]) <= 1)
                ninja->slash(enemy->arr[j]);
              else{
                ninja->move(enemy->arr[j]);
              }
             index++;
          }
          }  
          index2++;
        
      }

    }}
        Team2::Team2(Character* leader) : Team(leader){

    }