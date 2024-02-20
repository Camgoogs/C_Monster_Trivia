#include <iostream>
#include "streak_multiplier.h"
#include <cstdlib>
#include <cmath>

int starting_damage;

void streak(int correct_answers)
{
    bool streak_achieved;
    if (correct_answers == 5)
    {
        streak_achieved = true;
    }
    else
    {
        streak_achieved = false;
    }
    multiplier_value(streak_achieved, starting_damage);
}



int multiplier_value(bool multer, int base_damage)
{
    double rand = std::rand() % 4 + 1;
    double damage;
    if(multer == true)
    {
        //damage = insert whatever the damage value is multiplied by rand
        return std::ceil(damage); 
    }
}
