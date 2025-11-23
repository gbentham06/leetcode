#pragma GCC optimize("O3, unroll-loops")
static int maxSumDivThree(int* nums, int n) {
    const int minus=-1e9;
    int dp[2][3]={ {0, 0, 0}, {0, minus, minus}};
    for(int i=0; i<n; i++){
        const int x=nums[i], xM3=x%3;
        for(int mod=0; mod<3; mod++){
            int modPrev=mod-xM3; modPrev+=(-(modPrev<0)) & 3;
            const int take=x+dp[~i&1][modPrev];
            const int skip=dp[~i&1][mod];
            dp[i&1][mod]=fmax(take, skip);
        }
    }
    return fmax(0, dp[~n&1][0]);
}
