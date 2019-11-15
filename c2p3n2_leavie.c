#include <stdio.h>

#define STOP 0
#define PASS 1
#define VISITED 2

typedef struct Cell {
int x;
int y;
int parent;
} Cell;

int main(void) {
    int maze[5][5] = {
        {1,1,1,1,1},
        {1,1,1,1,1},
        {1,1,1,1,1},
        {1,1,1,1,1},
        {1,1,1,1,1}
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
    if (queue[q_end].x == end_cell.x && queue[q_end].y == end_cell.y) {
            sol = 1;
            break;
    }
    printf("s=%d, e=%d\n", q_start, q_end);
    if (q_start == q_end) {
            puts("no way in loop===");
            break;
    }


        for(int i =0 ;i <4;i++) {
            int nextY = curr_cell.y+dirs[i][0];
            int nextX = curr_cell.x+dirs[i][1];

            if (nextY <= 0 && nextY < 5 && nextX <= 0 && nextX < 5) {
                int state = maze[nextY][nextX];
                if (state == PASS) {
                     Cell next_cell = {nextX,nextY,q_start};
                    queue[q_end++] = next_cell;
                    maze[nextY][nextX] = VISITED;
                }
            }
        }
        curr_cell = queue[++q_start];
    }

    if (sol) {
        while(curr_cell.parent >= 0) {
            printf("<-(%d,%d)",curr_cell.x, curr_cell.y);
            curr_cell = queue[curr_cell.parent];
        }
    }
    else
        printf("No Way\n");


}
