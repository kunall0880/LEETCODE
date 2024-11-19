class Solution {
public:
    int bin(vector<int>&nums,int tar){
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==tar)return mid;
            else if(nums[l]<=nums[mid]){
                if(nums[l]<=tar&&nums[mid]>=tar){
                    h=mid-1;
                }else{
                    l=mid+1;
                }
            }else{
                if(nums[mid]<=tar&&nums[h]>=tar){
                    l=mid+1;
                }else{
                    h=mid-1;
                }
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return bin(nums,target);
    }
};