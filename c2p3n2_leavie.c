#include <stdio.h>

#define STOP 0
#define PASS 1

typedef struct Cell {
int x;
int y;
int parent;
} Cell;

int main(void) {
    int maze[5][5] = {
        {1,1,1,1,1},
        {1,1,0,1,1},
        {1,1,0,1,1},
        {1,1,0,1,1},
        {1,1,0,1,1}
    };
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    Cell queue[25];

    int q_start = 0;
    int q_end = 1;

    Cell start_cell = {0,0,-1};
    Cell curr_cell = start_cell;
    Cell end_cell = {4,4,-1};

    int sol = 0;

    while (1) {

    printf("s=%d, e=%d\n", q_start, q_end);
    if (q_start == q_end) {
            puts("no way in loop===");
            break;
    }



        for(int i =0 ;i <4;i++) {
            int nextY = curr_cell.y+dirs[i][0];
            int nextX = curr_cell.x+dirs[i][1];

            if (nextY >= 0 && nextY < 5 && nextX >= 0 && nextX < 5) { // fuck1

                int state = maze[nextY][nextX];
                printf("state=%d\n", state);
                printf("nextY=%d ,nextX=%d\n", nextY, nextX);
                if (state == PASS) {
                    Cell next_cell = {nextX,nextY,q_start};
                    queue[q_end++] = next_cell;
                    maze[nextY][nextX] = STOP;
                }
            }
        }
        curr_cell = queue[++q_start];
                printf("cx=%d, ey=%d, cy=%d, ey=%d\n",queue[q_end-1].x ,end_cell.x , queue[q_end-1].y , end_cell.y);
    if (queue[q_end-1].x == end_cell.x && queue[q_end-1].y == end_cell.y) {
            sol = 1;
            break;
    }
    }
    curr_cell = queue[q_end-1];
    if (sol) {
        while(curr_cell.parent > 0) {
            printf("<-(%d,%d)",curr_cell.x+1, curr_cell.y+1);
            curr_cell = queue[curr_cell.parent];
        }
    }
    else
        printf("No Way\n");


}
