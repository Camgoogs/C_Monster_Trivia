#include <iostream>

// Function definition for healthSystemTimer
bool healthSystemTimer(bool question, double time) {
    // Initialize user's health and monster's health
    int userHealth = 3;
    int monsterHealth = 20;
    int damage = 0; // Initialize damage
    bool gameOver = false; // Initialize gameOver flag
    bool winner = false; // Initialize winner flag
    bool continueGame = true; // Initialize continueGame flag

    // Loop until either the user's health or monster's health reaches zero
    while (userHealth != 0 && monsterHealth != 0) {
        // Check if the question answer is correct
        if (question) {
            // Calculate damage based on time
            if (time <= 5) {
                damage = 3;
            } else if (time > 5 && time <= 10) {
                damage = 2;
            } else if (time > 10 && time <= 15) {
                damage = 1;
            }
            // Subtract damage from monster's health
            monsterHealth -= damage;
        } else {
            // If question is incorrect, subtract 1 from user's health
            userHealth -= 1;
        }

        // Ensure monster's health and user's health don't go negative
        if (monsterHealth < 0)
            monsterHealth = 0;
        if (userHealth < 0)
            userHealth = 0;
    }

    // Check if the game is over
    if (userHealth == 0)
        gameOver = true;
    // Check if the player won
    if (monsterHealth == 0)
        winner = true;

    // Return whether the game should continue
    return continueGame;
}
