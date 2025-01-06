class Solution {
public:
    int minimumTotal(vector<vector<int>>& nums) {
        int m=nums.size(),n=nums[0].size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        //return sol(triangle,0,0,m,dp);
        vector<int>temp(m,-1);
        for(int i=0;i<m;i++){
            temp[i]=nums[m-1][i];
        }
        for(int i=m-2;i>=0;i--){
            vector<int>prev(m,-1);
            for(int j=i;j>=0;j--){
                    int down=nums[i][j]+temp[j];
                    int dia=nums[i][j]+temp[j+1];
                    prev[j]=min(down,dia);
            }
            temp=prev;
        }
        return temp[0];
    }
};