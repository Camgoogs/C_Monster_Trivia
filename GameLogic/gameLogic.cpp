//
// Created by Tyler McCoy and Camden Welander on 2/20/24.
//

#include "gameLogic.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;
using namespace std::chrono;

// Structure to represent a trivia question
struct Question {
    string questionText;
    string correctAnswer;
};

// Structure to represent a monster
struct Monster {
    string name;
    int health;
};

// Function to read trivia questions from a text file
vector<Question> readQuestionsFromFile(const string& filename) {
    vector<Question> questions;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return questions;
    }

    string line;
    while (getline(file, line)) {
        // Each question and its correct answer are separated by a delimiter (e.g., ';')
        size_t pos = line.find(';');
        if (pos != string::npos) {
            string questionText = line.substr(0, pos);
            string correctAnswer = line.substr(pos + 1);
            questions.push_back({questionText, correctAnswer});
        }
    }

    file.close();
    return questions;
}

// Function to present a random question to the player
Question getRandomQuestion(const vector<Question>& questions) {
    int index = rand() % questions.size();
    return questions[index];
}

// Function to measure time taken by the player to answer the question
double measureTime() {
    high_resolution_clock::time_point start = high_resolution_clock::now();
    string answer;
    cin >> answer;
    high_resolution_clock::time_point end = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(end - start);
    return time_span.count();
}

// Function to determine damage based on time taken to answer
int calculateDamage(double timeTaken) {
    // You can adjust the formula based on your game's rules
    const int maxDamage = 100;
    double maxTime = 10.0; // Maximum time allowed (in seconds) to deal max damage
    double normalizedTime = min(timeTaken, maxTime) / maxTime;
    return static_cast<int>(maxDamage * (1 - normalizedTime));
}

// Function to check if the answer is correct
bool isAnswerCorrect(const Question& question, const string& playerAnswer) {
    return question.correctAnswer == playerAnswer;
}

// Function to select a monster model for each level
Monster selectMonsterModelForLevel(int level) {
    switch (level) {
        case 1:
            return {"Sea Serpent", 100}; // Example: Level 1 monster model
        case 2:
            return {"Kraken", 200}; // Example: Level 2 monster model
        case 3:
            return {"Leviathan", 300}; // Example: Level 3 monster model
        default:
            return {"Unknown Monster", 0}; // Default monster model
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Read questions from file
    vector<Question> questions = readQuestionsFromFile("questions.txt");
    if (questions.empty()) {
        return 1;
    }

    int currentLevel = 0; // Level 0 represents the easiest level
    int playerLives = 3;

    while (currentLevel < 3 && playerLives > 0) {
        // Increment the level and display level information
        currentLevel++;
        cout << "Level " << currentLevel << endl;

        // Select monster model for the current level
        Monster monster = selectMonsterModelForLevel(currentLevel);

        while (monster.health > 0 && playerLives > 0) {
            // Get a random question
            Question question = getRandomQuestion(questions);
            cout << question.questionText << endl;

            // Measure time taken by the player to answer
            double timeTaken = measureTime();

            // Calculate damage based on time taken
            int damage = calculateDamage(timeTaken);
            monster.health -= damage;

            string playerAnswer;
            cin >> playerAnswer;

            if (isAnswerCorrect(question, playerAnswer)) {
                cout << "Correct! Monster takes " << damage << " damage." << endl;
            } else {
                cout << "Incorrect! You lose a life." << endl;
                playerLives--;
            }

            cout << "Monster health: " << monster.health << endl;
        }

        if (monster.health <= 0) {
            cout << "Monster defeated! Proceeding to next level." << endl;
        } else {
            cout << "Out of lives! Game over." << endl;
        }
    }

    if (currentLevel >= 3 && playerLives > 0) {
        cout << "Congratulations! You have defeated all monsters and won the game!" << endl;
    }

    return 0;
}
