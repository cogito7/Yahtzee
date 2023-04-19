//#ifndef YAHTZEE_H_INCLUDED
//#define YAHTZEE_H_INCLUDED
#include "yahtzee.h"





//main funtion
int main()
{
    //call function gameRules
    //gameRules();

    //call function clearScreen
    //clearScreen();

    //call function displayExplicitDice
    //displayExplicitDice();

    //while loop control variable
    int play = 1;

    //need the random function
    srand ((unsigned int) time (NULL));
    //continue to loop until the player quits or the game ends
    while (play)
    {

        switch (displayGameMenu())
        {
        case RULES:
            //call function gameRules
            clearScreen();
            gameRules();
            clearScreen();
            break;

        case GAME:
            //call function displayRandomDice
            clearScreen();
            //displayRandomDice();
            playGame();
            clearScreen();
            break;

        case EXIT:

            clearScreen();
            printf("Thank you for playing!\n");
            play = 0;
            break;

        default:
            printf("Incorrect option, hit enter and try again\n");
            char enter;
            scanf("%c", &enter );
            break;
        }

    }
    //program executed successfully
    return 0;
}

/*
Write the function gameRules to do the following
a.	Return type void
b.	Empty parameter list
c.	Outputs to the screen using a series of calls of function printf the name of the game and the instructions as shown in Figure 1 Game rules screen function output
*/
void gameRules()
{
    printf( "\t\t\t\tLET'S PLAY YAHTZEE!!!\n\n");
    printf("RULES OF THE GAME:\n");
    printf("\t1. The scorecard used for Yahtzee is composed of an upper section and a lower section.\n");
    printf("\t2. A total of 13 scoring combinations are divided amongst the sections.\n");
    printf("\t3. The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.\n");
    printf("\t4. If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.\n");
    printf("\t5. Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds.\n");
    printf("\t6. If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus. The lower section contains a number of poker like combinations.\n");
}

/*
Write function clearScreen to do the following
a.	Return type void
b.	Empty parameter list
c.	Outputs to the screen using a call of function printf to prompt the user to hit the enter key to move on to the next screen as shown in Figure 2 Clear screen function output
d.	Declare a variable of data type char
e.	Call function scanf to store input in the variable declared in step 8.d.
f.	Call function system passing argument explicit text “cls”
g.	Call function system passing argument explicit text “clear”
h.	If your operating system is Windows, comment out the second call to function system with argument “clear”
i.	If your operating system is Mac or Linux, comment out the first call to function system with argument “cls”
*/
void clearScreen()
{
    printf("\n\t\t\t\tHit <ENTER> to continue!\n\n");

    char enter;

    scanf("%c", &enter);
    //Windows
    system("cls");
    //Linux
    //system("clear");
}

/*
Write function displayExplicitDice to do the following
a.	Return type void
b.	Empty parameter list
c.	Outputs to the screen using a series of calls of function printf the hard coded dice values as shown in Figure 3 Explicit dice function output
*/
void displayExplicitDice()
{
    printf("|---------------------------------------|\n");
    printf("|       |       |       |       |       |\n");
    printf("|   1   |   2   |   3   |   4   |   5   |\n");
    printf("|       |       |       |       |       |\n");
    printf("|---------------------------------------|\n");
}

//function displayRandomDice displays a randomly generated dice for three rolls
void displayRandomDice()
{
    //looping variable
    int roll;
    int die1;
    int die2;
    int die3;
    int die4;
    int die5;

    for(roll = 0; roll < ROLLS; roll++)
    {
        die1 = rollDie();
        die2 = rollDie();
        die3 = rollDie();
        die4 = rollDie();
        die5 = rollDie();

        printf("|---------------------------------------|\n");
        printf("|       |       |       |       |       |\n");
        printf("|   %d   |   %d   |   %d   |   %d   |   %d   |\n", die1, die2, die3, die4, die5);
        printf("|       |       |       |       |       |\n");
        printf("|---------------------------------------|\n");
    }
}

