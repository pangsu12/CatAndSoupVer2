#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>


#define ROOM_WIDTH  10
#define HME_POS 1
#define BWL_POS  (ROOM_WIDTH -2)


int has_toy_mouse = 0; //0이 미보유 1이 보유
int has_laser_pointer = 0;
int has_scratcher = 0; 
int has_cattower = 0; 
int cp = 0; //cp

int main(void) {
    //초기값
    int scnt = 0; //지금까지 만든 수프의 개수 카운터
    int intimacy = 2; //친밀도 초기값 2
    int dice, move_threshold; //주사위 , 이동값
    int cat_pos = HME_POS;   // 고양이 현재 위치
    int prev_pos = -1; // 고양이 이전위치
    int mood = 3;//기분
    int SCR_POS = 3;
    int CAT_POS = 6;
    int turn_count = 0;
    //1 -1 고양이 그림
    printf("****야옹이와 스프****\n \n");
    printf("       /\\_/\\  \n");
    printf(" /\\   / o o \\\n");
    printf("//\\\\  \\~(*)~/ \n");
    printf("`   \\/   ^ /\n");
    printf("    | \\|| ||\n");
    printf("    \\ `|| ||\n");
    printf("     \\)()-())\n");
    printf("쫀떡이는 식빵을 굽고 있습니다.\n");
    Sleep(1000);
    system("cls");
    //1-2상태출력
    while (1) {
        Sleep(500);
        printf("==================== 현재상태===================\n");
        printf("현재까지 만든 수프 :  %d개\n", scnt);
        printf("cp: %d 포인트\n", cp);
        printf("쫀덕이의 기분(0~3): %d\n", mood);
        switch (mood) {
        case 0:printf("     기분이 매우 나쁩니다.\n"); break;
        case 1:printf("     심심해합니다.\n"); break;
        case 2:printf("     식빵을 굽습니다.\n"); break;
        case 3:printf("     골골송을 부릅니다.\n"); break;
        }

        printf("집사와의 관계(0~4) :  %d\n", intimacy);
        switch (intimacy) {
        case 0: printf("    곁에 오는 것조차 싫어합니다.\n"); break;
        case 1: printf("    간식 자판기 취급입니다\n"); break;
        case 2: printf("    그럭저럭 쓸 만한 집사입니다.\n"); break;
        case 3: printf("    훌륭한 집사로 인정 받고 있습니다.\n"); break;
        case 4: printf("    집사 껌딱지입니다.\n"); break;
        }
        printf("=================================================\n\n");
        //2-2
        int dicelimit = 6 - intimacy;
        printf("6-%d: 주사위 눈이 %d이하이면 그냥 기분이 니빠집니다.\n", intimacy, dicelimit);
        printf("주사위를굴립니다. 또르르...\n");
        int mooddice = rand() % 6 + 1;
        printf("%d가 나왔습니다.\n",mooddice);
        if (mooddice <= dicelimit) {
            if (mood > 0) {
                printf("쫀덕의 기분이 나빠집니다. : %d -> %d\n", mood, mood-1);
                mood--;
            }
            else {
                printf("쫀덕의 기분이 나빠집니다. : %d -> %d\n", mood, mood);
            }
               
        }


        // 1-5 이동
        dice = rand() % 6 + 1;
        move_threshold = 6 - intimacy;
        Sleep(500);
        printf("쫀떡이 이동: 주사위 눈이 %d 이상이면 냄비쪽으로 이동합니다.\n", move_threshold);
        printf("주사위를 굴립니다... %d이(가) 나왔습니다!\n", dice);


        Sleep(500);
        prev_pos = cat_pos;

        if (mood == 0) {
            printf("기분이 매우 나쁜 쫀떡이는 집으로 향합니다.\n");
            if (cat_pos > HME_POS) cat_pos--;
        }
        else if (mood == 1) {
            if (has_scratcher) {
                printf("쫀떡이는 심심해서 스크래처 쪽으로 이동합니다.\n");
                if (cat_pos < SCR_POS) cat_pos++;
                else if (cat_pos > SCR_POS) cat_pos--;
            }
            else {
                printf("놀거리가 없어서 기분이 매우 나빠집니다.\n");
                if (mood > 0) mood--;
            }
        }
        else if (mood == 2) {
            printf("쫀떡이는 기분 좋게 식빵을 굽고 있습니다.\n");
            // 이동 없음
        }
        else if (mood == 3) {
            printf("쫀떡이는 골골송을 부르며 수프를 만들러 갑니다.\n");
            if (cat_pos < BWL_POS) cat_pos++;
        }

        Sleep(500);
        
        

        // 1-4 방그리기 ,1-5
        Sleep(500);
        for (int i = 0; i < ROOM_WIDTH; i++) printf("#");
        printf("\n");

        // 첫 번째 줄: H, B, 가구(S/T)
        printf("#H");
        for (int i = 2; i < BWL_POS; i++) {
            if (has_scratcher && i == SCR_POS) printf("S");
            else if (has_cattower && i == CAT_POS) printf("T");
            else printf(" ");
        }
        printf("B#\n");

        // 두 번째 줄: 고양이(C)와 이동 흔적(.)
        printf("#");
        for (int i = 1; i < ROOM_WIDTH - 1; i++) {
            if (i == cat_pos) printf("C");
            else if (i == prev_pos) printf(".");
            else printf(" ");
        }
        printf("#\n");
        for (int i = 0; i < ROOM_WIDTH; i++) printf("#");

        Sleep(500);
        // 행동 처리 (쫀떡이 위치 기반 효과)
        if (cat_pos == BWL_POS) {
            printf("쫀떡이가 감자 수프를 만들었습니다.\n");
            scnt++;
            printf("현재까지 만든 수프 : %d개\n", scnt);
        }
        else if (cat_pos == HME_POS) {
            if (prev_pos == HME_POS) {  // 집에 계속 있는 상태
                if (mood < 3) {
                    printf("쫀떡이는 집에서 편안하게 쉬고 있습니다.\n");
                    printf("기분이 조금 좋아졌습니다: %d -> %d\n", mood, mood + 1);
                    mood++;
                }

            }
        }
        else if (cat_pos == SCR_POS && has_scratcher) {
            if (mood < 3) {
                printf("쫀떡이는 스크래처를 긁고 놀았습니다.\n");
                printf("기분이 조금 좋아졌습니다: %d -> %d\n", mood, mood + 1);
                mood++;
            }
            
        }
        else if (cat_pos == CAT_POS && has_cattower) {
            int prev_mood = mood;
            mood += 2;
            if (mood > 3) mood = 3;
            printf("쫀떡이는 캣타워를 뛰어다닙니다.\n");
            printf("기분이 제법 좋아졌습니다: %d -> %d\n", prev_mood, mood);
        }

        // 1-3 상호작용, 2-5~2-6
        int num;
        while (1) {
            printf("\n어떤 상호작용을 하시겠습니까?\n");
            printf("0. 아무것도 하지 않음\n");
            printf("1. 긁어 주기\n");

            int option_num = 2;
            if (has_toy_mouse) {
                printf("%d. 장난감 쥐로 놀아 주기\n", option_num);
                option_num++;
            }
            if (has_laser_pointer) {
                printf("%d. 레이저 포인터로 놀아 주기\n", option_num);
            }

            printf(">> ");
            if (scanf_s("%d", &num) == 1) {
                int max_option = 1 + has_toy_mouse + has_laser_pointer;
                if (num >= 0 && num <= max_option) break;
            }
            printf("잘못된 입력입니다. 다시 입력하세요.\n");
            while (getchar() != '\n');
        }

        // 상호작용 처리
        int dice = rand() % 6 + 1;
        switch (num) {
        case 0:
            printf("아무것도 하지 않습니다.\n");
            if (mood > 0) {
                mood--;
                printf("기분이 나빠졌습니다: %d -> %d\n", mood + 1, mood);
            }
            if (dice <= 5 && intimacy > 0) {
                intimacy--;
                printf("친밀도가 떨어졌습니다: %d -> %d\n", intimacy + 1, intimacy);
            }
            break;

        case 1:
            printf("턱을 긁어주었습니다.\n");
            if (dice >= 5 && intimacy < 4) {
                intimacy++;
                printf("친밀도가 올랐습니다: %d -> %d\n", intimacy - 1, intimacy);
            }
            break;

        case 2:
            if (has_toy_mouse && (!has_laser_pointer || num == 2)) {
                printf("장난감 쥐로 놀아주었습니다.\n");
                if (mood < 3) {
                    mood++;
                    printf("기분이 좋아졌습니다: %d -> %d\n", mood - 1, mood);
                }
                if (dice >= 4 && intimacy < 4) {
                    intimacy++;
                    printf("친밀도가 올랐습니다: %d -> %d\n", intimacy - 1, intimacy);
                }
            }
            else {
                printf("레이저 포인터로 놀아주었습니다!\n");
                mood = (mood + 2 > 3) ? 3 : mood + 2;
                printf("기분이 매우 좋아졌습니다: %d -> %d\n", mood - 2, mood);
                if (dice >= 2 && intimacy < 4) {
                    intimacy++;
                    printf("친밀도가 올랐습니다: %d -> %d\n", intimacy - 1, intimacy);
                }
            }
            break;
        }
        int base_value = 3; // 콘덱의 기본값
        int new_cp = (base_value - 1 > 0 ? base_value - 1 : 0) + intimacy;
        cp += new_cp;
        printf("CP %d포인트 생산되었습니다! (보유 CP: %d)\n", new_cp, cp);
        if (cp > 0) { // CP가 있을 때만 상점 표시
            int buy_choice;
            while (1) {
                printf("\n상점에서 물건을 살 수 있습니다. 구매할까요?\n");
                printf("0. 아무것도 사지 않는다\n");
                printf("1. 장남감 쥐: 1 CP%s\n", has_toy_mouse ? " (구매함)" : "");
                printf("2. 레이저 포인터: 2 CP%s\n", has_laser_pointer ? " (구매함)" : "");
                printf("3. 스크래처: 4 CP%s\n", has_scratcher ? " (구매함)" : "");
                printf("4. 캣 타워: 6 CP%s\n", has_cattower ? " (구매함)" : "");
                printf(">> ");

                if (scanf_s("%d", &buy_choice) == 1 && buy_choice >= 0 && buy_choice <= 4) {
                    break;
                }
                printf("잘못된 입력입니다.\n");
                while (getchar() != '\n');
            }

            // 구매 처리
            switch (buy_choice) {
            case 1:
                if (has_toy_mouse) {
                    printf("이미 장남감 쥐를 구매했습니다.\n");
                }
                else if (cp >= 1) {
                    cp -= 1;
                    has_toy_mouse = 1;
                    printf("장남감 쥐를 구매했습니다! (보유 CP: %d)\n", cp);
                }
                else {
                    printf("CP가 부족합니다.\n");
                }
                break;

            case 2:
                if (has_laser_pointer) {
                    printf("이미 레이저 포인터를 구매했습니다.\n");
                }
                else if (cp >= 2) {
                    cp -= 2;
                    has_laser_pointer = 1;
                    printf("레이저 포인터를 구매했습니다! (보유 CP: %d)\n", cp);
                }
                else {
                    printf("CP가 부족합니다.\n");
                }
                break;

            case 3:
                if (has_scratcher) {
                    printf("이미 스크래처를 구매했습니다.\n");
                }
                else if (cp >= 4) {
                    cp -= 4;
                    has_scratcher = 1;
                    // 스크래처 위치 랜덤 배치 (기존 가구와 겹치지 않게)
                    do {
                        SCR_POS = rand() % (ROOM_WIDTH - 2) + 1;
                    } while (SCR_POS == CAT_POS || SCR_POS == HME_POS || SCR_POS == BWL_POS);
                    printf("스크래처를 %d번 위치에 설치했습니다! (보유 CP: %d)\n", SCR_POS, cp);
                }
                else {
                    printf("CP가 부족합니다.\n");
                }
                break;

            case 4:
                if (has_cattower) {
                    printf("이미 캣 타워를 구매했습니다.\n");
                }
                else if (cp >= 6) {
                    cp -= 6;
                    has_cattower = 1;
                    // 캣타워 위치 랜덤 배치
                    do {
                        CAT_POS = rand() % (ROOM_WIDTH - 2) + 1;
                    } while (CAT_POS == SCR_POS || CAT_POS == HME_POS || CAT_POS == BWL_POS);
                    printf("캣 타워를 %d번 위치에 설치했습니다! (보유 CP: %d)\n", CAT_POS, cp);
                }
                else {
                    printf("CP가 부족합니다.\n");
                }
                break;
            }
        }

        if (turn_count == 3) {
            int correct_cup = rand() % 3 + 1;
            int guess;

            printf("\t 돌발 퀘스트 발생! \n");
            printf("쫀떡이가 좋아하는 간식을 컵 세 개 중 하나에 숨겼습니다!\n");
            printf("1, 2, 3 중 어느 컵에 간식이 있을까요?\n");

            while (1) {
                printf("당신의 선택 (1~3): ");
                if (scanf_s("%d", &guess) == 1 && guess >= 1 && guess <= 3) break;
                printf("잘못된 입력했어요. 숫자 1, 2, 3 중 하나를 입력하세요.\n");
                while (getchar() != '\n'); //버퍼비우기
            }

            if (guess == correct_cup) {
                printf("정답입니다! 쫀떡이와의 친밀도가 상승합니다!\n");
                if (intimacy < 4) intimacy++;
            }
            else {
                printf("틀렸습니다ㅠㅠ... 쫀떡이와의 친밀도가 감소합니다.\n");
                if (intimacy > 0) intimacy--;
            }

            printf("현재 친밀도: %d\n", intimacy);
            Sleep(3000);
        }


        Sleep(2500);
        turn_count++; 

        system("cls");
    }


}
