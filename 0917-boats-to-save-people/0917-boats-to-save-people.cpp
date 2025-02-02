class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        int i=0,sum=0,j=n-1;
        while(i<=j){
            if((nums[i]+nums[j])<=limit){
                i++;
                j--;
                count++;
            }else{
                j--;
                count++;
            }
        }
        return count;
    }
};