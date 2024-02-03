#include "account.h"
#include <stdio.h>

// Viewing the Records

void displayRecords() {

  FILE *view;
  view = fopen("record.dat", "r");

  system("cls");
  printf("\nACC. NO.\tNAME\t\tAGE\t\tPHONE\t\tACCOUNT TYPE\t\tBALANCE\n");

  while (f_scanf(view)) {
    printf("\n%10s\t%10s\t%d\t\t%10s\t\t%d\t\t%f", acc.acc_no, acc.name,
           acc.age, acc.phone, acc.acc_type, acc.amt);
  }
  fclose(view);

  main_menu();
}