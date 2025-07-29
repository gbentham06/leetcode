class FindSumPairs {
    vector<int> nums1,nums2,fa;
    unordered_map<int,int> map;
    const int M = 200000;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;

        fa = vector<int>(M+1, 0);
        
        for (int i: nums2){
            if (i <= M){
                fa[i]++;
            } else{
                map[i]++;
            }
        }
    }
    
    void add(int index, int val) {
        int old = nums2[index];

        if (old <= M){
            fa[old]--;
        } else if (--map[old] == 0) {
            map.erase(old);
        }

        int newv = old + val;
        nums2[index] = newv;
        if (newv <= M){
            fa[newv]++;
        } else {
            map[newv]++;
        }
    }
    
    int count(int tot) {
        int out = 0;
        for (int a : nums1){
            int b = tot - a;
            if (b >= 0 && b <= M){
                out += fa[b];
            } else{
                out += map[b];
            }
        }
        return out;
    }
};
