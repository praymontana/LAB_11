#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

///Структура, описывающая информационное поле элемента списка
typedef struct C
{
    char* name;             ///Название автомобиля
    char* type;             ///Тип кузова
    int* vin;               ///Характеристики автомобиля
    int year;               ///Год выпуска
    float cost;             ///Цена автомобиля
}cars;

///Структура, описывающая элемент списка
typedef struct e
{
    int ID;                 ///Индивидуальный идентификатор списка
    cars *content;          ///Адрес информационного поля элемента списка
    struct e *next;         ///Адрес следующего элемента списка
    struct e *prev;         ///Адрес предыдущего элемента списка
}node;

///Структура, описывающая "голову" списка
typedef struct h
{
    int cnt;                ///Количество структур в списке
    node *first;            ///Адрес первого элемента списка
    node *last;             ///Адрес последнего элемента списка
}head;

///Функция, вызывающая задержку и очистку экрана
void delay();

///Функция, возвращающая выбор пользователя
int choose();

///Функция, осуществлющая считывание
char* input_line();

///Функция, заполняющая структуру
cars* str_fill();

///Функция, выводящая список
void str_out(head *h);

///Функция очищающая структуры
void clear_str(head *h);

///Функция, освобождающая память из-под двумерного массива строк
void clear(char** data1, int schet);

///Функция, делящая строку по знаку разделителю
char **split(char *data0, char sep);

///Функция, заполняющая структуру из файла
void file_fill(head *h, char *data, char sep, int schet);

///Функция, создающая "голову" списка
head *create_head();

///Функция, создающая лемент списка
void create_elem(head* h, int k, int g, cars *ks);

///Функция, удаляющая элемент списка
void del_node(head *st, int id);

#endif // FUNC_H_INCLUDED
