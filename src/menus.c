#include "menus.h"

void fordelay(int j) {
  int i;
  for (i = 0; i < j; i++)
    ;
}

// To Display the main menu after completing each operation.

void main_menu() {
  int main_exit;

  fordelay(1000000000); // To show the menu with a certain amount of time delay

  printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit: ");
  while (scanf("%d", &main_exit) != 1) {
    printf("\n\t\tInvalid input. Please enter a number: ");
    while (getchar() != '\n')
      ;
  }
  system("cls");
  if (main_exit == 1)
    Bank_mainmenu();
  else if (main_exit == 0)
    close();
  else {
    printf("\n\nInvalid Input\n\n");
    main_menu();
  }
}

// Bank Main Menu with different operations a user can perform

void Bank_mainmenu() {

  int choice;

  system("cls");
  printf("\n\n\n\t\t       WELCOME TO THE BANK MAIN MENU");
  printf("\n\n\t\t1.Update "
         "account\n\t\t2.Transactions\n\t\t3.Balance Enquiry\n\t\t4.Interest "
         "Rate Check\n\t\t5.Delete account\n\t\t6.View "
         "account details\n\t\t7.Validate Account no\n\t\t8.Validate "
         "PanCard\n\t\t9.Validate "
         "AadhaarCard\n\t\t10.Logout\n\t\t11.Exit\n\n\n\n\n\t\t Enter "
         "your choice: ");
  while (scanf("%d", &choice) != 1) { // Error handling for a string input
    printf("\n\t\tInvalid input. Please enter a number: ");
    while (getchar() != '\n')
      ;
  }

  system("cls");
  switch (choice) {
  case 1:
    updateAccount();
    break;
  case 2:
    transactions();
    break;
  case 3:
    balanceCheck();
    break;
  case 4:
    interestRate();
    break;
  case 5:
    deleteAccount();
    break;
  case 6:
    displayRecords();
    break;
  case 7:
    validateAccno();
    break;
  case 8:
    validatePanCard();
    break;
  case 9:
    validateAadhaarCard();
    break;
  case 10:
    logout();
    break;
  case 11:
    close();
    break;
  default:
    printf("Invalid Input");
    main_menu();
  }
}