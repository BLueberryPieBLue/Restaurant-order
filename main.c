#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>
#include <string.h>
char enter__name[500];//用户名
char key[1000];/*用户输入字符*/
struct node
{
    char num[70];//订单号
    char status[70];//状态
    char action[70];//活动
    char name[70];//名称
    int typ; //类型
    double price;//金额
    char user__name[70];//用户名
    char password[70];//密码
    struct node *next;
}*tab, *dish, *user, *order;
/**建立读写文件**/
struct node *creats__table(); /*建立台桌文件*/
struct node *creats__dish(); /*建立菜单文件*/
struct node *creats__users();/*建立用户文件*/
struct node *creats__order();/*建立订单文件*/
struct node *creats__black();/*建立初始文件*/
struct node *creats__dish__order();/*建立订单点菜信息文件*/
struct node *read__link(int number, struct node *head);/*将链表从文件中读取*/
struct node *write__link(int number, struct node *head); /*将链表写入文件*/
/**进出系统**/
void system__enter();/*系统启动*/
void user__enter();/*进入登录界面*/
int check__password();/*匹配用户*/
void system__quit();/*退出系统*/
/**管理界面**/
void manage__enter();/*进入管理界面*/
/*菜单管理*/
void menu__enter();/*进入菜单管理界面*/
void add__dish();/*增 加 菜 目*/
void delete__dish();/*删 除 菜 目*/
void alter__dish();/*修 改 菜 目*/
void look__dish();/*查 询 菜 目*/
void all__dish();/*所 有 菜 目*/
/*餐桌管理*/
void table__charge();/*进入餐桌管理*/
void add__table();/*增加台桌*/
void delete__table();/*删除台桌*/
void alter__table();/*修改台桌*/
void look__table();/*查询台桌*/
/*人员管理*/
void staff__charge();/*人员管理*/
void add__staff();/*增加人员*/
void delete__staff();/*删除人员*/
void alter__staff();/*修改人员*/
void look__staff();/*查询人员*/
/**主管界面**/
void director__enter();/*进入主管界面*/
void sell__total();/*营销统计*/
/**服务界面**/
void dervice__enter();/*进入服务界面*/
void start__table();/*开    桌*/
void start__dish();/*点    菜*/
void looks__table();/*查询台桌*/
void looks__dish();/*点菜记录*/
void looks__order();/*查询订单*/
void pay__off();/*买    单*/
/**打印信息**/
void table__menu();/*打印台桌信息*/
void order__menu();/*打印订单信息*/
void dish__menu();/*打印菜单信息*/
void staff__menu();/*打印人员信息*/
void dish__order();/*打印点菜信息*/
void order__menus();/*打印订单点菜信息*/
int main()
{

    system("color A0");
    system__enter();/*系统启动*/
    return 0;
}
/**建立读写文件**/
/*建立台桌文件*/
struct node *creats__table()
{
    FILE *ff;
    if((ff = fopen("c:\\restaurant\\tab.data", "rb")) == NULL)
    {
        int i;
        struct node *p, *t, *head;
        head = (struct node *)malloc(sizeof(struct node));
        t = head;
        for (i = 0; i < 1; i ++)
        {
            p = (struct node *)malloc(sizeof(struct node));
            strcpy(p -> num, "001");
            strcpy(p -> status, "Y");
            strcpy(p -> action, "Y");

            p -> typ = 0;
            t -> next = p;
            p -> next = NULL;
            t = p;
        }
        tab = head;
        FILE *in = fopen("c:\\restaurant\\tab.dat", "wb+");
        p = head -> next;
        while(p)
        {
            fwrite(p, sizeof(struct node), 1, in);
            p = p -> next;
        }
        fclose(in);
    }
    return 0;
}
/*建立菜单文件*/
struct node *creats__dish()
{
    FILE *ff;
    if((ff = fopen("c:\\restaurant\\dish.data", "rb")) == NULL)
    {
        int i;
        struct node *p, *t, *head;
        head = (struct node *)malloc(sizeof(struct node));
        t = head;
        for (i = 0; i < 1; i ++)
        {
            p = (struct node *)malloc(sizeof(struct node));
            strcpy(p -> num, "0001");
            strcpy(p -> status, "Y");
            strcpy(p -> name, "凉拌黄瓜");
            strcpy(p -> action, "N");
            p -> price = 5.23;
            t -> next = p;
            p -> next = NULL;
            t = p;
        }
        dish = head;
        FILE *in = fopen("c:\\restaurant\\dish.dat", "wb+");
        p = head -> next;
        while(p)
        {
            fwrite(p, sizeof(struct node), 1, in);
            p = p -> next;
        }
        fclose(in);
    }
    return 0;
}
/*建立用户文件*/
struct node *creats__users()
{
    FILE *ff;
    if((ff = fopen("c:\\restaurant\\user.dat", "rb")) == NULL)
    {
        int i;
        struct node *p, *t, *head;
        head = (struct node *)malloc(sizeof(struct node));
        t = head;
        for (i = 0; i < 1; i ++)
        {
            p = (struct node *)malloc(sizeof(struct node));
            strcpy(p -> user__name, "111");
            strcpy(p -> password, "111");
            p -> typ = 1;
            t -> next = p;
            p -> next = NULL;
            t = p;
        }
        user = head;
        FILE *in = fopen("c:\\restaurant\\user.dat", "wb+");
        p = head -> next;
        while(p)
        {
            fwrite(p, sizeof(struct node), 1, in);
            p = p -> next;
        }
        fclose(in);
    }
    return 0;
}
/*建立订单文件*/
struct node *creats__order()
{
    FILE *ff;
    if ((ff = fopen("c:\\restaurant\\order.dat", "rb")) == NULL)
    {
        int i;
        struct node *p, *t, *head;
        head = (struct node *)malloc(sizeof(struct node));
        t = head;
        for (i = 0; i < 1; i ++)
        {
            p = (struct node *)malloc(sizeof(struct node));
            strcpy(p -> name, "001");
            strcpy(p -> num, "001");
            strcpy(p -> status, "Y");
            strcpy(p -> action, "N");
            t -> next = p;
            p -> next = NULL;
            t = p;
        }
        user = head;
        FILE *in = fopen("c:\\restaurant\\order.dat", "wb+");
        p = head -> next;
        while(p)
        {
            fwrite(p, sizeof(struct node), 1, in);
            p = p -> next;
        }
        fclose(in);
    }
    return 0;
}
/*建立订单点菜信息文件*/
struct node *creats__dish__order()
{
    FILE *ff;
    if ((ff = fopen("c:\\restaurant\\order__menu.dat", "rb")) == NULL)
    {
        int i;
        struct node *p, *t, *head;
        head = (struct node *)malloc(sizeof(struct node));
        t = head;
        for (i = 0; i < 1; i ++)
        {
            p = (struct node *)malloc(sizeof(struct node));
            t -> next = p;
            p -> next = NULL;
            t = p;
        }
        user = head;
        FILE *in = fopen("c:\\restaurant\\order__menu.dat", "wb+");
        p = head -> next;
        while(p)
        {
            fwrite(p, sizeof(struct node), 1, in);
            p = p -> next;
        }
        fclose(in);
    }
    return 0;
}
struct node *creats__black()
{
    FILE *ff;
    if ((ff = fopen("c:\\restaurant\\black.dat", "rb")) == NULL)
    {
        int i;
        struct node *p, *t, *head;
        head = (struct node *)malloc(sizeof(struct node));
        t = head;
        for (i = 0; i < 1; i ++)
        {
            p = (struct node *)malloc(sizeof(struct node));
            t -> next = p;
            p -> next = NULL;
            t = p;
        }
        user = head;
        FILE *in = fopen("c:\\restaurant\\black.dat", "wb+");
        p = head -> next;
        while(p)
        {
            fwrite(p, sizeof(struct node), 1, in);
            p = p -> next;
        }
        fclose(in);
    }
    return 0;


}
/*将链表从文件中读取*/
struct node *read__link(int number, struct node * head)
{
    FILE *fp;
    if (number == 1)
    {
        fp = fopen("c:\\restaurant\\user.dat", "rb");
    }
    else if (number == 2)
    {
        fp = fopen("c:\\restaurant\\dish.dat", "rb");
    }
    else if (number == 3)
    {
        fp = fopen("c:\\restaurant\\tab.dat", "rb");
    }
    else if (number == 4)
    {
        if((fp = fopen("c:\\restaurant\\order.dat", "rb")) == NULL)
        {
            printf("\n\n\n没有订单信息！\n\n\n");
        }
    }
    else if (number == 5)
    {
        fp = fopen("c:\\restaurant\\order__menu.dat", "rb");
    }
    else if(number == 6)
    {
        fp = fopen("c:\\restaurant\\black.dat", "ab+");
    }
    struct node *p, *t;
    t = head;
    p = (struct node *)malloc(sizeof(struct node));
    fread(p, sizeof(struct node), 1, fp);
    while(!feof(fp))
    {
        t -> next = p;
        t = t -> next;
        p = (struct node *)malloc(sizeof(struct node));
        fread(p, sizeof(struct node), 1, fp);
    }
    fclose(fp);
    return head;
}
//将链表写入文件//
struct node *write__link(int number, struct node * head)
{
    FILE *in;
    struct node *p;
    if (number == 1)
    {
        in = fopen("c:\\restaurant\\user.dat", "wb+");
    }
    else if (number == 2)
    {
        in = fopen("c:\\restaurant\\dish.dat", "wb+");
    }
    else if(number == 3)
    {
        in = fopen("c:\\restaurant\\tab.dat", "wb+");
    }
    else if(number == 4)
    {
        in = fopen("c:\\restaurant\\order.dat", "wb+");
    }
    else if(number == 5)
    {
        in = fopen("c:\\restaurant\\order__menu.dat", "ab+");
    }
    else if(number == 6)
    {
        in = fopen("c:\\restaurant\\black.dat", "ab+");
    }

