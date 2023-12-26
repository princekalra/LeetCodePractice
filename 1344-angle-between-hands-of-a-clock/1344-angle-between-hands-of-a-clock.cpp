class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour%=12;
        double newHour = hour*(30.0) + (0.5)*minutes;
        double newMinutes = minutes*(6.0);
        cout<<newHour<<" "<<newMinutes<<endl;
        double sol = abs(newHour-newMinutes);
        sol = min(sol,360.0-sol);
        return sol;
    }
};