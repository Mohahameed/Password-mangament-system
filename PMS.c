#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include<stdio.h>
#include "color.h"  //color header file
#include <conio.h>
#include <string.h>
#include<stdlib.h>


void welcome();
void Enterance();
void read_func();
void stor_func();

const char MyUsername[]={"asd1234"}; // write here your username 
const char MyPassword[]={"md12345"} ; // write here your password

typedef struct 
{

char Email[40];
char Password[40];

}account;

char num1;
char num2;

char ex[80]="securityfile/File/personal_file/"; //write here your file extesion
char final[5] = ".rec";           // write here the extension of the file 

int main()
{ 

     char ch;
     unsigned char i=0;
     welcome();
     Enterance();
 do{

     printf("choose one of the following choices:\n");
     printf("1-To add new password or change old one.\n");
     printf("2-To Show password \n");
     printf("choice: ");
     scanf("%d",&i);
 

       switch(i)
      {
         case 1:
         {
            stor_func();
            fflush(stdin);
            printf("Do you want to continue [Y/N]");
            scanf("%c",&ch);
            printf("\n");
           break;
         }
        case 2:
        {
          read_func();
          printf("Do you want to continue [Y/N]");
          scanf("%c",&ch);
          printf("\n"); 
          break;
        }
     
      default:
         {   printf("You have enterd wrong choice"); 
             printf(" Please try again![Y/N]:");
             scanf("%c",&ch);
             printf("\n");
         }

   }



 }while(ch=='y'||ch=='Y');
 

 
 
 
 return 0;
}
void read_func()
{  strcpy(ex,"security/INFile/encrypted_file/");
   strcpy(final,".rec");
  
char accName[20]; //The account Name
fflush(stdin);
printf(BLU "Which account do you want to open (Account_Name.rec):"RESET);
scanf("%s",accName);
fflush(stdin);
  strcat(ex, strupr(accName));
	strcat(ex, final);
account acc1; // a structure object


FILE*  fptr_out;

if((fptr_out=fopen(ex,"rb"))==NULL)
{
    printf(RED"Can't open the file\n"RESET);
    exit(1);
}
    char c;
    while(fread(&acc1,sizeof(acc1),1, fptr_out))
     {
       printf(BLU"%s\n"RESET,accName);
       printf("Email:");
       printf(GRN"%s\n"RESET,acc1.Email);
       printf("Password:");
       printf(GRN"%s\n"RESET,acc1.Password);


     }
   fclose(fptr_out);



}




//to store the passwords in a file 
void stor_func()
{ 
    account acc1;   //struct object
    char Acc_Name[20];
        strcpy(ex,"security/INFile/encrypted_file/");
        strcpy(final,".rec");

    char c;
    fflush(stdin);
    printf("Enter the Account name in the form of(Acount): ");
    gets(Acc_Name);
    fflush(stdin);
    strcat(ex, strupr(Acc_Name));
	  strcat(ex,final);

       FILE * fptr_in;
       if((fptr_in=fopen(ex,"wb"))==NULL)
       {
           printf("Error in opening the file ");
           exit(1);
       }

      do
      { 
         printf("the file has open successfuly\n");
         printf(GRN"The Account Email:"RESET);
         gets(acc1.Email);
         fflush(stdin);
         printf(GRN"The Password: "RESET);
         gets(acc1.Password);
         fflush(stdin);
         //entering the data from the structur to the file
         fwrite(&acc1,sizeof( acc1),1,fptr_in);

         printf(RED"Do you want to add another account sir [Y/N]: "RESET);
         scanf("%c",&c);
         printf("\n");

   
        } while (c=='y'||c=='Y');

       //you should close the file after writing
      fclose(fptr_in);




}



void Enterance()
{
  char UserName[50];
  char Password[50];
  char tries=3;

  printf("Please enter your Username and Password\n");
  fflush(stdin);
  
  //Three tries only to enter to the system or it will lock
  
 do
   {

      if(tries ==0)
      {
        exit(1);
      }
    
     //get username  from the user 
      printf("Username:");
      gets(UserName);
      fflush(stdin);
      // get password from the user
      printf("Password:");
      gets(Password);
      fflush(stdin);


     num1 = strcmp(UserName,MyUsername);
     num2 = strcmp(Password,MyPassword);

     if((num1 != 0) ||( num2 != 0))
       {
          tries--;
       }
  

    }while((num1 !=0) || (num2 !=0));

  //the next step will be here 


}


void welcome()
{
 printf("----------------------------------------------------\n");
 printf("|                                                  |\n");
 printf("|                Welcome to P.M.S                  |\n");
 printf("|                                                  |\n");
 printf("----------------------------------------------------\n");
 printf("\nWelcome Mr.Mohamed Rashad Ibrahim at your program\n ");

}