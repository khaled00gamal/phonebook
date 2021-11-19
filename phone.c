#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "phone.h"
#include <ctype.h>


typedef struct
{
    int day;
    int month;
    int year;
} date;

typedef struct phonebook
{
    char lastname[100];
    char firstname[100];
    date d;
    char address[100];
    char email[100];
    char phonenumber[100];

} phone;


phone contacts[1000];
FILE* p;
int r; //modify index number
int x; //tells index number
count=0;

void Fname(int m) //scans first name,checks if valid,,,,in add,m is count
{
    int i,flag2;
    do
    {
        flag2 = 1;
        printf("First name:");
        scanf("%s", contacts[m].firstname);


        for (i = 0; i < strlen(contacts[m].firstname); i++)
        {
            if (isdigit(contacts[m].firstname[i]))
            {
                flag2 = 0;//invalid
            }
        }
        if (flag2 == 0)
        {
            printf("Name should not contain numbers \n");
        }

    }


    while( flag2==0);
}

void Lname(int m) //scans last name,checks if valid
{
    int i,flag2;
    do
    {
        flag2 = 1;
        printf("Lastname:");
        scanf("%s", contacts[m].lastname);


        for (i = 0; i < strlen(contacts[m].lastname); i++)
        {
            if (isdigit(contacts[m].lastname[i]))
            {
                flag2 = 0;
            }
        }
        if (flag2 == 0)
        {
            printf("Name should not contain numbers \n");
        }

    }


    while(flag2==0);
}
void phonenumber(int m)
{
    int i,flag1,flag2;
    do
    {
        flag1 = flag2 = 1; //flag1 for number of digits ,,, flag2 for char in the number
        printf("phone number [6..12 digits]: ");
        scanf("%s", contacts[m].phonenumber);

        if (strlen(contacts[m].phonenumber) < 6 || strlen(contacts[m].phonenumber) > 12)
        {
            printf("Length of phone numbers should be between 6 and 12 digits.\n");
            flag1 = 0;
        }

        for (i = 0; i < strlen(contacts[m].phonenumber); i++)
        {
            if (!isdigit(contacts[m].phonenumber[i]))
            {
                flag2 = 0;
            }
        }
        if (flag2 == 0)
        {
            printf("Phone numbers should only contain digits (0-9).\n");
        }

    }


    while(flag1==0 || flag2==0);
}
int ValidAddress(char *address)
{
    int i, flag =0;
    for (i =0; i<strlen(address); i++)
    {
        if(address[i]=='@' || address[i]=='$' || address[i]=='+' || address[i]=='=' || address[i]=='%' || address[i]=='!' || address[i]=='^' || address[i]==')' || address[i]=='(' || address[i]=='*' || address[i]=='"' || address[i]==';' || address[i]=='<' || address[i]=='>' || address[i]==':' || address[i]== '&')

            if(flag)
                return 1; //invalid


            else
                return 0; //valid
    }
}

int isValidEmail(char *email)
{
    int sLen = strlen(email);
    int i,flagat = 0;
    int flagdot = 0;
    for (i=0; i<sLen; i++)
    {
        if (email[i] == '@')
        {
            if (flagat)//if @ is found again (invalid)
                return 0;
            flagat = i;
        }
        if (email[i] == '.')
        {
            if (flagdot && flagdot > flagat) //if dot found again && and is after @ (invalid)
                return 0;
            flagdot = i;
        }
    }
    if (flagdot && (flagdot - flagat) <= 1) //if dot found and space between dot & @ is 1 or less (invalid)
        return 0;

 if ((flagdot)&&((sLen-1)-flagdot)!=3)

             return 0; //invalid

if (flagdot == sLen-1)
        return 0;
    if (flagdot && flagat)
        return 1;
    return 0;
    }






