#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    string s;
    getline(cin, s); 


    transform(s.begin(), s.end(), s.begin(), ::tolower);


    int freq[26] = {0};

    int wordCount = 0; 

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ' || s[i] == ',' || s[i] == '.') {

            wordCount++;
        } else {
            freq[s[i] - 'a']++;
        }
    }


    wordCount++;

    cout << wordCount << endl;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            cout << (char)('a' + i) << " " << freq[i] << endl;
        }
    }

    return 0;
}

