#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isPrime(long long n) {
    if (n <= 1) return false;
    
    for(long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false; 
    }    
    return true;
}

int solution(int n, int k) {
    stack<int> st;
    vector<int> v;
    
    int tmp = n;
    
    // k 진법 변환
    while (tmp > 0) {
        st.push(tmp % k);
        tmp /= k;
    }
    
    long long num = 0;
    while (!st.empty()) {
        int top = st.top();
        if (top != 0) { // 0이 아니라면 
            num *= 10;
            num += top;
        } else {
            if (num > 0 && isPrime(num)) v.push_back(num);
            num = 0;
        }
        st.pop();
    }
    
    if (num > 0 && isPrime(num)) v.push_back(num);
    
    return v.size();
}