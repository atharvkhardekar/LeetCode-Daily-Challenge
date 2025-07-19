// LeetCode Problem No. 1233
// Daily Challenge - 19/07/2025

class Solution {
    struct trienode {
        bool wordEnd = false;
        unordered_map<string, trienode*> child;
    };

    void trieInsert(const string& folder, trienode* curr) {
        int i = 1;
        while (i < folder.size()) {
            string name;
            while (i < folder.size() && folder[i] != '/') {
                name.push_back(folder[i]);
                i++;
            }

            if (curr->wordEnd) {
                return;
            }

            if (!curr->child.count(name)) {
                curr->child[name] = new trienode;
            }

            curr = curr->child[name];
            i++;
        }

        curr->wordEnd = true;
    }

    void searchTrie(trienode* curr, vector<string>& res, string path) {
        if (!curr) {
            return;
        }

        if (curr->wordEnd) {
            path.pop_back();
            res.push_back(path);
            return;
        }

        for (auto& [name, child] : curr->child) {
            searchTrie(child, res, path + name + "/");
        }
    }

public:
    vector<string> removeSubfolders(vector<string>& folders) {
        trienode* root = new trienode;

        for (const string& folder : folders) {
            trieInsert(folder, root);
        }

        vector<string> res;
        searchTrie(root, res, "/");
        return res;
    }
};
