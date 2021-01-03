#include<bits/stdc++.h>

using namespace std;
using namespace std::literals::chrono_literals;

int numberOfRefills(vector<int> station,int tank)
{
    int cur_tank=tank,refill=0;
    for(int i=1;i<station.size();++i)
    {
        int diff = station[i]-station[i-1];
        this_thread::sleep_for(3s);
        cout << "Current tank : " << cur_tank << "..." << endl;
        if(diff<=cur_tank)
        {
            cur_tank -= diff;
        }
        else if(tank>=diff)
        {
            cur_tank = tank;
            cur_tank -= diff;
            ++refill;
            cout << "Refilled" << endl;
        }
        else
            return -1;
    }
    return refill;
}

int main()
{
    int N;
    cin >> N;
    vector<int> station(N);
    for(int i=0;i<N;++i)
        cin >> station[i];
    int tank;
    cin >> tank;
    int refill = numberOfRefills(station,tank);
    cout << "Number of refills needed : " << refill;
}
