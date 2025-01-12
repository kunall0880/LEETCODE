class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.length();
        if(n%2 != 0){
            return false;
        }
        int ltr=0,rtl=0;
        for(int i=0;i<n;i++){
            if(locked[i]=='0'||s[i]=='('){
                ltr++;
            }else{
                ltr--;
            }
            if(ltr<0){
                return false;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(locked[i]=='0'||s[i]==')'){
                rtl++;
            }
            else{
                rtl--;
            }
            if(rtl<0){
                return false;
            }
        }
        return true;
    }
};