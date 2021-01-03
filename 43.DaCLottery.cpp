#include<bits/stdc++.h>

using namespace std;

typedef long long huge;

class Segment
{
public :
    huge a;
    huge b;

    Segment() : a(0),b(0) {}
    Segment(huge x,huge y) : a(x),b(y) {}
};

huge bsearch(Segment temp[],huge ticket,huge left,huge right,huge count)
{
    if(left>right)
        return count;
    huge mid = (left+right)/2;
    if(ticket >= temp[mid].a && ticket<=temp[mid].b)
    {
        count++;
    }
    bsearch(temp,ticket,left,mid-1,count);
    bsearch(temp,ticket,mid+1,right,count);
}

huge lottery(Segment S[],huge ticket,huge left,huge right)
{
    huge count = 0;
    Segment temp[right+1];
    for(huge i=0;i<right+1;i++)
    {
        temp[i] = S[i];
    }
    bsearch(temp,ticket,left,right,count);
}

bool Compare(Segment S1,Segment S2)
{
    if(S1.a == S2.a)
    {
        return S1.b > S2.b;
    }
    else
    {
        return S1.a > S2.a;
    }

}

int main()
{
    huge s,p; // s : number of segments // p : number of people
    cin >> s >> p;
    Segment S[s];
    for(huge i=0;i<s;i++)
    {
        cin >> S[i].a >> S[i].b;
    }
    sort(S,S+s,Compare);
    huge P[p];
    for(huge i=0;i<p;i++)
    {
        cin >> P[i];
    }
    for(huge i=0;i<p;i++)
    {
        cout << lottery(S,P[i],0,s-1) << " ";
    }
}
