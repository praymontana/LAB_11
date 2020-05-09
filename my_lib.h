#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

///���������, ����������� �������������� ���� �������� ������
typedef struct C
{
    char* name;             ///�������� ����������
    char* type;             ///��� ������
    int* vin;               ///�������������� ����������
    int year;               ///��� �������
    float cost;             ///���� ����������
}cars;

///���������, ����������� ������� ������
typedef struct e
{
    int ID;                 ///�������������� ������������� ������
    cars *content;          ///����� ��������������� ���� �������� ������
    struct e *next;         ///����� ���������� �������� ������
    struct e *prev;         ///����� ����������� �������� ������
}node;

///���������, ����������� "������" ������
typedef struct h
{
    int cnt;                ///���������� �������� � ������
    node *first;            ///����� ������� �������� ������
    node *last;             ///����� ���������� �������� ������
}head;

///�������, ���������� �������� � ������� ������
void delay();

///�������, ������������ ����� ������������
int choose();

///�������, ������������� ����������
char* input_line();

///�������, ����������� ���������
cars* str_fill();

///�������, ��������� ������
void str_out(head *h);

///������� ��������� ���������
void clear_str(head *h);

///�������, ������������� ������ ��-��� ���������� ������� �����
void clear(char** data1, int schet);

///�������, ������� ������ �� ����� �����������
char **split(char *data0, char sep);

///�������, ����������� ��������� �� �����
void file_fill(head *h, char *data, char sep, int schet);

///�������, ��������� "������" ������
head *create_head();

///�������, ��������� ������ ������
void create_elem(head* h, int k, int g, cars *ks);

///�������, ��������� ������� ������
void del_node(head *st, int id);

#endif // FUNC_H_INCLUDED