void load() // Load the file
{
    p=fopen("contacts.txt","r");
    if(p==NULL)
    {
        printf("There is an error");
        exit(0);
    }
    else
    {
        while(!feof(p))
        {
            fscanf(p,"%[^,],",contacts[count].lastname);
            fscanf(p,"%[^,],",contacts[count].firstname);
            fscanf(p,"%d-",&contacts[count].d.day);
            fscanf(p,"%d-",&contacts[count].d.month);
            fscanf(p,"%d,",&contacts[count].d.year);
            fscanf(p,"%[^,],",contacts[count].address);
            fscanf(p,"%[^,],",contacts[count].email);
            fscanf(p,"%s\n",contacts[count].phonenumber);
            printf("\n%s %s %d-%d-%d %s %s %s",contacts[count].lastname,contacts[count].firstname,contacts[count].d.day,contacts[count].d.month,contacts[count].d.year,contacts[count].address,contacts[count].email,contacts[count].phonenumber);
            count++;
        }
    }
    fclose(p);
}

void Add() //Add a contact
{
    int flag1,flag2,flag3;//flags for day,month and year conditions,respectively
    char temp;//takes up new line from scanf so address string is scaned whole


        Lname(count);//scans from user and checks if valid (count) adds new contact last in array
        Fname(count);//scans from user and checks if valid
        printf(" date of birth\n");
        printf("Day:");
        do
        {
            flag1 =1;
            scanf("%d", &contacts[count].d.day);
            if (contacts[count].d.day>31 || contacts[count].d.day<1 )
            {
                printf("Days should be between (1-31)");
                flag1 = 0;
            }
            else
                break;
        }
        while(flag1==0);
        printf("month:");
        do
        {
            flag2 =1;
            scanf("%d", &contacts[count].d.month);
            if (contacts[count].d.month>12 || contacts[count].d.month<1)
            {
                printf("Months should be between (1-12)");
                flag2 = 0;
            }
            else
                break;
        }
        while (flag2==0);

        printf("Year : ");
        do
        {
            flag3 =1;
            scanf("%d", &contacts[count].d.year);
            if (contacts[count].d.year>2020 || contacts[count].d.year<1000)
            {
                printf("Enter a valid year");
                flag3 = 0;
            }
            else
                break;
        }
        while (flag3==0);
        printf("Address: ");
        scanf("%c",&temp);
        scanf("%[^\n]",contacts[count].address);
        while(!ValidAddress(contacts[count].address))
        {
            printf("Invalid address, Please enter a valid address:");
            scanf("%c",&temp);
            scanf("%[^\n]",contacts[count].address);
        }
        printf("Email: ");
        scanf("%s",contacts[count].email);
        while(!isValidEmail(contacts[count].email))
        {
            printf("Invalid Email, Please enter a valid email:");
            scanf("%s",contacts[count].email);
        }
        phonenumber(count);
        printf("\n\tcontact successfully added to Phonebook\n");
        count++;
    }


int search(int c) //search for contact
{

    int counter=0;//counts number of contacts found with scanned name
    char a;
    char name[50];
    printf("Do you wanna search via last name or first name?\n");
    while (a!='l' && a!='L' && a!='f' && a!='F')
    {
        printf("Enter either L or F:");
        scanf("%s",&a);
    }
    if(a=='L' || a=='l')
    {
        printf("Enter the last name you want to search for : ");
        scanf("%s",name);
        for(x=0; x<count; x++)
        {
            if(strcasecmp(name,contacts[x].lastname)==0)
            {
                counter++;
                printf("\nPerson #%d: \n",x+1);
                printf("First name : %s \n",contacts[x].firstname);
                printf("Last name: %s \n",contacts[x].lastname);
                printf("Birth date : %d-%d-%d \n",contacts[x].d.day,contacts[x].d.month,contacts[x].d.year);
                printf("Address : %s \n",contacts[x].address);
                printf("email : %s \n",contacts[x].email);
                printf("Phone number : %s \n\n\n",contacts[x].phonenumber);
                r=x;
            }
        }
    }
    if(a=='F'|| a=='f')
    {

        printf("Enter the first name you want to search for : \n");
        scanf("%s",name);
        for(x=0; x<count; x++)
        {
            if(strcasecmp(name,contacts[x].firstname)==0)
            {
                counter++;
                printf("\nPerson #%d: \n",x+1);
                printf("First name : %s \n",contacts[x].firstname);
                printf("Last name: %s \n",contacts[x].lastname);
                printf("Birth date : %d-%d-%d \n",contacts[x].d.day,contacts[x].d.month,contacts[x].d.year);
                printf("Address : %s \n",contacts[x].address);
                printf("email : %s \n",contacts[x].email);
                printf("Phone number : %s \n\n",contacts[x].phonenumber);
                r=x;

            }
        }
    }
    if(counter!=0)
        printf("%d contact/s found with this last name\n ",counter);
    else
        printf(" No contacts found with this last name \n");

    return counter;
}

