#include <stdio.h>
#include <wchar.h>

#define STOP '*'
#define PASS ' '

typedef struct Cell {
int x;
int y;
int parent;
} Cell;

int main(void) {
    wchar_t maze[5][5] = {
        {' ',' ','*',' ',' '},
        {' ','*',' ',' ',' '},
        {' ',' ',' ',' ',' '},
        {' ','*','*',' ',' '},
        {' ',' ','*',' ',' '}
    };
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; // 代表上下左右 （順序不計）

    Cell queue[25]; // 隊列
    int q_start = 0; // 列隊頭部
    int q_end = 1; // 列隊的尾部

    Cell start_cell = {0,0,-1}; // 代表迷宮起點的Cell
    Cell end_cell = {4,4, 9999/*屠龍寶刀點擊就送只要9999 隨便填 因為這個欄位並不會使用到*/}; // 迷宮終點

    queue[q_start] = start_cell; // 開始尋路前，隊列需要一個起始點

  //前置作業
  //=========分隔線========
  //計算

    Cell curr_cell;
    while (q_start != q_end) {
      //printf("s=%d, e=%d\n", q_start, q_end);
      Cell last_cell = queue[q_end-1];
      //printf("cx=%d, ex=%d, cy=%d, ey=%d\n",last_cell.x ,end_cell.x , last_cell.y , end_cell.y);
      if (last_cell.x == end_cell.x && last_cell.y == end_cell.y) { // 當列隊的尾部的Cell的座標相等於迷宮終點 => 找對路徑
        while(1) { // 反向列印路徑
          printf("<-(%d,%d)",last_cell.x+1, last_cell.y+1);
          if (last_cell.parent > -1)
            last_cell = queue[last_cell.parent];
          else
            break;
        }
        //printf("%d %d\n", queue[0].x, queue[0].y);
        return 0;
      }

      curr_cell = queue[q_start]; // 從列隊頭部得到
      for(int i =0 ;i <4;i++) { // 列舉出四個方向，產生四個相鄰地點
          int nextY = curr_cell.y+dirs[i][0]; // y座標
          int nextX = curr_cell.x+dirs[i][1]; // x座標

          if (nextY >= 0 && nextY < 5 && nextX >= 0 && nextX < 5) { // 判斷有沒有超出迷宮的邊界
              int state = maze[nextY][nextX]; // 獲取相鄰座標在迷宮中的通過與否狀態
              //printf("state=%d\n", state);
              //printf("nextY=%d ,nextX=%d\n", nextY, nextX);
              if (state == PASS) { // 如果可以通過
                  Cell next_cell = {nextX,nextY,q_start}; // 將迷宮的兩個相鄰地點的相鄰關係成與包裝成一個Cell記錄起來
                  queue[q_end++] = next_cell; // 將紀錄好的Cell加入進列隊的尾部
                  maze[nextY][nextX] = STOP; // 避免迷宮裡的同個Cell通過兩次
              }
          }
      }
      q_start++;
    }

    //printf("s=%d, e=%d\n", q_start, q_end);
    printf("No Way\n");

    return 0;

}