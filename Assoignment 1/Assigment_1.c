#include<stdio.h>

struct Date {
    int day;
    int month;
    int year;
};
void initDate(struct Date* ptrDate)
{
    ptrDate->day = 0;
   ptrDate-> month = 0;
    ptrDate->year = 0;

}

void acceptDateFromConsole(struct Date* ptrDate)
{
    printf("Enter the full Date ...day --month--year");
    scanf("%d%d%d",&ptrDate->day,&ptrDate->month,&ptrDate->year);
}

void printDateOnConsole(struct Date* ptrDate)
{
    printf("%d --%d --%d\n",ptrDate->day , ptrDate->month ,ptrDate->year );
}

int main()
{
    int choise ;
    struct Date  d1;

    do{

      printf("menu\n");
        printf("1.initdata\n");
        printf("2.accept date\n");
        printf("3.output date\n");
          printf("4.Exit\n");



        printf("Enter your choise: ");
        scanf("%d",&choise);

        switch (choise){
            case 1:
                initDate(&d1);
                break;

            case 2:
                acceptDateFromConsole(&d1);
                break;

            case 3:
            printDateOnConsole(&d1);
           


               
        }
    } while(choise != 0);
  
  printf("Thank you\n");
    return 0;
}