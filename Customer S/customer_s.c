#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GOTOXY(x,y) printf("\033[%d,%df",y,x)

void delay(int time)
{
  int time_milli = 1000 * time;
  clock();
  while(clock() < time_milli);
}

void input();
void writefile();
void search();
void output();

struct date
{
  int month;
  int day;
  int year;
};

struct account 
{
  int number;
  char name[100];
  int account_num;
  float mobile_num;
  char street[100];
  char city[100];
  char account_type;
  float oldbalance;
  float newbalance;
  float payment;
  struct date lastpayment;
}customer;

int tl,sl,ts;

void main()
{
  int i,n;
  char ch;
  do 
  {
    system("clear");
    printf("  CUSTOMER BILLING SYSTEM   \n\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("1 : ADD Acount On List \n");
    printf("2 : Search About Customer \n");
    printf("3 : Exit \n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\nSelect What You Want \n");
    ch=getchar();
  }while(ch <= '0' || ch > '3');

  switch (ch)
  {
    case '1':
      system("clear");
      printf("\nhow many customer accounts : ");
      scanf("%d", &n);
      getchar();
      for (i = 0; i < n; i++)
      {
        input();
        if (customer.payment > 0.0)
          customer.account_type=(customer.payment < customer.oldbalance) ? '0' : 'D';
        else
          customer.account_type = (customer.oldbalance > 0) ? 'D' : 'C';
        customer.newbalance=customer.oldbalance - customer.payment;
        writefile();
      }
      main();
    case '2':
      getchar();
      system("clear");
      printf("Search By What : \n");
      printf("1 : =-=-= Customer Number \n");
      printf("2 : =-=-= Customer Name \n");
      search();
      ch=getchar();
      main();
    case '3':
      system("clear");
      delay(500);
      GOTOXY(10,25);
      printf("Thank and Good Bay\n");
      delay(1500);
      exit(1);
  }
}

void input()
{
  FILE *fp=fopen("data.txt", "ab");
  fseek(fp,0,SEEK_END);
  tl=ftell(fp);
  sl=sizeof(customer);
  ts=tl/sl;
  fseek(fp,(ts-1)*sl,SEEK_SET);
  fread(&customer, sizeof(customer),1,fp);
  printf("\nCustomer Number : %d \n", ++customer.number);
  fclose(fp);
  printf("Account Number : ");
  scanf("%d", &customer.account_num);
  getchar();
  printf("Name : ");
  scanf("%s", customer.name);
  getchar();
  printf("Mobile Number : ");
  scanf("%f", &customer.mobile_num);
  getchar();
  printf("Street : ");
  scanf("%s", customer.street);
  getchar();
  printf("City : ");
  scanf("%s", customer.city);
  getchar();
  printf("Previous Balance : ");
  scanf("%f", &customer.oldbalance);
  getchar();
  printf("Current Payment : ");
  scanf("%f", &customer.payment);
  getchar();
  printf("  Payment date (dd/mm/yyyy) : ");
  scanf("%d / %d / %d", &customer.lastpayment.day, &customer.lastpayment.month, &customer.lastpayment.year);
  getchar();
}

void writefile()
{
  FILE *fp;
  fp = fopen("data.txt", "ab+");
  fwrite(&customer, sizeof(customer),1,fp);
  fclose(fp);
  return;
}

void search()
{
  char ch;
  char name[100];
  int n,i,m=1;
  FILE *fp;
  fp=fopen("data.txt", "r+");
  do 
  {
    printf("Enter Your Choice : ");
    ch=getchar();
  }while(ch!='1' && ch!='2');
  switch(ch)
  {
    case '1':
      fseek(fp,0, SEEK_END);
      tl=ftell(fp);
      sl=sizeof(customer);
      ts=tl/sl;
      do
      {
        printf("Chose Customer Number : ");
        scanf("%d", &n);
        if (n <= 0 || n > ts)
        {
          printf("Enter Correct Number Costomer \n");
        }
        else
        {
          fseek(fp,(n - 1)*sl,SEEK_SET);
          fread(&customer, sl, 1, fp);
          output();
        }
        printf("\n\nSearch Again (Y/N)");
        ch=getchar();
      }while(ch == 'y');
      fclose(fp);
      break;
    case '2':
      fseek(fp, 0, SEEK_SET);
      tl=ftell(fp);
      sl=sizeof(customer);
      ts=tl/sl;
      fseek(fp, (ts - 1) * sl, SEEK_SET);
      fread(&customer, sizeof(customer), 1, fp);
      n = customer.number;
      do
      {
        printf("\nEnter the Name : ");
        scanf("%s", name);
        fseek(fp, 0, SEEK_SET);
        for (i = 1; i <= n; i++)
        {
          fread(&customer, sizeof(customer), 1, fp);
          if (strcmp(customer.name, name) == 0)
          {
            output();
            m = 0;
            break;
          }
        }
        if (m != 0)
          printf("\n\nDesn't Exist .\n");
        printf("\nAnother One (Y/N)");
        ch=getchar();
      }while(ch == 'y');
      fclose(fp);
  }
  return ;
}

void output()
{
  printf("\n\nCustomer Number : %d \n", customer.number);
  printf("Name : %s \n", customer.name);
  printf("Mobile Number : %.f \n", customer.mobile_num);
  printf("Account Number : %d \n", customer.account_num);
  printf("Street : %s \n", customer.street);
  printf("City : %s \n", customer.city);
  printf("Old Balance : %.f \n", customer.oldbalance);
  printf("Current Payment : %.f \n", customer.payment);
  printf("New Balance : %.f \n", customer.newbalance);
  printf("Payment Date : %d/%d/%d \n", customer.lastpayment.day,customer.lastpayment.month,customer.lastpayment.year);
  printf("=-=-=Accout Status=-=-=\n");
  switch(customer.account_type)
  {
    case 'C':
      printf(">>>> CURRENT \n");
      break;
    case '0':
      printf("OVERDUE \n");
      break;
    case 'D':
      printf("DELINQUENT \n");
      break;
    default:
      printf("ERROR \n");
  }
  return ;
}

