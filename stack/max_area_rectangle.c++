class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> s;
        int n=height.size();
        vector<int> l(n,0);
        int max_width=0;
        for(int i=0;i<=n;i++){
            while(!s.empty() && (i==n|| height[i]<=height[s.top()])){
                int h=height[s.top()];
                s.pop();
                int width=0;
                if(s.empty()) width=i;
                else width=i-s.top()-1;
                max_width=max(max_width,width*h);
            }
            s.push(i);
        }
        return max_width;
    }
};
