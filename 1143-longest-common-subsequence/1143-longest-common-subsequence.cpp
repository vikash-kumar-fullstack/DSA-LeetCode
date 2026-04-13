class Solution {
public:

//using recursion
    // int solveUsingRecur(string text1,string text2,int start1,int start2,int index1,int index2){
    //     if(start1>=index1){
    //         return 0;
    //     }
    //     if(start2>=index2){
    //         return 0;
    //     }
    //     //include case
    //     int ans1=0;int ans2=0;
    //     if(text1[start1]==text2[start2]){
    //         ans1=1+solveUsingRecur(text1,text2,start1+1,start2+1,index1,index2);
    //     }else{
    //         //exclude
    //     ans2=max(solveUsingRecur(text1,text2,start1,start2+1,index1,index2),solveUsingRecur(text1,text2,start1+1,start2,index1,index2));
    //     }
    //     return max(ans1,ans2);
    // }

// using memoization
    //     int solveUsingMemoization(vector<vector<int>>&dp,string &text1,string &text2,int start1,int start2){
    //     if(start1>=text1.length()){
    //         return 0;
    //     }
    //     if(start2>=text2.length()){
    //         return 0;
    //     }
    //     step3:-
    //     if(dp[start1][start2]!=-1){
    //         return dp[start1][start2];
    //     }
    //     //include case
    //     int ans1=0;int ans2=0;
    //     if(text1[start1]==text2[start2]){
    //         ans1=1+solveUsingMemoization(dp,text1,text2,start1+1,start2+1);
    //     }else{
    //         //exclude
    //     ans2=max(solveUsingMemoization(dp,text1,text2,start1,start2+1),solveUsingMemoization(dp,text1,text2,start1+1,start2));
    //     }
    //     step2:-
    //     dp[start1][start2]=max(ans1,ans2);
    //     return dp[start1][start2];
    // }


// //using tabulation
//     int solveUsingTabulation(string &text1,string &text2,int start1,int start2){
//         vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,0));
//         //include case
//         for(int i=text1.length()-1;i>=0;i--){
//             for(int j=text2.length()-1;j>=0;j--){
//                 int ans1=0;int ans2=0;
//                 if(text1[i]==text2[j]){
//                     ans1=1+dp[i+1][j+1];
//                 }else{
//                     //exclude
//                 ans2=max(dp[i][j+1],dp[i+1][j]);
//                 }
//                 dp[i][j]=max(ans1,ans2);
//             }
//         }
        
        
//         return dp[start1][start2];
//     }


//using spaceoptimisation
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
    int longestCommonSubsequence(string text1, string text2) {
        //using recursion
        // int index1=text1.length();
        // int index2=text2.length();
        // int ans=solveUsingRecur(text1,text2,0,0,index1,index2);
        // return ans;


        //using memoization
        // int index1=0;
        // int index2=0;
        // // step1:-
        // vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,-1));
        // int ans=solveUsingMemoization(dp,text1,text2,index1,index2);
        // return ans;

        // //using tabulation
        // int index1=0;
        // int index2=0;
        // int ans=solveUsingTabulation(text1,text2,index1,index2);
        // return ans;


        // //using space optimisation
        int index1=0;
        int index2=0;
        int ans=solveUsingOptimisation(text1,text2,index1,index2);
        return ans;


    }
};