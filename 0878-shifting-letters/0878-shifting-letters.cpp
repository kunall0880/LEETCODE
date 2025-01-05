class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.length();
        long sum=0;
        //vector<int>pre(n,0);
        //pre[n-1]=shifts[n-1];
        for(int i=0;i<n;i++){
            sum+=shifts[i];
        }
        string ans="";
        for(int i=0;i<n;i++){
            ans+=char('a'+(s[i]-'a'+(sum))%26);
            sum=sum-shifts[i];
        }
        return ans;
    }
};