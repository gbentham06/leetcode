int minOperations(int* nums, int n, int k) {
    int ans=0;
    for(int i=0; i<n; i++) ans+=nums[i];
    return ans%k;
}