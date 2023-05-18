/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */
//https://github.com/cpp-exercises/cowboy_vs_ninja_b/tree/main
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;


int main() {
    Point a(32.3,44),b(1.3,3.5);
    assert(a.distance(b) == b.distance(a));
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    tom->shoot(sushi);
    cout << tom->print() <<endl;

    sushi->move(tom);
    sushi->slash(tom);

    Team team_A(tom); 
    cout << "check1" << endl;

    team_A.add(new YoungNinja("Yogi", Point(64,57)));
    // Team b(tom); should throw tom is already in team a
     Team team_B(sushi);
     team_B.add(new TrainedNinja("Hikari", Point(12,81)));

    cout << "num of live members: " << team_A.stillAlive() << endl;
    
     while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
      cout << "while" << endl;

        team_A.attack(&team_B);
        team_B.attack(&team_A);
        team_A.print();
        team_B.print();
     }
    
     if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
     else cout << "winner is team_B" << endl;

    cout << "my check" << endl;
    unsigned long i = 0;
    for(; i < 10; i++){
      cout << "i is: " << i << endl;
      if(team_B.arr[i] != nullptr)
        cout << team_B.arr[i]->name_ << endl;
    }
    cout << "end" << endl;

     return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}
