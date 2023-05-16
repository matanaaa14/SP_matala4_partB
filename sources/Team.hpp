#ifndef TEAM
#define TEAM
#include <iostream>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "array"

using namespace std;
//#define  arraySize 10
constexpr int arraySize = 10;
namespace ariel{}
class Team{
    public:
    std::array<Character*, arraySize> arr;
    Character* leader_;
    void add(Character* fighter);
    void attack(Team* enemy);
    int stillAlive();
    void print();
    Team(Character* leader);
    ~Team();
    Team(const Team& other);
    Team(Team&& other) noexcept;
    Team& operator=(const Team& other);
    Team& operator=(Team&& other) noexcept;
};
#endif