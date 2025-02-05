#include <stdio.h>
#include "voting.h"

void displaySymbols() {
    printf("Available symbols: ");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (!symbolTaken[i]) {
            printf("%c ", symbols[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. Vote\n");
        printf("3. Show Results\n");
        printf("4. Display Symbols\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fillCandidate();
                break;
            case 2:
                displayAllCandidates();
                castVote();
                break;
            case 3:
                showResults();
                break;
            case 4:
                displaySymbols();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}