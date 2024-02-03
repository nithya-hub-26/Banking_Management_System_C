#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Structure for date
struct date {
  int month;
  int day;
  int year;
};

// Structure for Customer Account
struct BankAccount {
  char *name;
  int age;
  char *acc_no;
  int acc_type;
  char *phone;
  char *pancard_no;
  char *aadhaar_no;
  float amt;
  struct date dob;

} acc;

// Function Declarations

bool isStrongPassword(char *);
void createAccount();
void updateAccount();
void displayRecords();
void deleteAccount();
void close();