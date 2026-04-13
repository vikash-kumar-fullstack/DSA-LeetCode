class Solution {
public:

    bool check(vector<int>&prev,vector<int>&curr){
        return prev[0]>=curr[0] && prev[1]>=curr[1] && prev[2]>=curr[2];
    }
//using Optimisation of 
        int solveUsingOptimisation(vector<vector<int>>& cuboids){
        vector<int>prev(cuboids.size()+1,0);
        vector<int>curr(cuboids.size()+1,0);
        for(int i=cuboids.size()-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int ans1=0;
                if(j==-1 || check(cuboids[i],cuboids[j])){
                    ans1=cuboids[i][2]+prev[i+1];
                }
                //exclude
                int ans2=prev[j+1];
                curr[j+1]=max(ans1,ans2);
            }
            prev=curr;
        }
        
        return curr[0];
    }


    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid:cuboids){
            sort(cuboid.begin(),cuboid.end());
        }
        sort(cuboids.begin(),cuboids.end());
        int ans=solveUsingOptimisation(cuboids);
        return ans;
    }
};