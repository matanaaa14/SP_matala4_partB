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
      while(index < this->arr.size()){
        if(!enemy->leader_->isAlive()){
        if(this->newLeader(enemy) == 11)
          return;
      }

      //there is alive leader old or new
        unsigned long j = this->whoToAttack(enemy);
        if(j == 11)
          return;

      //there is a member to attack
        bool flag = false;
        while( index < this->arr.size() && enemy->arr[j]->isAlive()){
          if(this->arr[index] != nullptr ){
            cout << "index is: " << index << endl;
          if(Cowboy* cowboy = dynamic_cast<Cowboy*>(this->arr[index]) ){
          flag = true;                    
             cout << "befor cowboy" << enemy->arr[j]->life << endl;
            cowboy->shoot(enemy->arr[j]);
             cout << "after" << enemy->arr[j]->life << endl;
          
          }}
          index++;
        }
        while(index < this->arr.size() && enemy->arr[j]->isAlive()){
          if(this->arr[index] != nullptr ){
          if(Ninja* ninja = dynamic_cast<Ninja*>(this->arr[index]) ){         
             cout << "befor ninja" << enemy->arr[j]->life << endl;
              ninja->slash(enemy->arr[j]);
             cout << "after" << enemy->arr[j]->life << endl;
          }
          }  
          index++;
        
      }
    }}
    unsigned long Team::newLeader(Team* team){
      double minDis = 1000000;
      Character* newLeader;
      for(unsigned long i = 0; i < team->arr.size(); i++){
        if(team->arr[i] != nullptr && team->arr[i] != leader_){
          Character* Character = team->arr[i];
          if(typeid(Character) == typeid(Cowboy))
            if(team->leader_->distance(team->arr[i]) < minDis){
              minDis = team->leader_->distance(team->arr[i]) ;
              newLeader = team->leader_;
            }
          }
        }
      for(unsigned long i = 0; i < team->arr.size(); i++){
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
      cout << "who to attack return: " << minDis <<", " << j << endl;
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
