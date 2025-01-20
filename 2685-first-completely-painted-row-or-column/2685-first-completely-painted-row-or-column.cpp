class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size(),k=arr.size();
        unordered_map<int,pair<int,int>>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[mat[i][j]]={i,j};
            }
        }
        vector<int>rowchk(m+1,0);
        vector<int>colchk(n+1,0);
        for(int i=0;i<k;i++){
            auto [row,col]=mp[arr[i]];
            mat[row][col]=-1;
            rowchk[row]++;
            colchk[col]++;
            if(rowchk[row]==n||colchk[col]==m){
                return i;
            }
        }
        return -1;
    }
};