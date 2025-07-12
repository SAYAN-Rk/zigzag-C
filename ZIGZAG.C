#include <stdio.h>
#include <stdlib.h>

// Prime check function
int is_prime(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Compute zigzag compressed path sum
int compute_zigzag_sum(int** matrix, int n) {
    int sum = 0;

    for (int d = 0; d <= 2 * (n - 1); d++) {
        int row_start = d < n ? 0 : d - n + 1;
        int row_end = d < n ? d : n - 1;

        if (d % 2 == 0) {
            // ↗ direction
            for (int i = row_end; i >= row_start; i--) {
                int j = d - i;
                int val = *(*(matrix + i) + j);
                sum += is_prime(val) ? -val : val;
            }
        } else {
            // ↙ direction
            for (int i = row_start; i <= row_end; i++) {
                int j = d - i;
                int val = *(*(matrix + i) + j);
                sum += is_prime(val) ? -val : val;
            }
        }
    }

    return sum;
}

int main() {
    int n = 3;
    int** matrix = (int**)malloc(n * sizeof(int*));
    int values[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int i = 0; i < n; i++) {
        *(matrix + i) = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            *(*(matrix + i) + j) = values[i][j];
        }
    }

    int result = compute_zigzag_sum(matrix, n);
    printf("Final Zigzag Compressed Sum: %d\n", result);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(*(matrix + i));
    }
    free(matrix);

    return 0;
}
