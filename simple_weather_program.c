/*
Written by: Antonio de Odilon Brito
April, 2022
Location: Natal, Rio Grande do Norte, Brazil

I created this very simple weather program to exercise loops and arrays in the C programming
language. The variable rainfall is a 2D array with numbers of type double that displays the amount
of rain for each year and each month. Each row refers to the years (3 rows, so 3 years) and each
columns refers to a month (12 months in a years, so 12 columns).

The program then iterates by the years and months and prints out the total rain for each particular
year, the total amount of rain for all years, the average rain, the total rain for each particular month,
and the average rain for each month. For example, in month 1 (January) for year 1 (2020), the amount of rain was
20.0; for the same month in year 2 (2021) it was 34.0, and for the 3rd year it was 45.0. So the average
rain for january was 33.0.

The data was all fictional and it shouldn't be representative of any real-life weather data.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define AMOUNTROWS 3 // 3 years, therefore 3 rows
#define AMOUNTCOLUMNS 12 //12 months, therefore 12 columns

int main(void){
    // Creating a 2D array that will hold the values we will be using in our loops:
   double rainfall[AMOUNTROWS][AMOUNTCOLUMNS] = {
    {20.0, 32.0, 21.0, 45.0, 56.0, 12.0, 91.0, 23.0, 41.0, 23.0, 63.0, 90.0}, // Year 1
    {34.0, 71.0, 26.0, 47.0, 92.0, 62.0, 94.0, 83.0, 64.0, 18.0, 32.0, 65.0}, // Year 2
    {45.0, 82.0, 12.0, 84.0, 78.0, 93.0, 51.0, 22.9, 63.0, 17.0, 41.0, 99.0} // Year 3
   };

   int indexRow;
   int indexColumn;
   int monthNumber;
   int yearNumber;
   double totalRain;
   double totalRainPerYear;
   double totalRainMonth;
   double averageRainYear;
   double averageRainMonth;

   // Iterating first over the years, and then over the months:
    yearNumber = 1;
   for (indexRow = 0, totalRain = 0; indexRow < AMOUNTROWS; indexRow++, yearNumber++)
   {
        for (indexColumn = 0, totalRainPerYear = 0; indexColumn < AMOUNTCOLUMNS; indexColumn++)
        {
            totalRainPerYear += rainfall[indexRow][indexColumn];
        };
        totalRain += totalRainPerYear;
        averageRainYear = totalRainPerYear/AMOUNTROWS;
        averageRainMonth = totalRainPerYear/indexColumn;
        printf("The total rain for year %d was %.2f\n", (2019 + yearNumber), totalRainPerYear);
   };
    // You have to reinitialize totalRain and totalRainPerYear to zero every time around the loop!
    // Otherwise, the values will always be added to the previous ones.


   printf("\n----------------\n");

   averageRainYear = totalRain / AMOUNTROWS;
   printf("The total rain in all years was %.2f\n", totalRain);
   printf("The average rain in these three years was %.2f\n", averageRainYear);

   printf("\n----------------\n");


   // Now iterating first over the months, and then over the years:
   monthNumber = 1;
    for (indexColumn = 0; indexColumn < AMOUNTCOLUMNS; indexColumn++, monthNumber++)
    {
        for (indexRow = 0, totalRainMonth = 0; indexRow < AMOUNTROWS; indexRow++)
        {
            totalRainMonth += rainfall[indexRow][indexColumn];
            averageRainMonth = totalRainMonth / AMOUNTROWS;
        };
        printf("The total rain in month %d for those three years was %.2f\n", monthNumber, totalRainMonth);
        printf("\tAnd the average for this month was %.2f\n\n", averageRainMonth);
    };
    // You have to reinitialize totalRainMonth to 0 in each iteration. Otherwise all the values
    // will be summed to the previous ones, as before.

    return 0;
};
