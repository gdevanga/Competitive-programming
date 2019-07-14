/*
*	Find problem description @
* 	https://practice.geeksforgeeks.org/problems/stickler-theif/0
*/
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void maxSum(vector<int> in)
{
    int ms[in.size()+2] = {0};
    for (int i = in.size()-1; i >= 0; --i)
    {
        ms[i] = max(in[i] + ms[i+2], ms[i+1]);
    }
    cout << ms[0] << "\n";
}
int main() {
	int testcases;
    cin >> testcases;
    
    for (int i = 0; i <testcases; ++i)
    {
        int size;
        cin >> size;
        vector<int> in;
        int t;
        for (int j = 0; j < size; ++j)
        {
            cin >> t;
            in.push_back(t);
        }
        maxSum(in);
    }
    
	return 0;
}