#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct Node {
    int id;
    string task;
    bool completed;
    Node* next;
};

class ToDoList {
private:
    Node* head;
    int latestID;

public:
    ToDoList() : head(nullptr), latestID(0) {}

    void addTask();
    void viewTasks();
    void removeTask();
    void completeTask();
    void deleteAllTasks(); 
    void saveToFile();
    void loadFromFile();
};

void ToDoList::addTask() {
    Node* newNode = new Node;
    newNode->completed = false;

    cin.ignore(); 
    cout << "Enter a new task: ";
    getline(cin, newNode->task);

    newNode->id = ++latestID;

    char saveChoice;
    cout << "Do you want to save this task? (y/n): ";
    cin >> saveChoice;

    if (saveChoice == 'y' || saveChoice == 'Y') {
        newNode->next = head;
        head = newNode;

        cout << "Task added successfully!\n";
    } else {
        delete newNode;
        cout << "Task not saved.\n";
    }
}

void ToDoList::viewTasks() {
    if (head == nullptr) {
        cout << "No tasks available.\n";
        return;
    }

    Node* current = head;

    while (current != nullptr) {
        cout << current->id << " : " << current->task;
        if (current->completed) {
            cout << " [Completed]";
        }
        cout << "\n";
        current = current->next;
    }

    char stayChoice;
    cout << "Do you want to continue viewing tasks? (y/n): ";
    cin >> stayChoice;

    if (stayChoice == 'y' || stayChoice == 'Y') {
        viewTasks();
    }
}

void ToDoList::removeTask() {
    if (head == nullptr) {
        cout << "No tasks available to remove.\n";
        return;
    }

    int idToRemove;
    cout << "Enter the ID of the task to remove: ";
    cin >> idToRemove;

    Node* current = head;
    Node* prev = nullptr;
    bool taskFound = false;

    while (current != nullptr) {
        if (current->id == idToRemove) {
            taskFound = true;
            cout << "Task found: " << current->id << " : " << current->task << "\n";

            char deleteChoice;
            cout << "Do you want to delete this task? (y/n): ";
            cin >> deleteChoice;

            if (deleteChoice == 'y' || deleteChoice == 'Y') {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;

                cout << "Task deleted successfully!\n";
            } else {
                cout << "Task not deleted.\n";
            }

            break;
        }

        prev = current;
        current = current->next;
    }

    if (!taskFound) {
        cout << "Task with ID " << idToRemove << " not found.\n";
    }
}

void ToDoList::completeTask() {
    if (head == nullptr) {
        cout << "No tasks available to mark as complete.\n";
        return;
    }

    int idToComplete;
    cout << "Enter the ID of the task to mark as complete: ";
    cin >> idToComplete;

    Node* current = head;
    bool taskFound = false;

    while (current != nullptr) {
        if (current->id == idToComplete) {
            taskFound = true;
            cout << "Task found: " << current->id << " : " << current->task << "\n";

            char completeChoice;
            cout << "Do you want to mark this task as complete? (y/n): ";
            cin >> completeChoice;

            if (completeChoice == 'y' || completeChoice == 'Y') {
                current->completed = true;
                cout << "Task marked as complete!\n";
            } else {
                cout << "Task status not changed.\n";
            }

            break;
        }

        current = current->next;
    }

    if (!taskFound) {
        cout << "Task with ID " << idToComplete << " not found.\n";
    }
}

void ToDoList::deleteAllTasks() {
    Node* current = head;
    Node* nextNode;

    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = nullptr;
    latestID = 0;
    cout << "All tasks deleted successfully!\n";
}

void ToDoList::saveToFile() {
    ofstream outFile("todo.txt");

    if (!outFile.is_open()) {
        cout << "Error opening file for writing.\n";
        return;
    }

    Node* current = head;

    while (current != nullptr) {
        outFile << current->id << "\n" << current->task << "\n" << current->completed << "\n";
        current = current->next;
    }

    outFile.close();
}

void ToDoList::loadFromFile() {
    ifstream inFile("todo.txt");

    if (!inFile.is_open()) {
        cout << "No existing tasks.\n";
        return;
    }

    while (inFile.peek() != EOF) {
        Node* newNode = new Node;
        inFile >> newNode->id;
        inFile.ignore();
        getline(inFile, newNode->task);
        inFile >> newNode->completed;

        newNode->next = head;
        head = newNode;

        latestID = max(latestID, newNode->id);
    }

    inFile.close();
}

int main() {
    ToDoList toDoList;
    toDoList.loadFromFile();

    int choice;

    do {
        cout << "---------------------------------------------------\n";
        cout << "\t My To-Do List\n";
        cout << "---------------------------------------------------\n";
        cout << " 1. Add Task\n 2. View Task\n 3. Remove Task\n 4. Complete Task\n 5. Delete All Tasks\n 6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                toDoList.addTask();
                break;
            case 2:
                toDoList.viewTasks();
                break;
            case 3:
                toDoList.removeTask();
                break;
            case 4:
                toDoList.completeTask();
                break;
            case 5:
                toDoList.deleteAllTasks();
                break;
            case 6:
                toDoList.saveToFile();
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
