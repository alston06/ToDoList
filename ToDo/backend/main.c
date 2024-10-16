#include "task.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
    Task* taskList = NULL;
    int choice, priority;
    char name[50], description[255], deadline[10], category[20];

    while (1) {
        printf("1. Add Task\n2. View Tasks\n3. Mark Task Complete\n4. Delete Task\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter task name: ");
            scanf(" %[^\n]%*c", name);
            printf("Enter description: ");
            scanf(" %[^\n]%*c", description);
            printf("Enter deadline (YYYY-MM-DD): ");
            scanf("%s", deadline);
            printf("Enter priority (integer): ");
            scanf("%d", &priority);
            printf("Enter category: ");
            scanf("%s", category);
            taskList = addTask(taskList, name, description, deadline, priority, category);
            break;
        case 2:
            displayTasks(taskList);
            break;
        case 3:
            printf("Enter task name to mark as complete: ");
            scanf(" %[^\n]%*c", name);
            markTaskComplete(taskList, name);
            break;
        case 4:
            printf("Enter task name to delete: ");
            scanf(" %[^\n]%*c", name);
            taskList = deleteTask(taskList, name);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}