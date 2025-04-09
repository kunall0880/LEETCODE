class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
            if(it<k){
                return -1;
            }
        }
        for(auto it : mp){
            if(it.first>k){
                count++;
            }
        }
        return count;
    }
};