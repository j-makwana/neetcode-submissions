class MyHashMap {
   private:
    vector<list<pair<int, int>>> custom_hp;

   public:
    MyHashMap() : custom_hp(1000) {}

    void put(int key, int value) {
        // when you are trying to put
        // hash the key
        int hash_val = key % custom_hp.size();
        auto& sl = custom_hp[hash_val];
        bool found = false;
        for (auto& element : sl) {
            if (element.first == key) {
                found = true;
                element.second= value;
                break;
            }
        }
        if (found) {
        } else {
            sl.push_back({key, value});
        }
    }

    int get(int key) {
        int hash_val = key % custom_hp.size();
        auto& sl = custom_hp[hash_val];
        bool found = false;
        for (auto& element : sl) {
            if (element.first == key) {
                found = true;
                return element.second;
            }
        }
            return -1;
    }

    void remove(int key) {
        int hash_val = key % custom_hp.size();
        auto& sl = custom_hp[hash_val];
        bool found = false;

        for (auto& element : sl) {
            if (element.first == key) {
                found = true;
                sl.remove(element);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */