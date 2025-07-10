#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Meeting
{
    int start;
    int end;
};

bool compareMeetings(const Meeting& a, const Meeting& b)
{
    return a.end < b.end;
}

int maxMeetings(vector<Meeting>& meetings)
{
    if (meetings.empty())
    {
        return 0;
    }

    sort(meetings.begin(), meetings.end(), compareMeetings);
    int count = 1;
    int lastEndTime = meetings[0].end;
    cout << "会议时间: " << meetings[0].start << " - " << meetings[0].end << endl;
    for (int i = 1; i < meetings.size(); ++i)
    {
        if (meetings[i].start >= lastEndTime)
        {
            ++count;
            cout << "会议时间: " << meetings[i].start << " - " << meetings[i].end << endl;
            lastEndTime = meetings[i].end;
        }
    }
    return count;
}

int main()
{
    vector<Meeting> meetings = {
        {1, 4},
        {3, 5},
        {0, 6},
        {5, 7},
        {3, 9},
        {5, 9},
        {6, 10},
        {8, 11},
        {8, 12},
        {2, 14},
        {12, 16}
    };
    int result = maxMeetings(meetings);
    cout << "能够安排的最大会议数量是: " << result << endl;
    return 0;

}
