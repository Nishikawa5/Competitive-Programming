#include <iostream>
#include <queue>

using namespace std;


class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        // the priority queue is like an array that is always sorted
        priority_queue<int> stonespq(begin(stones), end(stones));

        while (stonespq.size() > 1)
        {
            // so we can store the values of the last two stones
            int heaviest = stonespq.top();
            stonespq.pop();
            int secondheaviest = stonespq.top();
            stonespq.pop();

            // and break them to each other
            // stores the value of the difference if the difference is different of 0
            if (heaviest > secondheaviest) stonespq.push(heaviest - secondheaviest);
        }
        // empty means the last two stones broke to each other and were the same weight
        // not empty means lasts one stone
        return stonespq.empty() ? 0 : stonespq.top();
    }
};



// very bad solution
class Solution2 {
public:
    // given a number of people, return the winner of the game
    // the game is: starting from 1, jumps k - 1 people and eliminate where the jump ends
    int findTheWinner(int n, int k) {
        // for this problem, we can use queue (very slow)
        queue<int> circle;
        
        // first, we put every number in order
        for (int i = 1; i <= n; i++)
        {
            circle.push(i);
        }

        // then we iterate, eliminating the number and changing order
        int i = 0;
        while (circle.size() != 1)
        {
            i++;
            if (i % k != 0)
            {
                // the first of the queue goes to the last
                int temp = circle.front();
                circle.pop();
                circle.push(temp);
            }
            else 
            {
                // eliminate i % k
                circle.pop();
            }
        }
        return circle.front();
    }
};