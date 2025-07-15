class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int i: arr){
            freq[i]++;
        }
        int lucky = -1;
        for (auto& [key, value]:freq){
            if (key == value){
                lucky = max(lucky, key);
            }
        }
        return lucky;
    }
};
