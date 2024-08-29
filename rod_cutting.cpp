#include <iostream>

using namespace std;

int rodCutting(int prices[], int length) {
    int n = sizeof(prices) / sizeof(prices[0]);
    int dp[length + 1];

    for (int i = 0; i <= length; ++i) {
        dp[i] = 0;
    }

    for (int i = 1; i <= length; ++i) {
        int max_value = 0;
        for (int j = 1; j <= i; ++j) {
            max_value = max(max_value, dp[i - j] + prices[j - 1]);
        }
        dp[i] = max_value;
    }

    return dp[length];
}

int main() {
    int n;
    cout << "Enter the number of rod lengths: ";
    cin >> n;

    int prices[n];
    cout << "Enter the prices for each length: ";
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    int length;
    cout << "Enter the length of the rod to cut: ";
    cin >> length;

    int max_value = rodCutting(prices, length);
    cout << "Maximum value obtained: " << max_value << endl;

    return 0;
}
