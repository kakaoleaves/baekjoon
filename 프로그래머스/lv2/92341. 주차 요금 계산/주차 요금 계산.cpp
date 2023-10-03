#include <string>
#include <vector>
#include <map>

using namespace std;

int parkingFee(int parking_time, vector<int>& fees) {
    int basic_time = fees[0];
    int basic_fee = fees[1];
    int unit_time = fees[2];
    int unit_fee = fees[3];

    if (parking_time <= basic_time) return basic_fee;
    else {
        int exceeded_time = parking_time - basic_time;
        bool need_ceiling = (exceeded_time % unit_time > 0);
        exceeded_time /= unit_time;
        if (need_ceiling) exceeded_time++;
        return basic_fee + exceeded_time * unit_fee;
    }
    
} 

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int, less<>> parking_m;
    map<string, int, less<>> cumulative_m;
        
    for (const string& record : records) {
        int hour = stoi(record.substr(0, 2));
        int minute = stoi(record.substr(3, 2));
        string car_number = record.substr(6, 4);
        string info = record.substr(11);
                
        if (info == "IN") {
            parking_m[car_number] = hour * 60 + minute;
        } else {
            int exit = hour * 60 + minute;
            int entrance = parking_m[car_number];
            if (cumulative_m[car_number]) {
                cumulative_m[car_number] += exit - entrance;
            } else {
                cumulative_m[car_number] = exit - entrance;
            }
            parking_m.erase(car_number);
        }
    }
    
    for (auto iter = parking_m.begin(); iter != parking_m.end(); iter++) {
        int exit = 23 * 60 + 59;
        string car_number = (*iter).first;
        int entrance = (*iter).second;
        if (cumulative_m[car_number]) {
            cumulative_m[car_number] += exit - entrance;
        } else {
            cumulative_m[car_number] = exit - entrance;
        }
    }
    
    
    for (auto iter = cumulative_m.begin(); iter != cumulative_m.end(); iter++) {
        answer.push_back(parkingFee((*iter).second, fees));
    }
    
    return answer;
}