    p = head -> next;
    while(p)
    {
        fwrite(p, sizeof(struct node), 1, in);
        p = p -> next;
    }
    fclose(in);
    return 0;
}
/**进出系统**/
/*系统启动*/
void system__enter()
{
    printf("+----------------------------------+\n");
    printf("+                                  +\n");
    printf("+         易用点菜系统             +\n");
    printf("+                                  +\n");
    printf("+----------------------------------+\n");
    int i;
    FILE *fp;
    printf("系统正在初始化");
    Sleep(50);
    for (i = 0; i <= 5; i ++)
    {
        Sleep(10);
        printf(".");
    }
    printf("\n");
    Sleep(500);
    printf("正在创建restaurant文件夹");
    for (i = 0; i <= 5; i ++)
    {
        Sleep(10);
        printf(".");
    }
    printf("\n");
    system("md c:\\restaurant");//C盘创建restaurant文件夹
    printf("已完成\n");
    printf("正在加载用户文件");
    for (i = 0; i <= 5; i ++)
    {
        Sleep(10);
        printf(".");
    }
    printf("\n");
    if((fp = fopen("c:\\restaurant\\user.dat", "rb+")) == NULL)
    {
        creats__users();/*建立用户文件*/
    }
    printf("已完成\n");
    printf("正在加载菜单文件");
    for (i = 0; i <= 5; i ++)
    {
        Sleep(10);
        printf(".");
    }
    printf("\n");
    if((fp = fopen("c:\\restaurant\\dish.dat", "rb+")) == NULL)
    {
        creats__dish(); /*建立菜单文件*/
    }
    printf("已完成\n");
    printf("正在加载台桌文件");
    for (i = 0; i <= 5; i ++)
    {
        Sleep(10);
        printf(".");
    }
    printf("\n");
    if((fp = fopen("c:\\restaurant\\tab.dat", "rb+")) == NULL)
    {
        creats__table(); /*建立台桌文件*/
    }
    printf("已完成\n");
    printf("正在加载订单文件");
    for (i = 0; i <= 5; i ++)
    {
        Sleep(10);
        printf(".");
    }
    printf("\n");
    if((fp = fopen("c:\\restaurant\\order.dat", "rb+")) == NULL)
    {
        creats__order();/*建立订单文件*/
    }
    printf("已完成\n");
    printf("正在加载订单点菜信息文件");
    for (i = 0; i <= 5; i ++)
    {
        Sleep(10);
        printf(".");
    }printf("\n");
    system("del/f/s/q c:\\restaurant\\black.dat");
    if(((fp = fopen("c:\\restaurant\\order__menu.dat", "rb+")) == NULL)||((fp = fopen("c:\\restaurant\\black.dat", "rb+")) == NULL))
    {
        creats__dish__order();/*建立订单点菜信息文件*/
        creats__black();
    }
    printf("已完成\n");
    /*打印进度条*/
    for (i = 0; i <= 15; i ++)
    {
        Sleep(50);
        printf("■ ");
    }
    printf("\n\n初始化完成\n\n");
    Sleep(500);
    printf("默认管理员用户\nuser:111 \npassword:111\n\n");
    Sleep(500);
    system("pause");//按任意键继续...
    system("cls");//清屏
    user__enter();/*进入登录界面*/
}
/*进入登录界面*/
void user__enter()
{
    system("color 9E");
    system("cls");//清屏
    printf("+----------------------------------+\n");
    printf("+                                  +\n");
    printf("+         易用点菜系统             +\n");
    printf("+          CopyRight@              +\n");
    printf("+                                  +\n");
    printf("+----------------------------------+\n");
    printf("\n");
    int s, i;
    s = check__password();
    if (s == 1)
    {
        system("cls");//清屏
        printf("\n          正在进入管理界面....\n");
        for (i = 0; i <= 20; i ++)
        {
            Sleep(50);
            printf("■ ");
        }
        system("color 9E");
        system("cls");//清屏
        manage__enter();/*进入管理界面*/
    }
    if (s == 2)
    {
        system("cls");//清屏
        printf("\n          正在进入主管界面.....\n");
        for (i = 0; i <= 20; i ++)
        {
            Sleep(50);
            printf("■ ");
        }
        system("color 9E");
        system("cls");
        director__enter();/*进入主管界面*/
    }
    if (s == 3)
    {
        system("cls");//清屏
        printf("\n          正在进入服务界面......\n");
        for (i = 0; i <= 20; i ++)
        {
            Sleep(50);
            printf("■ ");
        }
        system("color 9E");
        system("cls");
        dervice__enter();/*进入服务界面*/
    }
    if (s != 1 && s != 2 && s != 3)
    {
        system("cls");//清屏
        printf("\n\n\n\n\n\n用户不存在，或密码错误！\n\n\n\n\n\n");
        system("pause");
        system("cls");
        user__enter();/*进入登录界面*/
    }
}
/*匹配用户*/
int check__password()
{
    char user__name[30];
    char password[30];
    printf("请输入用户名  \n>>");
    scanf("%s", user__name);
    printf("请输入用户密码 \n>>");
    scanf("%s", password);
    FILE *fp;
    struct node *p, *q, *t, *head;
    head = (struct node *)malloc(sizeof(struct node));
    t = head;
    p = (struct node *)malloc(sizeof(struct node));
    fp = fopen("c:\\restaurant\\user.dat", "rb");
    fread(p, sizeof(struct node), 1, fp);
    while(!feof(fp))
    {
        t -> next = p;
        t = t -> next;
        p = (struct node *)malloc(sizeof(struct node));
        fread(p, sizeof(struct node), 1, fp);
    }
    fclose(fp);
    q = head -> next;
    while(q)
    {
        if ((strcmp(user__name, q -> user__name) == 0) && (strcmp(password, q -> password) == 0))
        {
            if(q -> typ == 3)
            {
                strcpy(enter__name, q -> user__name);
            }
            return (q->typ);
        }
        else
        {
            if (q->next == NULL)
            {
                return 0;
            }
            q = q -> next;
        }
    }
    p = user -> next;
    q = user;
    while(p)
    {
        if ((strcmp(user__name, p -> name) == 0) && (strcmp(password, p -> password) == 0))
        {
            return (p->typ);
        }
        else
        {
            if (p->next == NULL)
            {
                return 0;
            }
            q = q -> next;
            p = p -> next;
        }
    }
    return 0;
}
/*退出系统*/
void system__quit()
{
    system("cls");//清屏
    printf("\n\n\n\n\n\n\n");
    printf("+----------------------------------+\n");
    printf("+                                  +\n");
    printf("+         易用点菜系统             +\n");
    printf("+         欢迎再次使用             +\n");
    printf("+                                  +\n");
    printf("+----------------------------------+\n");
    printf("\n\n\n\n\n\n\n");
    exit(1);
}
/**管理界面**/
/*进入管理界面*/
void manage__enter()
{
    system("cls");//清屏
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           管理界面           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n");
    printf("          1 :菜单管理\n\n");
    printf("          2 :餐桌管理\n\n");
    printf("          3 :人员管理\n\n");
    printf("          c :切换用户\n\n");
    printf("          q :退出系统\n\n");
    printf("\n");
    while (1)
    {
        printf("          输入你的选择 \n>>");
        scanf("%s", key);
        if (strcmp(key, "1") == 0)
        {
            menu__enter();/*菜单管理界面*/
            break;
        }
        if (strcmp(key, "2") == 0)
        {
            table__charge();/*餐桌管理*/
            break;
        }
        if (strcmp(key, "3") == 0)
        {
            staff__charge();/*人员管理*/
            break;
        }
        if (strcmp(key, "c") == 0 || strcmp(key, "C") == 0)
        {
            user__enter();/*进入系统*/  //切换用户
            break;
        }
        if (strcmp(key, "q") == 0 || strcmp(key, "Q") == 0)
        {
            system__quit();/*退出系统*/
            break;
        }
    }
}
/*菜单管理*/
/*进入菜单管理界面*/
void menu__enter()
{
    system("cls");//清屏
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-          菜 单 界 面         -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n");
    printf("          1 ->  增 加 菜 目\n\n");
    printf("          2 ->  删 除 菜 目\n\n");
    printf("          3 ->  修 改 菜 目\n\n");
    printf("          4 ->  查 询 菜 目\n\n");
    printf("          5 ->  所 有 菜 目\n\n");
    printf("          q ->  返       回\n\n");
    printf("\n");
    while (1)
    {
        printf("          输入你的选择 \n>>");
        scanf("%s", key);
        if (strcmp(key, "1") == 0)
        {
            add__dish();/*增 加 菜 目*/
            break;
        }
        if (strcmp(key, "2") == 0)
        {
            delete__dish();/*删 除 菜 目*/
            break;
        }
        if (strcmp(key, "3") == 0)
        {
            alter__dish();/*修 改 菜 目*/
            break;
        }
        if (strcmp(key, "4") == 0)
        {
            look__dish();/*查 询 菜 目*/
            break;
        }
        if (strcmp(key, "5") == 0)
        {
            all__dish();/*所 有 菜 目*/
            break;
        }
        if (strcmp(key, "c") == 0 || strcmp(key, "C") == 0)
        {
            user__enter();/*进入系统*/  //切换用户
            break;
        }
        if (strcmp(key, "q") == 0 || strcmp(key, "Q") == 0)
        {
            manage__enter();/*进入管理界面*/
            break;
        }
    }
}
/*增 加 菜 目*/
void add__dish()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           增加菜目           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n");
    printf("\n当前菜目:\n\n");
    dish__menu();
    FILE *fp;
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    printf("输入菜目编号: \n>>");
    scanf("%s", p -> num);
    printf("输入菜目名称: \n>>");
    scanf("%s", p -> name);
    printf("输入菜目价格: \n>>");
    scanf("%lf", &p -> price);
    while (1)
    {
        printf("输入菜目状态<Y/N>: \n>>");
        scanf("%s", p -> status);
        if (strcmp(p -> status, "Y") == 0 || strcmp(p-> status, "y") == 0 || strcmp(p -> status, "N") == 0 || strcmp(p-> status, "n") == 0)
        {
            break;
        }
    }
    while (1)
    {
        printf("输入菜目活动<Y/N>: \n>>");
        scanf("%s", p -> action);
        if (strcmp(p -> action, "Y") == 0 || strcmp(p -> action, "y") == 0 || strcmp(p -> action, "N") == 0 || strcmp(p-> action, "n") == 0)
        {
            break;
        }
    }
    if ((fp = fopen("c:\\restaurant\\dish.dat", "ab+")) == NULL)
    {
        creats__dish();
    }
    fwrite(p, sizeof(struct node), 1, fp);
    free(p);
    fclose(fp);
    while (1)
    {
        printf("是否继续添加<Y/N>: \n>>");
        scanf("%s", key);
        if (strcmp(key, "Y") == 0 || strcmp(key, "y") == 0)
        {
            add__dish();
            break;
        }
        else
        {
            if(strcmp(key, "N") == 0 || strcmp(key, "n") == 0)
            {
                menu__enter();
                break;
            }
        }
    }
}
/*删 除 菜 目*/
void delete__dish()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           删除菜目           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n");
    printf("\n当前菜目:\n\n");
    dish__menu();
    char s[70];
    printf("输入要删除的菜号 \n>>");
    scanf("%s", s);
    while (1)
    {
        printf("是否删除<Y/N> \n>>");
        scanf("%s", key);
        if (strcmp(key, "Y") == 0 || strcmp(key, "y") == 0)
        {
            struct node *p, *q, *head;
            head = (struct node *)malloc(sizeof(struct node));
            head = read__link(2, head);
            p = head;
            q = p -> next;
            while(q)
            {
                if (strcmp(s, q -> num) == 0)
                {
                    p->next = q -> next;
                    free(q);
                    break;
                }
                else
                {
                    p = p -> next;
                    q = q -> next;
                }
            }

            if(q == NULL)
            {
                printf("\n\n该菜目不存在! \n\n");

            }
            else
            {
                write__link(2, head);
                printf("\n\n删除成功! \n\n");
            }
            while (1)
            {
                printf("是否继续删除<Y/N> \n>>");
                scanf("%s", key);
                if (strcmp(key, "Y") == 0 || strcmp(key, "y") == 0)
                {
                    delete__dish();
                    break;
                }
                else
                {
                    if(strcmp(key, "N") == 0 || strcmp(key, "n") == 0)
                    {
                        menu__enter();
                        break;
                    }
                }
            }
        }
        else
        {
            if(strcmp(key, "N") == 0 || strcmp(key, "n") == 0)
            {
                delete__dish();
                break;
            }
        }
    }
}
/*修改菜目*/
void alter__dish()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           修改菜目           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n");
    printf("\n当前菜目:\n\n");
    dish__menu();
    struct node *q, *head;
    head = (struct node *)malloc(sizeof(struct node));
    head = read__link(2, head);
    q = head -> next;
    printf("输入要修改的菜号 \n>>");
    scanf("%s", key);
    while(q)
    {
        if (strcmp(key, q -> num) == 0)
        {
            printf("请输入新菜号 \n>>");
            scanf("%s", q -> num);
            printf("请输入新菜名 \n>>");
            scanf("%s", q -> name);
            printf("请输入新价格 \n>>");
            scanf("%lf", &q -> price);
            while (1)
            {
                printf("请输入新状态<Y/N> :\n>>");
                getchar();
                scanf("%s", q -> status);
                if (strcmp(q -> status, "Y") == 0 || strcmp(q -> status, "y") == 0 || strcmp(q -> status, "N") == 0 || strcmp(q -> status, "n") == 0)
                {
                    break;
                }
            }
            while (1)
            {
                printf("请输入新活动<Y/N> \n>>");
                scanf("%s", q -> action);
                if (strcmp(q -> action, "Y") == 0 || strcmp(q -> action, "y") == 0 || strcmp(q -> action, "N") == 0 || strcmp(q -> action, "n") == 0)
                {
                    break;
                }
            }

            break;
        }
        else
            q = q -> next;
    }

    if (q == NULL)
    {
        printf("\n\n该菜目不存在!\n\n");
    }
    else
    {
        write__link(2, head);
        printf("\n\n修改成功！\n\n");
    }
    while (1)
    {
        printf("是否继续修改<Y/N> \n>>");
        scanf("%s", key);
        if (strcmp(key, "Y") == 0 || strcmp(key, "y") == 0)
        {
            alter__dish();
            break;
        }
        else
        {
            if(strcmp(key, "N") == 0 || strcmp(key, "n") == 0)
            {
                menu__enter();
                break;
            }
        }
    }
}
/*查 询 菜 目*/
void look__dish()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           查询菜目           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n");
    struct node *p, *q, *head;
    printf("输入要查询的菜号 :\n>>");
    scanf("%s", key);
    head = (struct node *)malloc(sizeof(struct node));
    head = read__link(2, head);
    p = head;
    q = head -> next;
    while(q)
    {
        if (strcmp(q -> num, key) == 0)
        {
            printf("菜号              菜名          价格            状态             是否活动\n");
            printf("%s                %s            %.2lf           %s               %s\n", q -> num, q -> name, q -> price, q -> status, q -> action);
            break;
        }
        else
        {
            p = p -> next;
            q = q -> next;
        }
    }
    if (q == NULL)
    {
        printf("\n\n该菜目不存在！\n\n");
    }

    while (1)
    {
        printf("是否继续查询<Y / N> \n>>");
        scanf("%s", key);
        if (strcmp(key, "Y") == 0 || strcmp(key, "y") == 0)
        {
            look__dish();
            break;
        }
        else
        {
            if(strcmp(key, "N") == 0 || strcmp(key, "n") == 0)
            {
                menu__enter();
                break;
            }
        }
    }
}
/*所 有 菜 目*/
void all__dish()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           所有菜目           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n");
    dish__menu();
    printf("\n\n         >>Q :返回菜单管理\n>>");
    while(1)
    {
        scanf("%s", key);
        if(strcmp(key, "Q") == 0 || strcmp(key, "q") == 0)
        {
            menu__enter();
            break;
        }
    }
}
/*餐桌管理*/
/*进入餐桌管理*/
void table__charge()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           餐桌管理           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n");
    printf("          1 :增加台桌\n\n");
    printf("          2 :删除台桌\n\n");
    printf("          3 :修改台桌\n\n");
    printf("          4 :查询台桌\n\n");
    printf("          q :返回目录\n\n");
    while (1)
    {
        printf("          输入你的选择 :\n>>");
        scanf("%s", key);
        if (strcmp(key, "1") == 0)
        {
            add__table();/*增加台桌*/
            break;
        }
        if (strcmp(key, "2") == 0)
        {
            delete__table();/*删除台桌*/
            break;
        }
        if (strcmp(key, "3") == 0)
        {
            alter__table();/*修改台桌*/
            break;
        }
        if (strcmp(key, "4") == 0)
        {
            look__table();/*查询台桌*/
            break;
        }
        if (strcmp(key, "q") == 0 || strcmp(key, "Q") == 0)
        {
            manage__enter();/*进入管理界面*/
            break;
        }
    }
}
/*增加台桌*/
void add__table()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           增加台桌           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n");
    printf("\n当前台桌：\n\n");
    table__menu();
    FILE *fp;
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    printf("输入桌号 :\n>>");
    scanf("%s", p -> num);
    while (1)
    {
        printf("输入状态:<Y/N> \n>>");
        scanf("%s", p -> status);
        if (strcmp(p -> status, "Y") == 0 || strcmp(p -> status, "y") == 0 || strcmp(p -> status, "N") == 0 || strcmp(p -> status, "n") == 0)
        {
            break;
        }
    }
    while (1)
    {
        printf("输入活动:<Y/N> \n>>");
        scanf("%s", p -> action);
        if (strcmp(p -> action, "Y") == 0 || strcmp(p -> action, "y") == 0 || strcmp(p -> action, "N") == 0 || strcmp(p -> action, "n") == 0)
        {
            break;
        }
    }

    if((fp = fopen("c:\\restaurant\\tab.dat", "ab+")) == NULL)
    {
        creats__table();
    }
    fwrite(p, sizeof(struct node), 1, fp);
    free(p);;
    fclose(fp);
    while (1)
    {
        printf("是否继续添加?<Y/N> \n>>");
        scanf("%s", key);
        if (strcmp(key, "Y") == 0 || strcmp(key, "y") == 0)
        {
            add__table();
            break;
        }
        else
        {
            if(strcmp(key, "N") == 0 || strcmp(key, "n") == 0)
            {
                table__charge();
                break;
            }
        }
    }
}
/*删除台桌*/
void delete__table()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           删除台桌           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n");
    printf("\n当前台桌：\n\n");
    table__menu();
    struct node *head, *p, *q;
    head = (struct node *)malloc(sizeof(struct node));
    head = read__link(3, head);
    printf("请输入要删除的桌号 \n>>");
    scanf("%s", key);
    p = head;
    q = p -> next;
    while(q)
    {
        if (strcmp(key, q -> num) == 0)
        {
            p -> next = q -> next;
            free(q);
            break;
        }
        else
        {
            p = p -> next;
            q = q -> next;
        }
    }
    if (q == NULL)
    {
        printf("\n该桌号不存在！\n\n");

    }
    else
    {
        write__link(3, head);
        printf("\n删除成功！\n\n");
    }
    while (1)
    {
        printf("是否继续删除?<Y/N> \n>>");
        scanf("%s", key);
        if (strcmp(key, "Y") == 0 || strcmp(key, "y") == 0)
        {
            delete__table();
            break;
        }
        else
        {
            if(strcmp(key, "N") == 0 || strcmp(key, "n") == 0)
            {
                table__charge();
                break;
            }
        }
    }
}
/*修改台桌*/
void alter__table()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           修改台桌           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n");
    printf("\n当前台桌：\n\n");
    table__menu();
    struct node *q, *head;
    head = (struct node *)malloc(sizeof(struct node));
    head = read__link(3, head);
    q = head -> next;
    printf("请输入桌号: \n>>");
    getchar();
    scanf("%s", key);
    while(q)
    {
        if (strcmp(key, q -> num) == 0)
        {
            printf("请输入新桌号: \n>>");
            scanf("%s", q -> num);
            while (1)
            {
                printf("请输入新状态:<Y/N> \n>>");
                scanf("%s", q -> status);
                if (strcmp(q -> status, "Y") == 0 || strcmp(q -> status, "y") == 0 || strcmp(q -> status, "N") == 0 || strcmp(q -> status, "n") == 0)
                {
                    break;
                }
            }

            while (1)
            {
                printf("请输入新活动:<Y/N> \n>>");
                scanf("%s", q -> action);
                if (strcmp(q -> action, "Y") == 0 || strcmp(q -> action, "y") == 0 || strcmp(q -> action, "N") == 0 || strcmp(q-> action, "n") == 0)
                {
                    break;
                }
            }
            write__link(3, head);
            printf("\n修改成功!\n\n");
            while (1)
            {
                printf("是否继续修改?<Y/N> \n>>");
                scanf("%s", key);
                if (strcmp(key, "Y") == 0 || strcmp(key, "y") == 0)
                {
                    alter__table();
                    break;
                }
                else
                {
                    if(strcmp(key, "N") == 0 || strcmp(key, "n") == 0)
                    {
                        table__charge();
                        break;
                    }
                }
            }

        }
        else
        {
            q = q -> next;
            if (q == NULL)
            {
                printf("\n该桌号不存在!\n\n");
                while (1)
                {
                    printf("是否继续修改?<Y/N> \n>>");
                    scanf("%s", key);
                    if (strcmp(key, "Y") == 0 || strcmp(key, "y") == 0)
                    {
                        alter__table();
                        break;
                    }
                    else
                    {
                        if(strcmp(key, "N") == 0 || strcmp(key, "n") == 0)
                        {
                            table__charge();
                            break;
                        }
                    }
                }
            }
        }

    }
}
/*查询台桌*/
void look__table()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           查询台桌           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n");
    printf("桌号             状态             活动   \n");
    struct node *q, *head;
    head = (struct node *)malloc(sizeof(struct node));
    head = read__link(3, head);
    q = head -> next;
    while(q)
    {
        printf("%5s             %s                %s\n", q -> num, q -> status, q -> action);
        q = q -> next;
    }
    printf("\n\n         >>Q :返回餐桌管理\n>>");
    while(1)
    {
        scanf("%s", key);
        if(strcmp(key, "Q") == 0 || strcmp(key, "q") == 0)
        {
            table__charge();
            break;
        }
    }
}
/*人员管理*/
/*进入人员管理*/
void staff__charge()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           人员管理           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n");
    printf("          1 :增加人员\n\n");
    printf("          2 :删除人员\n\n");
    printf("          3 :修改人员\n\n");
    printf("          4 :查询人员\n\n");
    printf("          q :返回目录\n\n");
    while (1)
    {
        printf("          输入你的选择 :\n>>");
        scanf("%s", key);
        if (strcmp(key, "1") == 0)
        {
            add__staff();/*增加人员*/
            break;
        }
        if (strcmp(key, "2") == 0)
        {
            delete__staff();/*删除人员*/
            break;
        }
        if (strcmp(key, "3") == 0)
        {
            alter__staff();/*修改人员*/
            break;
        }
        if (strcmp(key, "4") == 0)
        {
            look__staff();/*查询人员*/
            break;
        }
        if (strcmp(key, "q") == 0 || strcmp(key, "Q") == 0)
        {
            manage__enter();/*进入管理界面*/
            break;
        }
    }
}
/*增加人员*/
void add__staff()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           增加人员           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n");
    printf("\n当前人员:\n\n");
    staff__menu();
    FILE *fp;
    struct node *p, *t, *head;
    p = (struct node *)malloc(sizeof(struct node));
    p -> price = 0.00;
    printf("请输入用户名: \n>>");
    scanf("%s", p -> user__name);
    head = (struct node *)malloc(sizeof(struct node));
    head = read__link(1, head);
    t = head -> next;
    while(t)
    {
        if (strcmp(p -> user__name, t -> user__name) == 0)
        {
            printf("\n\n用户已存在！\n\n");
            system("pause");
            add__staff();
        }
        t = t -> next;
    }
    printf("请输入用户密码: \n>>");
    scanf("%s", p -> password);
    printf("请输入用户类型 <1> 经理  <2> 主管 <3> 服务员 \n>>");
    scanf("%d", &p -> typ);
    if(p -> typ == 2)
    {
        p -> price = 0.00;
    }
    if((fp = fopen("c:\\restaurant\\user.dat", "ab+")) == NULL)
    {
        creats__users();
    }
    fwrite(p, sizeof(struct node), 1, fp);
    free(p);
    fclose(fp);
    while (1)
    {
        printf("是否继续添加<Y / N> \n>>");
        scanf("%s", key);
        if (strcmp(key, "Y") == 0 || strcmp(key, "y") == 0)
        {
            add__staff();
            break;
        }
        else
        {
            if(strcmp(key, "N") == 0 || strcmp(key, "n") == 0)
            {
                staff__charge();
                break;
            }
        }
    }
}
/*删除人员*/
void delete__staff()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           删除人员           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n");
    printf("\n当前人员:\n\n");
    staff__menu();
    struct node *head, *p, *q;
    head = (struct node *)malloc(sizeof(struct node));
    head = read__link(1, head);
    printf("请输入要删除的用户名：\n>>");
    scanf("%s", key);
    p = head;
    q = p -> next;
    while(q)
    {
        if(strcmp(key, q -> user__name) == 0)
        {
            p -> next = q -> next;
            free(q);
            break;
        }
        else
        {
            p = p -> next;
            q = q -> next;
        }
    }
    if(q == NULL)
    {
        printf("\n\n\n该用户名不存在!\n\n\n");
    }
    else
    {
        write__link(1, head);
        printf("\n\n\n删除成功！ \n\n\n");
    }
    while (1)
    {
        printf("是否继续删除<Y / N> \n>>");
        scanf("%s", key);
        if (strcmp(key, "Y") == 0 || strcmp(key, "y") == 0)
        {
            delete__staff();
            break;
        }
        else
        {
            if(strcmp(key, "N") == 0 || strcmp(key, "n") == 0)
            {
                staff__charge();
                break;
            }
        }
    }
}
/*修改人员*/
void alter__staff()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           修改人员           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n");
    printf("\n当前人员:\n\n");
    staff__menu();
    struct node *q, *head;
    head = (struct node *)malloc(sizeof(struct node));
    head = read__link(1, head);
    q = head -> next;
    printf("请输入用户名: \n>>");
    scanf("%s", key);
    while(q)
    {
        if (strcmp(key, q -> user__name) == 0)
        {
            printf("输入新用户名: \n>>");
            scanf("%s", q -> user__name );
            printf("输入新用密码: \n>>");
            scanf("%s",  q -> password);
            printf("输入新用类型: \n>>");
            scanf("%d", &q -> typ);
            break;
        }
        else
            q = q -> next;
    }
    if(q == NULL)
    {
        printf("\n\n\n该用户名不存在!\n\n\n");
    }
    else
    {
        write__link(1, head);
        printf("\n\n\n修改成功!\n\n\n");
    }
    while (1)
    {
        printf("是否继续修改<Y / N> \n>>");
        scanf("%s", key);
        if (strcmp(key, "Y") == 0 || strcmp(key, "y") == 0)
        {
            alter__staff();
            break;
        }
        else
        {
            if(strcmp(key, "N") == 0 || strcmp(key, "n") == 0)
            {
                staff__charge();
                break;
            }
        }
    }
}
/*查询人员*/
void look__staff()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           查询人员           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n");
    printf("\n当前人员:\n\n");
    staff__menu();
    printf("\n\n         >>Q :返回人员管理\n>>");
    while(1)
    {
        scanf("%s", key);
        if(strcmp(key, "Q") == 0 || strcmp(key, "q") == 0)
        {
            staff__charge();
            break;
        }
    }
}
/**主管界面**/
/*进入主管界面*/
void director__enter()
{
    system("cls");//清屏
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           主管界面           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n");
    printf("          1 :营销统计\n\n");
    printf("          2 :\n\n");
    printf("          3 :\n\n");
    printf("          c :切换用户\n\n");
    printf("          q :退出系统\n\n");
    while (1)
    {
        printf("          输入你的选择 >>\n");
        char key[10000];
        scanf("%s", key);
        if (strcmp(key, "1") == 0)
        {
            sell__total();/*营销统计*/
            break;
        }
        if (strcmp(key, "c") == 0 || strcmp(key, "C") == 0)
        {
            user__enter();/*进入系统*/  //切换用户
            break;
        }
        if (strcmp(key, "q") == 0 || strcmp(key, "Q") == 0)
        {
            system__quit();
            break;
        }
    }
}
/*营销统计*/
void sell__total()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           营销统计           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n");
    double total = 0;
    printf("       用户       营业额\n");
    struct node *head, *t;
    head = (struct node *)malloc(sizeof(struct node));
    head = read__link(1, head);
    t = head -> next;
    while(t)
    {
        if (t -> typ == 3)
        {
            printf("%10s%10.2lf\n", t -> user__name, t -> price);
            total = total + t -> price;
        }
        t = t -> next;
    }
    printf("\n\n       总计     %.2lf\n", total);
    printf("\n");
    printf("\n\n         >>Q :返回菜单管理\n>>");
    while (1)
    {
        scanf("%s", key);
        if (strcmp(key, "q") == 0 || strcmp(key, "Q") == 0)
        {
            director__enter();/*进入主管界面*/
            break;
        }
    }
}
/**服务界面**/
/*进入服务界面*/
void dervice__enter()
{
    system("cls");//清屏
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           服务界面           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n");
    printf("           1 :开    桌\n\n");
    printf("           2 :点    菜\n\n");
    printf("           3 :查询台桌\n\n");
    printf("           4 :点菜记录\n\n");
    printf("           5 :查询订单\n\n");
    printf("           6 :买    单\n\n");
    printf("           c :切换用户\n\n");
    printf("           q :退出系统\n\n");
    printf("\n");
    while (1)
    {
        printf("          输入你的选择 \n>>");
        scanf("%s", key);
        if (strcmp(key, "1") == 0)
        {
            start__table();/*开    桌*/
            break;
        }
        if (strcmp(key, "2") == 0)
        {
            start__dish();/*点    菜*/
            break;
        }
        if (strcmp(key, "3") == 0)
        {
            looks__table();/*查询台桌*/
            break;
        }
        if (strcmp(key, "4") == 0)
        {
            looks__dish();/*点菜记录*/
            break;
        }
        if (strcmp(key, "5") == 0)
        {
            looks__order();/*查询订单*/
            break;
        }
        if (strcmp(key, "6") == 0)
        {
            pay__off();/*买    单*/
            break;
        }
        if (strcmp(key, "c") == 0 || strcmp(key, "C") == 0)
        {
            user__enter();/*进入系统*/  //切换用户
            break;
        }
        if (strcmp(key, "q") == 0 || strcmp(key, "Q") == 0)
        {
            system__quit();
            break;
        }
    }
}
/*开    桌*/
void start__table()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           开    桌           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    table__menu();
    FILE *fp;
    struct node *p, *head, *t;
    p = (struct node *)malloc(sizeof(struct node));
    printf("请输入桌号 :\n>>");
    scanf("%s", p -> num);
    printf("请输订单号号 :\n>>");
    scanf("%s", p -> name);
    head = (struct node *)malloc(sizeof(struct node));
    head = read__link(3, head);
    t = head -> next;
    while(t)
    {
        if (strcmp(t -> num, p -> num) == 0 && ((strcmp(t -> status, "Y") == 0) || (strcmp(t -> status, "y") == 0)))
        {
            strcpy(t -> status, "N");
            strcpy(p -> status, "N");
            strcpy(p -> action, "Y");
            if ((fp = fopen("c:\\restaurant\\order.dat", "rb")) == NULL)
            {
                fp = fopen("c:\\restaurant\\order.dat", "wb+");
                fwrite(p, sizeof(struct node), 1, fp);
                free(p);
                fclose(fp);
                write__link(3, head);
                while (1)
                {
                    printf("是否继续添加<Y/N> :\n>>");
                    scanf("%s", key);
                    if (strcmp(key, "Y") == 0 || strcmp(key, "y") == 0)
                    {
                        start__table();
                        break;
                    }
                    else
                    {
                        if(strcmp(key, "N") == 0 || strcmp(key, "n") == 0)
                        {
                            dervice__enter();
                            break;
                        }
                    }
                }
            }
            else
            {
                fp = fopen("c:\\restaurant\\order.dat", "ab+");
                fwrite(p, sizeof(struct node), 1, fp);
                free(p);
                fclose(fp);
                write__link(3, head);
                while (1)
                {
                    printf("是否继续添加<Y/N> :\n>>");
                    scanf("%s", key);
                    if (strcmp(key, "Y") == 0 || strcmp(key, "y") == 0)
                    {
                        start__table();
                        break;
                    }
                    else
                    {
                        if(strcmp(key, "N") == 0 || strcmp(key, "n") == 0)
                        {
                            dervice__enter();
                            break;
                        }
                    }
                }
            }

        }
        t = t -> next;
    }
    if (t == NULL)
    {
        printf("\n\n\n不能添加此桌!\n\n\n");
        while (1)
        {
            printf("是否继续添加<Y/N> :\n>>");
            scanf("%s", key);
            if (strcmp(key, "Y") == 0 || strcmp(key, "y") == 0)
            {
                start__table();
                break;
            }
            else
            {
                if(strcmp(key, "N") == 0 || strcmp(key, "n") == 0)
                {
                    dervice__enter();
                    break;
                }
            }
        }
    }
}
/*点    菜*/
void start__dish()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           点    菜           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    printf("\n\n当前订单\n\n");
    order__menu();
    printf("请输入需要点菜的订单号：\n>>");
    char ordernum[70];
    scanf("%s", ordernum);
    struct node *head2, *t;
    head2 = (struct node *)malloc(sizeof(struct node));
    head2 = read__link(4, head2);
    t = head2 -> next;

    while(t)
    {
        if (strcmp(t -> name, ordernum) == 0)
        {
            printf("             菜      单\n\n");
            dish__menu();
            printf("请输入菜号: \n>>");
            char number1[50];//菜号
            int num2;//份数
            scanf("%s", number1);
            struct node *p, *head1;
            head1 = (struct node *)malloc(sizeof(struct node));
            head1 = read__link(2, head1);
            p = head1 -> next;
            struct node *pa, *head1a;
            head1a = (struct node *)malloc(sizeof(struct node));
            head1a = read__link(6, head1a);
            pa = head1a -> next;
            while(p)
            {
                if (strcmp(number1, p -> num) == 0)
                {
                    printf("请输入份数:  \n>>");
                    scanf("%d", &num2);
                    t -> price = t -> price + num2 * p -> price;
                    t->typ = t->typ + num2;
                    strcpy(t -> action, "Y");
                    strcpy(t -> status, "N");
                    write__link(4, head2);

                    pa -> price = num2 * p -> price;
                    pa->typ = num2;
                    strcpy(pa->name, p->name);
                    strcpy(pa->num, ordernum);
                    write__link(5, head1a);
                    while (1)
                    {
                        printf("是否继续点菜<Y / N> \n>>");
                        scanf("%s", key);
                        if (strcmp(key, "Y") == 0 || strcmp(key, "y") == 0)
                        {
                            start__dish();
                            break;
                        }
                        else
                        {
                            if(strcmp(key, "N") == 0 || strcmp(key, "n") == 0)
                            {
                                dervice__enter();
                                break;
                            }
                        }
                    }
                }
                p = p -> next;
            }
            if (p == NULL)
                printf("\n\n\n没有此菜！！！\n\n\n");
            system("pause");
            start__dish();
        }
        t = t -> next;
    }
    if (t == NULL)
    {
        printf("\n\n\n没有此订单或该订单已结账！ \n\n\n");
        while (1)
        {
            printf("是否继续点菜<Y/N> :\n>>");
            scanf("%s", key);
            if (strcmp(key, "Y") == 0 || strcmp(key, "y") == 0)
            {
                start__dish();
                break;
            }
            else
            {
                if(strcmp(key, "N") == 0 || strcmp(key, "n") == 0)
                {
                    dervice__enter();
                    break;
                }
            }
        }

    }
}
/*查询台桌*/
void looks__table()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           查询台桌           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    table__menu();//打印台桌信息
    printf("\n\n         >>Q :返回服务界面\n>>");
    while(1)
    {
        scanf("%s", key);
        if(strcmp(key, "Q") == 0 || strcmp(key, "q") == 0)
        {
            dervice__enter();
            break;
        }
    }
}
/*点菜记录*/
void looks__dish()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           点菜记录           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    order__menus();
    printf("\n\n         >>Q :返回服务界面\n>>");
    while(1)
    {
        scanf("%s", key);
        if(strcmp(key, "Q") == 0 || strcmp(key, "q") == 0)
        {
            dervice__enter();
            break;
        }
    }
}
/*查询订单*/
void looks__order()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           查询订单           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    order__menu();
    printf("\n\n         >>Q :返回服务界面\n>>");
    while(1)
    {
        scanf("%s", key);
        if(strcmp(key, "Q") == 0 || strcmp(key, "q") == 0)
        {
            dervice__enter();
            break;
        }
    }
}
/*买    单*/
void pay__off()
{
    system("cls");
    printf("+---------------  ---------------+\n");
    printf("+-------------      -------------+\n");
    printf("+-           买    单           -+\n");
    printf("+-------------      -------------+\n");
    printf("+---------------  ---------------+\n");
    order__menu();
    char key2[70];//订单号
    printf("请输入要付账的订单号：\n>>");
    scanf("%s", key2);
    struct node *head, *p; //结账操作
    head = (struct node *)malloc(sizeof(struct node));
    head = read__link(4, head);
    p = head -> next;
    int f=1;
    while(p)
    {
        if (strcmp(p -> name, key2) == 0 && ((strcmp(p -> status, "N") == 0) || (strcmp(p -> status, "n") == 0)))
        {
            printf("是否确认结账<Y / N> :\n>>");
            while(1)
            {
                scanf("%s", key);
                if (strcmp(key, "Y") == 0 || strcmp(key, "y") == 0)
                {
                    printf("\n\n\n结账成功！\n\n\n");
                    strcpy(p -> status, "Y");
                    write__link(4, head);

                    struct node *head2, *t2; //进行修改台桌操作
                    head2 = (struct node *)malloc(sizeof(struct node));
                    head2 = read__link(3, head);
                    t2 = head2 -> next;
                    while(t2)
                    {
                        if (strcmp(t2 -> num, p -> num) == 0)
                        {
                            strcpy(t2 -> status, "Y");
                            strcpy(t2 -> action, "N");
                            write__link(6, head2);
                            break;
                        }
                        t2 = t2 -> next;

                    }

                    struct node *head1, *t; //进行记录账单操作
                    head1 = (struct node *)malloc(sizeof(struct node));
                    head1 = read__link(1, head1);
                    t = head1 -> next;
                    while(t)
                    {
                        if (strcmp(t -> user__name, enter__name) == 0) //如果登陆用户 与t相同
                        {
                            t -> price = t -> price + p -> price;
                            write__link(1, head1);
                            printf("\n\n\n已将销售金额写入该用户!\n\n\n");
                            f=0;
                            break;
                        }
                        t = t -> next;
                    }
                    break;
                }
                if (strcmp(key, "N") == 0 || strcmp(key, "n") == 0)
                {
                    pay__off();
                }

            }

        }
        else
        {
            p = p -> next;
            if (p == NULL&&f)
            {
                printf("\n\n\n没有该订单！\n\n\n");
                break;
            }
        }

    }


    while (1)
    {
        printf("是否继续买单<Y / N> \n>>");
        scanf("%s", key);
        if (strcmp(key, "Y") == 0 || strcmp(key, "y") == 0)
        {
            pay__off();
            break;
        }
        else
        {
            if(strcmp(key, "N") == 0 || strcmp(key, "n") == 0)
            {
                dervice__enter();
                break;
            }
        }
    }
}
/**打印信息**/
/*打印台桌信息*/
void table__menu()
{
    printf("      桌号       状态       活动   \n");
    struct node *q, *head;
    head = (struct node *)malloc(sizeof(struct node));
    head = read__link(3, head);
    q = head -> next;
    while(q)
    {
        printf("%10s%10s%10s\n", q -> num, q -> status, q -> action);
        q = q -> next;
    }
}
/*打印订单信息*/
void order__menu()
{
    printf("      单号      桌号      菜数      合计      已买单      活动  \n");
    struct node *head, *p;
    head = (struct node *)malloc(sizeof(struct node));
    head = read__link(4, head);
    p = head -> next;
    while(p)
    {
        printf("%10s%10s%10d%10.2lf%10s%10s\n", p -> name, p -> num, p->typ, p->price, p -> status, p -> action);
        p = p -> next;
    }
}
/*打印菜单信息*/
void dish__menu()
{
    printf("     菜号      菜名        价格      状态     是否活动\n");
    struct node *q, *head;
    head = (struct node *)malloc(sizeof(struct node));
    head = read__link(2, head);
    q = head -> next;
    while(q)
    {
        printf("%10s%10s%10.2lf%10s%10s\n", q -> num, q -> name, q -> price, q -> status, q -> action);
        q = q -> next;
    }
}
/*打印人员信息*/
void staff__menu()
{

    printf("      用户名                  密码                      类型\n");
    struct node *q, *head;
    head =  (struct node *)malloc(sizeof(struct node));
    head = read__link(1, head);
    q = head -> next;
    while(q)
    {
        printf("%10s              %10s               %10d\n", q -> user__name, q -> password, q -> typ);
        q = q -> next;
    }
}
/*打印订单点菜信息信息*/
void order__menus()
{
    printf("      订单号      菜目      数目      合计\n");
    struct node *head, *p;
    head = (struct node *)malloc(sizeof(struct node));
    head = read__link(5, head);
    p = head -> next;
    while(p)
    {
        printf("%10s%10s%10d%10.2lf\n", p->num, p -> name, p->typ, p->price);
        p = p -> next;
    }
}
