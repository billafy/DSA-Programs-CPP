#include<iostream>
using namespace std;

int refill(int stops[],int TC,int NS,int FD)
{
    int intervals[NS+1] = {};
    intervals[0] = stops[0];
    for(int i=1;i<NS+1;i++)
    {
        intervals[i] = stops[i] - stops[i-1];
    }
    intervals[NS] = FD-stops[NS-1];

    int num_refill = 0;
    int cur_tank = TC;
    int next_dist;

    for(int i=0;i<NS;i++)
    {
        cur_tank = cur_tank - intervals[i];
        next_dist = intervals[i+1];
        if(cur_tank < next_dist)
        {
            cur_tank = TC;
            num_refill++;
        }
        if(TC < next_dist)
        {
            return -1;
        }
        else
        {
            continue;
        }
    }
    return num_refill;
}

int main()
{
    int num_stops,tank_cap,final_distance;
    cin >> final_distance;
    cin >> tank_cap;
    cin >> num_stops;
    int stops[num_stops] = {};
    for(int i=0;i<num_stops;i++)
    {
        cin >> stops[i];
    }
    int result = refill(stops,tank_cap,num_stops,final_distance);
    cout << result << endl;
}
