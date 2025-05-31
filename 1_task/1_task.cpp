#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_set>
#include <algorithm>


struct Segment
{
    int begin;
    int end;
};

struct Event_points
{
    int coord;
    enum Type
    {
        OPENING,
        CLOSING
    } type;
    int seg_index;
};



bool operator<(const Segment& a, const Segment& b)
{
    if (a.begin != b.begin)
    {
        return a.begin < b.begin;
    }
    return a.end < b.end;
}

bool operator<(const Event_points& a, const Event_points& b)
{
    if (a.coord != b.coord)
    {
        return a.coord < b.coord;
    }
    if (a.type != b.type)
    {
        return a.type == Event_points::OPENING;
    }
    return a.seg_index < b.seg_index;
}


int solution(const std::vector<Segment>& seg_array)
{
    std::vector<Event_points> event_points(2 * seg_array.size());
    for (int i = 0; i < seg_array.size(); i++)
    {
        event_points[2 * i] = {seg_array[i].begin, Event_points::OPENING, i};
        event_points[2 * i + 1] = {seg_array[i].end, Event_points::CLOSING, i};
    }

    std::sort(event_points.begin(), event_points.end());

    std::unordered_set<int> opened_segments;
    int dots_number = 0;
    std::vector<bool> has_dot(seg_array.size(), false);


    for (const auto& event : event_points)
    {
        if (event.type == Event_points::OPENING)
        {
            opened_segments.insert(event.seg_index);
        }
        else
        {
            opened_segments.erase(event.seg_index);
            if (!has_dot[event.seg_index])
            {
                dots_number += 1;
                for (auto& i : opened_segments)
                {
                    has_dot[i] = true;;
                }
            }
        }
    }

    return dots_number;
}


int main()
{
    
    std::ifstream input("data_prog_contest_problem_1.txt");
    int n;
    input >> n;
    

    std::vector<Segment> seg_array(n);

    for (int i = 0; i < n; i++)
    {
        input >> seg_array[i].begin >> seg_array[i].end;
    }

    std::cout << "Answer : " << solution(seg_array) << std::endl;
    
}