//presents a menu to the player
int displayGameMenu()
{
    int select = 0;

    while(select != RULES && select != GAME && select != EXIT)
    {
        printf( "\t\t\t\tLET'S PLAY YAHTZEE!!!\n\n");
        printf("%d. Display Game Rules\n", RULES);
        printf("%d. Start a game of Yahtzee\n", GAME);
        printf("%d. Exit\n", EXIT);
        scanf("%d", &select);

    }

    return select;
}

//produces random number between 1 and 6
int rollDie() {
    int dieValue = 0;
    dieValue = (rand() % 6) + 1;

    return dieValue;
}

void initializeDice(int dice [DICE])
{
    int die;
    for (die = 0; die < DICE; ++die) {
        dice[die] = 0;
    }
}

void playGame()
{
    int roll;
    int turn;
    int dice[DICE];
    int keep[DICE];
    int scoreCard[13][2];
    int category;

    initializeScores(scoreCard);


    for (turn = 0; turn < TURNS; ++turn) {
        int current = 1;
        initializeDice(dice);
        printf("Turn %d of game", turn + 1);
        printf("\n");
        printf("\n");
        resetKeep(keep);
        for (roll = 0; roll < ROLLS; ++roll){

            printf("Rolling the dice...\n");


            rollDice(dice, keep);
            displayDice(dice);
            if (roll < ROLLS - 1) {

                //Call function selectDice passing as arguments arrays dice and keep
                selectDice(dice, keep);
            }
        }
        category = selectCategory();
        updateScores(scoreCard, category, dice);
        displayScoreCard(scoreCard);
        char enter;
        scanf("%c", &enter);
    }
}



void displayDice(int dice[DICE])
{
    int die;
    char enter;
    printf("+-------+ +-------+ +-------+ +-------+ +-------+\n");
    printf("|       | |       | |       | |       | |       |\n");
    for (die = 0; die < DICE; ++die) {
    printf("    %d     ", dice[die]);
    }
    printf("\n");
    printf("|       | |       | |       | |       | |       |\n");
    printf("+-------+ +-------+ +-------+ +-------+ +-------+\n");
    //scanf("%c", &enter );
}



void resetKeep(int keep[DICE])
{
    int die;
    for (die = 0; die < DICE; ++die) {
        keep[die] = 0;
    }
}

void rollDice(int dice[DICE], int keep[DICE])
{
    int die;
    for (die = 0; die < DICE; ++die) {
        if (keep[die] == 0) {
            dice[die] = rollDie();
        }

    }
}

void initializeScores(int scorecard[CATEGORIES][COLS])
{
    int row;
    int col;
    for (row = 0; row < CATEGORIES; ++row) {
        for (col = 0; col < COLS; ++col) {
            if (col == 0) {
                scorecard[row][col] = row;
            }
            else {
                scorecard[row][col] = 0;
            }
        }
    }

}

int selectCategory()
{
    int select;
    printf("\n\tSelect category for dice\n");
    printf("1. Ones\n");
    printf("2. Twos\n");
    printf("3. Threes\n");
    printf("4. Fours\n");
    printf("5. Fives\n");
    printf("6. Sixes\n");
    printf("7. Three of a kind\n");
    printf("8. Four of a kind\n");
    printf("9. Full house\n");
    printf("10. Small straight\n");
    printf("11. Large straight\n");
    printf("12. Yahtzee\n");
    printf("13. Chance\n");
    scanf("%d", &select);
    return select;
}
void selectDice(int dice[DICE], int keep[DICE])
{
    int die = 0;
    char data[20];
    char *value;
    int valid = 0;
    resetKeep(keep);
    printf("\nSelect dice to keep, enter values 1 through 5 with spaces between numbers\n");
    fgets(data, 20, stdin);
    value = strtok(data, " ");

    while(value != NULL)
    {
        valid = 0;
        while(valid == 0)
        {
           switch(*value)
           {
           case '1':
            printf("die 1 selected to keep\n");
            keep[0] = 1;
            valid = 1;
            break;

           case '2':
            printf("die 2 selected to keep\n");
            keep[1] = 1;
            valid = 1;
            break;

           case '3':
            printf("die 3 selected to keep\n");
            keep[2] = 1;
            valid = 1;
            break;

           case '4':
            printf("die 4 selected to keep\n");
            keep[3] = 1;
            valid = 1;
            break;

           case '5':
            printf("die 5 selected to keep\n");
            keep[4] = 1;
            valid = 1;
            break;

            default:
            printf("Invalid dice number\n");
            valid = 1; //this doesn't make sense but we need it to avoid an infinite loop
            break;

           }

        }


        value = strtok(NULL, " ");
    }
}
/*
3.	Update function playGame to do the following
a.	Modify function call updateScores to include a third argument,
the int array dice
*/

