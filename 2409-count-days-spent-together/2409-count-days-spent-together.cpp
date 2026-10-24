class Solution {
private:
    const int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int dateToDayOfYear(string dateStr) {
        int month = stoi(dateStr.substr(0, 2));
        int day = stoi(dateStr.substr(3, 2));
        
        int dayCount = 0;
        for (int i = 0; i < month - 1; ++i) {
            dayCount += daysInMonths[i];
        }
        return dayCount + day;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startAlice = dateToDayOfYear(arriveAlice);
        int endAlice = dateToDayOfYear(leaveAlice);
        int startBob = dateToDayOfYear(arriveBob);
        int endBob = dateToDayOfYear(leaveBob);
        
        int overlapStart = max(startAlice, startBob);
        int overlapEnd = min(endAlice, endBob);
        
        return max(0, overlapEnd - overlapStart + 1);
    }
};
