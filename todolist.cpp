#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    Task(const std::string& name) : name(name), completed(false) {}

    void markCompleted() {
        completed = true;
    }

    std::string getName() const {
        return name;
    }

    bool isCompleted() const {
        return completed;
    }

private:
    std::string name;
    bool completed;
};

class ToDoList {
public:
    void addTask(const std::string& taskName) {
        tasks.emplace_back(taskName);
        std::cout << "Task added: " << taskName << std::endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available." << std::endl;
            return;
        }

        std::cout << "Tasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].getName()
                      << " [" << (tasks[i].isCompleted() ? "Completed" : "Pending") << "]" << std::endl;
        }
    }

    void markTaskCompleted(size_t index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid task number." << std::endl;
            return;
        }
        tasks[index - 1].markCompleted();
        std::cout << "Task marked as completed: " << tasks[index - 1].getName() << std::endl;
    }

    void deleteTask(size_t index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid task number." << std::endl;
            return;
        }
        std::string removedTask = tasks[index - 1].getName();
        tasks.erase(tasks.begin() + index - 1);
        std::cout << "Task deleted: " << removedTask << std::endl;
    }

private:
    std::vector<Task> tasks;
};

int main() {
    ToDoList todoList;
    int choice;
    std::string task;

    do {
        std::cout << "\n--- To-Do List Manager ---" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Delete Task" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task: ";
                std::cin.ignore(); // Clear the newline character from the input buffer
                std::getline(std::cin, task);
                todoList.addTask(task);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                std::cout << "Enter task number to mark as completed: ";
                size_t completeTaskNumber;
                std::cin >> completeTaskNumber;
                todoList.markTaskCompleted(completeTaskNumber);
                break;
            case 4:
                std::cout << "Enter task number to delete: ";
                size_t deleteTaskNumber;
                std::cin >> deleteTaskNumber;
                todoList.deleteTask(deleteTaskNumber);
                break;
            case 5:
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }

    } while (choice != 5);

    return 0;
}
