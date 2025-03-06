class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n=grid.size();
        n=n*n;
        long long cs=0,ws=0,css=0,wss=0;
        cs=(n*(n+1))/2;
        css=(n*(n+1)*(2*n+1))/6;
        n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ws=ws+grid[i][j];
                wss=wss+pow(grid[i][j],2);
            }
        }
        long long a=ws-cs;
        long long b=wss-css;
        return {(int)((b/a)+a)/2,(int)((b/a)-a)/2};
    }
};