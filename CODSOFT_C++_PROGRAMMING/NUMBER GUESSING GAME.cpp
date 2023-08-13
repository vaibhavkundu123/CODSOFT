#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));
    int secret_num = rand() % 100 + 1;
    int guess;
    std::cout << "I'm thinking of a number between 1 and 100. Can you guess it?" << std::endl;
    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        if (guess < secret_num) {
            std::cout << "Your guess is too low. Try again." << std::endl;
        } else if (guess > secret_num) {
            std::cout << "Your guess is too high. Try again." << std::endl;
        }
    } while (guess != secret_num);
    std::cout << "Congratulations! You guessed the number!" << std::endl;
    return 0;
}
