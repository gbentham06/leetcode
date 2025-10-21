class Solution {
public:
    static int maxFrequency(vector<int>& nums, int k, int numOperations) {
        static constexpr int N=1e5+1;
        int freq[N]={0}, MM=0;
        for(int x: nums){
            freq[x]++;
            MM=max(MM, x);
        }
        int* prefix=(int*)alloca((MM+1)*sizeof(int));
        partial_sum(freq, freq+MM+1, prefix);
        int ans=0, cnt=0;
        for (int x=1; x<=MM; x++){
            int l=max(1,x-k), r=min(MM, x+k);
            cnt=prefix[r]-prefix[l-1];
            ans=max(ans, freq[x]+min(cnt-freq[x], numOperations));
        }
        return ans;
    }
};
