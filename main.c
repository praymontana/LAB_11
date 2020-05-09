#include "my_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <errno.h>

int main()
{
    head *start=NULL;       ///Àäðåñ "ãîëîâû" èñõîäíîãî ñïèñêà
    FILE *ph;               ///Àäðåñ ôàéëà, â êîòîðîì ñîäåðæàòñÿ èñõîäíûå äàííûå
    char *data,             ///Àäðåñ ïåðâîãî ýëåìåíòà ñòðîêè, èç ôàéëà ph
        sep;                ///Ñèìâîë-ðàçäåëèòåëü
    int ans,                ///Âûáîð ïîëüçîâàòåëÿ
        schet,              ///Ïåðåìåííàÿ äëÿ õðàíåíèÿ ïîñëåäíåãî ID
        count;              ///Ñ÷åò÷èê

    setlocale(LC_ALL, "RUS");
    count=0;
    schet=0;

    do
    {
        puts("Ìåíþ:");
        puts("1) - Ââîä ïîñëåäîâàòåëüíîñòè ñòðóêòóð");
        puts("2) - Âûâîä ââåäåííîé ïîñëåäîâàòåëüíîñòè");
        puts("3) - Óäàëåíèå ýëåìåíòà");
        puts("4) - Êîíåö");
        ans=choose();
        system("cls");
        switch(ans)
        {
            ///--------------------------------------------------------
            case(1):
                do
                {
                    puts("Ïîäìåíþ:");
                    puts("1) - Ââîä ñòðóêòóð èç ôàéëà");
                    puts("2) - Ââîä ñòðóêòóð ñ êëàâèàòóðû");
                    puts("3) - Âîçâðàùåíèå â ãëàâíîå ìåíþ");
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
                                    free(data);
                                    puts("Ââîä äàííûõ óñïåøíî çàâåðøåí!");
                                    delay();
                                }
                                else
                                {
                                    puts("Îøèáêà âûäåëåíèÿ ïàìÿòè");
                                    fclose(ph);
                                    delay();
                                }
                            }
                            else
                            {
                                perror("Ïðîèçîøëà îøèáêà: ");
                                puts("Ïîïðîáóéòå ââåñòè äàííûå ñ êëàâèàòóðû.");
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
                                    puts("Õîòèòå ââåñòè åùå ñòðóêòóðû? (1)");
                                    ans=choose();
                                }
                                else if(start==NULL)
                                {
                                    start=create_head();
                                    create_elem(start, schet, 1, NULL);
                                    puts("Õîòèòå ââåñòè åùå ñòðóêòóðû? (1)");
                                    ans=choose();
                                }
                                else
                                {
                                    clear_str(start);
                                    start=create_head();
                                    create_elem(start, schet, 1, NULL);
                                    puts("Õîòèòå ââåñòè åùå ñòðóêòóðû? (1)");
                                    ans=choose();
                                }
                            }while(ans==1);
                            puts("\nÂâîä ñòðóêòóð çàâåðøåí");
                            delay();
                            break;
                        ///--------------------------------------------
                        case(3):
                            puts("Âîçâðàùåíèå â ãëàâíîå ìåíþ");
                            delay();
                            break;
                        ///--------------------------------------------
                        default:
                            puts("Ââåäåíî íåêîððåêòíîå çíà÷åíèå. Ïîïðîáóéòå åù¸ ðàç");
                            delay();
                    }
                }while(ans!=3);
                ans=1;

                break;
            ///--------------------------------------------------------
            case(2):
                if (start!=NULL)
                {
                    puts("Ââåäåííàÿ ïîñëåäîâàòåëüíîñòü ñòðóêòóð:");
                    str_out(start);
                }
                else
                {
                    puts("Âû åù¸ íå ââåëè íè îäíîé ñòðóêòóðû");
                    delay();
                }
                break;
            ///--------------------------------------------------------
            case(3):
                if (start!=NULL)
                {
                    puts("Óäàëåíèå ýëåìåíòà...");
                    del_node(start, start->cnt);
                    puts("Óñïåøíî!");
                    str_out(start);
                }
                else
                    puts("Âû åù¸ íå ââåëè íè îäíîé ñòðóêòóðû");
                delay();
                break;
            ///--------------------------------------------------------
            case(4):
                puts("Çàâåðøåíèå ïðîãðàììû");
                if (start)
                    clear_str(start);
                delay();
                break;
            ///--------------------------------------------------------
            default:
                puts("Íåêîððåêòíûé ââîä. Ïîïðîáóéòå åù¸ ðàç");
                delay();
        }
    }while(ans!=4);

    return 0;
}
