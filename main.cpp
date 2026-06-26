#include <iostream>
#include <vector>
using namespace std;

// Convert grade to points
int getGradePoint(char grade)
{
    switch (grade)
    {
        case 'A': return 10;
        case 'B': return 8;
        case 'C': return 6;
        case 'D': return 4;
        case 'F': return 0;
        default: return 0;
    }
}

int main()
{
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    vector<char> grades(n);
    vector<int> credits(n);

    int totalCredits = 0;
    int totalGradePoints = 0;

    cout << "\nEnter course details:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nCourse " << i + 1 << ":\n";

        cout << "Grade (A/B/C/D/F): ";
        cin >> grades[i];

        cout << "Credit Hours: ";
        cin >> credits[i];

        int gradePoint = getGradePoint(grades[i]);

        totalCredits += credits[i];
        totalGradePoints += gradePoint * credits[i];
    }

    cout << "\n==============================\n";
    cout << "COURSE SUMMARY\n";
    cout << "==============================\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Course " << i + 1
             << " | Grade: " << grades[i]
             << " | Credits: " << credits[i] << endl;
    }

    double gpa = (double)totalGradePoints / totalCredits;

    cout << "\n==============================\n";
    cout << "TOTAL CREDITS: " << totalCredits << endl;
    cout << "TOTAL GRADE POINTS: " << totalGradePoints << endl;
    cout << "GPA / CGPA: " << gpa << endl;
    cout << "==============================\n";

    return 0;
}
