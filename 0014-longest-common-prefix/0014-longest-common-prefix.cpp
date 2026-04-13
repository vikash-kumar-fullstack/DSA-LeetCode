class Solution {
public:
    class TrieNode{
    public :
    char value;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char value){
        this->value=value;
        for(int i=0;i<26;i++){
            this->children[i]=NULL;
        }
        this->isTerminal=false;
    }
};

void insert(TrieNode*root,string str){
    if(str.length()==0){
        root->isTerminal=true;

        return;
    }
    char ch=str[0];
    int index=ch-'a';
    TrieNode *child;
    if(root->children[index]!=NULL){
        //present
        child=root->children[index];
    }else{
        //absent
        child=new TrieNode(ch);
        root->children[index]=child;
    }
    insert(child,str.substr(1));
}
string find(TrieNode*root,string ans){
    if(root->isTerminal==true){
        return ans;
    }
    int count=0;
    int index;
    for(int i=0;i<26;i++){
        if(root->children[i]!=NULL){
            index=i;
            count++;
        }
    }
    if(count==1 && root->isTerminal==false){
        ans.push_back('a'+index);
    }else{
        return ans;
    }
    return find(root->children[index],ans);
    
}
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode*root=new TrieNode('*');
        for(int i=0;i<strs.size();i++){
        insert(root,strs[i]);
        }
        string ans;
        return find(root,ans);
    }
};