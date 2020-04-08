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
void load();
void save(char bname[50], char author[50], int pages, float prices);
void iload();
void isave();
void idelsave(int i);
void delete ();
void idelete();
void delsave(int i);

int count = 0, issued = 0;
struct tm t[50];

void main()
{

    load();
    iload();
    char c;
    int j = 1;
    while (j == 1)
    {
        system("clear");
        logo();
        printf("\t\t\t\t\t|||||||||||||||||MAIN MENU||||||||||||||||||||\n");
        printf("1.New book entry\n");
        printf("2.Delete a book entry\n");
        printf("3.Display book information \n");
        printf("4.Issue book\n");
        printf("5.Return book\n");
        printf("Press any other key to exit from program \n");

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
            delete ();
            break;
        case '3':
            /* Display book information */
            disp();
            break;
        case '4':
            issue();
            break;
        case '5':
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
        getchar();
        gets(l[count].bname);
        printf("Enter the author name-");
        gets(l[count].author);
        printf("Enter the total no. of pages of the book -");
        scanf("%d", &l[count].pages);
        printf("Enter the book price-");
        scanf("%f", &l[count].prices);
        save(l[count].bname, l[count].author, l[count].pages, l[count].prices);
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
    isave();
    issued++;
}
void ret()
{
    if (issued != 0)
    {

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
        idelete();
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

void load()
{

    char pa[25] = "Books/0";

    FILE *f;
    char n[5], b;
    int j = 0;
    f = fopen(pa, "r");
    if (f != NULL)
        while (1)
        {
            fclose(f);
            sprintf(n, "%d", count);
            pa[6] = n[0];
            f = fopen(pa, "r");
            b = ' ';
            if (f != NULL)
            {
                while (b != EOF)
                {
                    fscanf(f, "Book name-%[^\n]\n", l[count].bname);
                    fscanf(f, "Author name-%[^\n]\n", l[count].author);
                    fscanf(f, "Total no. of pages-%d\n", &l[count].pages);
                    fscanf(f, "Book price-%f\n", &l[count].prices);
                    b = getc(f);
                }
            }
            else
            {
                break;
            }

            printf("\n");
            count++;
        }
}

void save(char bname[50], char author[50], int pages, float prices)
{
    FILE *f;
    char n[5];
    char pa[25] = "Books/";
    sprintf(n, "%d", count);
    pa[6] = n[0];
    f = fopen(pa, "w");
    fprintf(f, "Book name-%s\n", bname);
    fprintf(f, "Author name-%s\n", author);
    fprintf(f, "Total no. of pages-%d\n", pages);
    fprintf(f, "Book price-%f\n", prices);
    fclose(f);
}

void delete ()
{
    if (count != 0)
    {
        disp();
        int j;
        printf("\nwhich book do you want to delete \n");
        scanf("%d", &j);
        for (int i = j - 1; i < count; i++)
        {
            strcpy(l[i].bname, l[i + 1].bname);
            strcpy(l[i].author, l[i + 1].author);
            l[i].pages = l[i + 1].pages;
            l[i].prices = l[i + 1].prices;
            delsave(i);
        }

        char n[5];
        char pa[25] = "Books/";
        sprintf(n, "%d", count);
        pa[6] = n[0];
        remove(pa);
        count--;
    }
    else
    {
        printf("\nenter the option 1 first then then check into display option\n");
    }
}

void delsave(int i)
{
    FILE *f;
    char n[5];
    char pa[25] = "Books/";
    sprintf(n, "%d", i);
    pa[6] = n[0];
    f = fopen(pa, "w");
    fprintf(f, "Book name-%s\n", l[i].bname);
    fprintf(f, "Author name-%s\n", l[i].author);
    fprintf(f, "Total no. of pages-%d\n", l[i].pages);
    fprintf(f, "Book price-%f\n", l[i].prices);
    fclose(f);
}

void iload()
{

    char pa[25] = "Issued/0";

    FILE *f;
    char n[5], b;
    int j = 0;
    f = fopen(pa, "r");
    if (f != NULL)
    {
        while (1)
        {
            fclose(f);
            sprintf(n, "%d", issued);
            pa[7] = n[0];
            f = fopen(pa, "r");
            b = ' ';
            if (f != NULL)
            {
                while (b != EOF)
                {
                    fscanf(f, "issuer name:- %[^\n]\n", a[issued].iname);
                    fscanf(f, "issuer mobile number:- %ld\n", &a[issued].mbnum);
                    fscanf(f, "book issued:- %[^\n]\n", a[issued].bname);
                    fscanf(f, "book issue date %02d/%02d/%04d\n", &t[issued].tm_mday - 14, &t[issued].tm_mon + 1, &t[issued].tm_year + 1900);
                    fscanf(f, "book return date %02d/%02d/%04d\n", &t[issued].tm_mday, &t[issued].tm_mon + 1, &t[issued].tm_year + 1900);
                    b = getc(f);
                }
            }
            else
            {
                break;
            }

            printf("\n");
            issued++;
        }
    }
}

void isave()
{
    FILE *f;
    char n[5];
    char pa[25] = "Issued/";
    sprintf(n, "%d", issued);
    pa[7] = n[0];
    f = fopen(pa, "w");
    fprintf(f, "issuer name:- %s\n", a[issued].iname);
    fprintf(f, "issuer mobile number:- %ld\n", a[issued].mbnum);
    fprintf(f, "book issued:- %s\n", a[issued].bname);
    fprintf(f, "book issue date %02d/%02d/%04d\n", t[issued].tm_mday - 14, t[issued].tm_mon + 1, t[issued].tm_year + 1900);
    fprintf(f, "book return date %02d/%02d/%04d\n", t[issued].tm_mday, t[issued].tm_mon + 1, t[issued].tm_year + 1900);
    fclose(f);
}

void idelsave(int i)
{
    FILE *f;
    char n[5];
    char pa[25] = "Issued/";
    sprintf(n, "%d", i);
    pa[7] = n[0];
    f = fopen(pa, "w");
    fprintf(f, "issuer name:- %s\n", a[i].iname);
    fprintf(f, "issuer mobile number:- %ld\n", a[i].mbnum);
    fprintf(f, "book issued:- %s\n", a[i].bname);
    fprintf(f, "book issue date %02d/%02d/%04d\n", t[i].tm_mday - 14, t[i].tm_mon + 1, t[i].tm_year + 1900);
    fprintf(f, "book return date %02d/%02d/%04d\n", t[i].tm_mday, t[i].tm_mon + 1, t[i].tm_year + 1900);
    fclose(f);
}

void idelete()
{
    int k;
    printf("which book do you want to return");
    scanf("%d", &k);
    for (int i = k - 1; i < issued; i++)
    {

        strcpy(a[i].iname, a[i + 1].iname);
        a[i].mbnum = a[i + 1].mbnum;
        strcpy(a[i].bname, a[i + 1].bname);
        t[i].tm_mday = t[i + 1].tm_mday;
        t[i].tm_mon = t[i + 1].tm_mon;
        t[i].tm_year = t[i + 1].tm_year;
        idelsave(i);
    }
    char n[5];
    char pa[25] = "Issued/";
    sprintf(n, "%d", count);
    pa[7] = n[0];
    remove(pa);
    issued--;
}
