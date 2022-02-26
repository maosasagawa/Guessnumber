#define _CRT_SECURE_NO_WARNINGS
/*
 *
 *
 *
 *
 *
 */
#include<stdio.h>
#include<stdlib.h>//rand srand函数
#include<time.h>//time函数
#include <Windows.h>//使用sleep函数

void PrintRule();//输出游戏规则，单独封装成函数是不想main里有太多内容影响代码可读性

void Player();//做观众（玩家）的时候执行这个

void Magician();//操作者作为魔术师的时候

int GuessNum(int sum);//电脑猜数字的过程

int MyRand();//返回随机数的函数
int main() {
    int t;
    srand((unsigned) time(NULL));//播种
    START:
    system("@cls||clear");
    PrintRule();
    printf("你想当观众还是魔术师呢，想当观众请输入0，想当魔术师的话就输入1，突然不想玩了就输入n吧：");
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
            printf("没有别的玩法哦，再问你一遍好了...\n");
            Sleep(1700);//让程序睡一会儿，不然就来不及看屏幕上的字了
            while (getchar() != '\n');//防止你调皮输入一大堆字符导致程序崩溃，所以我在这里吃掉了
            goto START;
    }
    printf("真的不想再玩一次吗，想的话输入y,不想就输入别的吧:");
    t = getchar();

    if (t == 'y' || t == 'Y') { while (getchar() != '\n');
        goto START; }
    system("mshta \"javascript:new ActiveXObject('WScript.Shell').popup('感谢游玩，欢迎下次再来!',7,'三位数魔术师',64);window.close();\"");
    return 0;
}

void PrintRule() {
    printf(
           "┌─────────────────────────────────────┐\n"
           "│                                     │\n"
           "│            三位数小魔术             │\n"
           "│                                     │\n"
           "│        只要你心里想三位数           │\n"
           "│      我就可以猜出那个数是多少       │\n"
           "│                                     │\n"
           "│      当然了你也可以来当魔术师       │\n"
           "│         来窥探我心中所想            │\n"
           "│                                     │\n"
           "│                                     │\n"
           "│                                     │\n"
           "│          下面让我们开始吧           │\n"
           "│                                     │\n"
           "└─────────────────────────────────────┘\n");
}

void Player() {
    char t;
    int sum = 0, num = 0;
    printf("在心里想一个三位数我可以猜到你心里在想什么数字哦\n");
    Sleep(2000);
    printf("想好了吗？准备告诉我这个数(abc)个位、十位、百位重组后的五个数(acb、bac、bca、cab、cba)的和吧\n");
    Sleep(2500);
    printf("什么？你说三位数的排列组合方式至多只有六种，告诉我五种就等于告诉我第六种了？\n");
    Sleep(4000);
    printf("气死了，那我给你打开一个别的计算器吧，这样你就相信我了\n");
    Sleep(4000);
    system("explorer \"https://www.geogebra.org/scientific?lang=zh_CN\"");
    Sleep(500);
    printf("那现在可以告诉我这个和了吧：");
    TELLME:
    scanf("%d", &sum);
    while (getchar() != '\n');
    if (sum >= 122 && sum <= 4995) {
        num = GuessNum(sum);
    } else {
        printf("你心里想的是一个三位数吗...再告诉我一遍吧:");
        goto TELLME;
    }
    if (num) {
        printf("好了，那我要开始猜了哦...倒数三秒钟\n3\n");
        Sleep(1000);
        printf("2\n");
        Sleep(1000);
        printf("1\n");
        Sleep(1000);
        printf("你心里想的数是...\n%d！\n怎么样我猜对了吧！\n", num);
        Sleep(2000);
    } else {
        printf("你是不是哪里弄错了...重新告诉我一遍好吗？[y/n]:");
        t = getchar();
        while (getchar() != '\n');
        if (t == 'y') {
            printf("它们的和是...");
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
    printf("魔术师大人，准备好的话我就要告诉你我心里想的数的和了哦？");
    system("pause");
    printf("我想的数的和是...:%d\n", sum);
    printf("告诉我我心里想的数字吧:");
    scanf("%d", &guessnum);
    while (getchar() != '\n');
    if (guessnum == num) {
        printf("好厉害...竟然真的猜对了...\n");
        system("pause");
    } else {
        printf("猜错了...看来也没那么厉害嘛...");
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