#include<bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> nums,int T)
{
    int left=0,right=nums.size()-1,index = 0;
    if(T<nums[0])
        return 0;
    if(T>nums[nums.size()-1])
        return nums.size();
    while(left<=right)
    {
        int mid = (left+right)/2;
        if(nums[mid]==T)
        {
            index = mid;
            break;
        }
        else if(nums[mid]<T)
        {
            if(mid+1<nums.size())
            {
                if(nums[mid+1]>T)
                {
                    index = mid+1;
                    break;
                }
            }
            left = mid+1;
        }
        else
        {
            if(mid-1>=0)
            {
                if(nums[mid-1]<T)
                {
                    index =  mid;
                    break;
                }
            }
            right = mid-1;
        }
    }
    return index;
}

int main()
{
    int N,target;
    cin >> N >> target;
    vector<int> A(N);
    for(int i=0;i<N;++i)
        cin >> A[i];
    cout << binarySearch(A,target);
}
