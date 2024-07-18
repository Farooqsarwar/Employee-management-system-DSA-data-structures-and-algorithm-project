# Employee Management System

this is my dsa project that i have made using stack and linked list.

## Features

- **Add Employee**: Add a new employee to the system.
- **Remove Employee**: Remove an employee by their ID.
- **Search Employee**: Search for an employee by their ID.
- **Sort Employees**: Sort employees by their ID.
- **Display All Employees**: Display all current employees.
- **Display Removed Employees**: Display all removed employees.

## How to Use

1. **Add Employee**: Select option `1` and enter the employee's name, salary, and ID.
2. **Remove Employee**: Select option `2` and enter the employee's ID to remove them from the system.
3. **Search Employee**: Select option `3` and enter the employee's ID to search for their details.
4. **Sort Employees**: Select option `4` to sort employees by their ID.
5. **Display All Employees**: Select option `5` to display all current employees.
6. **Display Removed Employees**: Select option `6` to display all removed employees.

## Code Overview

### Structure Definitions

- **Employee**: Structure to store employee details.
  ```cpp
  struct Employee {
      string name;
      float salary;
      int id;
  };
