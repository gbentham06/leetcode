class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> out, cur, nxt;
        for (int num : arr){
            nxt.clear();
            nxt.insert(num);
            for(int x : cur){
                nxt.insert(x | num);
            }
            cur = nxt;
            out.insert(cur.begin(), cur.end());
        }
        return out.size();
    }
};
