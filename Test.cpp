#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "doctest.h"
#include "Team.hpp"
namespace ariel{
    TEST_CASE("Correct Init"){
        Point p1(1,1);
        CHECK(p1.getX() == 1);
        CHECK(p1.getY() == 1);
        YoungNinja yon = YoungNinja("yon", p1);
        CHECK(yon.getName() == "yon");
        CHECK(yon.getLocation().getX() == 1);
        CHECK(yon.isAlive() == true);
        yon.hit(100);
        CHECK(yon.isAlive() == false);
        TrainedNinja trn = TrainedNinja("trn", p1);
        CHECK(trn.getName() == "trn");
        CHECK(trn.getLocation().getX() == 1);
        CHECK(trn.isAlive() == true);
        trn.hit(120);
        CHECK(trn.isAlive() == false);
        OldNinja old = OldNinja("old", p1);
        CHECK(old.getName() == "old");
        CHECK(old.getLocation().getX() == 1);
        CHECK(old.isAlive() == true);
        old.hit(150);
        CHECK(old.isAlive() == false);
        Cowboy cow = Cowboy("cow", p1);
        CHECK(cow.getName() == "cow");
        CHECK(cow.getLocation().getX() == 1);
        CHECK(cow.isAlive() == true);
        cow.hit(110);
        CHECK(cow.isAlive() == false);
        YoungNinja yon2 = YoungNinja("yon2", p1);
        Team team = Team(&yon2);
        CHECK(team.stillAlive() == 1);  
        CHECK(team.leader->getName() == "yon2");
        yon2.hit(100);
        CHECK(team.stillAlive() == 0);
    }
    TEST_CASE("Fight"){
        YoungNinja yon = YoungNinja("yon", Point(1,1));
        Cowboy cow = Cowboy("cow", Point(1,1));
        yon.slash(&cow);
        CHECK(cow.isAlive() == true);
        for(int i = 0; i < 6; i++){
            cow.shoot(&yon);
        }
        CHECK(cow.hasboolets() == false);
        cow.reload();
        CHECK(cow.hasboolets() == true);
        CHECK(yon.isAlive() == true);
        for(int i = 0; i < 6; i++){
            yon.slash(&cow);
        }
        CHECK(cow.isAlive() == false);


    }
}