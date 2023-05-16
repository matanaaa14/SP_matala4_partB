#include "Team.hpp"
#include "Character.hpp"
#include <iostream>
namespace ariel{}
    void Team::add(Character* fighter){
      if(fighter == nullptr)
        return;
      for(unsigned long i = 0; i < this->arr.size(); i++){
        if(this->arr[i] == nullptr){
          this->arr[i] = fighter;
          break;
        }
      }
    }
    void Team::attack(Team* enemy){}
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
        if(this->arr[i] != nullptr)
          this->arr[i]->print();
        }
    }
    Team::Team(Character* leader) : leader_(leader){
      this->arr[0] = this->leader_;
    }
    Team::~Team(){
    for (Character* fighter : arr) {
        delete fighter;
    }
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
        this->arr[i] = other.arr[i];
      }
      return *this;
    }
    Team& Team::operator=(Team&& other) noexcept {
      return *this;
    }
