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
public:
    
    int find(TreeNode* root,long long sum,long long target,unordered_map<long long,int>freq){
        if(!root)return 0;
        sum+=root->val;
        int ans=freq[sum-target];
        freq[sum]++;
        ans+=find(root->left,sum,target,freq);
        ans+=find(root->right,sum,target,freq);
        freq[sum]--;
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        unordered_map<long long,int>freq;
        freq[0]=1;
        return find(root, 0, targetSum,freq);
    }
};