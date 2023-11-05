#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int low, int high){
    if(s.size() == 0) return 0;
    if(s.size() == 1) return 1;
    while(low < high){
        if(s[low] != s[high]){
            return false;
        }
        else{
            low++;
            high--;
        }
    }
    return true;
}

string longestPalindromicSubstring(const string& s, int start, int end) {
    if (start >= end) {
        return s.substr(start, 1);
    }

    if (s[start] == s[end] && isPalindrome(s, start, end)) {
        return s.substr(start, end - start + 1);
    }

    string left = longestPalindromicSubstring(s, start, end - 1);
    string right = longestPalindromicSubstring(s, start + 1, end);

    return (left.length() >= right.length()) ? left : right;
}


int main(){
    string s;
    cout << "Enter the String: ";
    cin >> s;
    cout << "The longest paliondromic substring is: " << longestPalindromicSubstring(s, 0, s.length() - 1);

}