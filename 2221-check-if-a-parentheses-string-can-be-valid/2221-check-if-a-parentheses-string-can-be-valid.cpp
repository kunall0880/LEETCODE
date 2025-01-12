class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.length();
        if(n%2 != 0){
            return false;
        }
        stack<int>open;
        stack<int>both;
        for(int i=0;i<n;i++){
            if(locked[i]=='0'){
                both.push(i);
            }else if(s[i]=='('){
                open.push(i);
            }else if(s[i]==')'){
                if(!open.empty()){
                    open.pop();
                }else if(!both.empty()){
                    both.pop();
                }else{
                    return false;
                }
            }
        }

        while(!open.empty()&&!both.empty()&&open.top()<both.top()){
            open.pop();
            both.pop();
        }
        
        if(open.empty()){
            return true;
        }
        return false;
    }
};