class Solution {
public:
    bool check(string st,string s){
        string str="";
        for(int i=0;i<s.length();i++){
            str=st.back()+str;
            st.pop_back();
        }
        if(str==s){
            return true;
        }
        return false;
    }
    string removeOccurrences(string s, string part) {
        int l1=s.length(),l2=part.length();
        string st="";
        for(int i=0;i<l1;i++){
           st=st+s[i];
           if(st.length()>=l2&&check(st,part)){
                int count=l2;
                while(count--){
                    st.pop_back();
                }
           }
        }
        return st;
    }
};