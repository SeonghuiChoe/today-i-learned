/**
 * 2017-02-05
 * x, n을 입력받아서 x부터 시작해서 x씩 증가하는 숫자 n개 출력
 */
#include <stdio.h>
#include <stdlib.h>

int* numberGenerator(int x, int n) {
    int *arr = malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = x * (i + 1);
    }
    return arr;
}

void print(int *arr, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ",  arr[i]);
    }
    printf("\n");
}

int main() {
    int x = 2, n = 5;
    int *arr = numberGenerator(x, n);
    print(arr, n);
}
