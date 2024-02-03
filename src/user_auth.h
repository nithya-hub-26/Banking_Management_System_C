#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// User structure for authentication
struct User {
  char *username;
  char *password;
  int attempts;
} user;

// Function Declarations

void Login_or_SignUp();
void loginAuth();
void logout();