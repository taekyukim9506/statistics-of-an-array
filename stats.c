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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
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
  print_statistics(test, SIZE);

  
  /* Statistics and Printing Functions Go Here */

}

  /* Other Variable Declarations Go Here */

void print_statistics(unsigned char *ptr, unsigned int size) {
  
  unsigned char min = find_minimum(ptr, size);
  unsigned char max = find_maximum(ptr, size);
  unsigned char mean = find_mean(ptr, size);
  unsigned char median = find_median(ptr, size);

  printf("---Array Statistics---\n");
  printf("Minimum : %d\n", min);
  printf("Maximum : %d\n", max);
  printf("Mean : %d\n", mean);
  printf("Median : %d\n", median);
}

void print_array(unsigned char *ptr, unsigned int size) {
  for (unsigned int i = 0; i < size; i++){
    if (i > 0 && i%8 == 0) {
      printf("\n");
    }
    if (i == size - 1) {
      printf("%d", ptr[i]);
    }
    else {
      printf("%d, ", ptr[i]);
    }
  }
  printf("\n");
}

unsigned char find_median(unsigned char *ptr, unsigned int size) {
  if (ptr == NULL || size == 0) {
    return 0;
  }
  unsigned int median = 0;
  sort_array(ptr, size);
  if (size %2 != 0) {
    median = ptr[size/2];
  }
  else {
    median = (ptr[(size/2)-1] + ptr[(size/2)])/2;
  }
  return median;
}

unsigned char find_mean(unsigned char *ptr, unsigned int size) {
  if (ptr == NULL || size == 0) {
    return 0;
  }
  unsigned int total = 0;
  for (unsigned int i = 0; i<size; i++) {
    total = total + ptr[i];
  }
  unsigned char mean = total/size;
  return mean;
}

unsigned char find_maximum(unsigned char *ptr, unsigned int size) {
  unsigned int maximum = ptr[0];
  if (ptr == NULL || size == 0) {
    return 0;
  }
  for (unsigned int i = 0; i<size-1; i++) {
    if (ptr[i]<ptr[i+1]) {
      maximum = ptr[i];
    }
  }
  return maximum;
}

unsigned char find_minimum(unsigned char *ptr, unsigned int size) {
  unsigned int minimum = ptr[0];
  if (ptr == NULL || size == 0) {
    return 0;
  }
  for (unsigned int i = 0; i<size-1; i++) {
    if (ptr[i]<ptr[i+1]) {
      minimum = ptr[i];
    }
  }
  return minimum;
}

void sort_array(unsigned char *ptr, unsigned int size){
  unsigned char temp;
  for (unsigned int i = 0; i<size-1; i++) {
    for (unsigned int j = 0; j<size-1; j++) {
      if (ptr[j] < ptr[j+1]) {
        temp = ptr[j];
        ptr[j] = ptr[j+1];
        ptr[j+1] = temp;
      }
    }
  }
}


/* Add other Implementation File Code Here */
