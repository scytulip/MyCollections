class Solution {
public:
    int addDigits(int num) {
        if (num==0) 
            return 0;
        else
            return (num % 9==0) ? 9 : (num % 9);
		/*
		1 .. 9 self
		10 -> 1
		11 -> 2
		...
		18 -> 9
		19 -> 1
		20 -> 2
		...
		27 -> 9
		28 -> 1
		...
		Repeated periodically!
		*/
    }
};