// Rock Paper Scissors: play against the computer. Type q to quit.
#include <cctype>
#include <iostream>
#include <random>
#include <string>

// Returns 0 for a tie, 1 if the player wins, -1 if the computer wins.
int decideRound(char player, char computer) {
    if (player == computer) return 0;
    if ((player == 'r' && computer == 's') ||
        (player == 's' && computer == 'p') ||
        (player == 'p' && computer == 'r')) {
        return 1;
    }
    return -1;
}

std::string nameOf(char choice) {
    if (choice == 'r') return "Rock";
    if (choice == 'p') return "Paper";
    return "Scissors";
}

int main() {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> pick(0, 2);
    const char choices[3] = {'r', 'p', 's'};

    int playerScore = 0;
    int computerScore = 0;
    int ties = 0;

    std::cout << "=== Rock Paper Scissors ===\n";
    std::cout << "Enter r (rock), p (paper), s (scissors), or q to quit.\n\n";

    while (true) {
        std::cout << "Your choice: ";
        std::string input;
        if (!(std::cin >> input)) break;  // stop if input ends

        char player = static_cast<char>(std::tolower(static_cast<unsigned char>(input[0])));
        if (player == 'q') break;
        if (input.size() != 1 || (player != 'r' && player != 'p' && player != 's')) {
            std::cout << "Please enter r, p, s or q.\n\n";
            continue;
        }

        char computer = choices[pick(rng)];
        std::cout << "You chose " << nameOf(player)
                  << ", computer chose " << nameOf(computer) << ".\n";

        int result = decideRound(player, computer);
        if (result == 1) {
            std::cout << "You win this round!\n";
            playerScore++;
        } else if (result == -1) {
            std::cout << "Computer wins this round.\n";
            computerScore++;
        } else {
            std::cout << "It's a tie.\n";
            ties++;
        }
        std::cout << "Score -> You: " << playerScore
                  << " | Computer: " << computerScore
                  << " | Ties: " << ties << "\n\n";
    }

    std::cout << "\nFinal score -> You: " << playerScore
              << " | Computer: " << computerScore
              << " | Ties: " << ties << "\n";
    if (playerScore > computerScore) std::cout << "You won overall. Well played!\n";
    else if (computerScore > playerScore) std::cout << "The computer won overall. Better luck next time!\n";
    else std::cout << "The game ended level.\n";
    return 0;
}
