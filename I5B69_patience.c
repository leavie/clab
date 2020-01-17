#include<stdio.h>
#include<stdlib.h>
char ranks[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9','T', 'J', 'Q', 'K'};
char suits[4] = {'H', 'D', 'C', 'S'};
char deck[4][13];
int cards[52];
int piles[13][5];

void shuffleCards() {
    for (int i = 0; i < 52; ++i)
    {
        int j = rand() % 52;
        cards[i] = cards[i]^cards[j];
        cards[j] = cards[i]^cards[j];
        cards[i] = cards[i]^cards[j];
    }
}

void dealCards() {
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 13; ++j)
        {
            piles[j][i+1] = cards[i*13+j];
        }
    }
}

void play() {
    /*
    ** BOTTOM           TOP
            0  1  2  3  4
    */
    // ------ define constant -----------
    int TOP = 5-1; // index of top starting from zero
    int BOTTOM = 0; // index of bottom starting from zero
    int INIT_PILE_NO = 8-1; // number of init pile starting from zero
    // ------ define variable -----------------
    int pile_no = INIT_PILE_NO;
    int top_card_no = piles[pile_no][TOP];
    // ------ define state transition
    while(deck[top_card_no/13][top_card_no%13]!='U') {
        deck[top_card_no/13][top_card_no%13] = 'U'; // turn up the top card
        for(int top=TOP;top>0;top--) // start from the top-1 card, shift cards one by one to TOP
          piles[pile_no][top] = piles[pile_no][top-1];

        // update to choose next pile and next top card
        pile_no = top_card_no%13; // update pile_no
        if (pile_no == INIT_PILE_NO) // insert card to bottom of next pile
            piles[pile_no][BOTTOM+1] = top_card_no;
        else
            piles[pile_no][BOTTOM] = top_card_no;

        // back to beginning
        top_card_no = piles[pile_no][TOP]; // update top_card_no
    }
    puts("遊戲結束時，最後一張翻開的卡片點數(rank)一定是一開始選中的牌堆(pile)的編號");
    puts("根據遊戲規則，遊戲結束代表目前牌堆的所有卡片都被翻開而且最後一張翻開卡片的點數與牌堆編號相同而不能轉移。\
         \n發牌後，每個牌堆上的卡片的分佈情況可分為兩種情形:\
         \n第一個是所有卡片的點數都與牌堆號碼一樣，第二個是至少有一張卡片的點數與牌堆號碼不一樣。\
         \n前面的情形使這個牌堆的卡片無法被轉移進來也無法轉移出去，後面的情形則代表牌堆至少有一張被卡片會轉移出去，而遊戲得以繼續。\
         \n遊戲不會結束在除了一開始選中的牌堆的其他牌堆上。因為除了一開始選中的牌堆，其他牌堆每個能轉移出去的次數是五次，而轉移進來的次數是四次。\
         \n移出與移入的動作是輪流進行的，而移出的次數比移入多一次，這代表最後在牌堆中被翻起來的一張牌一定會移出牌堆而使得能夠轉移到其他牌堆使遊戲繼續。\
         \n而一開始的牌堆的移出與移入均是四次，順序為先出後入，因此最後一定會因爲某張點數等於牌堆編號的卡片移入牌堆而使得牌堆的所有卡片被全部翻開，而結束遊戲。\
         \n不論是否成功翻所有開卡片與否，「遊戲結束時，最後一張翻開的卡片點數(rank)一定是一開始選中的牌堆(pile)的編號」。");
    puts("--------------------------------------");
    printf("起始牌堆編號 pile no.=%d\n", INIT_PILE_NO+1);
    printf("最後一張牌的點數 last card rank=%c%c%c\n", suits[top_card_no/13], ranks[top_card_no%13], deck[top_card_no/13][top_card_no%13]);
}

void displayResult() {
    for (int j = 0; j < 13; ++j)
    {
        for (int i = 4; i >= 1 ; --i)
        {
            int card_no = piles[j][i];
            printf("%c%c%c ", suits[card_no/13], ranks[card_no%13], deck[card_no/13][card_no%13]);
        }
        puts("");
    }
}



int main() {
    // initialization in main
    srand(14); // (seed:14, INIT:13): success
    for (int i = 0; i < 52; ++i)  cards[i] = i;
    for (int i = 0; i < 4; ++i) for (int j = 0; j < 13; ++j) deck[i][j] = 'D';

    shuffleCards();

    dealCards();
    puts("---------------------");
    displayResult();
    puts("---------------------");
    play();
    displayResult();

    puts("Do all the card be turned up?");
    for (int i = 0; i < 13; ++i) {
        if (deck[piles[i][4]/13][piles[i][4]%13] == 'D') {
            puts("failure");
            return 0;
        }
    }
    puts("success");
    return 0;
}