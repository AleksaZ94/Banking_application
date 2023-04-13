#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "main_functions.h"
#include "secundary.h"
/* Funkcija koja ispisuje glavni meni. U okviru glavnog menija se nalaze osnovne operacije. */
void menu()
{
    system("cls");
    system("color 8");
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions"
           "\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's"
           "list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d", &choice);
    while(1)
    {
        switch(choice)
        {
        case 1:
            system("cls");
            add_user();
            break;
        case 2:
            system("cls");
            update_account();
            break;
        case 3:
            system("cls");
            transactions();
            break;
        case 4:
            system("cls");
            user_details();
            break;
        case 5:
            system("cls");
            remove_user();
            break;
        case 6:
            system("cls");
            print();
            break;
        case 7:
            system("cls");
            exit_app();
            break;
        default:
            system("cls");
            printf("You enter the wrong number!\n");
            break;
        }
        menu();
    }
}
/* Funkcija koja porverava da li je sifra koju smo uneli tacna. Ukoliko se vise od 3 puta pogresi
   dolazi do izlaska iz funkcije i prekida rada aplikacije. */
void password()
{
    int counter = 0;
    char pass[MAX_C];
    printf("Enter the password: ");
    scanf("%s", pass);
    while(1)
    {
        system("cls");
        if(strcmp(pass,"1234") == 0)
        {
            break;
        }
        else
        {
         counter++;
         if(counter == 3)
        {
            system("cls");
            printf("You have exceeded the number of attempts to enter the corrcect code!\a\n");
            exit_app();
            break;
        }
         printf("You enter the wrong password!\a\n");
         printf("Enter the password again (there are %d attempts more): ", 3 - counter);
         scanf("%s", pass);
        }
    }
}

