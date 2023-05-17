#include "Team.hpp"
#include "Character.hpp"
#include <iostream>
namespace ariel{}
    void Team::add(Character* fighter){
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

      unsigned long index = 0;
      while(index < 10){
        if(!enemy->leader_->isAlive()){
        if(this->newLeader(enemy) == 11)
          return;
      }
      //there is alive leader old or new
        unsigned long j = this->whoToAttack(enemy);
        if(j == 11)
          return;
      //there is a member to attack
        while( index < 10 && enemy->arr[j]->isAlive()){
          Character* Character = this->arr[index];
          if(typeid(Character) == typeid(Cowboy)) 
            this->arr[index]->attackEnemy(enemy->arr[j]);
          index++;
        }
        while( index < 10 && enemy->arr[j]->isAlive()){
          Character* Character = this->arr[index];
          if(typeid(Character) == typeid(Ninja)) 
            this->arr[index]->attackEnemy(enemy->arr[j]);
          index++;
        }
      }
    }
    unsigned long Team::newLeader(Team* team){
      double minDis = 1000000;
      Character* newLeader;
      for(unsigned long i = 0; i < this->arr.size(); i++){
        if(team->arr[i] != nullptr && team->arr[i] != leader_){
          Character* Character = team->arr[i];
          if(typeid(Character) == typeid(Cowboy))
            if(team->leader_->distance(team->arr[i]) < minDis){
              minDis = team->leader_->distance(team->arr[i]) ;
              newLeader = team->leader_;
            }
          }
        }
      for(unsigned long i = 0; i < this->arr.size(); i++){
        if(team->arr[i] != nullptr && team->arr[i] != leader_){
          Character* Character = team->arr[i];
          if(typeid(Character) == typeid(Ninja))
            if(team->leader_->distance(team->arr[i]) < minDis){
              minDis = team->leader_->distance(team->arr[i]) ;
              newLeader = team->arr[i];
            }
          }
        }
      if(minDis > 10)
        return 11;
      team->leader_ = newLeader;
      return 1;
    }
    unsigned long Team::whoToAttack(Team* enemy){
      unsigned long j;
      double minDis = 1000000;
      for(unsigned long i = 0; i < this->arr.size(); i++){
          Character* Character = enemy->arr[i];
          if(typeid(Character) == typeid(Cowboy) && this->leader_->distance(enemy->arr[i]) < minDis)
            j = i;  
        }
      for(unsigned long i = 0; i < this->arr.size(); i++){
          Character* Character = enemy->arr[i];
          if(enemy->arr[i]->isAlive() && typeid(Character) == typeid(Ninja) && this->leader_->distance(enemy->arr[i]) <minDis)
            j = i;
        }
      if(minDis > 10)
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
    Team::Team(Character* leader) : leader_(leader){
      this->arr[0] = this->leader_;
      //for(this.)
    }
    Team::~Team(){
    for(unsigned long i = 0; i < this->arr.size() ; i++){
      if(this->arr[i] == NULL)
      if(this->arr[i] == nullptr)
      if(this->arr[i] != NULL)
        delete this->arr.at(i);
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
