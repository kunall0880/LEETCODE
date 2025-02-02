class Solution {
public:
    int dist(string s){
        int n=s.length(),x=0,y=0,ans=-1e8;
        for(int i=0;i<n;i++){
            if(s[i]=='N'){
                y++;
            }
            if(s[i]=='S'){
                y--;
            }
            if(s[i]=='E'){
                x++;
            }
            if(s[i]=='W'){
                x--;
            }
            ans=max(ans,abs(x)+abs(y));
        }
        return ans;
    }
    int maxDistance(string str, int k) {
        int n=str.length();
        int x=k,ans=INT_MIN;
        string s=str;
        for(int i=0;i<n;i++){
            if(s[i]=='S'&&x>0){
                s[i]='N';
                x--;
            }
            if(s[i]=='W'&&x>0){
                s[i]='E';
                x--;
            }
        }
        ans=max(ans,dist(s));
        x=k,s=str;
        for(int i=0;i<n;i++){
            if(s[i]=='S'&&x>0){
                s[i]='N';
                x--;
            }
            if(s[i]=='E'&&x>0){
                s[i]='W';
                x--;
            }
        }
        ans=max(ans,dist(s));
        x=k,s=str;
        for(int i=0;i<n;i++){
            if(s[i]=='N'&&x>0){
                s[i]='S';
                x--;
            }
            if(s[i]=='W'&&x>0){
                s[i]='E';
                x--;
            }
        }
        ans=max(ans,dist(s));
        x=k,s=str;
        for(int i=0;i<n;i++){
            if(s[i]=='N'&&x>0){
                s[i]='S';
                x--;
            }
            if(s[i]=='E'&&x>0){
                s[i]='W';
                x--;
            }
        }
        ans=max(ans,dist(s));
        return ans;
    }
};