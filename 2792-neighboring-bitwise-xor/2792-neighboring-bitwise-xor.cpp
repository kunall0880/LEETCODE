class Solution {
public:
    bool doesValidArrayExist(vector<int>& nums) {
        int start=0,n=nums.size(),curr=0,next=0;
        for(int i=0;i<n-1;i++){
            next=curr^nums[i];
            curr=next;
        }
        if(curr^start==nums[n-1]){
            return true;
        }
        start=1,curr=1,next=0;
        for(int i=0;i<n-1;i++){
            next=curr^nums[i];
            curr=next;
        }
        if(curr^start==nums[n-1]){
            return true;
        }
        return false;
    }
};