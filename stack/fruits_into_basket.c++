class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low=0;
        int high=0;
        unordered_map<int,int> u;
        int maxlen=0;
        while(high<fruits.size()){
            u[fruits[high]]++;
            if(u.size()<=2){
                maxlen=max(maxlen,high-low+1);
            }
            else{
                u[fruits[low]]--;
                if(u[fruits[low]]==0){
                    u.erase(fruits[low]);
                }
                low++;
            }
            high++;
        }
        return maxlen;
    }
};
