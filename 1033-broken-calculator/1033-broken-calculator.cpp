class Solution {
public:
    int brokenCalc(int start, int tar) {
        if(tar<=start){
            return start-tar;
        }
        if(tar%2==0){
            return 1+brokenCalc(start,tar/2);
        }
        return 1+brokenCalc(start,tar+1);
    }
};