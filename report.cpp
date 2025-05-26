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