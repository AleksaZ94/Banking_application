/* U ovom fajlu obradjene su sve osnovne operacije koje se mogu videti u pocetnom meniju */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "menu.h"
#include "secundary.h"
#define NAME_FILE "baza.txt"
#define CHANGES "Changes is saved!\n"
#define READ "Error with reading the base!\n"
#define WRITE "Error with writing in base!\n"
#define OPEN "There is a error with opening a %s file!\n"
#define NO_USER "There is no user with this account number!\n"

char new_address[MAX_C];
int new_phone_number;
int acount_num;

/* Funkcija koja se koristi kao izlaz iz citave aplikacije
   Nakon svake obrade koja podrazumeva izmenu trenutne baze podataka
   trenutna baza se prazni i pravi se nova baza sa izmenjenim podacima. */
void exit_app()
{
    printf("\nThanks for using our application!\n");
    exit(0);
}
/* Citanje podataka iz baze i kreiranje liste na osnovu iste*/
void reading_data()
{
    FILE* f = fopen(NAME_FILE, "r");
    if(f == NULL)
    {
        printf("%s", READ);
        exit(EXIT_FAILURE);
    }
    /* U okviru while cita se svaki red i podaci se upisuju u pojedinacne cvorove liste*/
    while(fscanf(f,"%d %s %s %d %d %d %d %s %s %lf %s %f %d %d %d\n", &add.account_number, add.name, add.lastname,
                 &add.birth.day, &add.birth.month, &add.birth.year, &add.age, add.address, add.citizenship,
                 &add.phone_number, add.type_of_account, &add.payment_amount, &add.deposit.day, &add.deposit.month,
                 &add.deposit.year) != EOF)
                 {
                    if(head == NULL)
                    {
                       User* temp = (User*)malloc(sizeof(User));
                       temp->account_number = add.account_number;
                       strcpy(temp->name,add.name);
                       strcpy(temp->lastname,add.lastname);
                       temp->birth.day = add.birth.day;
                       temp->birth.month = add.birth.month;
                       temp->birth.year = add.birth.year;
                       temp->age = add.age;
                       strcpy(temp->address,add.address);
                       strcpy(temp->citizenship,add.citizenship);
                       temp->phone_number = add.phone_number;
                       strcpy(temp->type_of_account,add.type_of_account);
                       temp->payment_amount = add.payment_amount;
                       temp->deposit.day = add.deposit.day;
                       temp->deposit.month = add.deposit.month;
                       temp->deposit.year = add.deposit.year;
                       temp->next = NULL;
                       head = temp;
                    }
                    else
                    {
                        User* temp2;
                        temp2 = head;
                        while(temp2->next != NULL)
                        {
                            temp2 = temp2->next;
                        }
                       User* temp = (User*)malloc(sizeof(User));
                       temp->account_number = add.account_number;
                       strcpy(temp->name,add.name);
                       strcpy(temp->lastname,add.lastname);
                       temp->birth.day = add.birth.day;
                       temp->birth.month = add.birth.month;
                       temp->birth.year = add.birth.year;
                       temp->age = add.age;
                       strcpy(temp->address,add.address);
                       strcpy(temp->citizenship,add.citizenship);
                       temp->phone_number = add.phone_number;
                       strcpy(temp->type_of_account,add.type_of_account);
                       temp->payment_amount = add.payment_amount;
                       temp->deposit.day = add.deposit.day;
                       temp->deposit.month = add.deposit.month;
                       temp->deposit.year = add.deposit.year;
                       temp2->next = temp;
                       temp->next = NULL;
                }
        }
        fclose(f);
}
/* Funkcija koja dodaje novi cvor u listu i popunjava sve podatke vezane za korisnika */
void add_user()
{
   User* temp = (User*)malloc(sizeof(User));
   FILE* f;
   f = fopen(NAME_FILE, "a+");
   if(f == NULL)
   {
       printf("%s", OPEN);
       exit(EXIT_FAILURE);
   }
   if(head == NULL)
   {
   printf("\t\t\t\xB2\xB2 Adding a new acount \xB2\xB2\n\n");
   printf("Enter today's date(day/month/year): ");
   scanf("%d/%d/%d", &temp->deposit.day, &temp->deposit.month, &temp->deposit.year);
   printf("Enter the account number: ");
   scanf("%d", &temp->account_number);
   printf("Enter your name: ");
   scanf("%s", temp->name);
   printf("Enter your last name: ");
   scanf("%s", temp->lastname);
   printf("Enter your birthdate(day/month/year): ");
   scanf("%d/%d/%d", &temp->birth.day, &temp->birth.month, &temp->birth.year);
   printf("How old are you?: ");
   scanf("%d", &temp->age);
   printf("Enter your address: ");
   scanf("%s", temp->address);
   printf("Enter your citizenship: ");
   scanf("%s", temp->citizenship);
   printf("Enter you phone number: ");
   scanf("%lf", &temp->phone_number);
   printf("Enter the amount you want to deposit:$");
   scanf("%f", &temp->payment_amount);
   enter_the_type_of_account(temp,f);
   temp->next = NULL;
   head = temp;
   fclose(f);
   menu();
   }
   else
   {
    printf("\t\t\t\xB2\xB2 Adding a new acount \xB2\xB2\n\n");
    printf("Enter today's date(day/month/year): ");
    scanf("%d/%d/%d", &temp->deposit.day, &temp->deposit.month, &temp->deposit.year);
    printf("Enter the account number: ");
    scanf("%d", &acount_num);
    User* temp2 = head;
    while(temp2)
    {
        if(temp2->account_number == acount_num)
        {
            printf("User with that account number already exists!\n");
            menu_or_exit();
            break;
        }
        temp2 = temp2->next;
    }
    temp->account_number = acount_num;
    temp2 = head;
    while(temp2->next != NULL)
      {
          temp2 = temp2->next;
      }
   temp->account_number = acount_num;
   printf("Enter your name: ");
   scanf("%s", temp->name);
   printf("Enter your last name: ");
   scanf("%s", temp->lastname);
   printf("Enter your birthdate(day/month/year): ");
   scanf("%d/%d/%d", &temp->birth.day, &temp->birth.month, &temp->birth.year);
   printf("How old are you?: ");
   scanf("%d", &temp->age);
   printf("Enter your address: ");
   scanf("%s", temp->address);
   printf("Enter your citizenship: ");
   scanf("%s", temp->citizenship);
   printf("Enter you phone number: ");
   scanf("%lf", &temp->phone_number);
   printf("Enter the amount you want to deposit:$");
   scanf("%f", &temp->payment_amount);
   enter_the_type_of_account(temp,f);
   temp->next = NULL;
   temp2->next = temp;
   fclose(f);
   menu();
   }
}
/* Funkcija koja menja odredjena polja u listi korisnika*/
void update_account()
{
   printf("Enter the account number of user which informations you would like to change: ");
   scanf("%d", &acount_num);
   User* temp = head;
   marker = ZERO;
   while(temp)
   {
       if(temp->account_number == acount_num)
       {
           printf("\nWhich info you would like to change?\n1.Address\n2Phone number\n");
           printf("\nEnter your choice(1 for address i 2 for phone number): ");
           scanf("%d", &choice);
           if(choice == FIRST)
            {
               marker = FIRST;
               system("cls");
               printf("Enter the new address: ");
               scanf("%s", new_address);
               strcpy(temp->address,new_address);
            }
            else if(choice == SECOND)
            {
              marker = FIRST;
              printf("Enter the new phone number: ");
              scanf("%d", &new_phone_number);
              temp->phone_number = new_phone_number;
            }
       }
   }
   if(marker == FIRST)
       {
             system("cls");
             modify_account();
             printf("%s", CHANGES);
             menu_or_exit();
       }
       else
       {
           system("cls");
           printf("%s", NO_USER);
           menu_or_exit();
       }
}
/* Na osnovu ove funkcije omogucava se prenos novca, odnosno podizvanje novca ili uplata sa racuna odredjenog korisnika*/
void transactions()
{
   marker = ZERO;
   float temp_amt;
   float add_amt;
   float withdraw;
   printf("Enter the user account number: ");
   scanf("%d", &acount_num);
   User* temp = head;
   while(temp)
   {
       if(temp->account_number == acount_num)
       {
           marker = FIRST;
           if(strcmp(temp->type_of_account,"Fiksno1") == 0 || strcmp(temp->type_of_account,"Fiksno2") == 0 || strcmp(temp->type_of_account,"Fiksno3") == 0)
           {
              printf("You can't add or withdraw for fixed type of account");
              break;
           }
              printf("\nDo you want to add money or withdraw?\n");
              printf("1.Add\n2.Withdraw\n");
              scanf("%d", &choice);
              if(choice == FIRST)
              {
               printf("Enter the amount of money you would like to add to your account: ");
               scanf("%f", &add_amt);
               temp->payment_amount += add_amt;
               break;
              }
              else if(choice == SECOND)
               {
                printf("Enter the amount you would like to take from your account: ");
                scanf("%f", &withdraw);
                temp_amt = temp->payment_amount;
                temp->payment_amount -= withdraw;
                if(temp->payment_amount < 0)
                  {
                   float minus = temp->payment_amount;
                   temp->payment_amount = temp_amt;
                   system("cls");
                   printf("You exceeded the amount you can take off your account! You go in minus of %.2f\n", minus);
                   menu_or_exit();
                  }
                  break;
                }
                else
                {
                    printf("You input the wrong number for choice!\n");
                    menu_or_exit();
                }
         }
         temp = temp->next;
   }
   if(marker == FIRST)
       {
             system("cls");
             modify_account();
             printf("%s", CHANGES);
             menu_or_exit();
       }
       else
       {
           system("cls");
           printf("%s", NO_USER);
           menu_or_exit();
       }
}
/* Funkcija koja ispisuje detalje u odnosu na zeljenog korisnika */
void user_details()
{
    User* temp = head;
    float time, earning;
    int rate;
    earning = 0.0;
    marker = ZERO;
    printf("How do you want to check information on user:\n1.By account number\n2.By user's name\nEnter you choice: ");
    scanf("%d", &choice);
    if(choice == FIRST)
    {
        printf("Enter the account number of the user: ");
        scanf("%d", &acount_num);
        while(temp != ZERO)
        {
            if(temp->account_number == acount_num)
            {
                marker = FIRST;
                printf("\nAccount number: %d\nName: %s\nLastname: %s\nBirthday: %d/%d/%d."
                       "\nAge: %d\nAddress: %s\nCitizenship: %s\nPhone number: %.lf\nType of account: %s"
                       "\nPayment amount: %.2f\nDate of deposit: %d/%d/%d.\n\n",temp->account_number, temp->name, temp->lastname,
                       temp->birth.day, temp->birth.month, temp->birth.year, temp->age, temp->address, temp->citizenship,
                       temp->phone_number, temp->type_of_account, temp->payment_amount, temp->deposit.day,temp->deposit.month,
                       temp->deposit.year);
                if(strcmp(temp->type_of_account, "Saving") == 0)
                {
                 time = (1.0/12.0);
                 rate = 8;
                 earning = interest(time,temp->payment_amount,rate);
                 printf("Your earning would be: %.2f$ every %d in month\n", earning, temp->deposit.day);
                }
                else if(strcmp(temp->type_of_account,"Fixed1") == 0)
                {
                 time = 1.0;
                 rate = 9;
                 earning = interest(time,temp->payment_amount,rate);
                 printf("On day %d/%d/%d. your earning would be %.2f\n", temp->deposit.day,temp->deposit.month,temp->deposit.year+1, earning);
                }
                else if(strcmp(temp->type_of_account,"Fixed1") == 0)
                {
                 time = 2.0;
                 rate = 11;
                 earning = interest(time,temp->payment_amount,rate);
                 printf("On day %d/%d/%d. your earning would be %.2f\n", temp->deposit.day,temp->deposit.month,temp->deposit.year+2, earning);
                }
                else if(strcmp(temp->type_of_account,"Fixed1") == 0)
                {
                 time = 3.0;
                 rate = 13;
                 earning = interest(time,temp->payment_amount,rate);
                 printf("On day %d/%d/%d. your earning would be %.2f\n", temp->deposit.day,temp->deposit.month,temp->deposit.year+3, earning);
                }
                else if(strcmp(temp->type_of_account,"Current") == 0)
                {
                 printf("There is not earning for this type of account \"Current\"\n");
                }
            }
            temp = temp->next;
        }
        if(marker == FIRST)
       {
        menu_or_exit();
       }
       else if(marker == ZERO)
       {
        system("cls");
        printf("There is no user with this account number!\n");
        menu_or_exit();
       }
      }
      else if(choice == SECOND)
      {
       char name[MAX_N];
       printf("Enter the name of the user whose data you would like to see: ");
       scanf("%s", name);
       while(temp != 0)
       {
           if(strcmp(temp->name, name) == 0)
           {
               marker = FIRST;
                printf("\nAccount number: %d\nName: %s\nLastname: %s\nBirthday: %d/%d/%d.\nAge: %d\nAddress: %s\nCitizenship: %s\nPhone number: %.lf\nType of account: %s\nPayment amount: %.2f\nDate of deposit: %d/%d/%d.\n\n",temp->account_number, temp->name, temp->lastname,
                temp->birth.day, temp->birth.month, temp->birth.year, temp->age, temp->address, temp->citizenship,
                temp->phone_number, temp->type_of_account, temp->payment_amount, temp->deposit.day,temp->deposit.month,
                temp->deposit.year);
                if(strcmp(temp->type_of_account, "Saving") == 0)
                {
                 time = (1.0/12.0);
                 rate = 8;
                 earning = interest(time,temp->payment_amount,rate);
                 printf("Your earning would be: %.2f$ every %d in month\n", earning, temp->deposit.day);
                }
                else if(strcmp(temp->type_of_account,"Fixed1") == 0)
                {
                 time = 1.0;
                 rate = 9;
                 earning = interest(time,temp->payment_amount,rate);
                 printf("On day %d/%d/%d. your earning would be %.2f\n", temp->deposit.day,temp->deposit.month,temp->deposit.year+1, earning);
                }
                else if(strcmp(temp->type_of_account,"Fixed1") == 0)
                {
                 time = 2.0;
                 rate = 11;
                 earning = interest(time,temp->payment_amount,rate);
                 printf("On day %d/%d/%d. your earning would be %.2f\n", temp->deposit.day,temp->deposit.month,temp->deposit.year+2, earning);
                }
                else if(strcmp(temp->type_of_account,"Fixed1") == 0)
                {
                 time = 3.0;
                 rate = 13;
                 earning = interest(time,temp->payment_amount,rate);
                 printf("On day %d/%d/%d. your earning would be %.2f\n", temp->deposit.day,temp->deposit.month,temp->deposit.year+3, earning);
                }
                else if(strcmp(temp->type_of_account,"Current") == 0)
                {
                 printf("There is not earning for this type of account \"Current\"\n");
                }
            }
            temp = temp->next;
        }
        if(marker == FIRST)
       {
        menu_or_exit();
       }
       else if(marker == ZERO)
       {
        system("cls");
        printf("There is no user with this account number!\n");
        menu_or_exit();
       }
    }
}
/* Funkcija koja uklanja zeljenog korisnika. */
void remove_user()
{
   printf("Enter the account number of user you wolud like to delete: ");
   scanf("%d", &acount_num);
   User* temp = head;
   User* temp2;
   marker = ZERO;
   while(temp != 0)
   {
       if(temp->account_number == acount_num)
       {
           marker = FIRST;
           if(temp == head)
           {
               head = temp->next;
               temp2 = temp;
               free(temp2);
           }
           else
           {
               User* temp3 = temp;
               temp2->next = temp->next;
               temp = temp->next;
               if(temp == NULL)
               {
                   free(temp3);
                   break;
               }
               free(temp3);
           }
       }
       else
       {
           temp2 = temp;
           temp = temp->next;
       }
   }
   if(marker == FIRST)
       {
             system("cls");
             modify_account();
             printf("%s", CHANGES);
             menu_or_exit();
       }
       else
       {
           system("cls");
           printf("%s", NO_USER);
           menu_or_exit();
       }
}

/* Funkcija koja ispisuje sve sto se nalazi u trenutnoj bazi podataka. */
void print()
{
    int count = 0;
    User* temp = (User*)malloc(sizeof(User));
    temp = head;
    while(temp)
    {
        printf("User: %d\n\nAccount number: %d\nName: %s\nLastname: %s\nBirthday: %d/%d/%d.\nAge: %d\nAddress: %s\nCitizenship: %s\nPhone number: %.lf\nType of account: %s\nPayment amount: %.2f\nDate of deposit: %d/%d/%d.\n\n", count,temp->account_number, temp->name, temp->lastname,
                temp->birth.day, temp->birth.month, temp->birth.year, temp->age, temp->address, temp->citizenship,
                temp->phone_number, temp->type_of_account, temp->payment_amount, temp->deposit.day,temp->deposit.month,
                temp->deposit.year);
        count++;
        temp = temp->next;
    }
    menu_or_exit();
}
