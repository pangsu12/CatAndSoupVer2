#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>

#define ROOM_WIDTH  10
#define HME_POS 1
#define BWL_POS  (ROOM_WIDTH -2)


int main(void) {
    //초기값
    int scnt = 0; //지금까지 만든 수프의 개수 카운터
    int intimacy = 2; //친밀도 초기값 2
    int dice, move_threshold; //주사위 , 이동값

    int cat_pos = HME_POS;   // 고양이 현재 위치
    int prev_pos = -1; // 고양이 이전위치



    //1 -1 고양이 그림
    printf("****야옹이와 스프****\n \n");
    printf("       /\\_/\\  \n");
    printf(" /\\   / o o \\\n");
    printf("//\\\\  \\~(*)~/ \n");
    printf("`   \\/   ^ /\n");
    printf("    | \\|| ||\n");
    printf("    \\ `|| ||\n");
    printf("     \\)()-())\n");
    /* char name[100];
    printf("야옹이의 이름을 지어 주세요 : \n");
    scanf("%s", name);(
    printf("야옹이의 이름은 %s입니다.\n", name);*/

    printf("쫀떡이는 식빵을 굽고 있습니다.\n");
    Sleep(1000);
    system("cls");

    //1-2상태출력
    while (1) {
        Sleep(500);
        printf("==================== 현재상태===================\n");
        printf("현재까지 만든 수프 :  %d개\n", scnt);
        printf("집사와의 관계(0~4) :  %d\n", intimacy);
        switch (intimacy) {
        case 0: printf("    곁에 오는 것조차 싫어합니다.\n"); break;
        case 1: printf("    간식 자판기 취급입니다\n"); break;
        case 2: printf("    그럭저럭 쓸 만한 집사입니다.\n"); break;
        case 3: printf("    훌륭한 집사로 인정 받고 있습니다.\n"); break;
        case 4: printf("    집사 껌딱지입니다.\n"); break;
        }
        printf("=================================================\n\n");

        // 1-5 이동
        dice = rand() % 6 + 1;
        move_threshold = 6 - intimacy;
        Sleep(500);
        printf("쫀떡이 이동: 주사위 눈이 %d 이상이면 냄비쪽으로 이동합니다.\n", move_threshold);
        printf("주사위를 굴립니다... %d이(가) 나왔습니다!\n", dice);


        Sleep(500);
        //냄비 이동
        if (dice >= move_threshold) {
            if (cat_pos < BWL_POS) {
                prev_pos = cat_pos;
                cat_pos++;
                printf("냄비쪽으로 움직입니다.\n");
            }
            else {
                printf("벽에 막혀 이동하지 못했습니다.\n");
            }
        }
        //집 이동
        else {
            if (cat_pos > HME_POS) {
                cat_pos--;
                printf("집쪽으로 움직입니다.\n");
            }
            else {
                printf("벽에 막혀 이동하지 못했습니다.\n");
            }
        }
        Sleep(500);
        //1-6 행동
        if (cat_pos == BWL_POS) {
            printf("쫀덕이가 감자 수프를 만들었습니다.\n ");

            scnt++;
            printf("현재까지 만든 수프 :  %d개\n", scnt);
        }
        else if (cat_pos == HME_POS) {
            printf("쫀덕이는 자신의 집에서 편안함을 느낍니다.\n");
        }

        // 1-4 방그리기 ,1-5
        Sleep(500);
        printf("##########\n");
        printf("#H      B#\n");
        printf("#");
        for (int i = 1; i <= ROOM_WIDTH - 2; i++) {
            if (cat_pos == i) // cat_pos 가 1이면#C 2이면 # C
                printf("C");
            else if (prev_pos == i) //냄비이동후에 초기화된 prev_pos가 1이면 cat_post는 2
                printf(".");
            else
                printf(" "); //공백
        }
        printf("#\n");
        printf("##########\n");

        Sleep(500);

        // 1-3 상호작용
        int num;
        while (1) {
            Sleep(500);
            printf("어떤 상호작용을 하시겠습니까?     0. 아무것도 하지 않음  1. 긁어 주기\n");
            if (scanf_s("%d", &num) == 1 && (num == 0 || num == 1)) break;
            //0과 1을 입력 받기, 0과 1이 아닌 수가 입력되면 다시 입력받기
            //숫자 하나를 입력받았음 (참) and   num이 0이거나 1이면 true  그외 break 후 아래 출력
            printf("잘못된 입력입니다. 숫자 0 또는 1을 입력하세요.\n");
            while (getchar() != '\n'); // 입력 버퍼 비우기 
        }
        //0을 눌렀을 떄 상호작용
        if (num == 0) {
            dice = rand() % 6 + 1;
            printf("아무것도 하지 않습니다.\n");
            printf("4/6 확률로 친밀도가 떨어집니다.\n 주사위를 굴립니다.  또르륵 . . . \n %d이 나왔습니다!\n", dice);
            if (dice <= 4) {
                if (intimacy > 0) {
                    intimacy--;
                    printf("친밀도가 떨어졌습니다.\n현재 친밀도: %d\n", intimacy);
                }
                else {
                    printf("이미 최저 친밀도입니다.\n현재 친밀도: %d\n", intimacy);
                }
            }
            else {
                printf("다행히 친밀도가 떨어지지 않았습니다.\n현재 친밀도: %d\n", intimacy);
            }
        }
        //1을 눌렀을 때 상호작용 
        else {
            dice = rand() % 6 + 1;
            printf("쫀떡이의 턱을 긁어주었습니다.\n");
            printf("2/6 확률로 친밀도가 올라갑니다. \n주사위를 굴립니다.  또르륵 . . . \n %d이 나왔습니다!\n", dice);
            if (dice >= 5) {
                if (intimacy < 4) {
                    intimacy++;
                    printf("친밀도가 높아집니다. \n현재 친밀도: %d\n", intimacy);
                }
                else {
                    printf("이미 최고 친밀도입니다.\n현재 친밀도: %d\n", intimacy);
                }
            }
            else {
                printf("친밀도는 그대로입니다.\n현재 친밀도: %d\n", intimacy);
            }
        }

        Sleep(2500);
        system("cls");
    }


}
