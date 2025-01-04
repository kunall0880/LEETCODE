class Solution {
public:
    int minPathSum(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();
        vector<long>prev(n,0);
        for (int i = 0; i < m; i++) {
            vector<long>temp(n,0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    temp[j] = nums[i][j];
                }else {
                    long rig=nums[i][j];
                    if(j>0){
                        rig += temp[j - 1];
                    }else{
                        rig=1e9;
                    }
                    long up=nums[i][j];
                    if(i>0){
                        up += prev[j];
                    }else{
                        up=1e9;
                    }
                    temp[j] = min(rig, up);
                }
            }
            prev=temp;
        }
        return prev[n-1];
    }
};