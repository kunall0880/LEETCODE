class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& nums) {
        string ans=s;
        int n=nums.size();
        vector<int>count(s.length()+1,0);
        for(int i=0;i<n;i++){
            int start=nums[i][0],end=nums[i][1],dir=nums[i][2];
            int x=1;
            if(dir==0){
                x=-1;
            }
            count[start]+=x;
            if(end+1<s.length()){
                count[end+1]-=x;
            }
        }
        n=s.length();
        for(int i=1;i<n;i++){
            count[i]+=count[i-1];
        }
        n=s.length();
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