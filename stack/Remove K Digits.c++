class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;

        for (char c : num) {
            while (!s.empty() && k > 0 && s.top() > c) {
                s.pop();
                k--;
            }
            s.push(c);
        }

        // If k still > 0, remove from the end
        while (k > 0 && !s.empty()) {
            s.pop();
            k--;
        }

        // Build the result string
        string ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());

        // Remove leading zeroes
        int idx = 0;
        while (idx < ans.size() && ans[idx] == '0') idx++;
        ans = ans.substr(idx);

        // If empty string, return "0"
        return ans.empty() ? "0" : ans;
    }
};
