#include "my_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <errno.h>

int main()
{
    head *start=NULL;       ///Адрес "головы" исходного списка
    FILE *ph;               ///Адрес файла, в котором содержатся исходные данные
    char *data,             ///Адрес первого элемента строки, из файла ph
        sep;                ///Символ-разделитель
    int ans,                ///Выбор пользователя
        schet,              ///Переменная для хранения последнего ID
        count;              ///Счетчик

    setlocale(LC_ALL, "RUS");
    count=0;
    schet=0;

    do
    {
        puts("Меню:");
        puts("1) - Ввод последовательности структур");
        puts("2) - Вывод введенной последовательности");
        puts("3) - Удаление элемента");
        puts("4) - Конец");
        ans=choose();
        system("cls");
        switch(ans)
        {
            ///--------------------------------------------------------
            case(1):
                do
                {
                    puts("Подменю:");
                    puts("1) - Ввод структур из файла");
                    puts("2) - Ввод структур с клавиатуры");
                    puts("3) - Возвращение в главное меню");
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
                                    puts("Ввод данных успешно завершен!");
                                    delay();
                                }
                                else
                                {
                                    puts("Ошибка выделения памяти");
                                    fclose(ph);
                                    delay();
                                }
                            }
                            else
                            {
                                perror("Произошла ошибка: ");
                                puts("Попробуйте ввести данные с клавиатуры.");
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
                                    puts("Хотите ввести еще структуры? (1)");
                                    ans=choose();
                                }
                                else if(start==NULL)
                                {
                                    start=create_head();
                                    create_elem(start, schet, 1, NULL);
                                    puts("Хотите ввести еще структуры? (1)");
                                    ans=choose();
                                }
                                else
                                {
                                    clear_str(start);
                                    start=create_head();
                                    create_elem(start, schet, 1, NULL);
                                    puts("Хотите ввести еще структуры? (1)");
                                    ans=choose();
                                }
                            }while(ans==1);
                            puts("\nВвод структур завершен");
                            delay();
                            break;
                        ///--------------------------------------------
                        case(3):
                            puts("Возвращение в главное меню");
                            delay();
                            break;
                        ///--------------------------------------------
                        default:
                            puts("Введено некорректное значение. Попробуйте ещё раз");
                            delay();
                    }
                }while(ans!=3);
                ans=1;

                break;
            ///--------------------------------------------------------
            case(2):
                if (start!=NULL)
                {
                    puts("Введенная последовательность структур:");
                    str_out(start);
                }
                else
                {
                    puts("Вы ещё не ввели ни одной структуры");
                    delay();
                }
                break;
            ///--------------------------------------------------------
            case(3):
                if (start!=NULL)
                {
                    puts("Удаление элемента...");
                    del_node(start, start->cnt);
                    puts("Успешно!");
                    str_out(start);
                }
                else
                    puts("Вы ещё не ввели ни одной структуры");
                delay();
                break;
            ///--------------------------------------------------------
            case(4):
                puts("Завершение программы");
                if (start)
                    clear_str(start);
                delay();
                break;
            ///--------------------------------------------------------
            default:
                puts("Некорректный ввод. Попробуйте ещё раз");
                delay();
        }
    }while(ans!=4);

    return 0;
}
