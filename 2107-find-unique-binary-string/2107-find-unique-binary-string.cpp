class Solution {
public:
    void solve(int n,string & s,vector<string>&nums){
        if(s.length()==n){
            nums.push_back(s);
            return;
        }
        for(int i=0;i<=1;i++){
            s.push_back(i+'0');
            solve(n,s,nums);
            s.pop_back();
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        vector<string>store;
        string str="";
        int n=nums[0].length();
        sort(nums.begin(),nums.end());
        solve(n,str,store);
        string ans="";
        for(string & it1 : store){
            int f=1;
            for(string & it2 : nums){
                if(it1==it2){
                    f=0;
                    continue;
                }
            }
            if(f==1){
                    return it1;
            }
        }
        return ans;
    }
};