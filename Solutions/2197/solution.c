#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int* replaceNonCoprimes(int* nums, int numsSize, int* returnSize) {
    // Using a dynamic array as stack
    int *stack = (int*)malloc(numsSize * sizeof(int));
    int top = 0;  // number of elements in stack
    
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        while (top > 0) {
            int prev = stack[top - 1];
            int g = gcd(prev, num);
            if (g == 1) break;
            // pop
            top--;
            // merge
            long long merged = (long long)prev / g * num;
            num = (int)merged;
        }
        stack[top++] = num;
    }
    
    *returnSize = top;
    return stack;
}
