#include "account.h"
#include "user_auth.h"
#include <stdio.h>

// To check for a strong password while creating a account

bool isStrongPassword(char *pass) {

  bool isUpper = false;
  bool isLower = false;
  bool isDigit = false;
  bool isSpecial = false;
  bool isLength = false;

  // To check for the length of the password
  if (strlen(pass) >= 6 && strlen(pass) <= 12) {
    isLength = true;
  }

  for (int i = 0; pass[i] != '\0'; i++) {
    // To check for uppercase letter
    if (isupper(pass[i])) {
      isUpper = true;
    }
    // To check for lowercase letter
    else if (islower(pass[i])) {
      isLower = true;
    }
    // To check for digit
    else if (isdigit(pass[i])) {
      isDigit = true;
    }
    // To check for special character
    else if (!isalnum(pass[i])) {
      isSpecial = true;
    }
  }
  // To check if all conditions are true to set a strong password
  if (isUpper && isLower && isDigit && isSpecial && isLength) {
    printf("\nGood. Strong Password\n");
    return true;
  } else {
    printf("\nWeak Password. Try setting a strong password\n");
    return false;
  }
}

// Account Creation

void createAccount() {

  char *accno = (char *)malloc(20 * sizeof(char));
  FILE *rec;

  rec = fopen("record.dat", "a+");

  system("cls");
  printf("              CREATE ACCOUNT                  \n");
  printf("\nEnter the account number:");
  scanf("%s", accno);

  while (f_scanf(rec)) { // reading the file
    if (strcmp(accno, acc.acc_no) == 0) {
      printf("\n\n\nAccount number already in use!\n\n");
      system("pause");
      createAccount();
    }
  }
  strcpy(acc.acc_no, accno);
  printf("\nEnter the name:");
  scanf("%s", acc.name);
  printf("\nEnter the date of birth(dd/mm/yy):");
  scanf("%d/%d/%d", &acc.dob.month, &acc.dob.day, &acc.dob.year);
  printf("\nEnter the age:");
  while (scanf("%d", &acc.age) != 1) { // Error handling for a string input
    printf("\nInvalid input. Please enter a number: ");
    while (getchar() != '\n')
      ;
  }
  printf("\nEnter the phone number: ");
  scanf("%s", acc.phone);
  printf("\nEnter the pan card number: ");
  scanf("%s", acc.pancard_no);
  printf("\nEnter the aadhaar card number: ");
  scanf("%s", acc.aadhaar_no);
  printf("\nEnter the username:");
  scanf("%s", user.username);

  do {
    printf("\nEnter the password:");
    scanf("%s", user.password);
  } while (!isStrongPassword(user.password)); // Check for a strong password

  printf("\nEnter the amount to deposit:$");
  while (scanf("%f", &acc.amt) != 1) {
    printf("\nInvalid input. Please enter a number: ");
    while (getchar() != '\n')
      ;
  }

  printf("\nType of account:\n\t1. Saving\n\t2. Current\n\n\tEnter your "
         "choice(1 or 2):");
  while (scanf("%d", &acc.acc_type) != 1) { // Error handling for a string input
    printf("\nInvalid input. Please enter a number: ");
    while (getchar() != '\n')
      ;
  }

  f_printf(rec); // Printing the user account details in a file

  fclose(rec);
  free(accno);
  accno = NULL;

  printf("\nAccount created successfully!\n\n");
  system("pause");

  Login_or_SignUp();
}

// Account Updation

