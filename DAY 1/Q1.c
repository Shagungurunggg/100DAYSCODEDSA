Q1.Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

  #include <stdio.h>
  int main() {
  int n, pos, x;
  int a[50];
  printf("enter number of elements:");
  scanf("%d", &n);
  printf("enter elements:\n");
  for(int i=0; i<n; i++)
    scanf"%d",&a[i]);
  printf("enter position (1-based): ");
  scanf ("%d", &pos);
  printf("enter element to insert:");
  scanf("%d", &x);
  for(int i = n; i>=pos; i--)
    a[i] = a[i-i];
  a[pos-1] = x;
  n++;
  printf("array after insertion:\n");
  for(int i = 0; i<n ; i++)
    printf("%d", a[i];
  return 0;
  }
  
