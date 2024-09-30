//GFG Link - https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-number-of-substrings

#include <bits/stdc++.h>
using namespace std;

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int solve(string s, int k) {
        if (k < 0) return 0;
        long long int res = 0;
        vector<int>arr(256,0);
        int i = 0, j = 0;
        int cnt = 0;
        
        while (i < s.length()) {
            arr[s[i]]++;
            if(arr[s[i]] == 1)cnt++;
            
            while (cnt > k) {
                arr[s[j]]--;
                if (arr[s[j]] <= 0) {
                    cnt--;
                }
                j++;
            }
            res += (i - j + 1);
            i++;
        }
        return res;
    }
    long long int substrCount (string s, int k) {
        return solve (s, k) - solve (s, k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends