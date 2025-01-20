class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size(),k=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++){
            mp[arr[i]]=i;
        }
        int minidx=INT_MAX;
        for(int row=0;row<m;row++){
            int maxidx=INT_MIN;
            for(int col=0;col<n;col++){
                int idx=mp[mat[row][col]];
                maxidx=max(maxidx,idx);
            }
            minidx=min(maxidx,minidx);
        }
        for(int col=0;col<n;col++){
            int maxidx=INT_MIN;
            for(int row=0;row<m;row++){
                int idx=mp[mat[row][col]];
                maxidx=max(maxidx,idx);
            }
            minidx=min(maxidx,minidx);
        }
        return minidx;
    }
};