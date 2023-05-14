#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "sources/point.hpp"

using namespace std;
namespace ariel{
    class Character{
        private:
            Point loc;
            string name;
            int health;
        public:
            bool isAlive() const;
            double distance(Character* other) const;
            void hit(int dmg);
            string getName() const;
            Point getLocation() const;
            void print() const;
    };
}