#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerChoice, computerChoice;
    int playerScore = 0, computerScore = 0;
    int rounds, currentRound = 1;

    printf("Welcome to Rock, Paper, Scissors!\n");
    printf("How many rounds do you want to play? ");
    scanf("%d", &rounds);

    // Initialize the random number generator
    srand(time(NULL));

    while (currentRound <= rounds) {
        printf("\nRound %d\n", currentRound);
        printf("Enter your choice (0 - Rock, 1 - Paper, 2 - Scissors): ");
        scanf("%d", &playerChoice);

        if (playerChoice < 0 || playerChoice > 2) {
            printf("Invalid choice. Please enter 0, 1, or 2.\n");
            continue;
        }

        computerChoice = rand() % 3;

        printf("Computer chose: %d\n", computerChoice);

        if (playerChoice == computerChoice) {
            printf("It's a tie!\n");
        } else if ((playerChoice == 0 && computerChoice == 2) ||
                   (playerChoice == 1 && computerChoice == 0) ||
                   (playerChoice == 2 && computerChoice == 1)) {
            printf("You win this round!\n");
            playerScore++;
        } else {
            printf("Computer wins this round!\n");
            computerScore++;
        }

        currentRound++;
    }

    printf("\nGame over!\n");
    printf("Your score: %d\n", playerScore);
    printf("Computer's score: %d\n", computerScore);

    if (playerScore > computerScore) {
        printf("You win the game!\n");
    } else if (computerScore > playerScore) {
        printf("Computer wins the game!\n");
    } else {
        printf("It's a tie game!\n");
    }

    return 0;
}

