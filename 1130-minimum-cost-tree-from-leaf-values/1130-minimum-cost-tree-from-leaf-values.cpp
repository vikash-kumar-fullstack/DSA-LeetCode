class Solution {
public:
    int solveUsingRecursion(vector<int>& arr, map<pair<int,int>, int>& maxi, int start, int end) {
    // base case
    if(start == end) {
        return 0;
    }

    int ans = INT_MAX;

    // try all partitions
    for(int k = start; k < end; k++) {
        int left = solveUsingRecursion(arr, maxi, start, k);
        int right = solveUsingRecursion(arr, maxi, k+1, end);

        int cost = left + right + maxi[{start, k}] * maxi[{k+1, end}];

        ans = min(ans, cost);
    }

    return ans;
}
    int solveUsingTabulation(vector<int>& arr, map<pair<int,int>, int>& maxi) {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // length of interval
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                dp[i][j] = INT_MAX;

                for(int k = i; k < j; k++) {
                    int cost = dp[i][k] 
                             + dp[k+1][j] 
                             + maxi[{i,k}] * maxi[{k+1,j}];

                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[0][n-1];
    }


    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();

        // 🔥 Precompute max in range
        map<pair<int,int>, int> maxi;

        for(int i = 0; i < n; i++) {
            maxi[{i,i}] = arr[i];
            for(int j = i+1; j < n; j++) {
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }

        return solveUsingTabulation(arr, maxi);
    }
};
