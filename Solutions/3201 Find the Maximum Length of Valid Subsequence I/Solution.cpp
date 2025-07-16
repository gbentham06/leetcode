class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int e_count = 0, o_count = 0, ae_count = 0, ao_count = 0;
        for (int n: nums){
            int p = n % 2;
            if (p == 0){
                e_count++;
                ae_count = ao_count + 1;
            } else{
                o_count++;
                ao_count = ae_count + 1;
            }
        }
        return max({e_count, o_count, ae_count, ao_count});
    }
};
