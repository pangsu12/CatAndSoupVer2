#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>

#define ROOM_WIDTH  10
#define HME_POS 1
#define BWL_POS  (ROOM_WIDTH -2)


int main(void) {
    //�ʱⰪ
    int scnt = 0; //���ݱ��� ���� ������ ���� ī����
    int intimacy = 2; //ģ�е� �ʱⰪ 2
    int dice, move_threshold; //�ֻ��� , �̵���

    int cat_pos = HME_POS;   // ����� ���� ��ġ
    int prev_pos = -1; // ����� ������ġ
    
    
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
        //���� �̵�
        if (dice >= move_threshold) {
            if (cat_pos < BWL_POS) {
                prev_pos = cat_pos;
                cat_pos++;
                printf("���������� �����Դϴ�.\n");
            }
            else {
                printf("���� ���� �̵����� ���߽��ϴ�.\n");
            }
        }
        //�� �̵�
        else {
            if (cat_pos > HME_POS) {
                cat_pos--;
                printf("�������� �����Դϴ�.\n");
            }
            else {
                printf("���� ���� �̵����� ���߽��ϴ�.\n");
            }
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

        // 1-3 ��ȣ�ۿ�
        int num;
        while (1) {
            Sleep(500);
            printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?     0. �ƹ��͵� ���� ����  1. �ܾ� �ֱ�\n");
            if (scanf_s("%d", &num) == 1 && (num == 0 || num == 1)) break;
            //0�� 1�� �Է� �ޱ�, 0�� 1�� �ƴ� ���� �ԷµǸ� �ٽ� �Է¹ޱ�
            //���� �ϳ��� �Է¹޾��� (��) and   num�� 0�̰ų� 1�̸� true  �׿� break �� �Ʒ� ���
            printf("�߸��� �Է��Դϴ�. ���� 0 �Ǵ� 1�� �Է��ϼ���.\n");
            while (getchar() != '\n'); // �Է� ���� ���� 
        }
        //0�� ������ �� ��ȣ�ۿ�
        if (num == 0) {
            dice = rand() % 6 + 1;
            printf("�ƹ��͵� ���� �ʽ��ϴ�.\n");
            printf("4/6 Ȯ���� ģ�е��� �������ϴ�.\n �ֻ����� �����ϴ�.  �Ǹ��� . . . \n %d�� ���Խ��ϴ�!\n", dice);
            if (dice <= 4) {
                if (intimacy > 0) {
                    intimacy--;
                    printf("ģ�е��� ���������ϴ�.\n���� ģ�е�: %d\n", intimacy);
                }
                else {
                    printf("�̹� ���� ģ�е��Դϴ�.\n���� ģ�е�: %d\n", intimacy);
                }
            }
            else {
                printf("������ ģ�е��� �������� �ʾҽ��ϴ�.\n���� ģ�е�: %d\n", intimacy);
            }
        }
        //1�� ������ �� ��ȣ�ۿ� 
        else {
            dice = rand() % 6 + 1;
            printf("�˶����� ���� �ܾ��־����ϴ�.\n");
            printf("2/6 Ȯ���� ģ�е��� �ö󰩴ϴ�. \n�ֻ����� �����ϴ�.  �Ǹ��� . . . \n %d�� ���Խ��ϴ�!\n", dice);
            if (dice >= 5) {
                if (intimacy < 4) {
                    intimacy++;
                    printf("ģ�е��� �������ϴ�. \n���� ģ�е�: %d\n", intimacy);
                }
                else {
                    printf("�̹� �ְ� ģ�е��Դϴ�.\n���� ģ�е�: %d\n", intimacy);
                }
            }
            else {
                printf("ģ�е��� �״���Դϴ�.\n���� ģ�е�: %d\n", intimacy);
            }
        }

        Sleep(2500);
        system("cls");
    }


}
