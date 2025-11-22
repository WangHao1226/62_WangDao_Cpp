//德州扑克：写一个程序循环读取 5 张手牌 (输入 0 结束程序)，然后把手中的牌分为下面某一类：
// 1.同花顺 2.四张 3.葫芦 (3 + 2) 4. 同花 5. 顺子 6.三张 7.两对 8. 一对 9.高牌。程序对话如下：
// Enter a card: 2s
// Enter a card: 5s
// Enter a card: 4s
// Enter a card: 3s
// Enter a card: 6s
// Straight flush

// Enter a card: 8c
// Enter a card: as
// Enter a card: 8c
// Duplicate card; ignored.
// Enter a card: 7c
// Enter a card: ad
// Enter a card: 3h
// Pair

// Enter a card: 6s
// Enter a card: d2
// Bad card; ignored.
// Enter a card: 2d
// Enter a card: 9c
// Enter a card: 4h
// Enter a card: ts
// High card

// Enter a card: 0
#include<stdio.h>
#include<stdlib.h>

int num_in_rank[13];
int num_in_suit[4];

bool straight,flush,four,three;
int pairs;

void read_cards(){
    bool in_hand[4][13]={false};
    
    for(int i=0;i<13;i++){
        num_in_rank[i]=0;
    }
    for(int i=0;i<4;i++){
        num_in_suit[i]=0;
    }

    int card_read=0;
    while(card_read<5){
        bool bad_card=false;

        printf("Enter a card:");

        char c=getchar();
        int rank;
        switch (c){
        case '0':exit(0);
        case '2':rank=0;break;
        case '3':rank=1;break;
        case '4':rank=2;break;
        case '5':rank=3;break;
        case '6':rank=4;break;
        case '7':rank=5;break;
        case '8':rank=6;break;
        case '9':rank=7;break;
        case 't':case 'T':rank=8;break;
        case 'j':case 'J':rank=9;break;
        case 'q':case 'Q':rank=10;break;
        case 'k':case 'K':rank=11;break;
        case 'a':case 'A':rank=12;break;
            
        default:    bad_card=true;
        }

        c=getchar();
        int suit;
        switch (c){
        case 'd':case 'D':suit=0;break;
        case 'c':case 'C':suit=1;break;
        case 'h':case 'H':suit=2;break;
        case 's':case 'S':suit=3;break;        
        default:    bad_card=true;
        }

        while((c=getchar()!='\n')){
            if(c!=' '&&c!='\t'){
                bad_card=true;
            }
        }

        if(bad_card){
            printf("Bad card; ignored.\n");
        }else if (in_hand[suit][rank]){
            printf("Duplicate card;ignored.\n");
        }else{
            in_hand[suit][rank]=true;
            card_read++;
            num_in_rank[rank]++;
            num_in_suit[suit]++;
        }
        {
            /* code */
        }
        
    }
}

void analyze_cards(){
    straight=false;
    flush=false;
    four=false;
    three=false;
    pairs=0;

    for(int i=0;i<4;i++){
        if(num_in_suit[i]==5){
            flush=true;
        }
    }

    int idx=0;
    while(num_in_rank[idx]==0){
        idx++;
    }

    int n_consection=0;
    while(idx<13&&num_in_rank[idx]!=0){
        n_consection++;
        idx++;
    }

    if(n_consection==5){
        straight=5;
        return;
    }

    for(int i=0;i<13;i++){
        if(num_in_rank[i]==4){
            four=true;
        }else if(num_in_rank[i]==3){
            three=true;
        }else if(num_in_rank[i]==2){
            pairs++;
        }
    }
}

void print_cards(){
    if(flush&&straight){
        printf("Straight flush\n");
    }else if(four){
        printf("Four\n");
    }else if(three&&pairs){
        printf("Full horse\n");
    }else if(flush){
        printf("Flush\n");
    }else if(straight){
        printf("Straight\n");
    }else if(three){
        printf("Three\n");
    }else if(pairs==2){
        printf("Two pairs\n");
    }else if(pairs==1){
        printf("One pairs\n");
    }else{
        printf("High card\n");
    }
    printf("\n");
}

int main(){
    for(;;){
        read_cards();
        analyze_cards();
        print_cards();
    }
    
    return 0;
}