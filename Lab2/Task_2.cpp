// #include <iostream>
// #include <iomanip>
// #include <algorithm>
// #include <locale>
//
// using namespace std;
//
// class Student
// {
// public:
//     string Surname;
//     string Name;
//     string DateOfBirth;
//     string PhoneNumber;
//
//     void setStudent(string SN, string N, string DB, string PN)
//     {
//         Surname = SN;
//         Name = N;
//         DateOfBirth = DB;
//         PhoneNumber = PN;
//     }
//
//     void showStudent() const
//     {
//         cout << left << setw(20) << Surname
//             << left << setw(15) << Name
//             << left << setw(20) << DateOfBirth
//             << left << setw(15) << PhoneNumber << endl;
//     }
// };
//
// class StudentGroup
// {
// private:
//     const int maxSize = 100;
//     Student students[100];
//     int numberOfStudents;
//
// public:
//     StudentGroup() : numberOfStudents(0)
//     {
//     }
//
//     void addStudent(const Student& newStudent)
//     {
//         if (numberOfStudents < maxSize)
//         {
//             students[numberOfStudents++] = newStudent;
//         }
//         else
//         {
//             cout << "Error: Unable to add a new student. Group size limit reached." << endl;
//         }
//     }
//
//     void removeStudent(const string& surname)
//     {
//         Student* it = nullptr;
//
//         for (Student* i = students; i != students + numberOfStudents; ++i)
//         {
//             if (i->Surname == surname)
//             {
//                 it = i;
//                 break;
//             }
//         }
//
//         if (it != nullptr)
//         {
//             *it = students[--numberOfStudents];
//         }
//         else
//         {
//             cout << "Student with the surname " << surname << " not found." << endl;
//         }
//     }
//
//     Student findStudentBySurname(const string& surname) const
//     {
//         const Student* it = nullptr;
//
//         for (const Student* i = students; i != students + numberOfStudents; ++i)
//         {
//             if (i->Surname == surname)
//             {
//                 it = i;
//                 break;
//             }
//         }
//
//         if (it != nullptr)
//         {
//             return *it;
//         }
//         else
//         {
//             return Student{};
//         }
//     }
//
//     void sortStudentsBySurname()
//     {
//         sort(students, students + numberOfStudents,
//              [](const Student& a, const Student& b)
//              {
//                  return a.Surname < b.Surname;
//              });
//     }
//
//     void displayAllStudents() const
//     {
//         if (students == nullptr || students->Surname.empty())
//         {
//             cout << "No students in the group." << endl;
//             return;
//         }
//         
//         cout << left << setw(20) << "Surname"
//             << left << setw(15) << "Name"
//             << left << setw(20) << "Date of Birth"
//             << left << setw(15) << "Phone Number" << endl;
//
//         for (int i = 0; i < numberOfStudents; ++i)
//         {
//             students[i].showStudent();
//         }
//     }
// };
//
// void printMenu()
// {
//     cout << "Menu:" << endl;
//     cout << "1. Add a student" << endl;
//     cout << "2. Remove a student" << endl;
//     cout << "3. Find a student by surname" << endl;
//     cout << "4. Sort students by surname" << endl;
//     cout << "5. Display all students" << endl;
//     cout << "0. Exit" << endl;
//     cout << "Select an action: ";
// }
//
// int main()
// {
//     StudentGroup group;
//
//     while (true)
//     {
//         printMenu();
//
//         int choice;
//         cin >> choice;
//
//         switch (choice)
//         {
//         case 1:
//             {
//                 cout << "Enter student information:" << endl;
//                 string surname, name, dateOfBirth, phoneNumber;
//                 cout << "Surname: ";
//                 cin >> surname;
//                 cout << "Name: ";
//                 cin >> name;
//                 cout << "Date of Birth: ";
//                 cin >> dateOfBirth;
//                 cout << "Phone Number: ";
//                 cin >> phoneNumber;
//
//                 Student newStudent;
//                 newStudent.setStudent(surname, name, dateOfBirth, phoneNumber);
//                 group.addStudent(newStudent);
//                 break;
//             }
//         case 2:
//             {
//                 cout << "Enter the surname of the student to remove: ";
//                 string surname;
//                 cin >> surname;
//                 group.removeStudent(surname);
//                 break;
//             }
//         case 3:
//             {
//                 cout << "Enter the surname of the student to find: ";
//                 string surname;
//                 cin >> surname;
//
//                 Student foundStudent = group.findStudentBySurname(surname);
//                 if (!foundStudent.Surname.empty())
//                 {
//                     cout << "\nFound student:\n";
//                     foundStudent.showStudent();
//                 }
//                 else
//                 {
//                     cout << "Student with the surname " << surname << " not found." << endl;
//                 }
//                 break;
//             }
//         case 4:
//             group.sortStudentsBySurname();
//             cout << "Students sorted by surname." << endl;
//             break;
//         case 5:
//             group.displayAllStudents();
//             break;
//         case 0:
//             cout << "Exiting the program." << endl;
//             return 0;
//         default:
//             cout << "Invalid input. Please choose again." << endl;
//             break;
//         }
//     }
//     return 0;
// }
