class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> arr(26, 0);
        for(char ch: word){
            arr[ch - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            cout << arr[i] << endl;
            if(arr[i] == 0) continue;
            arr[i]--;
            unordered_set<int> st;
            for(int it: arr){
                if(it > 0) st.insert(it);
            }
            if(st.size() == 1) return true;
            arr[i]++;
        }
        return false;
    }
};

// aaaa:- true