class Solution {
public:
    string change(vector<int>nums){
        int first=nums[0],n=nums.size();
        string ans="";
        for(int i=1;i<n;i++){
            if(nums[i]!=first){
                ans=ans+"c";
            }else{
                ans=ans+"n";
            }
        }
        return ans;
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_map<string, int> mp;
        for (auto row : matrix) {
            string take2 = change(row);
            mp[take2]++;
        }
        int maxi = 0;
        for (auto it : mp) {
            maxi = max(maxi, it.second);
        }
        return maxi;
    }
};