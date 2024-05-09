#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num_semesters;
    cout << "Enter number of semesters: ";
    cin >> num_semesters;

    vector<int> max_marks(num_semesters);

    for (int i = 0; i < num_semesters; ++i) {
        int num_subjects;
        cout << "Enter number of subjects in semester " << i + 1 << ": ";
        cin >> num_subjects;

        int max_mark = -1;

        for (int j = 0; j < num_subjects; ++j) {
            int mark;
            cout << "Enter marks obtained in semester " << i + 1 << ", subject " << j + 1 << ": ";
            cin >> mark;

            if (mark >= 0 && mark <= 100) {
                if (mark > max_mark) {
                    max_mark = mark;
                }
            } else {
                cout << "Invalid mark entered." << endl;
                return 1;
            }
        }

        max_marks[i] = max_mark;
    }

    for (int i = 0; i < num_semesters; ++i) {
        cout << "Maximum mark in semester " << i + 1 << ": " << max_marks[i] << endl;
    }

    return 0;
}
