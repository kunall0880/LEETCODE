class Solution {
public:
    int minimumLength(string s) {
        vector<int>ans(26,0);
        int n=s.length(),count=0;
        int l=n;
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            ans[idx]++;
            if(ans[idx]==3){
                //count=count-ans[idx]-2;
                ans[idx]=1;
                l=l-2;
            }
        }
        return l;
    }
};