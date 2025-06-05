class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        for(int num:asteroids){
            bool destroyed=false;
            while(!s.empty() && s.top()>0 && num<0){
                int top=s.top();
                if (top < -num) {
                    s.pop();
                    continue;
                } else if (top == -num) {
                    s.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed) s.push(num);
        }
        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
