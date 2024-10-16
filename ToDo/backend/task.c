#include "task.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Task* addTask(Task* head, char* name, char* description, char* deadline, int priority, char* category) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    strcpy(newTask->description, description);
    strcpy(newTask->deadline, deadline);
    newTask->priority = priority;
    strcpy(newTask->category, category);
    newTask->completed = false;
    newTask->next = head;
    return newTask;
}

void displayTasks(Task* head) {
    Task* current = head;
    while (current != NULL) {
        printf("Task: %s\n", current->name);
        printf("Description: %s\n", current->description);
        printf("Deadline: %s\n", current->deadline);
        printf("Priority: %d\n", current->priority);
        printf("Category: %s\n", current->category);
        printf("Completed: %s\n", current->completed ? "Yes" : "No");
        printf("\n");
        current = current->next;
    }
}

void markTaskComplete(Task* head, char* name) {
    Task* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            current->completed = true;
            printf("Task %s is marked as completed\n", current->name);
            return;
        }
        current = current->next;
    }
    printf("Task %s not found\n", name);
}

Task* deleteTask(Task* head, char* name) {
    Task* current = head;
    Task* previous = NULL;
    if (head == NULL) {
        printf("Task list is empty.\n");
        return NULL;
    }
    if (strcmp(head->name, name) == 0) {
        Task* temp = head;
        head = head->next;
        free(temp);
        printf("Task '%s' has been deleted.\n", name);
        return head;
    }
    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Task '%s' not found.\n", name);
        return head;
    }
    previous->next = current->next;
    free(current);
    printf("Task '%s' has been deleted.\n", name);
    return head;
}