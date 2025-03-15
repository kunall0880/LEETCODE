class Solution {
public:
    // int solve(vector<int>&nums,int k,int n,int i){
    //     if(k==0){
    //         return 0;
    //     }
    //     if(i>=n){
    //         return INT_MAX;
    //     }
    //     int take=max(nums[i],solve(nums,k-1,n,i+2));
    //     int nottake=solve(nums,k,n,i+1);

    //     return min(take,nottake);
    // }
    bool solve(vector<int>&nums,int k,int ele){
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=ele){
                count++;
                i++;
            }
        }
        return count>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int l=*min_element(nums.begin(),nums.end());
        int h=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(solve(nums,k,mid)){
                h=mid-1;
                ans=mid;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};