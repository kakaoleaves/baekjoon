#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1) return false;
    else if (n == 2) return true;
    else
    {
        if (n % 2 == 0) return false;
        else
        {
            for (int i = 2; i <= sqrt(n); i++)
                if (n % i == 0) return false;  
            return true;
        }        
    }
}

int solution(vector<int> nums) {
    int answer = 0;

    int s = nums.size();
    
    for (int i = 0; i < s - 2; i++)
    {
        for (int j = i + 1; j < s - 1; j++)
        {
            for (int k = j + 1; k < s; k++)
            {
                int num = nums[i] + nums[j] + nums[k];
                if (isPrime(num)) answer++;
            }
        }
    }
    
    return answer;
}