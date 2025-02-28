#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start, end;
};

// Comparator function to sort activities by end time
bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

int main() {
    int n;

    cout << "Enter number of activities: ";
    cin >> n;

    Activity activities[n];

    cout << "Enter start and end times of activities:\n";
    for (int i = 0; i < n; i++) {
        cout << "Activity " << i + 1 << " (start end): ";
        cin >> activities[i].start >> activities[i].end;
    }

    // Sort activities by end time
    sort(activities, activities + n, compare);

    cout << "\nSelected activities are:\n";
    int count = 1;
    cout << "Activity 1 (Start: " << activities[0].start << ", End: " << activities[0].end << ")\n";

    int last_end = activities[0].end;

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= last_end) {
            count++;
            cout << "Activity " << i + 1 << " (Start: " << activities[i].start << ", End: " << activities[i].end << ")\n";
            last_end = activities[i].end;
        }
    }

    cout << "\nMaximum number of non-overlapping activities: " << count << endl;

    return 0;
}
