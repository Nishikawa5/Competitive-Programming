#include <bits/stdc++.h>
using namespace std;

/*
what is the maximum intersections we have at same time?
*/
int main() {
    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> rooms(n);
    for (int i = 0; i < n; i++) {
        cin >> rooms[i].first.first >> rooms[i].first.second;
        rooms[i].second = i;
    }
    sort(rooms.begin(), rooms.end());

    int max_rooms = 0;
    priority_queue<pair<int, int>> min_heap;
    vector<int> room_type(n);
    for (int i = 0; i < n; i++) {
        if (min_heap.empty()) {
            min_heap.push({-rooms[i].first.second, 1});
            room_type[rooms[i].second] = 1;
        } else {
            if (-min_heap.top().first < rooms[i].first.first) {
                // this event ended so make it the room of this
                pair<int, int> curr_room = min_heap.top();
                room_type[rooms[i].second] = curr_room.second;
                min_heap.pop();
                min_heap.push({-rooms[i].first.second, curr_room.second});
            } else {
                min_heap.push({-rooms[i].first.second, min_heap.size() + 1});
                room_type[rooms[i].second] = min_heap.size();
            }
        }

        max_rooms = max(max_rooms, (int) min_heap.size()); 
    }

    cout << max_rooms << endl;
    for (int i = 0; i < n; i++) {
        cout << room_type[i] << " ";
    }
    cout << endl;
}