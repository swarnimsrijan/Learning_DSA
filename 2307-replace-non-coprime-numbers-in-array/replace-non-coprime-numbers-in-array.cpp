class Solution {
public:
    using lli = long long int;
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<lli> st;
        st.push(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            int num = nums[i];
            while (!st.empty() && gcd(st.top(), num) > 1) {
                num = lcm(st.top(), num);
                st.pop();
            }
            st.push(num);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back((int)st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    lli gcd(lli a, lli b){
        while (b != 0) {
            lli temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    lli lcm(lli a, lli b){
        return (a / gcd(a, b)) * b;
    }
};

/*
things to achieve
1. finding 2 adj. no. which are non-coprime
2. if not found then stop the process
3. otherwise delete the numbers and replace them with their LCM
4. repeat as long as you find the 2 adj. non-coprime nos.


ideas:-
1. i can use stack and push the element in the stack(1st)
2. if the top of stack and the next number are coprime then insert that number
3. otherwise find the lcm of the top of stack and the number and then push that new number into the stack
4. return the converted stack
*/