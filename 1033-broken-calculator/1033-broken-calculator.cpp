class Solution {
public:
    int brokenCalc(int start, int tar) {
        int curr=tar;
        int oper=0;
        while(curr!=start&&curr>=0){
            if(curr<start){
                curr++;
                oper++;
            }else if(curr%2==0){
                curr=curr/2;
                oper++;
            }else{
                curr++;
                oper++;
            }
        }
        return oper;
    }
};