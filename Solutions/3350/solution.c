int maxIncreasingSubarrays(int* nums, int numsSize) {
    int up = 1, preUp = 0, res = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i-1]) up++;
        else {
            preUp = up;
            up = 1;
        }
        int half = up >> 1;
        int m = preUp < up ? preUp : up;
        int candidate = half > m ? half : m;
        if (candidate > res) res = candidate;
    }
    return res;
}
