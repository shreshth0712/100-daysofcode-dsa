#include <stdio.h>

int missingNum(int arr[], int size) {
    int n = size + 1;

    int xor1 = 0, xor2 = 0;

    for (int i = 1; i <= n; i++) {
        xor1 ^= i;
    }

    for (int i = 0; i < size; i++) {
        xor2 ^= arr[i];
    }

    return xor1 ^ xor2;
}

int main() {
    int size;
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", missingNum(arr, size));

    return 0;
}