# **Bank Management System**

This project is a simple Bank Management System implemented in C, designed to manage customer accounts, transactions, and account information. It provides basic functionalities like creating a new account, updating account details, making transactions (deposit and withdrawal), checking balances, view customer details and more.

This project contains 2 structure and a union:

1. Accounts union - contains savings and current account structure
2. Saving structure
3. Current structure

**User can create two types of account:**

**1. Savings account:** It has interest rate which is set to 7%.<br>
                      - The interest rate for every month could be checked in interest rate check module.
                      - If the withdraw amount is less than the balance of that account then the withdraw will be unsuccessful.
   
**2. Current account:** It has overdraft limit which is set to 1 lakh.<br>
                       - It has no interest
                       - If the withdraw amount is less than the balance of that account then the withdraw will be successful with minus balance. But if the withdraw amount exceeds even the overdraft limit of 1 lakh then the withdraw will be unsuccessful.

**Features:**
1. User authentication with a username and password
2. User can create savings or current account
3. Creation, updating, and deletion of customer accounts
4. Transaction functionalities: deposit and withdrawal
5. Balance checking and interest rate calculation
6. Validation of account number, Pan Card, and Aadhaar Card
