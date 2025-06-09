#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>


#define ROOM_WIDTH  10
#define HME_POS 1
#define BWL_POS  (ROOM_WIDTH -2)


int has_toy_mouse = 0; //0�� �̺��� 1�� ����
int has_laser_pointer = 0;
int has_scratcher = 0; 
int has_cattower = 0; 
int cp = 0; //cp

int main(void) {
    //�ʱⰪ
    int scnt = 0; //���ݱ��� ���� ������ ���� ī����
    int intimacy = 2; //ģ�е� �ʱⰪ 2
    int dice, move_threshold; //�ֻ��� , �̵���
    int cat_pos = HME_POS;   // ����� ���� ��ġ
    int prev_pos = -1; // ����� ������ġ
    int mood = 3;//���
    int SCR_POS = 3;
    int CAT_POS = 6;
    int turn_count = 0;
    //1 -1 ����� �׸�
    printf("****�߿��̿� ����****\n \n");
    printf("       /\\_/\\  \n");
    printf(" /\\   / o o \\\n");
    printf("//\\\\  \\~(*)~/ \n");
    printf("`   \\/   ^ /\n");
    printf("    | \\|| ||\n");
    printf("    \\ `|| ||\n");
    printf("     \\)()-())\n");
    printf("�˶��̴� �Ļ��� ���� �ֽ��ϴ�.\n");
    Sleep(1000);
    system("cls");
    //1-2�������
    while (1) {
        Sleep(500);
        printf("==================== �������===================\n");
        printf("������� ���� ���� :  %d��\n", scnt);
        printf("cp: %d ����Ʈ\n", cp);
        printf("�˴����� ���(0~3): %d\n", mood);
        switch (mood) {
        case 0:printf("     ����� �ſ� ���޴ϴ�.\n"); break;
        case 1:printf("     �ɽ����մϴ�.\n"); break;
        case 2:printf("     �Ļ��� �����ϴ�.\n"); break;
        case 3:printf("     ������ �θ��ϴ�.\n"); break;
        }

        printf("������� ����(0~4) :  %d\n", intimacy);
        switch (intimacy) {
        case 0: printf("    �翡 ���� ������ �Ⱦ��մϴ�.\n"); break;
        case 1: printf("    ���� ���Ǳ� ����Դϴ�\n"); break;
        case 2: printf("    �׷����� �� ���� �����Դϴ�.\n"); break;
        case 3: printf("    �Ǹ��� ����� ���� �ް� �ֽ��ϴ�.\n"); break;
        case 4: printf("    ���� �������Դϴ�.\n"); break;
        }
        printf("=================================================\n\n");
        //2-2
        int dicelimit = 6 - intimacy;
        printf("6-%d: �ֻ��� ���� %d�����̸� �׳� ����� �Ϻ����ϴ�.\n", intimacy, dicelimit);
        printf("�ֻ����������ϴ�. �Ǹ���...\n");
        int mooddice = rand() % 6 + 1;
        printf("%d�� ���Խ��ϴ�.\n",mooddice);
        if (mooddice <= dicelimit) {
            if (mood > 0) {
                printf("�˴��� ����� �������ϴ�. : %d -> %d\n", mood, mood-1);
                mood--;
            }
            else {
                printf("�˴��� ����� �������ϴ�. : %d -> %d\n", mood, mood);
            }
               
        }


        // 1-5 �̵�
        dice = rand() % 6 + 1;
        move_threshold = 6 - intimacy;
        Sleep(500);
        printf("�˶��� �̵�: �ֻ��� ���� %d �̻��̸� ���������� �̵��մϴ�.\n", move_threshold);
        printf("�ֻ����� �����ϴ�... %d��(��) ���Խ��ϴ�!\n", dice);


        Sleep(500);
        prev_pos = cat_pos;

        if (mood == 0) {
            printf("����� �ſ� ���� �˶��̴� ������ ���մϴ�.\n");
            if (cat_pos > HME_POS) cat_pos--;
        }
        else if (mood == 1) {
            if (has_scratcher) {
                printf("�˶��̴� �ɽ��ؼ� ��ũ��ó ������ �̵��մϴ�.\n");
                if (cat_pos < SCR_POS) cat_pos++;
                else if (cat_pos > SCR_POS) cat_pos--;
            }
            else {
                printf("��Ÿ��� ��� ����� �ſ� �������ϴ�.\n");
                if (mood > 0) mood--;
            }
        }
        else if (mood == 2) {
            printf("�˶��̴� ��� ���� �Ļ��� ���� �ֽ��ϴ�.\n");
            // �̵� ����
        }
        else if (mood == 3) {
            printf("�˶��̴� ������ �θ��� ������ ���鷯 ���ϴ�.\n");
            if (cat_pos < BWL_POS) cat_pos++;
        }

        Sleep(500);
        
        

        // 1-4 ��׸��� ,1-5
        Sleep(500);
        for (int i = 0; i < ROOM_WIDTH; i++) printf("#");
        printf("\n");

        // ù ��° ��: H, B, ����(S/T)
        printf("#H");
        for (int i = 2; i < BWL_POS; i++) {
            if (has_scratcher && i == SCR_POS) printf("S");
            else if (has_cattower && i == CAT_POS) printf("T");
            else printf(" ");
        }
        printf("B#\n");

        // �� ��° ��: �����(C)�� �̵� ����(.)
        printf("#");
        for (int i = 1; i < ROOM_WIDTH - 1; i++) {
            if (i == cat_pos) printf("C");
            else if (i == prev_pos) printf(".");
            else printf(" ");
        }
        printf("#\n");
        for (int i = 0; i < ROOM_WIDTH; i++) printf("#");

        Sleep(500);
        // �ൿ ó�� (�˶��� ��ġ ��� ȿ��)
        if (cat_pos == BWL_POS) {
            printf("�˶��̰� ���� ������ ��������ϴ�.\n");
            scnt++;
            printf("������� ���� ���� : %d��\n", scnt);
        }
        else if (cat_pos == HME_POS) {
            if (prev_pos == HME_POS) {  // ���� ��� �ִ� ����
                if (mood < 3) {
                    printf("�˶��̴� ������ ����ϰ� ���� �ֽ��ϴ�.\n");
                    printf("����� ���� ���������ϴ�: %d -> %d\n", mood, mood + 1);
                    mood++;
                }

            }
        }
        else if (cat_pos == SCR_POS && has_scratcher) {
            if (mood < 3) {
                printf("�˶��̴� ��ũ��ó�� �ܰ� ��ҽ��ϴ�.\n");
                printf("����� ���� ���������ϴ�: %d -> %d\n", mood, mood + 1);
                mood++;
            }
            
        }
        else if (cat_pos == CAT_POS && has_cattower) {
            int prev_mood = mood;
            mood += 2;
            if (mood > 3) mood = 3;
            printf("�˶��̴� ĹŸ���� �پ�ٴմϴ�.\n");
            printf("����� ���� ���������ϴ�: %d -> %d\n", prev_mood, mood);
        }

        // 1-3 ��ȣ�ۿ�, 2-5~2-6
        int num;
        while (1) {
            printf("\n� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n");
            printf("0. �ƹ��͵� ���� ����\n");
            printf("1. �ܾ� �ֱ�\n");

            int option_num = 2;
            if (has_toy_mouse) {
                printf("%d. �峭�� ��� ��� �ֱ�\n", option_num);
                option_num++;
            }
            if (has_laser_pointer) {
                printf("%d. ������ �����ͷ� ��� �ֱ�\n", option_num);
            }

            printf(">> ");
            if (scanf_s("%d", &num) == 1) {
                int max_option = 1 + has_toy_mouse + has_laser_pointer;
                if (num >= 0 && num <= max_option) break;
            }
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
            while (getchar() != '\n');
        }

        // ��ȣ�ۿ� ó��
        int dice = rand() % 6 + 1;
        switch (num) {
        case 0:
            printf("�ƹ��͵� ���� �ʽ��ϴ�.\n");
            if (mood > 0) {
                mood--;
                printf("����� ���������ϴ�: %d -> %d\n", mood + 1, mood);
            }
            if (dice <= 5 && intimacy > 0) {
                intimacy--;
                printf("ģ�е��� ���������ϴ�: %d -> %d\n", intimacy + 1, intimacy);
            }
            break;

        case 1:
            printf("���� �ܾ��־����ϴ�.\n");
            if (dice >= 5 && intimacy < 4) {
                intimacy++;
                printf("ģ�е��� �ö����ϴ�: %d -> %d\n", intimacy - 1, intimacy);
            }
            break;

        case 2:
            if (has_toy_mouse && (!has_laser_pointer || num == 2)) {
                printf("�峭�� ��� ����־����ϴ�.\n");
                if (mood < 3) {
                    mood++;
                    printf("����� ���������ϴ�: %d -> %d\n", mood - 1, mood);
                }
                if (dice >= 4 && intimacy < 4) {
                    intimacy++;
                    printf("ģ�е��� �ö����ϴ�: %d -> %d\n", intimacy - 1, intimacy);
                }
            }
            else {
                printf("������ �����ͷ� ����־����ϴ�!\n");
                mood = (mood + 2 > 3) ? 3 : mood + 2;
                printf("����� �ſ� ���������ϴ�: %d -> %d\n", mood - 2, mood);
                if (dice >= 2 && intimacy < 4) {
                    intimacy++;
                    printf("ģ�е��� �ö����ϴ�: %d -> %d\n", intimacy - 1, intimacy);
                }
            }
            break;
        }
        int base_value = 3; // �ܵ��� �⺻��
        int new_cp = (base_value - 1 > 0 ? base_value - 1 : 0) + intimacy;
        cp += new_cp;
        printf("CP %d����Ʈ ����Ǿ����ϴ�! (���� CP: %d)\n", new_cp, cp);
        if (cp > 0) { // CP�� ���� ���� ���� ǥ��
            int buy_choice;
            while (1) {
                printf("\n�������� ������ �� �� �ֽ��ϴ�. �����ұ��?\n");
                printf("0. �ƹ��͵� ���� �ʴ´�\n");
                printf("1. �峲�� ��: 1 CP%s\n", has_toy_mouse ? " (������)" : "");
                printf("2. ������ ������: 2 CP%s\n", has_laser_pointer ? " (������)" : "");
                printf("3. ��ũ��ó: 4 CP%s\n", has_scratcher ? " (������)" : "");
                printf("4. Ĺ Ÿ��: 6 CP%s\n", has_cattower ? " (������)" : "");
                printf(">> ");

                if (scanf_s("%d", &buy_choice) == 1 && buy_choice >= 0 && buy_choice <= 4) {
                    break;
                }
                printf("�߸��� �Է��Դϴ�.\n");
                while (getchar() != '\n');
            }

            // ���� ó��
            switch (buy_choice) {
            case 1:
                if (has_toy_mouse) {
                    printf("�̹� �峲�� �㸦 �����߽��ϴ�.\n");
                }
                else if (cp >= 1) {
                    cp -= 1;
                    has_toy_mouse = 1;
                    printf("�峲�� �㸦 �����߽��ϴ�! (���� CP: %d)\n", cp);
                }
                else {
                    printf("CP�� �����մϴ�.\n");
                }
                break;

            case 2:
                if (has_laser_pointer) {
                    printf("�̹� ������ �����͸� �����߽��ϴ�.\n");
                }
                else if (cp >= 2) {
                    cp -= 2;
                    has_laser_pointer = 1;
                    printf("������ �����͸� �����߽��ϴ�! (���� CP: %d)\n", cp);
                }
                else {
                    printf("CP�� �����մϴ�.\n");
                }
                break;

            case 3:
                if (has_scratcher) {
                    printf("�̹� ��ũ��ó�� �����߽��ϴ�.\n");
                }
                else if (cp >= 4) {
                    cp -= 4;
                    has_scratcher = 1;
                    // ��ũ��ó ��ġ ���� ��ġ (���� ������ ��ġ�� �ʰ�)
                    do {
                        SCR_POS = rand() % (ROOM_WIDTH - 2) + 1;
                    } while (SCR_POS == CAT_POS || SCR_POS == HME_POS || SCR_POS == BWL_POS);
                    printf("��ũ��ó�� %d�� ��ġ�� ��ġ�߽��ϴ�! (���� CP: %d)\n", SCR_POS, cp);
                }
                else {
                    printf("CP�� �����մϴ�.\n");
                }
                break;

            case 4:
                if (has_cattower) {
                    printf("�̹� Ĺ Ÿ���� �����߽��ϴ�.\n");
                }
                else if (cp >= 6) {
                    cp -= 6;
                    has_cattower = 1;
                    // ĹŸ�� ��ġ ���� ��ġ
                    do {
                        CAT_POS = rand() % (ROOM_WIDTH - 2) + 1;
                    } while (CAT_POS == SCR_POS || CAT_POS == HME_POS || CAT_POS == BWL_POS);
                    printf("Ĺ Ÿ���� %d�� ��ġ�� ��ġ�߽��ϴ�! (���� CP: %d)\n", CAT_POS, cp);
                }
                else {
                    printf("CP�� �����մϴ�.\n");
                }
                break;
            }
        }

        if (turn_count == 3) {
            int correct_cup = rand() % 3 + 1;
            int guess;

            printf("\t ���� ����Ʈ �߻�! \n");
            printf("�˶��̰� �����ϴ� ������ �� �� �� �� �ϳ��� ������ϴ�!\n");
            printf("1, 2, 3 �� ��� �ſ� ������ �������?\n");

            while (1) {
                printf("����� ���� (1~3): ");
                if (scanf_s("%d", &guess) == 1 && guess >= 1 && guess <= 3) break;
                printf("�߸��� �Է��߾��. ���� 1, 2, 3 �� �ϳ��� �Է��ϼ���.\n");
                while (getchar() != '\n'); //���ۺ���
            }

            if (guess == correct_cup) {
                printf("�����Դϴ�! �˶��̿��� ģ�е��� ����մϴ�!\n");
                if (intimacy < 4) intimacy++;
            }
            else {
                printf("Ʋ�Ƚ��ϴ٤Ф�... �˶��̿��� ģ�е��� �����մϴ�.\n");
                if (intimacy > 0) intimacy--;
            }

            printf("���� ģ�е�: %d\n", intimacy);
            Sleep(3000);
        }


        Sleep(2500);
        turn_count++; 

        system("cls");
    }


}
