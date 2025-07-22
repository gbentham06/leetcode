class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        const int n = nums.size();
        bitset<10001> hasX = 0;
        int out = 0, sum = 0;
        for (int lp = 0, rp = 0; rp < n; rp++){
            const int x = nums[rp];
            while (hasX[x]){
                hasX[nums[lp]] = 0;
                sum -= nums[lp];
                lp++;
            }
            hasX[x] = 1;
            sum += x;
            out = max(out, sum);
        }
        return out;
    }
};
