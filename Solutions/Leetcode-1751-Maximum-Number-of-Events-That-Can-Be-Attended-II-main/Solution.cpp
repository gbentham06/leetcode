class Solution {
public:
    static int maxValue(vector<vector<int>>& events, int k) {
        const int n=events.size();
        sort(events.begin(), events.end());
        array<vector<int>, 2>  dp={vector<int>(n+1,0), vector<int>(n+1,0)}; 
        vector<int> next(n, n);
        for(int i=0; i<n; i++){
            next[i]=upper_bound(events.begin()+i+1, events.end(), events[i][1], [](int x, const vector<int>& event) {
                    return x<event[0];
                })-events.begin();
        }
        for(int j=1; j<=k; j++){
            for(int i=n-1; i>=0; i--){
                const int attend_i=events[i][2]+dp[(j-1)&1][next[i]];
                const int skip_i=dp[j&1][i+1];
                dp[j&1][i]=max(attend_i, skip_i);
            }
        }
        return dp[k&1][0];
    }
};
