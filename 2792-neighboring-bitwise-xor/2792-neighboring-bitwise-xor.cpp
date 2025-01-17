class Solution {
public:
    bool doesValidArrayExist(vector<int>& nums) {
        int start1=0,n=nums.size(),curr1=0,next1=0,start2=1,curr2=1,next2=0;
        for(int i=0;i<n-1;i++){
            next1=curr1^nums[i];
            curr1=next1;
            next2=curr2^nums[i];
            curr2=next2;
        }if(curr1^start1==nums[n-1]||curr2^start2==nums[n-1])
            return true;
        return false;
    }
};