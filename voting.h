#ifndef VOTING_H
#define VOTING_H

#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 3
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol;
    int votes;
} Candidate;

extern Candidate allCandidates[MAX_CANDIDATES];
extern int candidateCount;
extern char symbols[];
extern int symbolTaken[];

void fillCandidate();
void displayAllCandidates();
void castVote();
void showResults();

#endif
