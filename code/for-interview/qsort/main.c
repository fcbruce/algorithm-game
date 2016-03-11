/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 11 Mar 2016 22:58:29
 *
 */

#include "qsort.h"

#include <stdio.h>
#include <stdlib.h>

const int N = 1000;

int main()
{
  int *arr = (int *)malloc(N * sizeof (int));
  for (int i = 0; i < N; i ++)
    arr[i] = rand();

  quick_sort(arr, N);
  
  for (int i = 1; i < N; i ++)
    if (arr[i] < arr[i-1])
    {
      free(arr);
      return -1;
    }

  free(arr);


  return 0;
}
