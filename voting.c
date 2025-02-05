#include <stdio.h>
#include "voting.h"

Candidate allCandidates[MAX_CANDIDATES];
int candidateCount = 0;
char symbols[] = {'A', 'B', 'C'};
int symbolTaken[MAX_CANDIDATES] = {0};

void fillCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }
    printf("Enter candidate name: ");
    scanf("%s", allCandidates[candidateCount].name);
    printf("Available symbols: ");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (!symbolTaken[i]) {
            printf("%c ", symbols[i]);
        }
    }
    printf("\nChoose a symbol: ");
    char symbol;
    scanf(" %c", &symbol);
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (symbols[i] == symbol && !symbolTaken[i]) {
            allCandidates[candidateCount].symbol = symbol;
            symbolTaken[i] = 1;
            break;
        }
    }
    allCandidates[candidateCount].votes = 0;
    candidateCount++;
}

void displayAllCandidates() {
    printf("Candidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s (%c)\n", i + 1, allCandidates[i].symbol);
    }
}

void castVote() {
    char symbol;
    printf("Enter candidate symbol to vote: ");
    scanf(" %c", &symbol);
    for (int i = 0; i < candidateCount; i++) {
        if (allCandidates[i].symbol == symbol) {
            allCandidates[i].votes++;
            printf("Vote casted for %s\n", allCandidates[i].name);
            return;
        }
    }
    printf("Invalid symbol.\n");
}

void showResults() {
    printf("Voting Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s (%c): %d votes\n", allCandidates[i].name, allCandidates[i].symbol, allCandidates[i].votes);
    }
}
