#ifndef _MAIN_FUNCTIONS_H
#define _MAIN_FUNCTIONS_H
#define NAME_FILE "baza.txt"
#define CHANGES "Changes is saved!\n"
#define READ "Error with reading the base!\n"
#define WRITE "Error with writing in base!\n"
#define OPEN "There is a error with opening a %s file!\n"
#define NO_USER "There is no user with this account number!\n"

void exit_app();
void add_user();
void reading_data();
void update_account();
void transactions();
void print();
void user_details();
void remove_user();

#endif

