class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0, lp = 0, n = nums.size();
        for (int i = 1; i < n-1; i++){
            if (nums[i] != nums[i+1]){
                if ((nums[i] > nums[lp] && nums[i] > nums[i+1]) ||
                    (nums[i] < nums[lp] && nums[i] < nums[i+1])){
                    ans++;
                }
                lp = i;
            }
        }
        return ans;
    }
};
