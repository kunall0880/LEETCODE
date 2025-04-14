class Solution {
public:
    int countGoodTriplets(vector<int>& nums, int a, int b, int c) {
        int count=0,n=nums.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                if(abs(nums[i]-nums[j])>a){
                    continue;
                }
                for(int k=j+1;k<n;k++){
                    if(abs(nums[i]-nums[j])<=a&&abs(nums[j]-nums[k])<=b&&abs(nums[i]-nums[k])<=c){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};