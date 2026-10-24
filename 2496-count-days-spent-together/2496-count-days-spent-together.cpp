class Solution {
public:
    int dateToDays(const string& date) {
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        
        int totalDays = 0;
        for (int i = 0; i < month - 1; ++i) {
            totalDays += daysInMonth[i];
        }
        totalDays += day;
        
        return totalDays;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arriveA = dateToDays(arriveAlice);
        int leaveA = dateToDays(leaveAlice);
        int arriveB = dateToDays(arriveBob);
        int leaveB = dateToDays(leaveBob);
        
        int overlapStart = max(arriveA, arriveB);
        int overlapEnd = min(leaveA, leaveB);
        
        if (overlapStart <= overlapEnd) {
            return overlapEnd - overlapStart + 1;
        }
        return 0;
    }
};