// LeetCode Problem No. 1028
// Daily Challenge - 22/02/2025

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
 class Solution {
    int getVal(string& traversal,const int& n,int& pos){
        int val = 0;
        while(pos<n and traversal[pos]>='0' and traversal[pos]<='9'){
            val = val*10 + (traversal[pos]-'0');
            pos++;
        }
        return val;
    }

    int getDashLen(string& traversal,const int& n,int& pos){
        int dash_len = 0;
        while(pos<n and traversal[pos]=='-'){
            dash_len++;
            pos++;
        }
        return dash_len;
    }

    void buildTree(TreeNode* curr,int expected_dash_len,string& traversal,const int& n,int& pos){
        if(pos==n)  return;

        int prev_pos = pos;
        int dash_len = getDashLen(traversal,n,pos);

        if(dash_len < expected_dash_len){
            pos = prev_pos;
            return;
        }
      
        int node_val = getVal(traversal,n,pos);
        TreeNode* newnode = new TreeNode(node_val);
        if(!curr->left) curr->left = newnode;
        else            curr->right = newnode;

        buildTree(newnode,1+expected_dash_len,traversal,n,pos);
        buildTree(newnode,1+expected_dash_len,traversal,n,pos);
    }

 public:
    TreeNode* recoverFromPreorder(string traversal) {
        int n=traversal.size();
        int pos=0;
        TreeNode *root = new TreeNode(getVal(traversal,n,pos));
        
        buildTree(root,1,traversal,n,pos);
        buildTree(root,1,traversal,n,pos);
        return root;
    }
};
