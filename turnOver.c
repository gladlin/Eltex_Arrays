/*
Вывести заданный массив размером N
в обратном порядке.
 */

#include <stdio.h>
#include <stdlib.h>

int flag = 1;

int *writeArray(int n) {
  int *resultArray = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    int newValue = 0;
    printf("Enter integer: ");
    if (scanf("%d", &newValue) != 1) {
      printf("Was entered not an integer");
      flag = 0;
      break;
    } else
      resultArray[i] = newValue;
  }
  return resultArray;
}

void printArray(int n, int *array) {
  for (int i = n - 1; i >= 0; i--) {
    printf("%d ", array[i]);
  }
  free(array);
}

int main() {
  unsigned int n = 0;
  if (scanf("%u", &n) != 1 || n < 1) {
    printf("Enter positive integer");
    return -1;
  }

  int *inputArray = writeArray(n);
  if (flag)
    printArray(n, inputArray);
    
  return 0;
}