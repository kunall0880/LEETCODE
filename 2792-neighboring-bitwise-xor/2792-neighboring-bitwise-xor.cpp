class Solution {
public:
    bool doesValidArrayExist(vector<int>& nums) {
        int n=nums.size(),x=0;
        for(int i=0;i<n;i++){
            x=x^nums[i];
        }
        if(x==0)
            return true;
        return false;
    }
};