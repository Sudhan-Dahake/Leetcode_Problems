#include <iostream>
#include <tuple>
#include <unordered_map>

class LRUCache {
    std::unordered_map<int, std::tuple<int, int>> umap;

    int size;

    int capacity;

    int element_count;

public:
    LRUCache(int capacity) {
        this->umap.clear();

        this->element_count = 0;

        this->size = 0;

        this->capacity = capacity;
    }

    int get(int key) {
        if (this->umap.find(key) == this->umap.end()) {
            return -1;
        };

        std::get<1>(this->umap[key]) = this->element_count;

        this->element_count++;

        return std::get<0>(this->umap[key]);
    }

    void put(int key, int value) {
        if (umap.find(key) != umap.end()) {
            std::get<0>(this->umap[key]) = value;

            std::get<1>(this->umap[key]) = this->element_count;

            this->element_count++;

            return;
        };

        if (this->size == this->capacity) {
            std::unordered_map<int, std::tuple<int, int>>::iterator it = this->umap.begin();

            int LRU_key = -1;

            int counter = INT_MAX;

            while (it != this->umap.end()) {
                if (std::get<1>(it->second) < counter) {
                    counter = std::get<1>(it->second);

                    LRU_key = it->first;
                };

                it++;
            };


            this->umap.erase(umap.find(LRU_key));

            this->size--;
        }


        this->umap[key] = std::make_tuple(value, this->element_count);

        this->size++;

        this->element_count++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



int main(void) {
    LRUCache* lRUCache = new LRUCache(2);

    lRUCache->put(2, 1);

    lRUCache->put(2, 2);

    std::cout << lRUCache->get(2) << std::endl;

    lRUCache->put(1, 1);

    lRUCache->put(4, 1);

    std::cout << lRUCache->get(2) << std::endl;
    
    return 0;
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */