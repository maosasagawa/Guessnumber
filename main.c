#define _CRT_SECURE_NO_WARNINGS
/*
 *
 *
 *
 *
 *
 */
#include<stdio.h>
#include<stdlib.h>//rand srand����
#include<time.h>//time����
#include <Windows.h>//ʹ��sleep����

void PrintRule();//�����Ϸ���򣬵�����װ�ɺ����ǲ���main����̫������Ӱ�����ɶ���

void Player();//�����ڣ���ң���ʱ��ִ�����

void Magician();//��������Ϊħ��ʦ��ʱ��

int GuessNum(int sum);//���Բ����ֵĹ���

int MyRand();//����������ĺ���
int main() {
    int t;
    srand((unsigned) time(NULL));//����
    START:
    system("@cls||clear");
    PrintRule();
    printf("���뵱���ڻ���ħ��ʦ�أ��뵱����������0���뵱ħ��ʦ�Ļ�������1��ͻȻ�������˾�����n�ɣ�");
    t = getchar();
    while (getchar() != '\n');
    switch (t) {
        case '0':
            Player();
            break;
        case '1':
            Magician();
            break;
        case 'n':
            break;
        default:
            printf("û�б���淨Ŷ��������һ�����...\n");
            Sleep(1700);//�ó���˯һ�������Ȼ������������Ļ�ϵ�����
            while (getchar() != '\n');//��ֹ���Ƥ����һ����ַ����³��������������������Ե���
            goto START;
    }
    printf("��Ĳ�������һ������Ļ�����y,����������İ�:");
    t = getchar();

    if (t == 'y' || t == 'Y') { while (getchar() != '\n');
        goto START; }
    system("mshta \"javascript:new ActiveXObject('WScript.Shell').popup('��л���棬��ӭ�´�����!',7,'��λ��ħ��ʦ',64);window.close();\"");
    return 0;
}

void PrintRule() {
    printf(
           "������������������������������������������������������������������������������\n"
           "��                                     ��\n"
           "��            ��λ��Сħ��             ��\n"
           "��                                     ��\n"
           "��        ֻҪ����������λ��           ��\n"
           "��      �ҾͿ��Բ³��Ǹ����Ƕ���       ��\n"
           "��                                     ��\n"
           "��      ��Ȼ����Ҳ��������ħ��ʦ       ��\n"
           "��         ����̽����������            ��\n"
           "��                                     ��\n"
           "��                                     ��\n"
           "��                                     ��\n"
           "��          ���������ǿ�ʼ��           ��\n"
           "��                                     ��\n"
           "������������������������������������������������������������������������������\n");
}

void Player() {
    char t;
    int sum = 0, num = 0;
    printf("��������һ����λ���ҿ��Բµ�����������ʲô����Ŷ\n");
    Sleep(2000);
    printf("�������׼�������������(abc)��λ��ʮλ����λ�����������(acb��bac��bca��cab��cba)�ĺͰ�\n");
    Sleep(2500);
    printf("ʲô����˵��λ����������Ϸ�ʽ����ֻ�����֣����������־͵��ڸ����ҵ������ˣ�\n");
    Sleep(4000);
    printf("�����ˣ����Ҹ����һ����ļ������ɣ����������������\n");
    Sleep(4000);
    system("explorer \"https://www.geogebra.org/scientific?lang=zh_CN\"");
    Sleep(500);
    printf("�����ڿ��Ը�����������˰ɣ�");
    TELLME:
    scanf("%d", &sum);
    while (getchar() != '\n');
    if (sum >= 122 && sum <= 4995) {
        num = GuessNum(sum);
    } else {
        printf("�����������һ����λ����...�ٸ�����һ���:");
        goto TELLME;
    }
    if (num) {
        printf("���ˣ�����Ҫ��ʼ����Ŷ...����������\n3\n");
        Sleep(1000);
        printf("2\n");
        Sleep(1000);
        printf("1\n");
        Sleep(1000);
        printf("�������������...\n%d��\n��ô���Ҳ¶��˰ɣ�\n", num);
        Sleep(2000);
    } else {
        printf("���ǲ�������Ū����...���¸�����һ�����[y/n]:");
        t = getchar();
        while (getchar() != '\n');
        if (t == 'y') {
            printf("���ǵĺ���...");
            goto TELLME;
        }
    }
}

void Magician() {
    int num = MyRand(), one, ten, hun, sum, guessnum;
    one = num % 10;
    ten = num / 10 % 10;
    hun = num / 100;
    // sum=one*100*2+one*10*2+ten*100*2+ten*2+hun*10*2+hun*2+hun+ten+one;
    sum = 222 * (one + ten + hun) - num;
    printf("ħ��ʦ���ˣ�׼���õĻ��Ҿ�Ҫ������������������ĺ���Ŷ��");
    system("pause");
    printf("��������ĺ���...:%d\n", sum);
    printf("������������������ְ�:");
    scanf("%d", &guessnum);
    while (getchar() != '\n');
    if (guessnum == num) {
        printf("������...��Ȼ��Ĳ¶���...\n");
        system("pause");
    } else {
        printf("�´���...����Ҳû��ô������...");
        system("pause");
    }
}

int MyRand() {
    return (rand() % 900 + 100);
}

int GuessNum(int sum) {
    int con, num, one, ten, hun;
    con = sum / 222;
    ZAILAI:
    num = 222 * con - sum;
    if (num < 100) {
        con++;
        goto ZAILAI;
    }
    else if (num > 1000) {
        return 0;
    } else {
        one = num % 10;
        ten = num / 10 % 10;
        hun = num / 100;
        if (one + ten + hun == con) {
            return num;
        } else {
            con++;
            goto ZAILAI;
        }
    }
}