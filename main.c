//Number Shifting Game
#include<stdio.h>
#include<conio.h>
int blankRow, blankCol; // global variables
void printMatrix(int matrix[4][4])
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(matrix[i][j] != 0)
            printf("%d ",matrix[i][j]);
            else printf("_"); // taking 0 as blank
        }
        printf("\n");
    }
}    
void find_blank_tile( int matrix[4][4])
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(matrix[i][j]==0)
            {
                blankRow = i;
                blankCol = j;
            }
        }
    }
}
int checkWin(int matrix[4][4]) // to check if our current situation match to winning situation
{
        int Winmatrix[4][4] = {
        {1 ,2 ,3 ,4},
        {5 ,6 ,7 ,8},
        {9 ,10 ,11 ,12},
        {13 ,14 ,15 ,0}
    };
    for (int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
           if (matrix[i][j] != Winmatrix[i][j])
             return 0;
        }
    }
  return 1;
} 
int main()
{
    printf("================================\n");
    printf("      NUMBER SHIFTING GAME      \n");
    printf("================================\n");
    printf("\nRules Of This Game\n");
    printf("\n1.You can move only 1 step at a time.\n");
    printf("Move Up   : Press w\n");
    printf("Move Down : Press s\n");
    printf("Move Left : Press a\n");
    printf("Move Right: Press d\n");
    printf("\n2.You can move number at empty position only.\n");
    printf("\n3.Wining situation: Number in a 4*4 matrix should be in order from 1 to 15.\n");
    printf("|  1 |  2 |  3 |  4 |\n");
    printf("|  5 |  6 |  7 |  8 |\n");
    printf("|  9 | 10 | 11 | 12 |\n");
    printf("| 13 | 14 | 15 |    |\n");
    printf("\nPress any key to start the game\n");
    getch();
    int win[4][4] = {
        {1  ,2  ,3  ,4},
        {5  ,6  ,7  ,8},
        {9 ,10 ,11 ,12},
        {13 ,14 ,15 ,0}
    };
    int matrix[4][4] = {
        {6 ,13 ,7 ,10},
        {8 ,9 ,11 ,0 },
        {15 ,2 ,12 ,5},
        {14 ,3 ,1 ,4 }
    };
    while(1)
    {
        printMatrix(matrix);
        char move;
        printf("Enter move (w/a/s/d): ");// to move the numbers up,down,left and right
        scanf(" %c",&move);
        if(move == 'w')
        printf("Up\n");
        else if(move == 'a')
        printf("Left\n");
        else if(move == 's')
        printf("Down\n");
        else if(move == 'd')
        printf("Right\n");
        else printf("Invalid move\n");
        find_blank_tile(matrix);
        if(move == 'w')//to move Up
        {
            if(blankRow>0)
            {
                int temp; 
                temp = matrix[blankRow][blankCol];
                matrix[blankRow][blankCol] = matrix[blankRow-1][blankCol];
                matrix[blankRow-1][blankCol] = temp;
            } 
            else printf("Invalid Move\n");
        }
        if(move == 'a')//to move Left
        {
            if(blankCol>0)
            {
                int temp; 
                temp = matrix[blankRow][blankCol];
                matrix[blankRow][blankCol] = matrix[blankRow][blankCol-1];
                matrix[blankRow][blankCol-1] = temp;
            } 
            else printf("Invalid Move\n");
        }
        if(move == 's')//to move Down
        {
            if(blankRow<3)
            {
                int temp; 
                temp = matrix[blankRow][blankCol];
                matrix[blankRow][blankCol] = matrix[blankRow+1][blankCol];
                matrix[blankRow+1][blankCol] = temp;
            } 
            else printf("Invalid Move\n");
        }
        if(move == 'd')//to move Right
        {
            if(blankCol<3)
            {
                int temp; 
                temp = matrix[blankRow][blankCol];
                matrix[blankRow][blankCol] = matrix[blankRow][blankCol+1];
                matrix[blankRow][blankCol+1] = temp;
            } 
            else printf("Invalid Move\n");
        }
        if(checkWin(matrix))
        {   
            printMatrix(win);
            printf("You Won!\n");
            break;
        }
    }
    getch();
    return 0;
}