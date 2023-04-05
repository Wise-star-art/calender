#include <stdio.h>  
int dayNum(int day, int month, int year)
{
    static int t[] = { 0, 3, 2, 5, 0, 3,
                    5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}
char* getMonthName(int monthNum)
{
    char* month = " ";

    switch (monthNum) 
    {
    case 0:
        month = "January";
        break;
    case 1:
        month = "February";
        break;
    case 2:
        month = "March";
        break;
    case 3:
        month = "April";
        break;
    case 4:
        month = "May";
        break;
    case 5:
        month = "June";
        break;
    case 6:
        month = "July";
        break;
    case 7:
        month = "August";
        break;
    case 8:
        month = "September";
        break;
    case 9:
        month = "October";
        break;
    case 10:
        month = "November";
        break;
    case 11:
        month = "December";
        break;
    }
    return month;
}
int numOfDays(int monthNum, int year)
{
    if (monthNum == 0)
        return (31);

    if (monthNum == 1) 
    {
      if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);
    }
    if (monthNum == 2)
        return (31);

    if (monthNum == 3)
        return (30);

    if (monthNum == 4)
        return (31);

    if (monthNum == 5)
        return (30);

    if (monthNum == 6)
        return (31);

    if (monthNum == 7)
        return (31);

    if (monthNum == 8)
        return (30);

    if (monthNum == 9)
        return (31);

    if (monthNum == 10)
        return (30);

    if (monthNum == 11)
        return (31);
}
void printCalendar(int year)
{
    printf("     Calendar - %d\n\n", year);
    int days;

    int current = dayNumber(1, 1, year);

    for (int i = 0; i < 12; i++) {
        days = numOfDays(i, year);

        printf("\n ------------%s-------------\n",
            getMonthName(i));

        printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        int k;
        for (k = 0; k < current; k++)
            printf("     ");

        for (int j = 1; j <= days; j++) {
            printf("%5d", j);

            if (++k > 6) {
                k = 0;
                printf("\n");
            }
        }

        if (k)
            printf("\n");

        current = k;
    }

    return;
}
int main()
{
    int year;
    printf("Enter the year:");
    scanf("%d", &year);
   
    printCalendar(year);
    return 0;
}