void del()   //delete contact
{
    int i,z;
    char lastname[50];
    char firstname[50];
    int flag=0;//found or not found
    printf("Enter the last name : \n");
    scanf("%s",lastname);
    printf("Enter the first name : \n");
    scanf("%s",firstname);
    for(i=0; i<count; i++)
    {
        if(strcasecmp(lastname,contacts[i].lastname)==0)
        {
            if(strcasecmp(firstname,contacts[i].firstname)==0)
            {
                flag=1;//found
                for(z=i; z<count-1; z++)
                {

                    strcpy(contacts[i].lastname,contacts[i+1].lastname);
                    strcpy(contacts[i].firstname,contacts[i+1].firstname);
                    strcpy(contacts[i].address,contacts[i+1].address);
                    strcpy(contacts[i].email,contacts[i+1].email);
                    strcpy(contacts[i].phonenumber,contacts[i+1].phonenumber);
                    contacts[i].d.day=contacts[i+1].d.day;
                    contacts[i].d.month=contacts[i+1].d.month;
                    contacts[i].d.year=contacts[i+1].d.year;
                }
                --count;
            }

        }


    }
    if(flag==0) //not found
        printf(" can't find contact \n");
    else if(flag==1)
        printf("  contact has been deleted \n");
}


void save()    //save changes
{
    int i;
    p=fopen("contacts.txt","w");
    for(i=0; i<count; i++)
    {
        fprintf(p,"%s,%s,%d-%d-%d,%s,%s,%s\n",contacts[i].lastname,contacts[i].firstname,
                contacts[i].d.day,contacts[i].d.month,contacts[i].d.year,contacts[i].address,contacts[i].email,contacts[i].phonenumber);
    }
    printf("your changes are saved successfully");
    fclose(p);
}
void sortbyLname()
{
    int i,j;
    phone temp;//used to swap in bubble sort
    for (j = 0; j < count-1; j++)
    {


        for (i = 0; i < count-j-1; i++)
        {

            if (strcasecmp(contacts[i].lastname,contacts[i+1].lastname)>0)
            {
                temp=contacts[i];
                contacts[i]=contacts[i+1];
                contacts[i+1]=temp;

            }

        }
    }
}
void sortbyDOB()
{
    int i,j;
    phone temp;
    for (j = 0; j< count-1; j++)
    {


        for (i= 0; i < count-j-1; i++)
        {

            if (contacts[i].d.year > contacts[i+1].d.year)
            {
                temp=contacts[i];
                contacts[i]=contacts[i+1];
                contacts[i+1]=temp;

            }
            else if(contacts[i].d.year == contacts[i+1].d.year)
            {
                if(contacts[i].d.month > contacts[i+1].d.month)
                {
                    temp=contacts[i];
                    contacts[i]=contacts[i+1];
                    contacts[i+1]=temp;
                }
                else if(contacts[i].d.month == contacts[i+1].d.month)
                {
                    if(contacts[i].d.day > contacts[i+1].d.day)
                    {
                        temp=contacts[i];
                        contacts[i]=contacts[i+1];
                        contacts[i+1]=temp;

                    }

                }

            }
        }
    }
}


void prnt()
{

    int i;
    int choice = 0;
    printf("Choose The Way You Would Like The PhoneBook To Be Sorted By: \n");
    printf("1- Sort By Last Name\n");
    printf("2- Sort By Date of Birth \n");
    scanf("%d",&choice);
    while(choice!=1 && choice!=2)
    {
        printf("please choose 1 or 2 \n");
        scanf("%d",&choice);
    }

    if(choice==1)
        sortbyLname();
    else if (choice==2)
        sortbyDOB();
    for(i=0; i<count; i++)
    {
        printf("contact #%d: \n\n",i+1);
        printf("\tLast name: %s \n",contacts[i].lastname);
        printf("\tFirst name : %s \n",contacts[i].firstname);
        printf("\tBirth date : %d-%d-%d \n",contacts[i].d.day,contacts[i].d.month,contacts[i].d.year);
        printf("\tAddress : %s \n",contacts[i].address);
        printf("\temail : %s \n",contacts[i].email);
        printf("\tPhone number : %s \n\n",contacts[i].phonenumber);
    }
}


