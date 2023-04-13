#ifndef _USER_H
#define _USER_H
#define MAX_N 20
#define MAX_C 50
#define FIRST 1
#define SECOND 2
#define ZERO 0

struct Date{
  int day;
  int month;
  int year;
};

typedef struct User{
    char name[MAX_N];
    char lastname[MAX_N];
    int account_number;
    float payment_amount;
    int age;
    double phone_number;
    char citizenship[MAX_C];
    char address[MAX_C];
    struct Date deposit;
    struct Date birth;
    char type_of_account[MAX_N];
    struct User* next;
}User;

struct User* head;
User add;

int choice;
int marker;

#endif

