#include "file_IO.h"

// File Reading Function till the end of the file

bool f_scanf(FILE *filename) {
  return fscanf(filename, "%s %s %s %s %d/%d/%d %d %s %s %s %d %f", acc.acc_no,
                acc.name, user.username, user.password, &acc.dob.month,
                &acc.dob.day, &acc.dob.year, &acc.age, acc.phone,
                acc.pancard_no, acc.aadhaar_no, &acc.acc_type, &acc.amt) != EOF;
}

// File Printing Function

void f_printf(FILE *filename) {
  fprintf(filename, "%s %s %s %s %d/%d/%d %d %s %s %s %d %f\n", acc.acc_no,
          acc.name, user.username, user.password, acc.dob.month, acc.dob.day,
          acc.dob.year, acc.age, acc.phone, acc.pancard_no, acc.aadhaar_no,
          acc.acc_type, acc.amt);
}