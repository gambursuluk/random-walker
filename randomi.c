#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(void){
    char grid[10][10];
    srand(time(NULL));  //rand()

    for(int i=0; i<10;i++){
        for(int j=0; j<10;j++){
            grid[i][j] = '.';
        }
    }

    /*
    for(int i=0; i<10;i++){
        for(int j=0; j<10;j++){
            printf("%2c", park[i][j]);
        }
        printf("\n");
    }
    
    
    printf("-------------------------------------\n\n\n");
    */
    char walker = 'A';
    int row = rand()%10;
    int col = rand()%10;
    grid[row][col]=walker;

    for(char walker ='B'; walker<='Z'; walker++){
        int up_open = (row>0    && grid[row-1][col] =='.');
        int down_open = (row<9  && grid[row+1][col] =='.');
        int left_open = (col>0  && grid[row][col-1] =='.');
        int right_open = (col<9 && grid[row][col+1] =='.');
        
        if (!up_open && !down_open && !left_open && !right_open) {
            break;
        }

        while (1) {
            int dir = rand() % 4;

            if (dir == 0 && up_open) {
                row--;
                break;
            } else if (dir == 1 && down_open) {
                row++;
                break;
            } else if (dir == 2 && left_open) {
                col--;
                break;
            } else if (dir == 3 && right_open) {
                col++;
                break;
            }
        }
        grid[row][col] = walker;
    }


    

    for(int i=0; i<10;i++){
        for(int j=0; j<10;j++){
            printf("%2c", grid[i][j]);
        }
        printf("\n");
    }
}