void Modify()   //Edit contact
{
    int choice=0;
    int flag1,flag2,flag3;
    char temp;
    int c;
    int y=search(c);
    if (y!=0)
    {
        if(y>1)
        {
            printf("\n Enter number of the contact you want to modify:");
            scanf("%d",&r);
            r--;

        }
        printf("Do You want to modify First name?\n1-Modify \n2-Skip\n");
        scanf("%d",&choice);
        while(choice!=1 && choice!=2)
        {
            printf("Please choose 1 or 2");
            scanf("%d",&choice);
        }


        if (choice==1)
        {
            Fname(r);
        }

        printf("Do You want to modify Last name?\n1-Modify \n2-Skip\n");
        scanf("%d",&choice);
        while(choice!=1 && choice!=2)
        {
            printf("Please choose 1 or 2");
            scanf("%d",&choice);
        }


        if (choice==1)
        {
            Lname(r);
        }

        printf("Do You want to modify Date of Birth?\n1-Modify \n2-Skip\n");
        scanf("%d",&choice);
        while(choice!=1 && choice!=2)
        {
            printf("Please choose 1 or 2");
            scanf("%d",&choice);
        }


        if (choice==1)
        {
            printf("New Date of birth:\nDay: ");

            do
            {
                flag1 =1;//valid
                scanf("%d", &contacts[r].d.day);
                if (contacts[r].d.day>31 || contacts[r].d.day<1 )
                {
                    printf("Days should be between (1-31)");
                    flag1 = 0;//invalid
                }
                else
                    break;
            }
            while(flag1==0);//redo loop if its invalid
            printf("month:");
            do
            {
                flag2 =1;
                scanf("%d", &contacts[r].d.month);
                if (contacts[r].d.month>12 || contacts[r].d.month<1)
                {
                    printf("Months should be between (1-12)");
                    flag2 = 0;
                }
                else
                    break;
            }
            while (flag2==0);

            printf("Year : ");
            do
            {
                flag2 =1;
                scanf("%d", &contacts[r].d.year);
                if (contacts[r].d.year>2020 || contacts[r].d.year<1000)
                {
                    printf("Enter a valid year");
                    flag2 = 0;
                }
                else
                    break;
            }
            while (flag2==0);
        }

        printf("Do You want to modify address?\n1-Modify \n2-Skip\n");
        scanf("%d",&choice);
        while(choice!=1 && choice!=2)
        {
            printf("Please choose 1 or 2");
            scanf("%d",&choice);
        }

        if (choice==1)
        {
            printf("Address: ");
            scanf("%c",&temp);
            scanf("%[^\n]",contacts[r].address);
            while(!ValidAddress(contacts[r].address))
            {
                printf("Invalid address, Please enter a valid address:");
                scanf("%c",&temp);
                scanf("%[^\n]",contacts[r].address);
            }
        }
        printf("Do You want to modify Email?\n1-Modify \n2-Skip\n");
        scanf("%d",&choice);
        while(choice!=1 && choice!=2)
        {
            printf("Please choose 1 or 2");
            scanf("%d",&choice);
        }

        if (choice==1)
        {
            printf("New Email: ");

            scanf("%s",contacts[r].email);
            while(!isValidEmail(contacts[r].email))
            {
                printf("Invalid Email, Please enter a valid email:");
                scanf("%s",contacts[r].email);
            }
        }

        printf("Do You want to modify Phone number?\n1-Modify \n2-Skip\n");
        scanf("%d",&choice);
        while(choice!=1 && choice!=2)
        {
            printf("Please choose 1 or 2");
            scanf("%d",&choice);
        }

        if (choice==1)
        {
            phonenumber(r);
        }

    }
}
