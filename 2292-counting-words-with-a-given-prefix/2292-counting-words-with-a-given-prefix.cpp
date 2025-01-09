class Solution {
public:
    int prefixCount(vector<string>& nums, string pref) {
        int count=0,n=nums.size(),l1=pref.length();
        for(int i=0;i<n;i++){
            int l2=nums[i].length();
            if(l2<l1){
                continue;
            }
            string str=nums[i].substr(0,l1);
            if(str==pref){
                count++;
            }
        }
        return count;
    }
};