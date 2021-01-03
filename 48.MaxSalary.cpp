// Given an array of numbers, program to arrange the numbers to form the
// largest number
#include<sstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int myCompare(string X, string Y)
{
	string XY = X.append(Y);
	string YX = Y.append(X);

	return XY.compare(YX) > 0 ? 1: 0;
}

string largestNumber(vector<string> arr)
{
	sort(arr.begin(), arr.end(), myCompare);
    stringstream LN;
	for (int i=0; i < arr.size() ; i++ )
		LN << arr.at(i);
    string result;
    LN >> result;
    return result;
}

int main()
{
	int n;
	cin >> n;
	vector<string> arr(n);
	for(int i=0;i<n;i++)
    {
        cin >> arr.at(i);
    }
    cout << largestNumber(arr)<<endl;

return 0;
}
