// class Solution {
// public:
//     bool check(vector<int>&prev,vector<int>&curr){
//         return prev[0]>curr[0] && prev[1]>curr[1];
//     }
// //using Optimisation of 
//         int solveUsingOptimisation(vector<vector<int>>& envelopes){
//         vector<int>prev(envelopes.size()+1,0);
//         vector<int>curr(envelopes.size()+1,0);
//         for(int i=envelopes.size()-1;i>=0;i--){
//             for(int j=i-1;j>=-1;j--){
//                 int ans1=0;
//                 if(j==-1 || check(envelopes[i],envelopes[j])){
//                     ans1=1+prev[i+1];
//                 }
//                 //exclude
//                 int ans2=prev[j+1];
//                 curr[j+1]=max(ans1,ans2);
//             }
//             prev=curr;
//         }
        
//         return curr[0];
//     }
//     int maxEnvelopes(vector<vector<int>>& envelopes) {
//         sort(envelopes.begin(),envelopes.end());
//         return solveUsingOptimisation(envelopes);
//     }
// };

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<int> lis;

        for(auto &e : envelopes){
            int h = e[1];

            auto it = lower_bound(lis.begin(), lis.end(), h);

            if(it == lis.end())
                lis.push_back(h);
            else
                *it = h;
        }

        return lis.size();
    }
};