#ifndef PHONE_H_INCLUDED
#define PHONE_H_INCLUDED
typedef struct date;
typedef struct phonebook;
void load();
void add();
int search(int x);
void del();
void save();
void prnt();
void Modify();
int isValidEmail(char *email);
void phonenumber(int x);
void sortbyDOB();
void sortbyLname();
void Lname(int x);
void Fname(int x);
int ValidAddress(char *address);


#endif // PHONE_H_INCLUDED
