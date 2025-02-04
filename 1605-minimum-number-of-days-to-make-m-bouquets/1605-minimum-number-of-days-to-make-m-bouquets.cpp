class Solution {
public:
    int solve(vector<int>& nums,int day,int no){
        int total=0,n=nums.size();
        int k=no,ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]>day){
                total=0;
            }else{
                total++;
                if(total==k){
                    ans++;
                    total=0;
                }
            }
        }
        return ans;
    }
    int minDays(vector<int>& nums, int m, int k) {
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());
        int maxi=high;
        int sol=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            int ans=solve(nums,mid,k);
            if(ans<m){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        if(low>maxi){
            return -1;
        }
        return low;
    }
};