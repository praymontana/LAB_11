#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_lib.h"

void delay()
{
    system("pause");
    system("cls");
}

int choose()
{
    char* line;         ///����� ������, ��������� �������������
    int ans_coose;      ///�������� ���� ������������

    line=(char*)malloc(15*sizeof(char));
    if (line!=NULL)
    {
        fflush(stdin);
        fgets(line, 15, stdin);
        ans_coose=atoi(line);
    }
    else
    {
        puts("������ ��������� ������");
        ans_coose=5;
    }

    free(line);

    return ans_coose;
}

char* input_line()
{
    char* line_input;          ///����� ������� �������� �������� ������

    line_input=(char*)malloc(80*sizeof(char));
    if (line_input!=NULL)
    {
        fflush(stdin);
        fgets(line_input, 79, stdin);
        line_input[strlen(line_input)-1]='\0';
        line_input=(char*)realloc(line_input, (strlen(line_input)+1)*sizeof(char));
    }
    else
    {
        puts("������ ��������� ������");
        delay();
    }
    return line_input;
}

cars* str_fill()
{
    cars *str; ///����� ���������, � ������� ���������� ���������� � ���������
    char *s;
    int cop;            ///���������� ��� �������� ����� ������������

    str=(cars*)malloc(sizeof(cars));
    if (str!=NULL)
    {
        str->name=(char*)malloc(80*sizeof(char));
        if (str->name!=NULL)
        {
            puts("������� ���������:");
            printf("������� �������� ���������� - ");
            str->name=input_line();
            str->name=(char*)realloc(str->name, (strlen(str->name)+1)*sizeof(char));

            printf("������� ��� ������ - ");
            str->type=input_line();
            str->type=(char*)realloc(str->type, (strlen(str->type)+1)*sizeof(char));
            str->vin=(int*)malloc(3*sizeof(int));

            do
            {
                printf("��� �� �� ������� ��������� ���������� �� 0 �� 10? - ");
                cop=choose();
                if ((cop<0)||(cop>10))
                    puts("������������ ����, ���������� �����");
            }while((cop<0)||(cop>10));
            str->vin[0]=cop;

            do
            {
                printf("������� �������: 0 - �������, 1 - ��������, 2 - ���������, 3 - �����. ");
                cop=choose();
                if ((cop<0)||(cop>3))
                    puts("������������ ����, ���������� �����");
            }while((cop<0)||(cop>3));
            str->vin[1]=cop;

            do
            {
                printf("��� ���������: 0 - ����������, 1 - ���������, 2 - ���, 3 - ������, 4 - �������. ");
                cop=choose();
                if ((cop<0)||(cop>4))
                    puts("������������ ����, ���������� �����");
            }while((cop<0)||(cop>4));
            str->vin[2]=cop;

            do
            {
                printf("������� ��� ������� ���������� - ");
                cop=choose();
                if ((cop<1885)||(cop>2020))
                    puts("������������ ����, ���������� �����");
            }while((cop<1885)||(cop>2020));
            str->year=cop;

            do
            {
                printf("������� ��������� ���������� - ");
                s=input_line();
                cop=atof(s);
                if ((cop<20)||(cop>1000000))
                    puts("������������ ����, ���������� �����");
            }while((cop<20)||(cop>1000000));
            str->cost=cop;
            free(s);
        }
        else
        {
            puts("������ ��������� ������ ��� ���� name");
            delay();
            free(str);
        }
    }
    else
    {
        puts("������ ��������� ������");
        delay();
    }
    return str;
}

void print_header()
{
    printf("|%20s |%10s |%18s|%6s|%6s|\n", "NAME","TYPE","CHARACTERISTICS","YEAR","COST");
    printf("+---------------------+-----------+------------------+------+------+\n");
}

void str_out(head *h)
{
    node *p;            ///����� ��������� ��� ������ ��-�� ������
    int ans_out;        ///����� ������������1

    p=(node*)malloc(sizeof(node));
    if (p)
    {
        puts("� ����� ������� �� ������ ������� �������� ������? (0 - ������, 1 - ��������)");
        ans_out=choose();
        do
        {
            if ((ans_out!=0)&&(ans_out!=1))
            {
                puts("������������ ��������. ���������� �����");
                ans_out=choose();
            }
        }while((ans_out!=0)&&(ans_out!=1));

        system("cls");
        if (ans_out)
        {
            p=h->last;
            puts("�������� ������ � �������� �������");
            print_header();
            while(p)
            {
                printf("|%20s |%10s |%5d %5d %5d |%5d |%5.2f |\n",
                    p->content->name,p->content->type,p->content->vin[0],p->content->vin[1],p->content->vin[2],p->content->year,p->content->cost);
                p=p->prev;
            }
        }
        else
        {
            p=h->first;
            puts("�������� ������ � ������ �������");
            print_header();
            while(p)
            {
                printf("|%20s |%10s |%5d %5d %5d |%5d |%5.2f |\n",
                    p->content->name,p->content->type,p->content->vin[0],p->content->vin[1],p->content->vin[2],p->content->year,p->content->cost);
                p=p->next;
            }
        }
        delay();
    }
}

