/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 11 Mar 2016 22:54:04
 *
 */

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int partition(int *arr, int n)
{
  -- n;
  int x = arr[n];
  int i = 0;
  for (int j = 0; j < n; j ++)
    if (arr[j] <= x) swap(&arr[i++], &arr[j]);
  swap(&arr[i], &arr[n]);
  return i;
}

void quick_sort(int *arr, int n)
{
  if (n <= 1) return ;
  int p = partition(arr, n);
  quick_sort(arr, p);
  quick_sort(arr + p + 1, n - p - 1);
}
