#include "Bp-tree.cpp"
#include <thread>
#include "common/time.cpp"
using namespace std;

int main()
{
    Btree<int> db(100 * 1000);
    const int TX_MAX = 1000000;
    vector<int> args;
    int t = 1;
    auto f = [&](int tx_max, int tid)
    {
        for (int tx = 0; tx < tx_max; tx++)
        {
            for (int i = tid; i < 16 * t; i += t)
            {
                int n = args.at(i);
                if (db.Search(n))
                {
                    auto s = db.get_data(n);
                    db.change_data(n,"n"+to_string(tid));
                }
            }
        }
    };
    for (; t < 6; t++)
    {
        vector<thread> threads;
        db = Btree<int>(50);
        for (int i = 0; i <  1000;i++)
        {
            db.Insert(i);
            db.change_data(i, "n" + to_string(i));
        }
        args = vector<int>(16 * t);
        std::random_device seed_gen;
        std::mt19937 engine(seed_gen());
        std::uniform_int_distribution<> dis(0, 1*1000 * 1000 - 2);
        for (auto i : args)
        {
            i = dis(engine);
        }
        auto s = get_now();
        for (int i = 0; i < t; i++)
        {
            threads.emplace_back(f, TX_MAX / t, i);
        }
        for (int i = 0; i < t; i++)
        {
            threads[i].join();
        }
        auto e = get_now();
        float ms = get_duration_ms(s, e);
        int tp = 1.0 * TX_MAX * 1000 / ms;
        cout << fixed << t << "thread : " << tp << " throughtput(1s)" << endl;
    }
}