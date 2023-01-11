#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// define the first date October 15, 1582
#define firstDay 15
#define firstMonth 10
#define firstYear 1582

// function to check leap year
bool isLeap(int year)
{
// Return true if year is a multiple pf 4 and
// not multiple of 100 OR year is multiple of 400
return (((year % 4 == 0) &&
(year % 100 != 0)) ||
(year % 400 == 0));
}

// our required function to validate date
bool isValidDate(int d, int m, int y)
{
// If year, month and day are not in given range
if (y < firstYear)
return false;
if (y == firstYear){
if (m == firstMonth)
if (d < firstDay)
return false;
if (m < firstMonth)
return false;
}
if (m < 1 || m > 12)
return false;
if (d < 1 || d > 31)
return false;

// Handle February month with leap year
if (m == 2)
{
if (isLeap(y))
return (d <= 29);
else
return (d <= 28);
}

// Months of April, June,
// Sept and Nov must have
// number of days less than
// or equal to 30.
if (m == 4 || m == 6 || m == 9 || m == 11)
return (d <= 30);

return true;
}

int main()
{
int d, m, y;
printf("Enter the date in mmddyyyy format :-\n");
printf("Month - ");
scanf("%d", &m);
printf("Day - ");
scanf("%d", &d);
printf("Year - ");
scanf("%d", &y);
if (isValidDate(d,m,y))
printf("\nValid Date");
else
printf("\nInvalid Date");
return 0;
}
