class Solution {
public:
    bool chk(unordered_map<int,int>&mp){
        for(auto it : mp){
            if(it.second>=2){
                return false;
            }
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        unordered_map<int,int>mp;
        for(auto it : nums){
            mp[it]++;
        }
        int i=0;
        while(i<n){
            if(chk(mp)){
                break;
            }
            int b=3;
            count++;
            while(b&&i<n){
                //cout<<nums[i]<<" ";
                mp[nums[i]]--;
                i++;
                b--;
            }
            //cout<<endl;
        }
        return count;
    }
};