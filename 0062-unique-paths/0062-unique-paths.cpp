class Solution {
public:
    int uniquePaths(int m, int n) {
        //vector<vector<long>>dp(m+1,vector<long>(n+1,-1));
        vector<long>prev(n+1,-1);
        if(m==1&&n==1){
            return m;
        }
        prev[0]=0;
        for(int i=1;i<m;i++){
            vector<long>temp(n+1,-1);
            for(int j=1;j<n;j++){
                int u=prev[j];
                int l=temp[j-1];
                temp[j]=(u+l);
            }
            prev=temp;
        }
        return -1*prev[n-1];
    }
};