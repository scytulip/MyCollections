#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

/// Experimental Code
/// http://www.themianjing.com/2015/08/uber-%E7%94%B5%E9%9D%A2-3/

class ExpObj {
private:
    unordered_map<int, map<int, int>> store; //umap<key, map<time, value>>
public:
    void put(int key, int value, int time);
    int get(int key, int time);
};

void ExpObj :: put(int key, int value, int time)
{
    map<int, int> timeList;
    store[key][time] = value;
}

int ExpObj :: get(int key, int time)
{
    int i;

    if (store.find(key) ==  store.end()) return -1;

    map<int, int> timeList = store[key];
    map<int, int>::iterator it;

    for (it=timeList.begin(); it!=timeList.end(); it++)
    {
        if (it->first >= time) break;
    }

    if (it==timeList.begin()) return -1;
    it--;
    return it->second;
}

int main()
{
    ExpObj obj;

    obj.put(1, 255, 1000);
    obj.put(2, 1, 1001);
    obj.put(2, 3, 1008);
    obj.put(2, 0, 1000);
    obj.put(2, 2, 1001);

    cout << obj.get(2,1000) << endl;
    cout << obj.get(2,1001) << endl;
    cout << obj.get(2,1008) << endl;
    cout << obj.get(2,1010) << endl;
    cout << obj.get(1,999) << endl;
    cout << obj.get(1,1001) << endl;

    return 0;
}
