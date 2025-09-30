int triangularSum(int* nums, int numsSize) {
    for (int n = numsSize; n > 1; --n) {
        for (int i = 0; i < n - 1; ++i) {
            nums[i] = (nums[i] + nums[i + 1]) % 10;
        }
    }
    return nums[0];
}

