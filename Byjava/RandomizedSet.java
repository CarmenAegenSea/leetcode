import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;

class RandomizedSet {
    private ArrayList<Integer> vals;
    private Map<Integer, Integer> pos;
    private Random rand;

    public RandomizedSet() {
        vals = new ArrayList<>();
        pos = new HashMap<>();
        rand = new Random();
    }

    public boolean insert(int val) {
        if (pos.containsKey(val)) return false;
        pos.put(val, vals.size());
        vals.add(val);
        return true;
    }

    public boolean remove(int val) {
        if (!pos.containsKey(val)) return false;
        int idx = pos.get(val);
        int last = vals.get(vals.size() - 1);
        vals.set(idx, last);
        pos.put(last, idx);
        vals.remove(vals.size() - 1);
        pos.remove(val);
        return true;
    }

    public int getRandom() {
        return vals.get(rand.nextInt(vals.size()));
    }
}
