#include "edit_task.h"


void edit_task(ofstream& monFlux){
    cout << "Vous souhaitez modifier une tâche. Veuillez renseigner quelques uns des critères suivant :"<<endl;
cout << "- L'id de la tâche à modifier avec id. Doit être obligatoirement renseigné, et en premier."<<endl;
cout << "- Le nom de la tâche avec name"<<endl;
cout << "- Une description avec description"<<endl;
cout << "- Une deadline avec deadline"<<endl;
cout << "- Son niveau d'urgence avec urgency"<<endl;
cout << "- Sa progression, en pourcent, avec progression"<<endl;
cout<<"Votre réponse doit avoir la forme nom_attribut_voulu,valeur_voulue le tout séparé par des virgules"<< endl;
string instruction;
getline(cin,instruction);
vector<string> cmd;
cmd={split(instruction,',')};

    if (monFlux)
    {
        monFlux.seekp(0, ios::end);
        int taille;
        taille = monFlux.tellp(); //ces 3 lignes donnent le nombre de caractères
        int id = -1; //indiquera à quelle ligne se trouve la tâche au bon id.
        if(taille != 0) //i.e si il existe une tâche. Sinon, on n'a pas besoin d'exécuter la suite.
        {
            
            string const Tasks("tasks.txt");
            ifstream lecture_flux(Tasks.c_str());
            string ligne; 
            while(getline(lecture_flux, ligne)) //on parcourt tout le tableau pour trouver la ligne
            //correspondant à l'Id demandé si il existe. Sinon il ne se passera rien
                {
                ++id; 
                vector<string> tache;
                tache={split(ligne,'/')};
                if(tache[0]==cmd[1]) //L'Id est le bon ; c'est la ligne à modifier.
                    {
                    int s;
                    s=cmd.size();
                    for (int i=2; i<s; i=i+2) // cmd[0] et cmd[1] étant l'attribut et sa valeur, etc...
                        {  // ici on répète les commandes pour que l'ordre des attributs ne soit pas important
                        if(!strcmp(cmd[i].c_str(),"name"))
                            {
                            tache[1] = cmd[i+1]; 
                            }
                        if(!strcmp(cmd[i].c_str(),"description"))
                            {
                            tache[2] = cmd[i+1];
                            }
                        if(!strcmp(cmd[i].c_str(),"deadline"))
                            {
                            tache[4] = cmd[i+1];
                            }
                            if(!strcmp(cmd[i].c_str(),"progression"))
                            {
                            tache[5] = cmd[i+1];
                            } 
                            if(!strcmp(cmd[i].c_str(),"urgency"))
                            {
                            tache[6] = cmd[i+1];
                            } 
                        }
            /* maintenant, notre tableau tache contient tous les éléments (modifiés ou non)
            pour re-entrer la tâche dans la liste 
            Pour ça, je ne vois pas d'autre manière que re-écrire tout le tableau.*/
            
                        //je remets la tâche modifiée en string
                        string finaltache = to_string(cmd[1]);  
                        for(int i=0; i<=6; ++i) 
                            {
                            finaltache += tache[i];
                            if(i!=6)
                                {
                                finaltache += "/";
                                }
                            }
                        //puis je transforme tout le tableau. 
                        tableau_fichier=file('tasks.txt');
                        tableau_fichier[id]=str_replace("\n",finaltache, tableau_fichier[id]);
                        file_put_contents('tasks.txt', tableau_fichier);
                        cout << "La tâche a bien été modifiée." << endl;
                        cout << finaltache << endl;

                    };
                
        }

        else // il n'y a encore aucune tâche à modifier. On ne fait rien.
        {        }


    }

    else
    {
        cout << "Ouverture du fichier impossible" << std::endl;
    }

};