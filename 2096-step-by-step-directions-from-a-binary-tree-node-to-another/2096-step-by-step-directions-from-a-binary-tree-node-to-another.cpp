class Solution {
public:

    TreeNode* findNode(TreeNode* root,int val){
        if(!root) return NULL;

        if(root->val == val) return root;

        TreeNode* left = findNode(root->left,val);
        if(left) return left;

        return findNode(root->right,val);
    }

    TreeNode* lowest_common_ancestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        if(root == p) return p;
        if(root == q) return q;

        TreeNode* left = lowest_common_ancestor(root->left, p, q);
        TreeNode* right = lowest_common_ancestor(root->right, p, q);

        if(left == NULL && right == NULL) return NULL;
        if(left == NULL && right != NULL) return right;
        if(left != NULL && right == NULL) return left;
        else return root;
    }

    bool findPath(TreeNode* root, TreeNode* target, string &path){
        if(root == NULL) return false;

        if(root == target) return true;

        path.push_back('L');
        if(findPath(root->left, target, path)) return true;
        path.pop_back();

        path.push_back('R');
        if(findPath(root->right, target, path)) return true;
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {

        TreeNode* start = findNode(root,startValue);
        TreeNode* dest = findNode(root,destValue);

        TreeNode* lca = lowest_common_ancestor(root,start,dest);

        string lcaToStart="";
        string lcaToEnd="";

        findPath(lca,start,lcaToStart);
        findPath(lca,dest,lcaToEnd);

        string ans;
        for(int i=0;i<lcaToStart.size();i++){
            ans+='U';
        }

        ans += lcaToEnd;

        return ans;
    }
};