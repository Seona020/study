#include <iostream>
using namespace std;

int main() {
    int num, evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;

    while (cin >> num && num != 0) {
        if (num % 2 == 0) {
            evenCount++; evenSum += num;
        }
        else {
            oddCount++; oddSum += num;
        }
    }

    double evenAvg = (evenCount ? (double)evenSum / evenCount : 0);
    double oddAvg = (oddCount ? (double)oddSum / oddCount : 0);

    cout << evenCount << " " << (evenAvg == (int)evenAvg ? (int)evenAvg : evenAvg) << " ";
    cout << oddCount << " " << (oddAvg == (int)oddAvg ? (int)oddAvg : oddAvg) << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string input, allText;
    while (true) {
        getline(cin, input);
        size_t found = input.find('&');
        if (found != string::npos) {
            allText += input.substr(0, found);
            break;
        }
        allText += input + " ";
    }

    // 전부 소문자로 변환
    transform(allText.begin(), allText.end(), allText.begin(), ::tolower);

    // "oop" 찾기
    int count = 0;
    for (size_t i = 0; i + 2 < allText.size(); i++) {
        if (allText.substr(i, 3) == "oop") {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
