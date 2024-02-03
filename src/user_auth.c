#include "user_auth.h"
#include "account.h"
#include <stdio.h>

void Login_or_SignUp() {
  int choice;

  system("cls");
  printf("\n\n\t\t\t BANK MANAGEMENT SYSTEM\n\n");

  printf("\n\t\t 1. Login\n\t\t 2. SignUp\n\n\t\t Enter your choice: ");
  while (scanf("%d", &choice) != 1) { // Error handling for string input
    printf("\n\t\tInvalid input. Please enter a number: ");
    while (getchar() != '\n')
      ;
  }

  if (choice == 1) {
    // A user has maximum of three attempts to give a correct username and
    // password
    user.attempts = 3;
    loginAuth();
  } else if (choice == 2) {
    createAccount();
  } else {
    system("cls");
    printf("\n\nInvalid Choice\n\n");
    system("pause");
    Login_or_SignUp();
  }
}

// Login Authentication

void loginAuth() {

  bool isLogin_success = false;
  char *uname = (char *)malloc(20 * sizeof(char));
  char *upass = (char *)malloc(20 * sizeof(char));

  FILE *rec;
  rec = fopen("record.dat", "r");

  system("cls");
  printf("\t\t\tLOGIN");

  printf("\n\n\t\tUSERNAME: ");
  scanf("%s", uname);

  printf("\n\n\t\tPASSWORD: ");
  scanf("%s", upass);

  while (f_scanf(rec)) {
    if ((strcmp(uname, user.username) == 0) &&
        (strcmp(upass, user.password) == 0)) {
      isLogin_success = true;
      break;
    }
  }
  fclose(rec);
  free(uname);
  uname = NULL;
  free(upass);
  upass = NULL;

  if (isLogin_success != true) {
    system("cls");
    printf("Try Again!!!\n\n");
    user.attempts--; // for each unsuccessful login the attempts get reduced
    system("pause");
    if (user.attempts == 0) {
      system("cls");
      printf("\nAll three attempts is over.You can't try again");
      close(); // if all three attempts are login it exits
    } else {
      loginAuth();
    }
  } else {
    system("cls");
    Bank_mainmenu();
  }
}

// Logging out of the account

void logout() {
  printf("Logging out successfully............");
  fordelay(1000000000);
  Login_or_SignUp();
}
