/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief program to calculate basic statistical functions on a given set of values
 *
 *  This code does the following statistical calulcations:
 *  	- Find maximum value on an array
 *  	- Find minimum value of an array
 *  	- Find the mean (average) of an array
 *  	- Find the median value of an array
 *  	- Sorts the value of an array in ascendent order
 *  	- prints the values of an array in groups of 5 elements
 *
 * @author Victor Argueta
 * @date 4/9/2025
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

   float median = 0;
   float mean =0;
   int maximum = 0;
   int minimum = 0;

   mean = find_mean(test, SIZE);
   maximum = find_maximum(test, SIZE);
   minimum = find_minimum(test, SIZE);

   printf("Original Array: \n\n");
   print_array(test,SIZE);

   printf("\n\nSorted Array: \n\n");
   sort_array(test, SIZE);
   print_array(test,SIZE);

   median = find_median(test,SIZE);

   printf("\n\n\n");
   printf("The mean of the sample is : %.2f\n", mean);
   printf("The minimum value of the array is: %d\n",minimum);
   printf("The maximum value of the array i s: %d\n", maximum);
   printf("The median of the array is : %0.2f\n",median);


} /*end of main() */


/*Finds the average of an array, it goes element by element on the array and adds each value to a variable called 'mean'
 * once all values have been added, we divide the result by the total number of elements in the array
 * the function return one float value, and receives a char *, and int counter as parameters 
 */

float find_mean(unsigned char *numbers, int counter){

   int i;
   float mean;
   for (i = 0 ; i < counter; i++){
     mean += numbers[i];
   }
   return(mean/counter);

}

/*The fucntion stores the first element of the array,
 * it then moves one position and compares the value with the stored one,
 * if its bigger it replaces it, if not it moves to the next element.
 * it continues until the end of the array
 */

int find_maximum(unsigned char *numbers, int counter){
   int i=0;
   int maximum= numbers[i];
   for (i=1; i< counter; i++){
     if (numbers[i] > maximum){
        maximum = numbers[i];
     }
   }
  return maximum;

}


/*The fucntion stores the first element of the array.
 * it then moves to the next element, and compares it to the value stored.
 * If its smaller it replaces it, if not it moves to the next element.
 * it continues until the end of the array
 */

int find_minimum(unsigned char *numbers, int counter){
   int i=0;
   int minimum = numbers[i];
   for(i=1; i < counter; i++){
      if (numbers[i] < minimum){
         minimum = numbers[i];
      }
   }
   return minimum;
}

/*it does a simple insertion substitution.
 */

void sort_array(unsigned char *numbers, int counter){
   int i, key, j;

   for (i = 1; i < counter; i++)
    {
        key = numbers[i];
        j = i - 1;

        /* Move elements of numbers[0..i-1], that are greater than key, to one position ahead 
		of their current position */
        while (j >= 0 && numbers[j] > key)
        {
            numbers[j + 1] = numbers[j];
            j = j - 1;
        }
        numbers[j + 1] = key;
    }
   
}

/* it print the elements of an array in groups of five,
 */

void print_array(unsigned char * numbers, int counter)
{
    int i,j=0;
    for (i = 0; i < counter; i++){
	j++;
        printf("%d ", numbers[i]);
        if (j%5==0){
           printf("\n");
	   j=0;
	}
    }
}

/*find the median of the array.  
 * If the number of elements is even it takes the average of the two elements in the midlle.
 * if the number of element is odd, it takes the value of element at the modpoint of the array
 */
float find_median(unsigned char * numbers, int counter)
{
   int i= counter /2;
   float median;
   if (counter % 2 == 0 ){
	   median = (numbers[i-1] + numbers[i])/2.0;
   }
   else{
	  median = numbers[i-1]; 
   }

   return (median);
}
