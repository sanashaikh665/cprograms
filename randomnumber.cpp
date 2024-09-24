#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Generate a random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;
    int userGuess = 0;
    int attempts = 0;

    std::cout << "Welcome to the Guess the Number Game!" << std::endl;
    std::cout << "I have selected a random number between 1 and 100." << std::endl;

    // Loop until the user guesses the correct number
    do {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        attempts++;

        if (userGuess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else if (userGuess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts." << std::endl;
        }

    } while (userGuess != randomNumber);

    return 0;
}
