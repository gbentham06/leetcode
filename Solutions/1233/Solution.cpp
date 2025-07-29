class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> out = {folder[0]};
        for (int i = 1; i < folder.size(); i++){
            if (folder[i].substr(0, out.back().size()+1) != out.back() + "/"){
                out.push_back(folder[i]);
            }
        }
        return out;
    }
};
