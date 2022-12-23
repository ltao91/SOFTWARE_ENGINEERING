#include "Bp-tree.cpp"
#include <thread>
#include "common/time.cpp"
using namespace std;

int main()
{
    Btree<int> db;
    const int TX_MAX = 10000000;
    vector<int> args;
    int t = 1;
    vector<int> conflict;
    auto f = [&](int tid)
    {
        for (int i = tid; i < TX_MAX; i += t)
        {
            int n = args.at(i);
            if (db.Search(n))
            {
                string key = "n" + to_string(tid);
                while (!db.change_data(n, key))
                {
                    conflict[tid]++;
                    // cout << "waiting" << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(10));
                }
            }
        }
    };
    for (; t < 6; t++)
    {
        vector<thread> threads;
        db = Btree<int>(50);
        conflict=vector<int>(100);
        for (int i = 0; i < 100; i++)
        {
            db.Insert(i);
            db.change_data(i, "n" + to_string(i));
        }
        args = vector<int>(TX_MAX);
        std::random_device seed_gen;
        std::mt19937 engine(seed_gen());
        std::uniform_int_distribution<> dis(0, 100);
        for (auto i : args)
        {
            i = dis(engine);
        }
        auto s = get_now();
        for (int i = 0; i < t; i++)
        {
            threads.emplace_back(f, i);
        }
        for (int i = 0; i < t; i++)
        {
            threads[i].join();
        }
        auto e = get_now();
        float ms = get_duration_ms(s, e);
        int tp = 1.0 * TX_MAX * 1000 / ms;
        cout << fixed << t << "thread : " << tp << " throughtput(1s)" << endl;
        int confs=0;
        for(auto i:conflict){
            confs+=i;
        }
        cout<<"    conflicts : "<<confs<<endl;
    }
}