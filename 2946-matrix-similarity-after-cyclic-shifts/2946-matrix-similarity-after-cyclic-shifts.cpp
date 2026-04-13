class Solution {
public:

        bool solveUsingRecurr(vector<vector<int>>& mat, int k){
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>copy(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                copy[i][j]=mat[i][j];
            }
        }
        for(int i=0;i<k;i++){
            for(int j=0;j<m;j++){
                if(j&1){
                    int temp=copy[j][n-1];
                    for(int l=n-2;l>=0;l--){
                        copy[j][l+1]=copy[j][l];
                    }
                    copy[j][0]=temp;

                    }else{
                        int temp=copy[j][0];
                    for(int l=1;l<n;l++){
                        copy[j][l-1]=copy[j][l];
                    }
                    copy[j][n-1]=temp;
                    }
            }
            
        }
            
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(copy[i][j]!=mat[i][j]){
                    return false;
                }
        }
        }
        return true; 
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        return solveUsingRecurr(mat,k);
    }
};
