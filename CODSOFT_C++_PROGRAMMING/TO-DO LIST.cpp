#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

class ToDoList {
    private:
        std::vector<Task> tasks;
    public:
        void addTask(std::string description) {
            Task newTask = {description, false};
            tasks.push_back(newTask);
        }
        void viewTasks() {
            std::cout << "To-Do List:" << std::endl;
            for (int i = 0; i < tasks.size(); i++) {
                std::cout << i+1 << ". " << tasks[i].description;
                if (tasks[i].completed) {
                    std::cout << " (completed)";
                }
                std::cout << std::endl;
            }
        }
        void markTaskCompleted(int taskNumber) {
            if (taskNumber > 0 && taskNumber <= tasks.size()) {
                tasks[taskNumber-1].completed = true;
            } else {
                std::cout << "Invalid task number" << std::endl;
            }
        }
        void removeTask(int taskNumber) {
            if (taskNumber > 0 && taskNumber <= tasks.size()) {
                tasks.erase(tasks.begin() + taskNumber - 1);
            } else {
                std::cout << "Invalid task number" << std::endl;
            }
        }
};

int main() {
    ToDoList myList;
    int choice = 0;
    while (choice != 5) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cin >> choice;

        if (choice == 1) {
            std::string description;
            std::cout << "Enter task description: ";
            getline(std::cin >> std::ws, description);
            myList.addTask(description);
        } else if (choice == 2) {
            myList.viewTasks();
        } else if (choice == 3) {
            int taskNumber;
            std::cout << "Enter task number: ";
            std::cin >> taskNumber;
            myList.markTaskCompleted(taskNumber);
        } else if (choice == 4) {
            int taskNumber;
            std::cout << "Enter task number: ";
            std::cin >> taskNumber;
            myList.removeTask(taskNumber);
        }
    }

    return 0;
}