void updateAccount() {
  int choice;
  bool isAccno_exist = false;
  char *accno = (char *)malloc(20 * sizeof(char));

  FILE *oldrec, *newrec;
  oldrec = fopen("record.dat", "r");
  newrec = fopen("new.dat", "w");

  printf("\nEnter the account no. to be change:");
  scanf("%s", accno);

  while (f_scanf(oldrec)) {
    if (strcmp(accno, acc.acc_no) == 0) {
      isAccno_exist = true;
      printf(
          "\nWhich information has to be "
          "updated?\n1.Account Type\n2.Phone\n3.Account holder "
          "name\n4.Age\n5.Username\n6.Password\n7.Back\n\nEnter your choice: ");

      while (scanf("%d", &choice) != 1) { // Error handling for a string input
        printf("\nInvalid input. Please enter a number: ");
        while (getchar() != '\n')
          ;
      }
      system("cls");
      if (choice == 1) {
        printf("Enter the new account type(1 - Savings or 2 - Current):");
        while (scanf("%d", &acc.acc_type) != 1) {
          printf("\nInvalid input. Please enter a number: ");
          while (getchar() != '\n')
            ;
        }
        f_printf(newrec);
        system("cls");
        printf("Changes saved!");
      } else if (choice == 2) {
        printf("Enter the new phone number:");
        scanf("%s", acc.phone);
        f_printf(newrec);
        system("cls");
        printf("Changes saved!");
      } else if (choice == 3) {
        printf("Enter the new account holder name:");
        scanf("%s", acc.name);
        f_printf(newrec);
        system("cls");
        printf("Changes saved!");
      } else if (choice == 4) {
        printf("Enter the new age:");
        while (scanf("%d", &acc.age) != 1) {
          printf("\nInvalid input. Please enter a number: ");
          while (getchar() != '\n')
            ;
        }
        f_printf(newrec);
        system("cls");
        printf("Changes saved!");
      } else if (choice == 5) {
        printf("Enter the new user name:");
        scanf("%s", user.username);
        f_printf(newrec);
        system("cls");
        printf("Changes saved!");
      } else if (choice == 6) {
        do {
          printf("\nEnter the password:");
          scanf("%s", user.password);
        } while (
            !isStrongPassword(user.password)); // Check for a strong password
        f_printf(newrec);
        system("cls");
        printf("Changes saved!");
      } else if (choice == 7) {
        main_menu();
      } else {
        printf("Invalid Input");
        main_menu();
      }
    } else {
      f_printf(newrec);
    }
  }
  fclose(oldrec);
  fclose(newrec);
  free(accno);
  accno = NULL;

  if (isAccno_exist != true) {
    system("cls");
    printf("\nNO RECORDS FOUND!!\n");
  } else {
    remove("record.dat");
    rename("new.dat", "record.dat");
  }
  main_menu();
}

// Account Deletion

void deleteAccount() {
  FILE *oldrec, *newrec;
  bool isAccno_exist = false;
  char *accno = (char *)malloc(20 * sizeof(char));

  oldrec = fopen("record.dat", "r");
  newrec = fopen("new.dat", "w");

  printf("Enter the account no. to be deleted:");
  scanf("%s", accno);

  while (f_scanf(oldrec)) {
    if (strcmp(accno, acc.acc_no) != 0)
      f_printf(newrec);
    else {
      isAccno_exist = true;
      printf("\nRecord deleted successfully!\n");
    }
  }
  fclose(oldrec);
  fclose(newrec);
  free(accno);
  accno = NULL;

  if (isAccno_exist != true) {
    system("cls");
    printf("\nNO RECORDS FOUND!!");
  } else {
    remove("record.dat");
    rename("new.dat", "record.dat");
  }
  main_menu();
}

// Exiting the Bank

void close() {
  printf("\n\n\n\n\t\t\tTHANK YOU FOR VISITING THE BANK\n\n\n\n");

  free(user.username);
  user.username = NULL;

  free(user.password);
  user.password = NULL;

  free(acc.name);
  acc.name = NULL;

  free(acc.acc_no);
  acc.acc_no = NULL;

  free(acc.aadhaar_no);
  acc.aadhaar_no = NULL;

  free(acc.pancard_no);
  acc.pancard_no = NULL;

  free(acc.phone);
  acc.phone = NULL;
}