#include <iostream>
#include <fstream>

using namespace std;

struct Student {
    string name;
    double grades[4];
    double average;
};

// تابع محاسبه معدل
double calculateAverage(double grades[], int numGrades) {
    double sum = 0;
    for (int i = 0; i < numGrades; i++) {
        sum += grades[i];
    }
    return sum / numGrades;
}

int main() {
    ifstream inputFile("students.txt");
    if (!inputFile) {
        cerr << "خطا در باز کردن فایل!" << endl;
        return 1;
    }

    Student students[1000]; 
    int studentCount = 0;
    double totalAverage = 0.0;

    while (studentCount < 1000 && inputFile >> students[studentCount].name) {
        for (int i = 0; i < 4; i++) {
            if (!(inputFile >> students[studentCount].grades[i])) {
                cerr << "خطا در خواندن نمرات!" << endl;
                return 1;
            }
        }

        students[studentCount].average = calculateAverage(students[studentCount].grades, 4);
        totalAverage += students[studentCount].average;
        studentCount++;
    }

    inputFile.close();

    for (int i = 0; i < studentCount; i++) {
        cout << "نام: " << students[i].name << ", معدل: " << students[i].average << endl;
    }

    if (studentCount > 0) {
        totalAverage /= studentCount;
        cout << "\nمعدل کل دانشجویان: " << totalAverage << endl;
    }

    return 0;
}
