class Solution {
public:
    struct Node{
        unordered_map<string, Node*> children;
        bool del = false;
    };
    unordered_map<string, vector<Node*>> seen;
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node();
        for (auto& path : paths){
            Node* cur = root;
            for (const string& dir : path){
                if (!cur->children.count(dir)){
                    cur->children[dir] = new Node();
                }
                cur = cur->children[dir];
            }
        }
        dfs(root);
        for (auto& [key, nodes] : seen){
            if (nodes.size() > 1){
                for (auto* node: nodes){
                    node->del = true;
                }
            }
        }
        vector<vector<string>> out;
        vector<string> path;
        collect(root, path, out);
        return out;
    }
    string dfs(Node* node){
        if (node->children.empty()){
            return "";
        }
        vector<string> subs;
        for (auto& [name, child] : node->children){
            subs.push_back(name + "(" + dfs(child) + ")");
        }
        sort(subs.begin(), subs.end());
        string serial = accumulate(subs.begin(), subs.end(), string());
        seen[serial].push_back(node);
        return serial;
    }
    void collect(Node* node, vector<string>& path, vector<vector<string>>& out){
        for (auto& [name, child] : node->children){
            if (child->del){
                continue;
            }
            path.push_back(name);
            out.push_back(path);
            collect(child, path, out);
            path.pop_back();
        }
    }
};
