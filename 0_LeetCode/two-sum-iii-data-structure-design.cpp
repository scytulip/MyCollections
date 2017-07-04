/*
170. Two Sum III - Data structure design My Submissions QuestionEditorial Solution
Total Accepted: 12551 Total Submissions: 52829 Difficulty: Easy
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false
*/

class TwoSum {
public:

    // Add the number to an internal data structure.
	void add(int number) {
        list<int>::iterator it = val.begin();
        while (it!=val.end() && (*it)<=number) ++it;
        val.insert(it, number);
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    if (val.empty()) return false;
	    
	    list<int>::iterator head, tail;
        head = val.begin(); 
        tail = val.end(); tail--;
        
        while (head!=tail) {
            while ((head!=tail) && (*head)+(*tail)>value) --tail;
            if (head!=tail) {
                if ((*head)+(*tail)==value) {
                    return true;
                }
                ++head;
            }
        }
        return false;
	}
	
private:
    list<int> val;
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);