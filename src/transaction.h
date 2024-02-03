#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Structure for saving account
struct Saving {
  float interestRate;
} save;

// Structure for current account
struct Current {
  float overdraftLimit;
} cur;

// Union to hold either Saving or Current account
union Accounts {
  struct Saving savingAccount;
  struct Current currentAccount;
} accountDetails;

// Function Declarations

void transactions();
void balanceCheck();
void interestRate();