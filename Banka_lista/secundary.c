/* Ovaj C fajl obuhvata sve pomocne funkcije koje sluze kao dopuna glavnim operacijama iz pocetnog menija. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "menu.h"
#include "main_functions.h"

/* Funkcija koja proverava da li je pri unosu novog korisnika tip njegovog naloga korektno popunjen. */
void enter_the_type_of_account(User* temp, FILE* f)
{
   int count = 0;
   const int NUM_OF_TRY = 3;
   while(count < NUM_OF_TRY)
   {
     printf("Type of account: \n");
     printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)"
     "\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
     scanf("%s", temp->type_of_account);

   if(strcmp(temp->type_of_account,"Saving") == 0 || strcmp(temp->type_of_account,"Current") == 0 || strcmp(temp->type_of_account,"Fixed1") == 0 || strcmp(temp->type_of_account,"Fixed2") == 0 || strcmp(temp->type_of_account,"Fixed3") == 0)
   {
       fprintf(f,"%d %s %s %d %d %d %d %s %s %lf %s %f %d %d %d\n", temp->account_number, temp->name, temp->lastname,
                 temp->birth.day, temp->birth.month, temp->birth.year, temp->age, temp->address, temp->citizenship,
                 temp->phone_number, temp->type_of_account, temp->payment_amount, temp->deposit.day,temp->deposit.month,
                 temp->deposit.year);
       break;
   }
   else
   {
       system("cls");
       printf("You entered the wrong type of account!\n");
       count++;
   }
 }
 if(count == NUM_OF_TRY)
 {
     printf("You entered the wrong type 3x times!\n");
 }
}
/* Funkcija koja nudi opcije na osnovu kojih mozemo da se vratimo u glavni meni ili potpuno izadjenmo iz aplikacije*/
void menu_or_exit()
{
    do{
        printf("Enter 0 if you want to exit the application or 1 to go in main menu: ");
        scanf("%d", &choice);
        switch(choice)
       {
       case 0:
           system("cls");
           exit_app();
           break;
       case 1:
           system("cls");
           menu();
           break;
       default:
        printf("Wrong input!\a\n");
       }
       }while(choice != 0 || choice != 1);

}
/* Funkcija cijim se pozivom vrsi modifikacija baze podataka. */
void modify_account()
{
    FILE* f;
    f = fopen(NAME_FILE,"w");
    if(f == NULL)
    {
       printf("%s", WRITE);
       exit(EXIT_FAILURE);
    }
    User* temp = head;
    while(temp)
    {
        fprintf(f,"%d %s %s %d %d %d %d %s %s %lf %s %f %d %d %d\n\n", temp->account_number, temp->name, temp->lastname,
                 temp->birth.day, temp->birth.month, temp->birth.year, temp->age, temp->address, temp->citizenship,
                 temp->phone_number, temp->type_of_account, temp->payment_amount, temp->deposit.day,temp->deposit.month,
                 temp->deposit.year);
        temp = temp->next;
    }
    fclose(f);
}
/* Funkcija koja izracunava zaradu u odnosu na tip naloga korisnika. */
float interest(float time, float amt, int rate)
{
    float earning_amt;
    earning_amt = (time*amt*rate)/(100.0);
    return (earning_amt);
}
