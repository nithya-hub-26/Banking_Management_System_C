#include "account.h"
#include <stdio.h>

// Validating the Account number

void validateAccno() {
  bool isValid_Accno = false;
  char *accno = (char *)malloc(20 * sizeof(char));

  FILE *val;
  val = fopen("record.dat", "r");

  system("cls");
  printf("Enter Account number: ");
  scanf("%s", accno);

  while (f_scanf(val)) {
    if ((strcmp(accno, acc.acc_no) == 0) &&
        ((strlen(accno) >= 10) && (strlen(accno) <= 15))) {
      system("cls");
      printf("Account number is valid.\n");
      isValid_Accno = true;
      break;
    }
  }
  fclose(val);
  free(accno);
  accno = NULL;

  if (isValid_Accno != true) {
    system("cls");
    printf("Invalid Account number.\n");
  }
  main_menu();
}

// Validating the Pancard number

void validatePanCard() {
  bool isValid_Pancard = false;
  char *panCardno = (char *)malloc(20 * sizeof(char));

  FILE *val;
  val = fopen("record.dat", "r");

  system("cls");
  printf("Enter Pan Card number: ");
  scanf("%s", panCardno);

  while (f_scanf(val)) {
    if ((strcmp(panCardno, acc.pancard_no) == 0) && (strlen(panCardno) == 10)) {
      system("cls");
      printf("Pan Card number is valid.\n");
      isValid_Pancard = true;
      break;
    }
  }
  fclose(val);
  free(panCardno);
  panCardno = NULL;

  if (isValid_Pancard != true) {
    system("cls");
    printf("Invalid Pan Card number.\n");
  }
  main_menu();
}

// Validating the Aadhaarcard number

void validateAadhaarCard() {
  bool isValid_Aadharcard = false;
  char *aadhar_no = (char *)malloc(20 * sizeof(char));

  FILE *val;
  val = fopen("record.dat", "r");

  system("cls");
  printf("Enter Aadhaar Card number: ");
  scanf("%s", aadhar_no);

  while (f_scanf(val)) {
    if ((strcmp(aadhar_no, acc.aadhaar_no) == 0) && (strlen(aadhar_no) == 12)) {
      system("cls");
      printf("Aadhaar Card number is valid.\n");
      isValid_Aadharcard = true;
      break;
    }
  }
  fclose(val);
  free(aadhar_no);
  aadhar_no = NULL;

  if (isValid_Aadharcard != true) {
    system("cls");
    printf("Invalid Aadhaar Card number.\n");
  }
  main_menu();
}