#include<iostream>
#include<vector>
#include<algorithm>
struct Meeting
{
    int start;
    int end;
};
bool compareMeetings(const Meeting& a, const Meeting& b)
{
    return a.end < b.end;
}
int maxMeetings(std::vector<Meeting> &meetings)
{
    if (meetings.empty())
    {
        return 0;
    }
    sort(meetings.begin(), meetings.end(), compareMeetings);
    int count = 1;
    int lastEndTime=meetings[0].end;
    std::cout<<"会议时间"<<meetings[0].start<<"-"<<meetings[0].end<<std::endl;
    for (int i = 1; i < meetings.size(); i++)
    {
        if (meetings[i].start> lastEndTime)
        {
            ++count;
            std::cout<<"会议时间"<<meetings[i].start<<"-"<<meetings[i].end<<std::endl;
            lastEndTime=meetings[i].end;
        }
    }
    return count;
}
int main()
{
    std::vector<Meeting> meetings={
    {1,4},
    {3,6},
    {9,0},
    {4,6},
    {5,7},
    {8,12},
    {8,11},
    {12,14},
    {18,22},
    {10,14}
    };
    int result=maxMeetings(meetings);
    std::cout<<"会议的最大安排数量"<<result<<std::endl;
    return 0;
}