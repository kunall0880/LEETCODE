class Solution {
public:
    int solve(int num){
        int sum=0;
        while(num>0){
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sol=solve(nums[i]);
            mp[sol].push(nums[i]);
        }
        int maxi=INT_MIN;
        for(auto it : mp){
            int siz=it.second.size();
            if(siz>=2){
                int m1=it.second.top();
                it.second.pop();
                int m2=it.second.top();
                it.second.pop();
                maxi=max(maxi,m1+m2);
            }
        }
        return maxi==INT_MIN ? -1:maxi;
    }
};