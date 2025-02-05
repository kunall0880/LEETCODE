class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int l1=s1.length(),l2=s2.length();
        for(int i=0;i<l2;i++){
            for(int j=0;j<l2;j++){
                string str=s2;
                char ch=str[i];
                str[i]=str[j];
                str[j]=ch;
                if(str==s1){
                    return true;
                }
            }
        }
        return false;
    }
};