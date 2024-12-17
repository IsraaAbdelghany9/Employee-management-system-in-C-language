# Employee-management-system-in-C-language

# **Employee Management System Project**

This project is a **console-based Employee Management System** written in C. It demonstrates the use of **dynamic memory allocation** for managing employee records.

---

## **Project Description**

- **Add Employee**  
Allows the user to dynamically add an employee with details such as **ID**, **Name**, and **Salary**.  

---

- **Search Employee**  
Searches for an employee by their **ID** and displays the details if the employee exists in the system.  

---

- **Display All Employees**  
Displays a list of all employees, showing their **ID**, **Name**, and **Salary**.  

---

- **Exit**  
Exits the program while freeing all dynamically allocated memory to prevent memory leaks.  

---
## **Short Demo Video**

![Watch the demo](demo.mp4)

---
##  **System Requirements**

To successfully run this project, follow the steps below:

- **Install a C Compiler**  
   - Ensure GCC or any standard C compiler is installed on your machine.

- **Windows Console Support**  
   - The system uses `gotoxy()` for cursor positioning, which works with Windows console applications.

---

## **Compilation Instructions**

1. Save the source code as `employee_management_system.c`.  
2. Open a terminal or command prompt and navigate to the source code's directory.  
3. Compile the code using GCC:  
   ```bash
   gcc employee_management_system.c -o employee_management_system
