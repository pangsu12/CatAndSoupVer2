#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>

#define ROOM_WIDTH  10
#define HME_POS 1
#define BWL_POS  (ROOM_WIDTH -2)
#define SCR_POS 3
#define CAT_POS 6

int has_toy_mouse = 0;
int has_laser_pointer = 0;

int main(void) {
    //�ʱⰪ
    int scnt = 0; //���ݱ��� ���� ������ ���� ī����
    int intimacy = 2; //ģ�е� �ʱⰪ 2
    int dice, move_threshold; //�ֻ��� , �̵���

    int cat_pos = HME_POS;   // ����� ���� ��ġ
    int prev_pos = -1; // ����� ������ġ
    int has_scratcher = 1; // ���̱ⱸ ����
    int has_cattower = 1; //ĹŸ�� ����
 \

    int cp = 0; //cp
    int mood = 3;//���



    //1 -1 ����� �׸�
    printf("****�߿��̿� ����****\n \n");
    printf("       /\\_/\\  \n");
    printf(" /\\   / o o \\\n");
    printf("//\\\\  \\~(*)~/ \n");
    printf("`   \\/   ^ /\n");
    printf("    | \\|| ||\n");
    printf("    \\ `|| ||\n");
    printf("     \\)()-())\n");
    /* char name[100];
    printf("�߿����� �̸��� ���� �ּ��� : \n");
    scanf("%s", name);(
    printf("�߿����� �̸��� %s�Դϴ�.\n", name);*/

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
        case 0:printf("     ����� �ſ� ���޴ϴ�.\n");
        case 1:printf("     �ɽ����մϴ�.\n");
        case 2:printf("     �Ļ��� �����ϴ�.\n");
        case 3:printf("     ������ �θ��ϴ�.\n");
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
        printf("%d�� ���Խ��ϴ�.\n");
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
        ////���� �̵�
        //if (dice >= move_threshold) {
        //    if (cat_pos < BWL_POS) {
        //        prev_pos = cat_pos;
        //        cat_pos++;
        //        printf("���������� �����Դϴ�.\n");
        //    }
        //    else {
        //        printf("���� ���� �̵����� ���߽��ϴ�.\n");
        //    }
        //}
        ////�� �̵�
        //else {
        //    if (cat_pos > HME_POS) {
        //        cat_pos--;
        //        printf("�������� �����Դϴ�.\n");
        //    }
        //    else {
        //        printf("���� ���� �̵����� ���߽��ϴ�.\n");
        //    }
        //}
        /*2-3*/
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
        //1-6 �ൿ
        if (cat_pos == BWL_POS) {
            printf("�˴��̰� ���� ������ ��������ϴ�.\n ");

            scnt++;
            printf("������� ���� ���� :  %d��\n", scnt);
        }
        else if (cat_pos == HME_POS) {
            printf("�˴��̴� �ڽ��� ������ ������� �����ϴ�.\n");
        }

        // 1-4 ��׸��� ,1-5
        Sleep(500);
        printf("##########\n");
        printf("#H      B#\n");
        printf("#");
        for (int i = 1; i <= ROOM_WIDTH - 2; i++) {
            if (cat_pos == i) // cat_pos �� 1�̸�#C 2�̸� # C
                printf("C");
            else if (prev_pos == i) //�����̵��Ŀ� �ʱ�ȭ�� prev_pos�� 1�̸� cat_post�� 2
                printf(".");
            else
                printf(" "); //����
        }
        printf("#\n");
        printf("##########\n");

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


        Sleep(2500);
        system("cls");
    }


}
