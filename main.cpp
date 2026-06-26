#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

// =========================
// Convert Grade → Points
// =========================
int getGradePoint(char grade)
{
    grade = toupper(grade);

    switch (grade)
    {
        case 'A': return 10;
        case 'B': return 8;
        case 'C': return 6;
        case 'D': return 4;
        case 'F': return 0;
        default: return -1; // invalid
    }
}

// =========================
// Input Validation Function
// =========================
char inputGrade()
{
    char grade;

    while (true)
    {
        cout << "Enter Grade (A/B/C/D/F): ";
        cin >> grade;
        grade = toupper(grade);

        if (grade == 'A' || grade == 'B' || grade == 'C' ||
            grade == 'D' || grade == 'F')
        {
            return grade;
        }

        cout << "Invalid grade! Please enter A, B, C, D, or F only.\n";
    }
}

// =========================
// MAIN FUNCTION
// =========================
int main()
{
    int n;

    cout << "==============================\n";
    cout << "      CGPA CALCULATOR\n";
    cout << "==============================\n";

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

        grades[i] = inputGrade();

        cout << "Enter Credit Hours: ";
        cin >> credits[i];

        int gp = getGradePoint(grades[i]);

        totalCredits += credits[i];
        totalGradePoints += gp * credits[i];
    }

    // =========================
    // OUTPUT SECTION
    // =========================
    cout << "\n==============================\n";
    cout << "       COURSE SUMMARY\n";
    cout << "==============================\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Course " << i + 1
             << " | Grade: " << grades[i]
             << " | Credits: " << credits[i] << endl;
    }

    double gpa = (double)totalGradePoints / totalCredits;

    cout << "\n==============================\n";
    cout << "TOTAL CREDITS      : " << totalCredits << endl;
    cout << "TOTAL GRADE POINTS : " << totalGradePoints << endl;
    cout << "GPA / CGPA         : " << gpa << endl;
    cout << "NOTE: For single semester GPA = CGPA\n";
    cout << "==============================\n";

    return 0;
}
