#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct lib
{
  char bname[50];
  char author[50];
  int pages;
  float prices;
} l[100];

struct issue
{
  char bname[50];
  char iname[50];
  long int mbnum;

} a[100];

void logo();
void entry();
void disp();
void issue();
void ret();
int count = 0, issued = 0;
struct tm t[50];

void main()
{

  char c;
  int j = 1;
  while (j == 1)
  {
    system("clear");
    logo();
    printf("\t\t\t\t\t|||||||||||||||||MAIN MENU||||||||||||||||||||\n");
    printf("1.New book entry\n");
    printf("2.Display book information \n");
    printf("3.Issue book\n");
    printf("4.Return book\n");
    printf("5.Press any other key to exit from program \n");

    printf("\n Enter any one option from above list :");
    scanf("%c", &c);
    getchar();
    switch (c)
    {
    /* new book entry */
    case '1':
      entry();
      break;
    case '2':
      /* Display book information */
      disp();
      break;
    case '3':
      issue();
      break;
    case '4':
      ret();
      break;
    default:
      printf("Bye\n");
      exit(0);
    }
    printf("press any key to continue");
    getchar();
  }
}

void entry()
{
  int n;
  printf("\nhow many no's. of books you want to fill information ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    printf("\nEnter details for book %d\n\n", i + 1);
    printf("Enter the book name-");
    scanf("%s", l[count].bname);
    printf("Enter the author name-");
    scanf("%s", l[count].author);
    printf("Enter the total no. of pages of the book -");
    scanf("%d", &l[count].pages);
    printf("Enter the book price-");
    scanf("%f", &l[count].prices);
    count++;
  }
}

void disp()
{

  if (count != 0)
  {
    printf("\nall book information\n");
    printf("------------------------\n");
    for (int i = 0; i < count; i++)
    {
      printf("%d. ", i + 1);
      printf("Book name-%s\n", l[i].bname);
      printf("Author name-%s\n", l[i].author);
      printf("Total no. of pages-%d\n", l[i].pages);
      printf("Book price-%f\n", l[i].prices);
      printf("------------------------\n");
    }
  }
  else
  {
    printf("\nenter the option 1 first then then check into display option\n");
  }
}
void issue()
{
  disp();
  int i;
  printf("\nWhich book do you want to issue\n");
  scanf("%d", &i);
  strcpy(a[issued].bname, l[i - 1].bname);
  printf("enter issuer's name \n");
  scanf("%s", a[issued].iname);
  printf("enter your mobile number\n");
  scanf("%ld", &a[issued].mbnum);

  time_t T = time(NULL);
  t[issued] = *localtime(&T);
  printf("Today's date %02d/%02d/%04d\n", t[issued].tm_mday, t[issued].tm_mon + 1, t[issued].tm_year + 1900);
  t[issued].tm_mday = t[issued].tm_mday + 14;
  printf("return date %02d/%02d/%04d\n", t[issued].tm_mday, t[issued].tm_mon + 1, t[issued].tm_year + 1900);
  issued++;
}
void ret()
{
  if (issued != 0)
  {
    int k;
    for (int i = 0; i < issued; i++)
    {
      printf("%d. ", i + 1);
      printf("issuer name:- %s\n", a[i].iname);
      printf("issuer mobile number:- %ld\n", a[i].mbnum);
      printf("book issued:- %s\n", a[i].bname);
      printf("book issue date %02d/%02d/%04d\n", t[i].tm_mday - 14, t[i].tm_mon + 1, t[i].tm_year + 1900);
      printf("book return date %02d/%02d/%04d\n", t[i].tm_mday, t[i].tm_mon + 1, t[i].tm_year + 1900);
      printf("------------------------\n");
    }
    printf("which book do you want to return");
    scanf("%d", &k);
    for (int j = 0; j < issued; j++)
    {
      if (j + 1 == k)
      {
        for (int i = j; i < issued; i++)
        {
          strcpy(a[i].iname, a[i + 1].iname);
          a[i].mbnum = a[i + 1].mbnum;
          strcpy(a[i].bname, a[i + 1].bname);
          t[i].tm_mday = t[i + 1].tm_mday;
          t[i].tm_mon = t[i + 1].tm_mon;
          t[i].tm_year = t[i + 1].tm_year;
        }
      }
    }
    issued--;
  }
  else
  {
    printf("no book has been issued\n");
  }
}

void logo()
{
  printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n");
  printf("\t\t\t\t\t\t********************************************\n\n\n");
  printf("\t\t\t\t\t\t         WELCOME TO MIT-ADT LIBRARY         \n\n\n");
  printf("\t\t\t\t\t\t********************************************\n\n\n");
  printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n");
}