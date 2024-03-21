#include <iostream>
#include "streak_multiplier.h"
#include <random>
#include <cmath>

using namespace std;

void streak(int correct_answers,int starting_damage)
{
    bool streak_achieved;
    //determines if the player has achieved an answer streak
    if (correct_answers >= 5)
    {
        streak_achieved = true;
    }
    else
    {
        streak_achieved = false;
    }
    //calls function to determine damage multiplier
    multiplier_value(streak_achieved, starting_damage);
}



void multiplier_value(bool multer, int base_damage)
{
    int damage = base_damage;
    if(multer == true)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(2, 5);
        int rand_num = dis(gen);
        damage = base_damage * rand_num;
    }
    cout << std::ceil(damage) << endl; 
}
