class Solution {
public:
//using recursion
    int solveUsingRecursion(string& word1,string& word2,int index1,int index2){
        if(index1==word1.length()){
            return word2.length()-index2;
        }
        if(index2==word2.length()){
            return word1.length()-index1;
        }
        int replace,insert,del;
        int ans;
        if(word1[index1]==word2[index2]){
            ans=solveUsingRecursion(word1,word2,index1+1,index2+1);

        }else{
            replace=1+solveUsingRecursion(word1,word2,index1+1,index2+1);
            insert=1+solveUsingRecursion(word1,word2,index1,index2+1);
            del=1+solveUsingRecursion(word1,word2,index1+1,index2);
            ans=min(replace,min(insert,del));
        }
        return ans ;
    }
//using memoization
        int solveUsingMemoization(vector<vector<int>>&dp,string& word1,string& word2,int index1,int index2){
        if(index1==word1.length()){
            return word2.length()-index2;
        }
        if(index2==word2.length()){
            return word1.length()-index1;
        }
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }
        int replace,insert,del;
        int ans;
        if(word1[index1]==word2[index2]){
            ans=solveUsingMemoization(dp,word1,word2,index1+1,index2+1);

        }else{
            replace=1+solveUsingMemoization(dp,word1,word2,index1+1,index2+1);
            insert=1+solveUsingMemoization(dp,word1,word2,index1,index2+1);
            del=1+solveUsingMemoization(dp,word1,word2,index1+1,index2);
            ans=min(replace,min(insert,del));
        }
        dp[index1][index2]=ans;
        return dp[index1][index2] ;
    }
//using tabulation
        int solveUsingTabulation(string& word1,string& word2){
        vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        for(int i=0;i<=word2.length();i++){
            dp[word1.length()][i]=word2.length()-i;
        }
        for(int i=0;i<=word1.length();i++){
            dp[i][word2.length()]=word1.length()-i;
        }
        for(int i=word1.length()-1;i>=0;i--){
            for(int j=word2.length()-1;j>=0;j--){
                int replace,insert,del;
                int ans=0;
                if(word1[i]==word2[j]){
                    ans=dp[i+1][j+1];
                }else{
                    replace=1+dp[i+1][j+1];
                    insert=1+dp[i][j+1];
                    del=1+dp[i+1][j];
                    ans=min(replace,min(insert,del));
                }dp[i][j]=ans;
            }
        }
        return dp[0][0] ;
    }

//using Optimisation
        int solveUsingOptimisation(string& word1,string& word2){
        vector<int>curr(word1.length()+1,0);
        vector<int>next(word1.length()+1,0);

        //isko bhul jao 
        // for(int i=0;i<=word2.length();i++){
        //     dp[word1.length()][i]=word2.length()-i;
        // }

        for(int i=0;i<=word1.length();i++){
            next[i]=word1.length()-i;
        }
        for(int j=word2.length()-1;j>=0;j--){
            curr[word1.length()]=word2.length()-j;
            for(int i=word1.length()-1;i>=0;i--){
                int replace,insert,del;
                int ans=0;
                if(word1[i]==word2[j]){
                    ans=next[i+1];
                }else{
                    replace=1+next[i+1];
                    insert=1+curr[i+1];
                    del=1+next[i];
                    ans=min(replace,min(insert,del));
                }curr[i]=ans;
            }
            next=curr;
        }
        return next[0] ;
    }
    int minDistance(string word1, string word2) {
        // int index1=0,index2=0;
        // vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        // int ans=solveUsingMemoization(dp,word1,word2,index1,index2);
        // return ans;

        //using tabulation method
        // int ans=solveUsingTabulation(word1,word2);
        // return ans;

        //using optimisation
        int ans=solveUsingOptimisation(word1,word2);
        return ans;
    }
};