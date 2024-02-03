#include "transaction.h"
#include "account.h"
#include <stdio.h>

// Transaction with deposit and withdraw operations

void transactions() {

  // Settings the rate and limit for savings and current account
  save.interestRate = 7;
  cur.overdraftLimit = 100000;

  int choice;
  bool isAccno_exist = false;
  float amount;
  char *accno = (char *)malloc(20 * sizeof(char));

  FILE *oldrec, *newrec;
  oldrec = fopen("record.dat", "r");
  newrec = fopen("new.dat", "w");

  printf("Enter the account no:");
  scanf("%s", accno);

  while (f_scanf(oldrec)) {

    if (strcmp(accno, acc.acc_no) == 0) {
      isAccno_exist = true;
      printf("\n\nWhat operation do you want to "
             "perform\n1.Deposit\n2.Withdraw\n3.Back\n\nEnter your "
             "choice: ");
      while (scanf("%d", &choice) != 1) { // Error handling for a string input
        printf("\nInvalid input. Please enter a number: ");
        while (getchar() != '\n')
          ;
      }
      system("cls");
      if (choice == 1) {
        printf("Enter the amount you want to deposit:$ ");
        while (scanf("%f", &amount) != 1) {
          printf("\nInvalid input. Please enter a number: ");
          while (getchar() != '\n')
            ;
        }
        acc.amt += amount;
        f_printf(newrec);
        printf("\n\nDeposited successfully!");
      } else if (choice == 2) {
        printf("Enter the amount you want to withdraw:$ ");
        while (scanf("%f", &amount) != 1) {
          printf("\nInvalid input. Please enter a number: ");
          while (getchar() != '\n')
            ;
        }
        float bal = acc.amt - amount;

        // if it is savings account, no withdrawal beyond the balance
        if (bal < 0 && acc.acc_type == 1) {
          printf("\n\nWithdrawal amount exceeds balance! Unsuccessfull!!\n");
        }

        // if it is current account check for overdraft limit
        else if (bal < 0 && acc.acc_type == 2) {
          // if it exceeds within overdraft, withdraw will be successful with
          // minus balance
          if (abs(bal) <= cur.overdraftLimit) {
            acc.amt -= amount;
            printf("\n\nWithdrawal amount exceeds balance with overdraft! "
                   "Withdrawn successfully!\n");
          }
          // if it exceeds the overdraft limit itself then withdraw will be
          // unsuccessful
          else {
            printf("\n\nWithdrawal amount exceeds overdraft limit of the "
                   "account! Unsuccessfull!!\n");
          }
        } else {
          // if the withdraw amount is within the balance
          acc.amt -= amount;
          printf("\n\nWithdrawn successfully!");
        }
        f_printf(newrec);
      } else if (choice == 3) {
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
    printf("\nNO RECORDS FOUND!!");
  } else {
    remove("record.dat");
    rename("new.dat", "record.dat");
  }
  main_menu();
}

// To check the balance in an account

void balanceCheck() {
  bool isAccno_exist = false;
  char *accno = (char *)malloc(20 * sizeof(char));

  FILE *rec;
  rec = fopen("record.dat", "r");

  printf("Enter the account no:");
  scanf("%s", accno);

  while (f_scanf(rec)) {
    if (strcmp(accno, acc.acc_no) == 0) {
      printf("\n\nBalance:$ %.2f", acc.amt);
      isAccno_exist = true;
      break;
    }
  }
  fclose(rec);
  free(accno);
  accno = NULL;

  if (isAccno_exist != true) {
    system("cls");
    printf("\nNO RECORDS FOUND!!\n");
  }
  main_menu();
}

// To check the interest based on the account type

void interestRate() {
  bool isAccno_exist = false;
  float amount, time, interest;
  char *accno = (char *)malloc(20 * sizeof(char));

  FILE *rec;
  rec = fopen("record.dat", "r");

  printf("Enter the account no:");
  scanf("%s", accno);

  while (f_scanf(rec)) {
    if (strcmp(accno, acc.acc_no) == 0) {
      isAccno_exist = true;

      // if savings account calculate the interest amount
      if (acc.acc_type == 1) {
        time = (1.0 / 12.0);
        interest = (time * acc.amt * save.interestRate) / 100.0;
        printf("\n\nYou will get $ %.2f as interest on every month", interest);
      }
      // if current account no interest
      else {
        printf("\n\nYou will get no interest\a\a");
      }
    }
  }
  fclose(rec);
  free(accno);
  accno = NULL;

  if (isAccno_exist != true) {
    system("cls");
    printf("\nNO RECORDS FOUND!!\n");
  }
  main_menu();
}