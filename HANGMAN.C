#include <stdio.h>
#include <string.h>

int main() {
    int i, n;
    int found;
    char guess;
    int triesLeft = 5;
    
    // 1. Declare variables
    char secretWord[20];
    char guessedWord[20];
    int length;

    printf("--- HANGMAN GAME ---\n");
    printf("Select difficulty: 1.easy 2.medium 3.hard: ");
    scanf("%d", &n);

    // 2. Populate arrays based on choice
    if (n == 1) {
        strcpy(secretWord, "AHMEDABAD");
        strcpy(guessedWord, "_________");
        length = 9; 
    } else if (n == 2) {
        strcpy(secretWord, "MALPUVA");
        strcpy(guessedWord, "_______");
        length = 7;
    } else if (n == 3) {
        strcpy(secretWord, "NATHDWARA");
        strcpy(guessedWord, "_________");
        length = 9; 
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    while (triesLeft > 0) {
        printf("\nWord: %s\n", guessedWord);
        printf("Tries left: %d\n", triesLeft);
        
        if(n == 1) printf("Hint: Indian city name (CAPITAL letters): ");
        if(n == 2) printf("Hint: RAJASTHAN SWEET DISH (CAPITAL letters): ");
        if(n == 3) printf("Hint: Place of highest Shiv statue (CAPITAL letters): ");
        
        scanf(" %c", &guess); 

        found = 0;
        for (i = 0; i < length; i++) {
            if (secretWord[i] == guess) {
                guessedWord[i] = guess;
                found = 1;
            }
        }

        if (found == 0) {
            printf("Wrong!\n");
            triesLeft--;
        } else {
            printf("Good job!\n");
        }

        // Check for Win
        if (strcmp(secretWord, guessedWord) == 0) {
            printf("\nCONGRATULATIONS! You won! Word: %s\n", secretWord);
            return 0;
        }
    }

    // Game Over / Lose
    printf("\n  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n=========\n");
    printf("\nMAN IS HANGED! The word was: %s\n", secretWord);

    return 0;
}