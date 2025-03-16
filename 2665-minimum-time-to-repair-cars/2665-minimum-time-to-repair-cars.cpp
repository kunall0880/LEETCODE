class Solution {
public:
    bool poss(vector<int>&nums,int cars,long long time){
        long long total=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            total+=sqrt(time/nums[i]);
        }
        return total>=cars;
    }
    long long repairCars(vector<int>& nums, int cars) {
        int n=nums.size();
        long long l=1;
        int maxi=*max_element(nums.begin(),nums.end());
        long long h=maxi*(cars),ans=-1;
        h=h*cars;
        while(l<=h){
            long long mid=(l+h)/2;
            if(poss(nums,cars,mid)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};