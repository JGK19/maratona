#include <iostream>
#include <queue>

using namespace std;

int get_sum(int x);

int main(void) {

    int N, K;
    cin >> N;
    cin >> K;

    priority_queue<int> flores;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        flores.push(x);
    }

    for (int i = 0; i < K-1; i++) {
        int flor = flores.top();
        int polem = get_sum(flor);
        flores.pop();
        flor = flor - polem;
        flores.push(flor);
    }

    cout << get_sum(flores.top());

    return 0;
}

int get_sum(int x) {
    int sum = 0;

    while (x != 0) {
        sum += x % 10;
        x = x/10;
    }
    return sum;
}