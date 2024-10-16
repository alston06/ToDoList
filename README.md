# To-Do List Application

This project is a simple console-based To-Do List application written in C, with a backend that manages tasks using a linked list data structure. Tasks can be added, displayed, marked as completed, and deleted, and the data can be saved to or loaded from a text file.

## Features

- **Add Tasks:** Add tasks with a name, description, deadline, priority, and category.
- **View Tasks:** Display all tasks in a list, including their completion status.
- **Mark Task as Complete:** Mark any task as completed by its name.
- **Delete Tasks:** Remove a task by name.
- **Persistent Storage:** Save tasks to a file and load them from a file to ensure task persistence between program executions.

## Technologies Used

- C programming language
- File handling (for saving and loading tasks)
- Linked lists (for managing tasks in memory)
- Console-based input and output

## Prerequisites

To compile and run the application, you need:

- A C compiler (like GCC or Visual Studio's MSVC).
- Basic knowledge of running terminal/command-line commands.

## Installation and Setup

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/yourusername/todoList.git
    ```

2. Navigate to the project directory:

    ```bash
    cd todoList
    ```

3. Compile the source files using your preferred compiler. Here are a few examples for different environments:

    **Using GCC:**

    ```bash
    gcc -o todo main.c task.c
    ```

    **Using Visual Studio (MSVC):**

    Open the project folder in Visual Studio and build the solution.

4. Run the compiled program:

    **For GCC:**

    ```bash
    ./todo
    ```

    **For MSVC (in Visual Studio):**

    Run the executable from Visual Studio or from the command line after building:

    ```bash
    .\Debug\todo.exe
    ```

## How to Use

Once the program is running, you will see a menu with the following options:

1. **Add Task**  
   Enter task details like name, description, deadline, priority, and category. The task will be added to the list and stored in memory.

2. **View Tasks**  
   Displays all tasks in the list, including their completion status (Yes/No).

3. **Mark Task Complete**  
   Enter the name of the task you want to mark as complete. The task’s status will be updated.

4. **Delete Task**  
   Enter the name of the task you want to delete. The task will be removed from the list.

5. **Exit**  
   Exits the program after saving all tasks to `tasks.txt`.

### Persistent Storage

All tasks are saved in the file `tasks.txt` located in the project directory when the program exits. The tasks are automatically loaded from this file when the program starts.

### Example

#### Add Task
```
Enter task name: Complete assignment
Enter description: Finish the math assignment
Enter deadline (YYYY-MM-DD): 2024-10-20
Enter priority (integer): 1
Enter category: Homework
Task added: Complete assignment
```

#### View Tasks
```
Task: Complete assignment
Description: Finish the math assignment
Deadline: 2024-10-20
Priority: 1
Category: Homework
Completed: No
```

#### Delete Task
```
Enter task name to delete: Complete assignment
Task 'Complete assignment' has been deleted.
```

## Code Structure

- `task.h`: Contains the task structure and function declarations.
- `task.c`: Implements task operations (add, delete, save to file, load from file, etc.).
- `main.c`: The main program logic with the menu-driven interface.

## Known Issues

- **File Permissions:** Ensure the program has write access to the directory where it’s run so it can save the `tasks.txt` file properly.
- **Input Validation:** Limited validation for inputs like date format and task priority. Future versions may include more robust input checking.

## Future Enhancements

- **Priority Sorting:** Automatically sort tasks by priority.
- **Date Validation:** Add stricter validation for the `deadline` field.
- **GUI:** Implement a graphical user interface for easier task management.

## License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/alston06/ToDoList/blob/master/LICENSE.txt) file for details.

## Contributions

Contributions, issues, and feature requests are welcome! Feel free to check the [issues page](https://github.com/alston06/ToDoList/issues) or submit a pull request.
