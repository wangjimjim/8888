#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float num[10];
    float max_num = -1e9, min_num = 1e9;


    for (int i = 0; i < 10; i++) {
        cin >> num[i];
        max_num = max(max_num, num[i]); 
        min_num = min(min_num, num[i]); 
    }


    cout << "Max: " << fixed << setprecision(2) << max_num << endl;
    cout << "Min: " << fixed << setprecision(2) << min_num << endl;

    return 0;
}

