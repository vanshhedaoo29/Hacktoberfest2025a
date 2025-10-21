#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> calculateSpan(const vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);      
    stack<int> s;             

    for (int i = 0; i < n; i++) {
       
        while (!s.empty() && prices[s.top()] <= prices[i])
            s.pop();

        
        span[i] = (s.empty()) ? (i + 1) : (i - s.top());

        s.push(i);
    }
    return span;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter stock prices for " << n << " days:\n";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    vector<int> result = calculateSpan(prices);

    cout << "\nStock Span Values:\n";
    for (int i = 0; i < n; i++) {
        cout << "Day " << i + 1 << " (" << prices[i] << ") -> " << result[i] << endl;
    }

    return 0;
}
