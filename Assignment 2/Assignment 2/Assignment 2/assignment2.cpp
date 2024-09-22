#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct STUDENT_DATA {
    string firstName;
    string lastName;
    string email;
};

vector<STUDENT_DATA> readStudentData() {
    vector<STUDENT_DATA> students; //store students in a vector
    string line;    

#ifdef PRE_RELEASE
    ifstream file("StudentData_Emails.txt");
    cout << "Running in pre-release source code" << endl;

    // Read each line of the file
    while (getline(file, line)) {
        stringstream ss(line);
        string firstName, lastName, email;

        // Split the line by comma to get first, last names and email
        if (getline(ss, firstName, ',') && getline(ss, lastName, ',') && getline(ss, email)) {
            // if the names and email were read it will create a student data object
            // and add it to the students vector
            STUDENT_DATA student = { firstName, lastName, email };
            students.push_back(student);
        }
        else {
            cout << "Error!" << endl;
        }
    }

#else 

    ifstream file("StudentData.txt");

    cout << "Running in standard source code" << endl;
    // Read each line of the file
    while (getline(file, line)) {
        stringstream ss(line);
        string firstName, lastName;

        // Split the line by comma to get first and last names
        if (getline(ss, firstName, ',') && getline(ss, lastName)) {
            // if both names were read it will create a student data object
            // and add it to the students vector
            STUDENT_DATA student = { firstName, lastName };
            students.push_back(student);
        }
        else {
            cout << "Error!" << endl;
        }
    }


#endif 
    file.close();
    return students;
}

int main(void) {
    // storing the return vector from read student data into students
    vector<STUDENT_DATA> students = readStudentData();

    // Print students data 
    for (int i = 0; i < students.size(); ++i) {

#ifdef PRE_RELEASE

     cout << "First Name: " << students[i].firstName << ", Last Name: " << students[i].lastName << ", Email: " << students[i].email << endl;

#else 
     cout << "First Name: " << students[i].firstName << ", Last Name: " << students[i].lastName << endl;

#endif // PRE_RELEASE

    }

	return 0;
}