class Solution {
public:
	int longestSubarray(vector<int>& nums){
		int max_v = *max_element(nums.begin(), nums.end());
		int cur = 0, max_l = 0;
		for (int n : nums){
			if (n == max_v){
				cur++;
				max_l = max(max_l, cur);
			} else {
				cur = 0;
			}
		}
		return max_l;
	}
};