void updateScores(int scorecard[CATEGORIES][COLS], int category, int dice[DICE])
{
    switch(category)
    {
        case ONE:
            scorecard[one][COL] = sumCategory(dice, category);
            printf("Scoring Yahtzee...\n");
            break;
        case TWO:
            scorecard[two][COL] = sumCategory(dice, category);
            printf("Scoring Yahtzee...\n");
            break;
        case THREE:
            scorecard[three][COL] = sumCategory(dice, category);
            printf("Scoring Yahtzee...\n");
            break;
        case FOUR:
            scorecard[four][COL] = sumCategory(dice, category);
            printf("Scoring Yahtzee...\n");
            break;
        case FIVE:
            scorecard[five][COL] = sumCategory(dice, category);
            printf("Scoring Yahtzee...\n");
            break;
        case SIX:
            scorecard[six][COL] = sumCategory(dice, category);
            printf("Scoring Yahtzee...\n");
            break;
        case THREEKIND:
            scorecard[threekind][COL] = checkThreeKind(dice);
            printf("Scoring Yahtzee...\n");
            break;
        case FOURKIND:
            scorecard[fourkind][COL] = checkFourKind(dice);
            printf("Scoring Yahtzee...\n");
            break;
        case FULLHOUSE:
            scorecard[fullhouse][COL] = checkFullHouse(dice);
            printf("Scoring Yahtzee...\n");
            break;
        case SMSTRAIGHT:
            scorecard[smstraight][COL] = checkSmStraight(dice);
            printf("Scoring Yahtzee...\n");
            break;
        case LGSTRAIGHT:
            scorecard[lgstraight][COL] = checkLgStraight(dice);
            printf("Scoring Yahtzee...\n");
            break;
        case YAHTZEE:
            scorecard[yahtzee][COL] = checkYahtzee(dice);
            printf("Scoring Yahtzee...\n");
            break;
        case CHANCE:
            scorecard[chance][COL] = sumChance(dice);
            printf("Scoring Yahtzee...\n");
            break;
        default:
            printf("Invalid");
            break;
    }
}

int sumCategory(int dice[DICE], int category) {
int sum = 0;
int die;
        for (die = 0; die < DICE; ++die) {
        if (dice[die] == category) {
            sum = category + sum;
        }
        }
return sum;
}

int sumChance(int dice[DICE]) {
int sum = 0;
int die;

for (die = 0; die < DICE; ++die) {
    sum = dice[die] + sum;
}

return sum;

}

int checkLgStraight(int dice[DICE]) {
//int dice[DICE] = {1,2,3,5,4};
int sum;
sortDice(dice);
if(dice[1] == dice[0] + 1 &&
   dice[2] == dice[1] + 1 &&
   dice[3] == dice[2] + 1 &&
   dice[4] == dice[3] + 1)
{

    return 40;

}
else {

    return 0;
}
}


