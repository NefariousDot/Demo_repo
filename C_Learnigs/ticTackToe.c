/*

 ####################################################################
 ### Maintainer : Nefarious
 ### Title : Tic Tack Toe Game
 ### Date : September 25 2023
 ####################################################################

 */


#include <stdio.h>
#include <stdlib.h>

char cell[9] = {'1','2','3','4','5','6','7','8','9'};
int player;

int checkGameStatus()
{
    /*
 This function is used to check the status of the game.
 This will return an integer value to identify the status

 gameStatus = -1 // GAME STILL PROGRESS
 gameStatus = 0 // GAME OVER. ITS A DRAW
 gameStatus = 1 // GAME OVER , WE HAVE A WINNER

 will return an integer value to identify the status

 */
    int gameStatus;

    /*
    ########################################
    writing condition for win check
    ########################################
    */

    //checking the row status

    if( cell[0] == cell[1] && cell[1] == cell[2])
    gameStatus = 1;

    else if( cell[3] == cell[4] && cell[4] == cell[5])
    gameStatus = 1;

    else if( cell[6] == cell[7] && cell[7] == cell[8])
    gameStatus = 1;

    //checking the Column status

    else if( cell[0] == cell[3] && cell[3] == cell[6])
    gameStatus = 1;

    else if( cell[1] == cell[4] && cell[4] == cell[7])
    gameStatus = 1;

    else if( cell[2] == cell[5] && cell[5] == cell[8])
    gameStatus = 1;

    //checking the Diagonal status

    else if( cell[2] == cell[4] && cell[4] == cell[6])
    gameStatus = 1;

    else if( cell[0] == cell[4] && cell[4] == cell[8])
    gameStatus = 1;

    /*
    ########################################
    writing condition for draw check
    ########################################
    */

   //if all the cells have different value than the original value we can consider it as a draw

    else if( cell[0] != '1' && cell[1] != '2' && cell[2] != '3' && cell[3] != '4' && cell[4] != '5'
    && cell[5] != '6' && cell[6] != '7' && cell[7] != '8' && cell[8] != '9')
    gameStatus = 0;

    //if all the above conditions fails then game is still on

    else
    gameStatus = -1;

    return gameStatus;

}

void displayGame()
{
    //This is a simple function used to display the game.

    system("clear");

    printf("\n\nTIC TACK TOE GAME\n\n");
    printf("Player 1 ==> 'X' \t\t Player 2 ==> 'O'\n\n");

    printf("||          ||         ||          ||\n");
    printf("||    %c     ||    %c    ||    %c     ||\n",cell[0],cell[1],cell[2]);
    printf("||          ||         ||          ||\n");
    printf("_____________________________________\n_____________________________________\n");
    printf("||          ||         ||          ||\n");
    printf("||    %c     ||    %c    ||    %c     ||\n",cell[3],cell[4],cell[5]);
    printf("||          ||         ||          ||\n");
    printf("_____________________________________\n_____________________________________\n");
    printf("||          ||         ||          ||\n");
    printf("||    %c     ||    %c    ||    %c     ||\n",cell[6],cell[7],cell[8]);
    printf("||          ||         ||          ||\n");
    
}

void playerMaking(int decision)
{
    //This function is used to mark the changes made by players

    //checking whether correct cell is selected or not

    if(decision > 9 || cell[decision - 1] == 'X' || cell[decision - 1] == 'O')
    {
        printf("\nEntered a wrong value. Please re assign ");
        getchar();

        player --;
    }
    else//Need to change the corresponding value in display
    cell[decision - 1] = (player == 1) ? 'X' : 'O';

}

int main()
{
    player = 1;
    int decision, status;
       

    do
    {
        displayGame();

        player = (player % 2) ? 1 : 2;

        status = checkGameStatus();
        printf("status value is %d & player playing now is %d\n", status, player);

        printf("\nPlayer %d make a decision : ", player);
        scanf("%d", &decision);

        playerMaking(decision);

        status = checkGameStatus();
        printf("status value is %d \n", status);
        getchar();

        player ++;

        if (status == 1)
        {
            --player;
            printf("\n****************************\n");
            printf("    PLAYER %d WON      \n", player);
            printf("****************************\n");
        }
        
        else if (status == 0)
        {
            printf("\n****************************\n");
            printf("         ITS A DRAW     \n");
            printf("****************************\n");
        }


    }while(status == -1);


    printf("\n\n****************************\n");
    printf("       GAME OVER      \n");
    printf("****************************\n");

    return 0;

}
