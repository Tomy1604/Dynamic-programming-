#include <stdio.h>
#include <stdlib.h>

int main() {
    int r1, c1, r2, c2, i, j, k;
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Invalid input: The number of columns of the first matrix must be equal to the number of rows of the second matrix.\n");
        return 0;
    }

    int **mat1 = (int **)malloc(r1 * sizeof(int *));
    for (i = 0; i < r1; i++) {
        mat1[i] = (int *)malloc(c1 * sizeof(int));
    }

    int **mat2 = (int **)malloc(r2 * sizeof(int *));
    for (i = 0; i < r2; i++) {
        mat2[i] = (int *)malloc(c2 * sizeof(int));
    }

    int **res = (int **)calloc(r1, sizeof(int *));
    for (i = 0; i < r1; i++) {
        res[i] = (int *)calloc(c2, sizeof(int));
    }

    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            for (k = 0; k < c1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("The result of matrix multiplication is:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < r1; i++) {
        free(mat1[i]);
    }
    free(mat1);

    for (i = 0; i < r2; i++) {
        free(mat2[i]);
    }
    free(mat2);

    for (i = 0; i < r1; i++) {
        free(res[i]);
    }
    free(res);

    return 0;
}
