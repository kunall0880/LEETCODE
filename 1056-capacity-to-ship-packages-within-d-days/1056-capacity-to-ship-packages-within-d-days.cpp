class Solution {
public:
    int solve(vector<int>& nums,int wt){
        int load=0,day=1;
        for(int i=0;i<nums.size();i++){
            if(load+nums[i]>wt){
                load=nums[i];
                day++;
            }else{
                load+=nums[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int maxi=0,sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }
        int h=sum,l=maxi,ans=INT_MAX;
        while(l<=h){
            int day=(l+h)/2;
            int chk=solve(nums,day);
            if(chk<=days){
                h=day-1;
            }else{
                l=day+1;
            }
        }
        return l;
    }
};