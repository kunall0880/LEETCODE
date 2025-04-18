class Solution {
public:
    string solve(int n){
        if(n==1){
            return "1";
        }
        string ans = solve(n-1);
        string str="";
        for(int i=0;i<ans.length();i++){
            int count=1;
            char ch=ans[i];
            while(i<ans.length()-1&&ans[i]==ans[i+1]){
                count++;
                i++;
            }
            str+=(to_string(count)+string(1,ch));
        }
        return str;
    }
    string countAndSay(int n) {
        return solve(n);
    }
};