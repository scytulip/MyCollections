class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i=0; i<words.size(); ++i) 
            wmap[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        list<int>::iterator it1 = wmap[word1].begin();
        list<int>::iterator it2 = wmap[word2].begin();
        int distance = INT_MAX;
        while (it1 != wmap[word1].end() && it2 != wmap[word2].end()) {
            distance = min(distance, abs(*it1-*it2));
            if (*it1 < *it2)
                ++ it1;
            else
                ++ it2;
        }
        return distance;
    }
private:
    unordered_map<string, list<int>> wmap;
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");