int checkSmStraight(int dice[DICE]) {
int sum;

sortDice(dice);

//checking first four dice
if(dice[1] == dice[0] + 1 &&
   dice[2] == dice[1] + 1 &&
   dice[3] == dice[2] + 1)
{

    return 30;
}

else if(dice[2] == dice[1] + 1 &&
        dice[3] == dice[2] + 1 &&
        dice[4] == dice[3] + 1)
{


    return 30;
}
else if(dice[1] == dice[0] + 1 &&
        dice[3] == dice[1] + 1 &&
        dice[4] == dice[3] + 1)
{


    return 30;
}
else if(dice[1] == dice[0] + 1 &&
        dice[2] == dice[1] + 1 &&
        dice[4] == dice[2] + 1)
{


    return 30;
}
else {

    return 0;
}


}

int checkYahtzee(int dice[DICE]) {
int sum = 0;
//int dice[DICE] = {4,4,4,4,4};

if(dice[1] == dice[0] &&
   dice[2] == dice[1] &&
   dice[3] == dice[2] &&
   dice[4] == dice[3])
{

    sum = 50;


}
    return sum;
}

int checkFourKind(int dice[DICE]) {

int sum = 0;
int die;
int count;
//int dice[DICE] = {1,1,1,1,4};
sortDice(dice);


if(dice[1] == dice[0] &&
   dice[2] == dice[1] &&
   dice[3] == dice[2])
{

    sum = 4 * dice[0];
}

else if(dice[2] == dice[1] &&
        dice[3] == dice[2] &&
        dice[4] == dice[3])
{


    sum = 4 * dice[4];
}



return sum;
}

int checkThreeKind(int dice[DICE]) {
    //int dice[DICE] = {1,1,1,3,4};

    int sum;
    int die;
    int count;

    sortDice(dice);

    if(dice[1] == dice[0] &&
   dice[2] == dice[1])

{
    sum = 3 * dice[0];
}
else if(dice[2] == dice[1] &&
        dice[3] == dice[2])
{
        sum = 3 * dice[2];
}
else if (dice[3] == dice[2] &&
            dice[4] == dice[3])
{
    sum = 3 * dice[4];
}



return sum;
}

int checkFullHouse(int dice[DICE]) {
    int sum = 0;
    int die;
    int count;
    int pair;
    int threeOfKind;


    //int dice[DICE] = {3,3,3,4,4};
    sortDice(dice);


    if(dice[1] == dice[0] &&
       dice[2] == dice[1])
    {
        // Here, the first three are the same
        if(dice[3] == dice[4]) {
        sum = 25;
        }
    }
    else if (dice[3] == dice[2] &&
            dice[4] == dice[3])
    {
        if(dice[0] == dice[1]) {
            sum = 25;
        }
        // Here, the last three are the same
    }




    return sum;
}


void sortDice(int dice[DICE]) {
int temp;
int outer;
int inner;



for (outer = 0; outer < DICE; ++outer)
{

    for (inner = outer + 1; inner < DICE; ++inner)
    {

        if(dice[outer] > dice[inner])
        {
            temp = dice[outer];
            dice[outer] = dice[inner];
            dice[inner] = temp;
        }
    }

}
}

void displayScoreCard(int scorecard[CATEGORIES][COLS])
{
    int total = sumUpper(scorecard) + checkBonus(scorecard);
    int grandTotal = total + sumLower(scorecard);
    printf("\n\tYAHTZEE SCORECARD\n");
    displayUpperSection(scorecard);
    displayLowerSection(scorecard);

    printf("| TOTAL (upper)   |     %d     |\n", total);
    printf("+-----------------+-----------+\n");
    printf("| GRAND TOTAL     |     %d     |\n", grandTotal);
    printf("+-----------------+-----------+\n");
}

int sumUpper(int scorecard[CATEGORIES][COLS]) {
    int sum = 0;
    int i;

    for (i = one; i <= six; ++i) {
        sum += scorecard[i][COL];
    }


return sum;
}

