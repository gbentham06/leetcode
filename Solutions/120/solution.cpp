class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        const int n=t.size();
        vector<int> dp(n, t[0][0]);
        for(int i=1; i<n; i++){
            dp[i]=dp[i-1]+t[i][i];
            for(int j=i-1; j>=1; j--){
                dp[j]=t[i][j]+min(dp[j], dp[j-1]);
            }
            dp[0]+=t[i][0];
        }
        return *min_element(dp.begin(), dp.end());
    }
};
