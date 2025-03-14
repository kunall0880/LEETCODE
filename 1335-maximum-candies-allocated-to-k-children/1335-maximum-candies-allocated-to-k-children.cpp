class Solution {
public:
    bool func(vector<int>nums,long long k,int cnt){
        int n=nums.size();
        long long count=0;
        for(int i=0;i<n;i++){
            count+=nums[i]/cnt;
        }
        if(count>=k){
            return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& nums, long long k) {
        int maxi=INT_MIN,n=nums.size(),mini=INT_MAX;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        int count=0;
        int low=1,high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            if(func(nums,k,mid)){
                count=max(count,mid);
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return count;
    }
};