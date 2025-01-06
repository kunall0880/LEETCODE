class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> nums;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            if (boxes[i] == '1') {
                st.insert(i);
            }
        }
        for (int i = 0; i < n; i++) {
            int score=0;
            for(auto it : st){
                score+=abs(it-i);
            }
            nums.push_back(score);
        }
        return nums;
    }
};