class Solution {
public:
    int solveUsingOptimisation(string &text1,string &text2,int start1,int start2){
        vector<int>next(text1.length()+1);
        vector<int>curr(text1.length()+1);
        //include case
        for(int j=text2.length()-1;j>=0;j--){
            for(int i=text1.length()-1;i>=0;i--){
                int ans1=0;int ans2=0;
                if(text1[i]==text2[j]){
                    ans1=1+next[i+1];
                }else{
                    //exclude
                ans2=max(next[i],curr[i+1]);
                }
                curr[i]=max(ans1,ans2);
            }
            next=curr;
        }
        
        
        return curr[start1];
    }
    int longestPalindromeSubseq(string s) {
        string text1=s;
        reverse(s.begin(),s.end());
        int ans=solveUsingOptimisation(text1,s,0,0);
        return ans;
    }
};