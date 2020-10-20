#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include "add_task.h" 
#include "view_tasks.h"
#include "edit_task.h"
using namespace std;

int main()
{
    string const Tasks("tasks.txt");
    ofstream monFlux(Tasks.c_str(), ios::app);
    cout << "Bienvenue dans votre ToDoList." <<endl;
    cout << "- Pour consulter vos tâches existantes, tapez 1"<<endl;
    cout << "- Pour créer une nouvelle tâche, tapez 2"<< endl;
    cout << "- Pour modifier une tâche existante, tapez 3"<< endl;
    int a;
    cin >> a;

    if (a=2)
    {
        add_task(monFlux);
    }

    if (a=1)
    {
        view_tasks(monFlux);
    }

    if (a=3)
    {
        edit_task(monFlux); 
    }
}