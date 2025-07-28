class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max = 0;
        for (int n: nums) {
            max |= n;
        }
        return backtrack(nums, max, 0, 0);
    }
private: 
    int backtrack(vector<int>& nums, int max, int index, int current) {
        if (index == nums.size()) {
            return current == max ? 1:0;
        }
        if (current == max){
            return 1 << (nums.size() - index);
        }
        return backtrack(nums, max, index+1, current | nums[index])
            + backtrack(nums, max, index + 1, current);
    }
};
