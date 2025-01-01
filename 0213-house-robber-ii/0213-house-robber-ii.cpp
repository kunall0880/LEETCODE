class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>temp1,temp2;
        int n=nums.size();
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        if(n==1)return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
        }
        //int ans1=0,ans2=0;
        dp1[0]=temp1[0];
        n=temp1.size();
        for(int i=1;i<n;i++){
            int take=temp1[i];
            if(i-2>=0){
                take+=dp1[i-2];
            }
            int nottake=dp1[i-1];
            dp1[i]=max(take,nottake);
        }
        dp2[0]=temp2[0];
        for(int i=1;i<n;i++){
            int take=temp2[i];
            if(i-2>=0){
                take+=dp2[i-2];
            }
            int nottake=dp2[i-1];
            dp2[i]=max(take,nottake);
        }
        return max(dp1[n-1],dp2[n-1]);
    }
};