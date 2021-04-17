#include<iostream>
#include<vector>
#define LEN 11
using namespace std;

class HashSet{
private:
    vector<int> set[LEN];
    /**
     * return the bucket index
     * @param key
     * @return
     */
    int getBucket(int key){
        return key % LEN;
    }
    /**
     * get the position of the key in the bucket
     * @param key
     * @param bucket
     * @return
     */
    int getPosition(int key, int bucket){
        for(int i = 0;i < set[bucket].size(); i++){
            if (set[bucket][i] == key) return i;
        }
        return -1;
    }
public:
    HashSet(){}
    bool contains(int key){
        int bucket = getBucket(key);
        for(int i = 0;i < set[bucket].size(); i++){
            if (set[bucket][i] == key) return true;
        }
        return false;
    }
    void add(int key){
        if(contains(key)) cout << "the key already exists!" << endl;
        else set[getBucket(key)].push_back(key);
    }
    void remove(int key){
        if(contains(key)) {
            int bucket = getBucket(key);
            set[bucket].erase(set->begin() + getPosition(key, bucket));
        }
        else cout << "the key does not exists!" << endl;
    }
    void display(){
        for(auto & bucket : set){
            for(int i = 0 ;i < bucket.size();i++){
                cout << bucket[i] << "->";
            }
            cout << endl;
        }
    }
};
int main() {
    HashSet set;
    set.add(5);
    set.add(16);
    set.add(18);
    set.display();
    set.remove(2);
    set.remove(5);
    set.display();
    return 0;
}
