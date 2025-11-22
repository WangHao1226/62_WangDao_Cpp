// 编写程序模拟掷骰子的游戏（两个骰子）。第一次掷的时候，如果点数之和为 7 或 11 则获胜；如果点数之和为2、3或12则落败；
// 其他情况下的点数之和称为“目标”，游戏继续。在后续的投掷中，如果玩家再次掷出“目标”点数则获胜，掷出7则落败，
// 其他情况都忽略，游戏继续进行。每局游戏结束时，程序询问用户是否再玩一次，如果用 户输入的回答不是 y 或 Y ，程序会显示胜败的次数然后终止。

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

int roll_dice(){
    int die1=rand()%6+1;
    int die2=rand()%6+1;
    return die1+die2;
}

int main(){
    srand(time(NULL));
    int wins=0,losses=0;
    char play_again;

    do{
        int target=0;
        int first_roll=roll_dice();
        printf("\n第一次掷骰子结果:%d\n",first_roll);

        if(first_roll==7||first_roll==11){
            wins++;
            printf("你赢了！\n");
        }else if(first_roll==2||first_roll==3||first_roll==12){
            losses++;
            printf("你输了！\n");
        }else{
            target=first_roll;
            printf("现在目标是:%d\n",target);

            int new_roll;
            do{
                new_roll=roll_dice();
                printf("下一次掷骰子结果:%d\n",new_roll);

                if(new_roll==target){
                    wins++;
                    printf("你赢了！\n");
                    break;
                }else if(new_roll==7){
                    losses++;
                    printf("点数为7,你输了！\n");
                    break;
                }else{
                    printf("再来一次...\n");
                }
            }while(1);
        }

        printf("\n再玩一次吗?(y/n):\n");
        scanf("%c",&play_again);
        while(getchar()!='\n');
    }while(tolower(play_again)=='y');

    printf("\n====== 游戏统计 ======\n");
    printf("胜利次数: %d\n", wins);
    printf("失败次数: %d\n", losses);
    
    return 0;
}