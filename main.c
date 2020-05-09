#include "my_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <errno.h>

int main()
{
    head *start=NULL;       ///����� "������" ��������� ������
    FILE *ph;               ///����� �����, � ������� ���������� �������� ������
    char *data,             ///����� ������� �������� ������, �� ����� ph
        sep;                ///������-�����������
    int ans,                ///����� ������������
        schet,              ///���������� ��� �������� ���������� ID
        count;              ///�������

    setlocale(LC_ALL, "RUS");
    count=0;
    schet=0;

    do
    {
        puts("����:");
        puts("1) - ���� ������������������ ��������");
        puts("2) - ����� ��������� ������������������");
        puts("3) - �������� ��������");
        puts("4) - �����");
        ans=choose();
        system("cls");
        switch(ans)
        {
            ///--------------------------------------------------------
            case(1):
                do
                {
                    puts("�������:");
                    puts("1) - ���� �������� �� �����");
                    puts("2) - ���� �������� � ����������");
                    puts("3) - ����������� � ������� ����");
                    ans=choose();
                    system("cls");
                    switch(ans)
                    {
                        ///--------------------------------------------
                        case(1):
                            if (start)
                                clear_str(start);

                            start=create_head();
                            ph=fopen("car_catalog.csv", "r");
                            if (ph)
                            {
                                sep=';';
                                data=(char*)malloc(80*sizeof(char));
                                if (data)
                                {
                                    while(fgets(data, 80, ph)!=NULL)
                                    {
                                        schet++;
                                        file_fill(start, data, sep, schet);
                                    }
                                    puts("���� ������ ������� ��������!");
                                    delay();
                                }
                                else
                                {
                                    puts("������ ��������� ������");
                                    fclose(ph);
                                    delay();
                                }
                            }
                            else
                            {
                                perror("��������� ������: ");
                                puts("���������� ������ ������ � ����������.");
                                delay();
                            }
                            break;
                        ///--------------------------------------------
                        case(2):
                            if (start)
                            {
                                ans=choose();
                                if (ans!=0)
                                    count=0;
                            }
                            else
                                count=0;

                            do
                            {
                                count++;
                                schet++;
                                if ((count!=1)&&(start))
                                {
                                    create_elem(start, schet, 1, NULL);
                                    puts("������ ������ ��� ���������? (1)");
                                    ans=choose();
                                }
                                else if(start==NULL)
                                {
                                    start=create_head();
                                    create_elem(start, schet, 1, NULL);
                                    puts("������ ������ ��� ���������? (1)");
                                    ans=choose();
                                }
                                else
                                {
                                    clear_str(start);
                                    start=create_head();
                                    create_elem(start, schet, 1, NULL);
                                    puts("������ ������ ��� ���������? (1)");
                                    ans=choose();
                                }
                            }while(ans==1);
                            puts("\n���� �������� ��������");
                            delay();
                            break;
                        ///--------------------------------------------
                        case(3):
                            puts("����������� � ������� ����");
                            delay();
                            break;
                        ///--------------------------------------------
                        default:
                            puts("������� ������������ ��������. ���������� ��� ���");
                            delay();
                    }
                }while(ans!=3);
                ans=1;

                break;
            ///--------------------------------------------------------
            case(2):
                if (start!=NULL)
                {
                    puts("��������� ������������������ ��������:");
                    str_out(start);
                }
                else
                {
                    puts("�� ��� �� ����� �� ����� ���������");
                    delay();
                }
                break;
            ///--------------------------------------------------------
            case(3):
                if (start!=NULL)
                {
                    puts("�������� ��������...");
                    del_node(start, start->cnt);
                    puts("�������!");
                    str_out(start);
                }
                else
                    puts("�� ��� �� ����� �� ����� ���������");
                delay();
                break;
            ///--------------------------------------------------------
            case(4):
                puts("���������� ���������");
                if (start)
                    clear_str(start);
                delay();
                break;
            ///--------------------------------------------------------
            default:
                puts("������������ ����. ���������� ��� ���");
                delay();
        }
    }while(ans!=4);

    return 0;
}