void clear_str(head *h)
{
    node *p=NULL;       ///����� ���������, ��� ������� ���������� ����������� ������

    p=(node*)malloc(sizeof(node));
    if(p)
    {
        p=h->first;
        while(p)
        {
            h->first=p->next;
            free(p->content->name);
            free(p->content);
            free(p);
            p=h->first;
            h->cnt=h->cnt-1;
        }
        free(h);
        h=NULL;
    }
}

void clear(char** data1, int schet)
{
    int i;

    for(i=0;i<schet;i++)
        free(data1[i]);

    free(data1);
}

char **split(char *data0, char sep)
{
    char **str=NULL;            ///����� ������� �������� ������ ������
    int i,                      ///�������� �����
        j,                      ///�������� �����
        k,                      ///
        m;                      ///���������� �������� ������������ � ������
    int key,                    ///����������, ������������, ��������� �� ���������� ������
        count;                  ///������� ��������� ��������

    for(j=0,m=0;j<strlen(data0);j++)
        if(data0[j]==sep)
            m++;

    key=1;
    str=(char**)malloc((m+1)*sizeof(char*));
    if(str!=NULL)
    {
        for(i=0,count=0;i<=m;i++,count++)
        {
            str[i]=(char*)malloc(strlen(data0)*sizeof(char));
            if(str[i]==NULL)
            {
                key=0;
                i=m;
            }
        }

        if(key)
        {
            k=0;
            m=0;
            for(j=0;j<strlen(data0);j++)
            {
                if(data0[j]!=sep)
                    str[m][j-k]=data0[j];
                else
                {
                    str[m][j-k]='\0';
                    k=j+1;
                    m++;
                }
            }
            str[m][j-k]='\0';
        }
        else
            clear(str, count);
     }
     return str;
}

head *create_head()
{
    head *h=NULL;               ///"������" ������

    h=(head*)malloc(sizeof(head));
    if (h)
    {
        h->cnt=0;
        h->first=NULL;
        h->last=NULL;
    }
    else
    {
        puts("������ ��������� ������");
        delay();
    }

    return h;
}

void create_elem(head* h, int k, int g, cars *ks)
{
    node *sled=NULL;            ///����� ��������� ��� �������� ��������� ������

    sled=(node*)malloc(sizeof(node));
    if (sled)
    {
        if (h->first==NULL)
        {
            sled->prev=NULL;
            h->first=sled;
        }
        else
        {
            h->last->next=sled;
            sled->prev=h->last;
        }

        h->cnt++;
        sled->ID=k;
        sled->next=NULL;
        h->last=sled;
        if (g)
            sled->content=str_fill();
        else
            sled->content=ks;
    }
}

void file_fill(head *h, char *data, char sep, int schet)
{
    cars *ks;           ///���������� ��� ���������� ��������������� ����
    char **str;         ///����� ������� �������� ������ ������ ��������� �������� ������ �� ����� �����������

    data[strlen(data)-1]='\0';
    str=split(data, sep);
    ks=(cars*)malloc(sizeof(cars));
    ks->name=(char*)malloc((strlen(str[0])+1)*sizeof(char));
    strcpy(ks->name, str[0]);
    ks->type=(char*)malloc(20*sizeof(char));
    strcpy(ks->type, str[1]);
    ks->vin=(int*)malloc(3*sizeof(int));
    ks->vin[0]=atoi(str[2]);
    ks->vin[1]=atoi(str[3]);
    ks->vin[2]=atoi(str[4]);
    ks->year=atoi(str[5]);
    ks->cost=atof(str[6]);
    create_elem(h, schet, 0, ks);
    clear(str, 7);
}

void del_node(head *h, int id)
{
    node *p0=NULL,          ///����� ��������� ��� �������� ��-�� ������
        *p1=NULL;           ///����� ��������� ��� �������� ��-�� ������

    p0=(node*)malloc(sizeof(node));
    p1=(node*)malloc(sizeof(node));
    if (p0&&p1)
    {
        p1=h->first;
        p0=p1;
        while(p1->ID!=id)
        {
            p0=p1;
            p1=p1->next;
        }

        if (h->cnt==1)
        {
            h->first=NULL;
            h->last=NULL;
            free(p1->content->name);
            free(p1->content);
            free(p1);
        }
        else if (p1==h->last)
        {
            free(p1->content->name);
            free(p1->content);
            free(p1);
            p0->next=NULL;
            h->last=p0;
        }
        else if (p1==h->first)
        {
            h->first=p1->next;
            free(p1->content->name);
            free(p1->content);
            free(p1);
        }
        else
        {
            p0->next=p1->next;
            free(p1->content->name);
            free(p1->content);
            free(p1);
        }
        h->cnt=h->cnt-1;
    }
}
