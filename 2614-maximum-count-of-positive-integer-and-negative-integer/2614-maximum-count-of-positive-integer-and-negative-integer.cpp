class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int cn=0,cp=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            cp+=(nums[i]>0);
            cn+=(nums[i]<0);
        }
        return max(cp,cn);
    }
};