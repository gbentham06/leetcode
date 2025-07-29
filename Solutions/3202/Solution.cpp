class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int maxlen = 0;
        for (int n : nums){
            int cr = n % k;
            for (int pr = 0; pr < k; pr++){
                dp[pr][cr] = dp[cr][pr] + 1;
                maxlen = max(maxlen, dp[pr][cr]);
            }
        }
        return maxlen;
    }
};
