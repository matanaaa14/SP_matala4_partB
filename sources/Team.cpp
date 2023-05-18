#include "Team.hpp"
#include "Character.hpp"
#include <iostream>
namespace ariel{}
    void Team::add(Character* fighter){
      if(this->stillAlive() >= 10)
        __throw_runtime_error("can't have more than 10\n");
      if(fighter->inTeam)
        __throw_runtime_error("already in team\n");
      fighter->inTeam = true;
      if(fighter == nullptr)
        return;
      for(unsigned long i = 0; i < this->arr.size(); i++){
        if(this->arr[i] == NULL)
        if(this->arr[i] == nullptr){
          this->arr[i] = fighter;
          break;
        }
      }
    }
    void Team::attack(Team* enemy){
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
              }}
              index++;
          }

          index2++;
        }

        index2 = 0;
        while(index2 < this->arr.size() && enemy->arr[j]->isAlive()){
          if(this->arr[index2] != nullptr && this->arr[index2]->isAlive() ){
          if(Ninja* ninja = dynamic_cast<Ninja*>(this->arr[index2]) ){         
             if(ninja->distance(enemy->arr[j]) <= 1){
                ninja->slash(enemy->arr[j]);}
              else{
                ninja->move(enemy->arr[j]);
              }}
             index++;
          
          }  
          index2++;
        
      }

    }}
    unsigned long Team::newLeader(){
      double minDis = 1000000;
      Character* newLeader;
      for(unsigned long i = 0; i < this->arr.size(); i++){
        if(this->arr[i] != nullptr && this->arr[i] != leader_){
          Character* Character = this->arr[i];
          if(typeid(Character) == typeid(Cowboy))
            if(this->leader_->distance(this->arr[i]) < minDis){
              minDis = this->leader_->distance(this->arr[i]) ;
              newLeader = this->arr[i];
            }
          }
        }
      for(unsigned long i = 0; i < this->arr.size(); i++){
        if(this->arr[i] != nullptr && this->arr[i] != leader_){
          Character* Character = this->arr[i];
          if(typeid(Character) == typeid(Ninja))
            if(this->leader_->distance(this->arr[i]) < minDis){
              minDis = this->leader_->distance(this->arr[i]) ;
              newLeader = this->arr[i];
            }
          }
        }
      if(minDis > 10)
        return 11;
      this->leader_ = newLeader;
      return 1;
    }
    unsigned long Team::whoToAttack(Team* enemy){

      unsigned long j = 12;
      double minDis = 10000;
      bool flag = false;
      for(unsigned long i = 0; i < enemy->arr.size(); i++){
        flag = false;
        if(enemy->arr[i] != nullptr){
          Character* character = enemy->arr[i];
          if(Cowboy* cowboy = dynamic_cast<Cowboy*>(enemy->arr[i]) ){
          flag = true;
          }
          if(enemy->arr[i]->isAlive() == true && flag && this->leader_->distance(enemy->arr[i]) < minDis){
            j = i;
            minDis = this->leader_->distance(enemy->arr[i]);  
          }
        }
        }

      for(unsigned long i = 0; i < enemy->arr.size(); i++){
        flag = false;
        if(enemy->arr[i] != nullptr){
          Character* Character = enemy->arr[i];
          if(Ninja* cowboy = dynamic_cast<Ninja*>(enemy->arr[i]) ){
          flag = true;
          }
          if(enemy->arr[i]->isAlive() && flag && this->leader_->distance(enemy->arr[i]) <minDis){
            j = i;
            minDis = this->leader_->distance(enemy->arr[i]);  
          }
            
        }
      }
     // cout << "need to atack: " << enemy->arr[j]->name_ << endl;
      if(minDis == 10000)
        return 11;
      return j;
    }

    int Team::stillAlive(){
      int cnt = 0;
      for(unsigned long i = 0; i < this->arr.size(); i++){
        if(this->arr[i] != nullptr && this->arr[i]->isAlive())
          cnt++;
      }
      return cnt;
    }
    void Team::print(){
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
    Team::Team(Character* leader) : leader_(leader){
      if(leader->inTeam)
        __throw_runtime_error("already in team\n");
      leader->inTeam = true;
      this->arr.push_back(this->leader_);
      this->arr.resize(10);
    }
    Team::~Team(){
    for(unsigned long i = 0; i < this->arr.size() ; i++){
      if(this->arr[i] == NULL)
      if(this->arr[i] == nullptr)
      if(this->arr[i] != NULL)
        delete this->arr[i];
    }
    cout << "good" <<endl;
    }
    Team::Team(const Team& other) : leader_(other.leader_){
      for(unsigned long i = 0; i < this->arr.size(); i++){
        this->arr[i] = other.arr[i];
      }
    }
    Team::Team(Team&& other) noexcept {
    }
    Team& Team::operator=(const Team& other){

      for(unsigned long i = 0; i < this->arr.size(); i++){
          Character* Character = this->arr[i];
          if(typeid(Character) == typeid(Cowboy))
            this->arr[i] = other.arr[i];
        }
      for(unsigned long i = 0; i < this->arr.size(); i++){
          Character* Character = this->arr[i];
          if(typeid(Character) == typeid(Ninja))
            this->arr[i] = other.arr[i];
        }
      
      return *this;
    }
    Team& Team::operator=(Team&& other) noexcept {
      return *this;
    }