int sumLower(int scorecard[CATEGORIES][COLS]) {
    int sum = 0;
    int i;
    for (i = threekind; i <= chance; ++i) {
        sum += scorecard[i][COL];
    }


return sum;


}

int checkBonus(int scorecard[CATEGORIES][COLS]) {
    int sum = 0;
    int score = 0;
    int i;
    for (i = one; i <= six; ++i) {
        sum += scorecard[i][COL];
    }
    if(sum >= 63) {
        score = 35;
    }


return score;


}

void displayUpperSection(int scorecard[CATEGORIES][COLS])
{

    int bonus = checkBonus(scorecard);
    int totalScore = sumUpper(scorecard);
    int total = bonus + totalScore;


    /*
    int i;
    totalScore = 0;
    for (i = one; i <= six; ++i) {
        totalScore += scorecard[i][COL];
    }
    int bonusScore;
    if (totalScore >= 43) {
        bonusScore = 35;
    }
    else {
        bonusScore = 0;
    }
*/
//enum scores {one, two, three, four, five, six, threekind, fourkind, fullhouse, smstraight, lgstraight, yahtzee, chance};

    printf("+-----------------+-----------+\n");
    printf("| UPPER SECTION   |   SCORE   |\n");
    printf("+-----------------+-----------+\n");
    printf("| ONES            |     %d     |\n", scorecard[one][COL]);
    printf("+-----------------+-----------+\n");
    printf("| TWOS            |     %d     |\n", scorecard[two][COL]);
    printf("+-----------------+-----------+\n");
    printf("| THREES          |     %d     |\n", scorecard[three][COL]);
    printf("+-----------------+-----------+\n");
    printf("| FOURS           |     %d     |\n", scorecard[four][COL]);
    printf("+-----------------+-----------+\n");
    printf("| FIVES           |     %d     |\n", scorecard[five][COL]);
    printf("+-----------------+-----------+\n");
    printf("| SIXES           |     %d     |\n", scorecard[six][COL]);
    printf("+-----------------+-----------+\n");
    printf("| TOTAL SCORE     |     %d     |\n", totalScore);
    printf("+-----------------+-----------+\n");
    printf("| BONUS           |     %d     |\n", bonus);
    printf("+-----------------+-----------+\n");
    printf("| SCORE           |     %d     |\n", total);
    printf("+-----------------+-----------+\n");

}

void displayLowerSection(int scorecard[CATEGORIES][COLS])
{

    int total = sumLower(scorecard);
    /*
    int i;
    totalScore = 0;
    for (i = threekind; i <= chance; ++i) {
        totalScore += scorecard[i][COL];

    }
    */
//enum scores {one, two, three, four, five, six, threekind, fourkind, fullhouse, smstraight, lgstraight, yahtzee, chance};
    printf("+-----------------+-----------+\n");
    printf("| LOWER SECTION   |   SCORE   |\n");
    printf("+-----------------+-----------+\n");
    printf("| THREE OF A KIND |     %d     |\n", scorecard[threekind][COL]);
    printf("+-----------------+-----------+\n");
    printf("| FOUR OF A KIND  |     %d     |\n", scorecard[fourkind][COL]);
    printf("+-----------------+-----------+\n");
    printf("| FULL HOUSE      |     %d     |\n", scorecard[fullhouse][COL]);
    printf("+-----------------+-----------+\n");
    printf("| SM STRAIGHT     |     %d      |\n", scorecard[smstraight][COL]);
    printf("+-----------------+-----------+\n");
    printf("| LG STRAIGHT     |     %d      |\n", scorecard[lgstraight][COL]);
    printf("+-----------------+-----------+\n");
    printf("| YAHTZEE         |     %d     |\n", scorecard[yahtzee][COL]);
    printf("+-----------------+-----------+\n");
    printf("| CHANCE          |     %d     |\n", scorecard[chance][COL]);
    printf("+-----------------+-----------+\n");
    printf("| TOTAL (lower)   |     %d     |\n", total);
    printf("+-----------------+-----------+\n");


}
