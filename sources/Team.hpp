#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "sources/Character.hpp"

using namespace std;

namespace ariel{
    class Team{// a team of up to 10 characters
        private:
            Character** team;
            Character* leader;
        public:
            Team(Character* leader);
            void add(Character* warrior);
            void attack(Team* other);
            int stillAlive() const;
            void print() const;
            ~Team();
    };
}