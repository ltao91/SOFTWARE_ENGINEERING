#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v;
    for (int i = 0; i < 1000; i += 2)
    {
        v.push_back(i);
    }
    sort(v.begin(), v.end());
    auto binary = [&](int k)
    {
        // k以下の最大値
        int step = 0;
        int ok = 0, ng = v.size();
        while (abs(ok - ng) > 1)
        {
            step++;
            int mid = (ok + ng) / 2;

            cout << "mid : "<<v[mid] << endl;
            if (v[mid] <= k)
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        return v[ok]==k;
        cout << "step : " << step << endl;
    };
    cout<<binary(6)<<endl; //ある
    cout<<binary(9)<<endl; //ない
}