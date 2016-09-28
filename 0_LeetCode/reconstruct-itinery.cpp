class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        tk = tickets;
        size = tk.size();
        sort(tk.begin(), tk.end(), LessKey);
        
        // Build index JFK->1,2,3... AFC-> 6,7...
        string key = "";
        for (int i=0; i<tk.size(); ++i) {
            if (tk[i].first != key) {
                key = tk[i].first;
                index[key] = i;
            }
        }
        
        // Start searching
        finished = false;
        FindNext("JFK");
        
        return rt_val;
    }
private:
    unordered_map<string, int> index;
    vector<pair<string, string>> tk;
    unordered_set<int> used;
    vector<int> track;
    vector<string> rt_val;
    bool finished;
    int size;

    static bool LessKey(const pair<string, string>& a, const pair<string, string>& b) {
        if (a.first=="JFK") {
            if (b.first=="JFK")
                return a.second<b.second;
            else
                return true;
        } else {
            if (b.first=="JFK")
                return false;
            else if (a.first==b.first)
                return a.second<b.second;
            else
                return a.first<b.first;
        }
    }
    
    void FindNext(string key) {
        if (used.size()==size) {
            // Processing the output sequence
            finished = true;
            rt_val.push_back("JFK");
            for (auto i : track) rt_val.push_back(tk[i].second);
            return;
        }
        
        int i = index[key];
        while(i<size && tk[i].first == key) {
            if (used.find(i)==used.end()) {
                // Pick and add an edge
                used.insert(i);
                track.push_back(i);
                FindNext(tk[i].second);
                if (finished) break;
                track.pop_back();
                used.erase(i);
            }
            ++i;
        }
    }
};