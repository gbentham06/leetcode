class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        int ans = 0;
        const int mod = 1e9 + 7;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cnt = (cnt + 1) % mod;
            } else {
                cnt = 0;
            }

            ans = (ans + cnt) % mod;
        }
        return ans;
    }
};
