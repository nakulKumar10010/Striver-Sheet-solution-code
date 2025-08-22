// Define a structure to hold meeting details
struct Meeting {
    int start, end;
};

// Comparator function to sort meetings based on end time (ascending)
bool compare(Meeting a, Meeting b) {
    return a.end < b.end;
}

class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        
        // Step 1: Store meetings in a vector of Meeting structs
        vector<Meeting> meetings(n);
        for (int i = 0; i < n; i++) {
            meetings[i].start = start[i];
            meetings[i].end = end[i];
        }
        
        // Step 2: Sort meetings by their end times (earliest ending first)
        sort(meetings.begin(), meetings.end(), compare);
        
        // Step 3: Initialize count of meetings and track last meeting end time
        int count = 0;
        int lastMeetingTime = -1;  // Initially, no meeting is scheduled
        
        // Step 4: Iterate through sorted meetings
        for (int i = 0; i < n; i++) {
            // If current meeting starts after the last selected meeting ended
            if (lastMeetingTime < meetings[i].start) {
                count++; // Include this meeting
                lastMeetingTime = meetings[i].end; // Update last meeting end time
            }
        }
        
        // Step 5: Return the maximum number of meetings that can be scheduled
        return count;
    }
};
