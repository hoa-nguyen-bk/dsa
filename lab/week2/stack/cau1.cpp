#include <iostream>
#include <stack>
using namespace std;
int baseballScore(string ops) {
    stack<int> scores;
    for (char c : ops) {
        if (c == 'C') {
            scores.pop(); // remove the previous score
        } else if (c == 'D') {
            int prevScore = scores.top();
            scores.push(2 * prevScore); // add a new score that is double the previous score
        } else if (c == '+') {
            int prevScore1 = scores.top(); scores.pop();
            int prevScore2 = scores.top();
            scores.push(prevScore1); // add back the previous score
            scores.push(prevScore1 + prevScore2); // add a new score that is the sum of the previous two scores
        } else {
            int score = c - '0';
            scores.push(score); // add a new score
        }
    }
    int sum = 0;
    while (!scores.empty()) {
        sum += scores.top(); scores.pop();
    }
    return sum;
}

int main()
{
  cout << baseballScore("52CD+");
// 30
  return 0;
}
