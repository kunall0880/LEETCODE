class Solution {
public:
    string shiftingLetters(string ans, vector<vector<int>>& nums) {
        int n=nums.size();
        vector<int>count(ans.length()+1,0);
        for(int i=0;i<n;i++){
            int start=nums[i][0],end=nums[i][1],dir=nums[i][2];
            int x=1;
            if(dir==0){
                x=-1;
            }
            count[start]+=x;
            if(end+1<ans.length()){
                count[end+1]-=x;
            }
        }
        n=ans.length();
        for(int i=1;i<n;i++){
            count[i]+=count[i-1];
        }
        for(int i=0;i<n;i++){
            int shift=count[i]%26;
            if(shift<0){
                shift=shift+26;
            }
            ans[i]='a'+(ans[i]-'a'+shift)%26;
        }
        return ans;
    }
};