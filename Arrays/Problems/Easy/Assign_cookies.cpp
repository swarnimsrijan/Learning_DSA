class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int a = 0, b = 0; 
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        while(a < g.size() && b < s.size()){
            if(g[a] <= s[b]){
                a++;
                b++;
            }
            else{
                b++;
            }
        }
        return a++;
    }
};