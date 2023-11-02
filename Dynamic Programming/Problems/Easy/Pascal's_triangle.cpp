#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pascal(int x){
    vector<vector<int>> ans;
    if(x == 0) return ans;
    ans.push_back({1});
    for(int i = 1; i < x; i++){
        vector<int> vec(i+1, 1);
        for(int j = 1; j < i; j++){
            vec[j] = (ans[i-1][j-1] + ans[i-1][j]);
        }
        ans.push_back(vec);
    }
    return ans;
}

int main(){
    int x;
    cout << "Enter the number of rows: ";
    cin >> x;
    cout << "The Pascal's triangle is: " << endl;
    vector<vector<int>> triangle = pascal(x);
    for(const auto& row : triangle) {
        for(int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
