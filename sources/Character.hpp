#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Point.hpp"

using namespace std;
namespace ariel{
    class Character{
        private:
            Point loc;
            string name;
            int health;
        public:
            Character(string name, Point loc);
            bool isAlive() const;
            double distance(Character* other) const;
            void hit(int dmg);
            string getName() const;
            Point getLocation() const;
            void print() const;
    };
    class Cowboy : public Character{
        private:
            int bullets;
        public:
            Cowboy(string name, Point loc);
            void shoot(Character* other); // 10 damage
            string print() const;
            bool hasboolets();
            void reload(); // 6 bullets
    };
    class YoungNinja : public Character{
        private:
            int speed;
        public:
            YoungNinja(string name, Point loc);
            void slash(Character* other); // 40 damage
            void move(Character* other); // move towards other
            void print() const;
    };
    class OldNinja : public Character{
        private:
            int speed;
        public:
            OldNinja(string name, Point loc);
            void slash(Character* other); // 40 damage
            void move(Character* other); // move towards other
            void print() const;
    };
    class TrainedNinja : public Character{
        private:
            int speed;
        public:
            TrainedNinja(string name, Point loc);
            void slash(Character* other); // 40 damage
            void move(Character* other); // move towards other
            void print() const;
    };
}