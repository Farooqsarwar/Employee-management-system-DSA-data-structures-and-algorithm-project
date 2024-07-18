#include <iostream>
using namespace std;
#include <stack>

struct Employee {
    string name;
    float salary;
    int id;
};

struct node {
    Employee employee;
    node* next;
};
stack<Employee> removedEmployees; 
 Employee employee;
node* head;
node *temp;
bool employeeExists(int id) {
    node* current = head;
    while (current != NULL) {
        if (current->employee.id == id) {
           // cout<<"can not add with existing id";
            return true;
        }
        current = current->next;
    }
    return false;
}
void addEmployee(string name, float salary, int id) {
   
    if (employeeExists(id)) {
        cout << "Employee with ID " << id << " already exists. Not added." << endl;
        return;
    }

    // Set employee details
    employee.name = name;
    employee.salary = salary;
    employee.id = id;

    // Create a new node
    node* newnode = new node;
    newnode->employee = employee;
    newnode->next = NULL;

    // Check if the list is empty
    if (head == NULL) {
        // If the list is empty, set the new node as the head and tail
        head = newnode;
        temp = newnode;
    } else {
        temp->next = newnode;
        temp = newnode;
    }

    cout << "Employee added" << endl;
}



void removeEmployee(int id) {
    if (head == NULL) {
        cout << "Employee list is empty!" << endl;
        return;
    }

    if (head->employee.id == id) {
        node* temp = head;
        head = head->next;
        removedEmployees.push(temp->employee);  // Push removed employee to the stack
        delete temp;
        cout << "Employee removed successfully!" << endl;
        return;
    }

    node* temp = head;
    node* following;
    while (temp != NULL) {
        if (temp->employee.id == id) {
            following->next = temp->next;
            removedEmployees.push(temp->employee);  // Push removed employee to the stack
            delete temp;
            cout << "Employee removed successfully!" << endl;
            return;
        }
        following = temp;
        temp = temp->next;
    }

    cout << "Employee not found!" << endl;
}

void displayRemovedEmployees() {
    while (removedEmployees.empty()){
        cout<<" Removed employe list is empty\n";
        break;
    }
    while (!removedEmployees.empty()) {
            cout << "<  Removed Employees list  > " << endl;

        Employee removed = removedEmployees.top();
        cout << "name: " << removed.name << ", salary: " << removed.salary << ", id: " << removed.id << endl;
        removedEmployees.pop();
    }
}

void searchEmployee(int id) {
    node* temp = head;
    while (temp != NULL) {
        if (temp->employee.id == id) {
            cout << "employee founded" << endl;
            cout << "name " << temp->employee.name << endl;
            cout << "salary " << temp->employee.salary << endl;
            cout << "id " << temp->employee.id << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Employee not found!" << endl;
}

void sortEmployees() {
    if (head == NULL || head->next == NULL) {
        return;
    }

    bool sorted = false;
    while (!sorted) {
        sorted = true;
        node* temp = head;
        node* nextnode = head->next;

        while (nextnode != NULL) {
            if (temp->employee.id > nextnode->employee.id) {
                swap(temp->employee, nextnode->employee);
                sorted = false;
            }

            temp = nextnode;
            nextnode = nextnode->next;
        }
    }

    cout << "employees sorted by ID " << endl;
}

void displayEmployees() {
    if (head == NULL) {
        cout << "Employee list is empty!" << endl;
        return;
    }

    node* temp = head;
    while (temp != NULL) {
        cout << "name  " << temp->employee.name << endl;
        cout << "salary " << temp->employee.salary << endl;
        cout << "id  " << temp->employee.id << endl;
        cout << "-----------------" << endl;
        temp = temp->next;
    }
}

int main() { 
    cout<<"\t++++++IQRA EMPLOYEE MANAGMENT+++++++++\n\n";
    while (true) {
        cout<<"\n";
        cout<<"1=add Employee\n";
          cout  <<"2= remove Employee\n";
           cout <<"3= search Employee\n";
            cout<<"4= sort Employees\n";
            cout<<"5= display All Employees\n";
            cout<<"6= display remove employe\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            float salary;
            int id;

            cout<<"enter employee name ";
            cin.ignore();
            getline(cin, name);

            cout<<"enter employee salary ";
            cin>>salary;

            cout<<"enter employee id ";
            cin>>id;
            addEmployee(name, salary, id);
            break;
        }
        case 2: {
            int id;
            cout<< "Enter employee ID to remove: ";
            cin>>id;

            removeEmployee(id);
            break;
        }

        case 3:{
            int id;
            cout<<"Enter employee ID to search";
            cin>>id;

            searchEmployee(id);
            break;
        }
        case 4:
            sortEmployees();
            break;

        case 5:
            displayEmployees();
            break;
            case 6: {
            displayRemovedEmployees();
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}





