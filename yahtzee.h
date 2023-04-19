#ifndef YAHTZEE_H_INCLUDED
#define YAHTZEE_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


/*Define global constants or macros for the following
a.	RULES, value of 1
b.	GAME, value of 2
c.	EXIT, value of 3
d.	ROLLS, value of 3
*/

#define CATEGORIES 13
#define DICE 5
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define THREEKIND 7
#define FOURKIND 8
#define FULLHOUSE 9
#define SMSTRAIGHT 10
#define LGSTRAIGHT 11
#define YAHTZEE 12
#define CHANCE 13
#define TURNS 13

#define RULES 1
#define GAME 2
#define EXIT 3
#define ROLLS 3

#define COLS 2
#define COL 1
#define ZERO 0

enum scores {one, two, three, four, five, six, threekind, fourkind, fullhouse, smstraight, lgstraight, yahtzee, chance};


// function prototypes
void initializeDice(int dice [DICE]);
void playGame();
void displayDice(int dice[DICE]);
void resetKeep(int keep[DICE]);
void rollDice(int dice[DICE], int keep[DICE]);

void gameRules();
void clearScreen();
void displayExplicitDice();
int displayGameMenu();
void displayRandomDice();
int rollDie();
void initializeScores(int scorecard[CATEGORIES][COLS]);
int selectCategory();
void selectDice(int dice[DICE], int keep[DICE]);
void updateScores(int scoreCard[CATEGORIES][COLS], int category, int dice[DICE]);
void displayScoreCard(int scorecard[CATEGORIES][COLS]);
void displayUpperSection(int scorecard[CATEGORIES][COLS]);
void displayLowerSection(int scorecard[CATEGORIES][COLS]);
void sortDice(int dice[DICE]);
int sumCategory(int dice[DICE], int category);
int sumUpper(int scoreCard[CATEGORIES][COLS]);
int sumLower(int scoreCard[CATEGORIES][COLS]);
int checkSmStraight(int dice[DICE]);
int checkLgStraight(int dice[DICE]);
int checkYahtzee(int dice[DICE]);
int checkFourKind(int dice[DICE]);
int checkThreeKind(int dice[DICE]);
int checkBonus(int scoreCard[CATEGORIES][COLS]);
int sumChance(int dice[DICE]);
int checkFullHouse(int dice[DICE]);


#endif // YAHTZEE_H_INCLUDED
