#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

bool majorityElement(int V[],int n)
{
    if(n%2==1)
    {
        int x = V[n/2];
        multiset<int> MTS;
        for(int i=0;i<n;i++)
        {
            MTS.insert(V[i]);
        }
        MTS.erase(x);
        if(MTS.size()<=n/2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        int x = V[n/2];
        multiset<int> MTS;
        for(int i=0;i<n;i++)
        {
            MTS.insert(V[i]);
        }
        MTS.erase(x);
        if(MTS.size()<n/2)
        {
            return true;
        }
        else
        {
            MTS.insert(x);
            int y = V[(n/2)+1];
            MTS.erase(y);
            if(MTS.size()<n/2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int V[n];
    for(int i=0;i<n;i++)
    {
        cin >> V[i];
    }
    sort(V,V+n);
    if(majorityElement(V,n)==true)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}
