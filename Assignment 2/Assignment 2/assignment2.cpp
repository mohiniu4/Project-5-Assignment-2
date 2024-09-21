#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct STUDENT_DATA {
    string firstName;
    string lastName;
};

vector<STUDENT_DATA> readStudentData(string fileName) {
    ifstream file(fileName);
    vector<STUDENT_DATA> students; //store students in a vector
    string line;    

    // Read each line of the file
    while (getline(file, line)) {
        stringstream ss(line);
        string firstName, lastName;

        // Split the line by comma to get first and last names
        if (getline(ss, firstName, ',') && getline(ss, lastName)) {
            // if both names were read well it will create a student data object
            // and add it to the students vector
            STUDENT_DATA student = { firstName, lastName };
            students.push_back(student);
        }
        else {
            cout << "Error!" << endl;
        }
    }

    file.close();
    return students;
}

int main(void) {
    // storing the return vector from read student data into students
    vector<STUDENT_DATA> students = readStudentData("StudentData.txt");

    // Print students data 
    for (int i = 0; i < students.size(); ++i) {
        cout << "First Name: " << students[i].firstName << ", Last Name: " << students[i].lastName << endl;
    }

	return 0;
}