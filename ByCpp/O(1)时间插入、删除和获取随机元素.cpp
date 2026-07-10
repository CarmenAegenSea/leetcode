#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class RandomizedSet {
    vector<int> vals;
    unordered_map<int, int> pos;
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (pos.count(val)) return false;
        pos[val] = vals.size();
        vals.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!pos.count(val)) return false;
        int idx = pos[val];
        int last = vals.back();
        vals[idx] = last;
        pos[last] = idx;
        vals.pop_back();
        pos.erase(val);
        return true;
    }

    int getRandom() {
        return vals[rand() % vals.size()];
    }
};
