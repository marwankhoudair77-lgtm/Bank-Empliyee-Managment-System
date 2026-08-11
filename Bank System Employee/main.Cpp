#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int MAX_EMPLOYEES = 50;

struct Employee
{
    int id;
    int age;
    string name;
    string job;
    string department;
    double salary;
};

Employee employees[MAX_EMPLOYEES] =
{
    {101, 25, "Ahmed", "Software Engineer", "IT", 15000},
    {102, 30, "Ali", "Accountant", "Finance", 12000},
    {103, 27, "Mona", "HR Specialist", "HR", 10000},
    {104, 35, "Omar", "Loan Officer", "Loans", 13000},
    {105, 24, "Sara", "Customer Service", "Customer Service", 9000},
    {106, 29, "Khaled", "Network Engineer", "IT", 14000},
    {107, 32, "Nour", "Financial Analyst", "Finance", 16000},
    {108, 26, "Youssef", "HR Coordinator", "HR", 9500},
    {109, 38, "Hassan", "Credit Officer", "Loans", 14500},
    {110, 28, "Salma", "Customer Service", "Customer Service", 10000},
    {111, 31, "Mahmoud", "Backend Developer", "IT", 18000},
    {112, 34, "Aya", "Senior Accountant", "Finance", 15500},
    {113, 25, "Menna", "Recruiter", "HR", 11000},
    {114, 40, "Tarek", "Loan Manager", "Loans", 19000},
    {115, 27, "Hana", "Customer Service", "Customer Service", 10500},
    {116, 33, "Mostafa", "Cyber Security Engineer", "IT", 20000},
    {117, 29, "Rania", "Financial Auditor", "Finance", 17000},
    {118, 36, "Eman", "HR Manager", "HR", 17500},
    {119, 41, "Adel", "Credit Manager", "Loans", 21000},
    {120, 30, "Dina", "Customer Service Manager", "Customer Service", 16000}
};

int employeeCount = 20;

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void showAllEmployees()
{
    cout << "\n========== ALL EMPLOYEES ==========\n";

    for (int i = 0; i < employeeCount; i++)
    {
        cout << "\nEmployee #" << i + 1 << endl;
        cout << "ID         : " << employees[i].id << endl;
        cout << "Name       : " << employees[i].name << endl;
        cout << "Age        : " << employees[i].age << endl;
        cout << "Job        : " << employees[i].job << endl;
        cout << "Department : " << employees[i].department << endl;
        cout << "Salary     : " << employees[i].salary << endl;
        cout << "----------------------------------\n";
    }
}

void addEmployee()
{
    if (employeeCount >= MAX_EMPLOYEES)
    {
        cout << "\nEmployee array is full!\n";
        return;
    }

    Employee newEmployee;

    cout << "\n========== ADD NEW EMPLOYEE ==========\n";

    cout << "Enter ID: ";
    while (!(cin >> newEmployee.id))
    {
        cout << "Invalid ID. Enter a number: ";
        clearInput();
    }

    clearInput();

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == newEmployee.id)
        {
            cout << "This ID already exists.\n";
            return;
        }
    }

    cout << "Enter Name: ";
    getline(cin, newEmployee.name);

    while (newEmployee.name.empty())
    {
        cout << "Name cannot be empty. Enter Name: ";
        getline(cin, newEmployee.name);
    }

    cout << "Enter Age: ";
    while (!(cin >> newEmployee.age) || newEmployee.age <= 0)
    {
        cout << "Invalid age. Enter a positive number: ";
        clearInput();
    }

    clearInput();

    cout << "Enter Job: ";
    getline(cin, newEmployee.job);

    while (newEmployee.job.empty())
    {
        cout << "Job cannot be empty. Enter Job: ";
        getline(cin, newEmployee.job);
    }

    cout << "Enter Department: ";
    getline(cin, newEmployee.department);

    while (newEmployee.department.empty())
    {
        cout << "Department cannot be empty. Enter Department: ";
        getline(cin, newEmployee.department);
    }

    cout << "Enter Salary: ";
    while (!(cin >> newEmployee.salary) || newEmployee.salary < 0)
    {
        cout << "Invalid salary. Enter a valid number: ";
        clearInput();
    }

    employees[employeeCount] = newEmployee;
    employeeCount++;

    cout << "\nEmployee added successfully!\n";
}

void searchEmployee()
{
    int id;

    cout << "\n========== SEARCH EMPLOYEE ==========\n";
    cout << "Enter Employee ID: ";

    while (!(cin >> id))
    {
        cout << "Invalid ID. Enter a number: ";
        clearInput();
    }

    bool found = false;

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == id)
        {
            cout << "\nEmployee Found!\n";
            cout << "ID         : " << employees[i].id << endl;
            cout << "Name       : " << employees[i].name << endl;
            cout << "Age        : " << employees[i].age << endl;
            cout << "Job        : " << employees[i].job << endl;
            cout << "Department : " << employees[i].department << endl;
            cout << "Salary     : " << employees[i].salary << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nEmployee Not Found!\n";
    }
}

void showEmployeesByDepartment()
{
    string department;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n========== SEARCH BY DEPARTMENT ==========\n";
    cout << "Enter Department: ";
    getline(cin, department);

    bool found = false;

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].department == department)
        {
            cout << "\nID     : " << employees[i].id << endl;
            cout << "Name   : " << employees[i].name << endl;
            cout << "Job    : " << employees[i].job << endl;
            cout << "Salary : " << employees[i].salary << endl;
            cout << "----------------------------------\n";

            found = true;
        }
    }

    if (!found)
    {
        cout << "\nNo employees found in this department!\n";
    }
}

void showDepartmentStatistics()
{
    string departments[5] =
    {
        "IT",
        "HR",
        "Finance",
        "Loans",
        "Customer Service"
    };

    cout << "\n========== DEPARTMENT STATISTICS ==========\n";

    for (int i = 0; i < 5; i++)
    {
        int count = 0;
        double totalSalary = 0;

        for (int j = 0; j < employeeCount; j++)
        {
            if (employees[j].department == departments[i])
            {
                count++;
                totalSalary += employees[j].salary;
            }
        }

        cout << "\nDepartment : " << departments[i] << endl;
        cout << "Employees  : " << count << endl;
        cout << "Total Salary : " << totalSalary << endl;

        if (count > 0)
        {
            cout << "Average Salary : "
                 << totalSalary / count << endl;
        }

        cout << "----------------------------------\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n========================================\n";
        cout << "       BANK EMPLOYEE SYSTEM\n";
        cout << "========================================\n";
        cout << "1. Show All Employees\n";
        cout << "2. Add New Employee\n";
        cout << "3. Search Employee\n";
        cout << "4. Show Employees By Department\n";
        cout << "5. Show Department Statistics\n";
        cout << "6. Exit\n";
        cout << "========================================\n";

        cout << "Enter your choice: ";

        while (!(cin >> choice))
        {
            cout << "Invalid choice. Enter a number from 1 to 6: ";
            clearInput();
        }

        switch (choice)
        {
        case 1:
            showAllEmployees();
            break;

        case 2:
            addEmployee();
            break;

        case 3:
            searchEmployee();
            break;

        case 4:
            showEmployeesByDepartment();
            break;

        case 5:
            showDepartmentStatistics();
            break;

        case 6:
            cout << "\nThank you for using Bank Employee System!\n";
            break;

        default:
            cout << "\nInvalid choice! Please choose 1 to 6.\n";
        }

    } while (choice != 6);

    return 0;
}