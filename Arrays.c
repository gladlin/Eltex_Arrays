#include <stdio.h>
#include <stdlib.h>

unsigned int **fillMatrix(unsigned int n) {
  unsigned int **resultMatrix = malloc(sizeof(unsigned int *) * n);
  for (int i = 0; i < n; i++) {
    resultMatrix[i] = malloc(sizeof(unsigned int) * n);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      resultMatrix[i][j] = i * n + j + 1;
    }
  }
  return resultMatrix;
}

void printMatrix(unsigned int **matrix, unsigned int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%u ", matrix[i][j]);
    }
    free(matrix[i]);
    printf("\n");
  }
  free(matrix);
}

int main() {
  unsigned int n = 0;
  printf("Введите разрядность матрицы: ");
  if (scanf("%u", &n) != 1 || n < 1) {
    printf("Enter positivre integer");
    return -1;
  }
  unsigned int **result = fillMatrix(n);
  printMatrix(result, n);

  return 0;
}