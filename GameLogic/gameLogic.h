//
// Created by Tyler McCoy and Camden Welander on 2/20/24.
//

#ifndef C_MONSTER_TRIVIA_GAMELOGIC_H
#define C_MONSTER_TRIVIA_GAMELOGIC_H

#include <string>
#include <vector>

// Structure to represent a trivia question
struct Question {
    std::string questionText;
    std::string correctAnswer;
};

// Structure to represent a monster
struct Monster {
    std::string name;
    int health;
};

// Function declarations
std::vector<Question> readQuestionsFromFile(const std::string& filename);
Question getRandomQuestion(const std::vector<Question>& questions);
double measureTime();
int calculateDamage(double timeTaken);
bool isAnswerCorrect(const Question& question, const std::string& playerAnswer);
Monster selectMonsterModelForLevel(int level);

#endif //C_MONSTER_TRIVIA_GAMELOGIC_H
