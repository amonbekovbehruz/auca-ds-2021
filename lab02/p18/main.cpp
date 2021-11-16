#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    for (int courses; cin >> courses && courses != 0;)
    {
        int categories;
        cin >> categories;

        vector<int> courseCodes(courses);

        for (auto &code : courseCodes)
        {
            cin >> code;
        }

        sort(begin(courseCodes), end(courseCodes));

        bool isDone = true;

        for (int i = 0; i < categories; ++i)
        {

            int categoriesCourses;
            cin >> categoriesCourses;

            int minCourse;

            cin >> minCourse;

            int courseTaken = 0;

            for (int j = 0; j < categoriesCourses; ++j)
            {
                int course;
                cin >> course;

                courseTaken += binary_search(begin(courseCodes), end(courseCodes), course);
            }

            if (courseTaken < minCourse)
            {
                isDone = false;
            }
        }
        cout << (isDone ? "yes\n" : "no\n");
    }
}