class Solution {
public:
    string clearDigits(string s) {
        string str="";
        int n=s.size(),count=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]>='0'&&s[i]<='9'){
                count++;
            }
            if(s[i]>='a'&&s[i]<='z'&&count==0){
                str=str+s[i];
            }else if(s[i]>='a'&&s[i]<='z'){
                count--;
                continue;
            }
        }
        reverse(str.begin(),str.end());
        return str;
    }
};