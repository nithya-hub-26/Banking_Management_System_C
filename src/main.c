#include "account.h"
#include "user_auth.h"
#include <stdio.h>
#include <stdlib.h>

// Main function

int main() {

  // Dynamic Allocation of the array fields in the struct

  user.username = (char *)malloc(20 * sizeof(char));
  user.password = (char *)malloc(20 * sizeof(char));

  acc.name = (char *)malloc(50 * sizeof(char));
  acc.acc_no = (char *)malloc(20 * sizeof(char));
  acc.phone = (char *)malloc(20 * sizeof(char));
  acc.pancard_no = (char *)malloc(20 * sizeof(char));
  acc.aadhaar_no = (char *)malloc(20 * sizeof(char));

  Login_or_SignUp(); // Starting Page

  return 0;
}