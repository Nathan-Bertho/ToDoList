#include "add_task.h"


void add_task(ofstream& monFlux)
{
cout << "Vous souhaitez ajouter une tâche. Veuillez renseigner quelques uns des critères suivant :"<<endl;
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
        int id = 1;
        if(taille != 0) //i.e si il y a déjà quelque chose d'écrit
        {
            string const Tasks("tasks.txt");
            ifstream lecture_flux(Tasks.c_str());
            string ligne; 
            while(getline(lecture_flux, ligne)) //on va ajouter la tâche en dernière,
            //donc on va à la dernière ligne
                {
                    ++id;
                }
        }
        else // il n'y a encore aucune tâche
        {
            monFlux << "id/name/description/creationdate/deadline/percent/urgency" << endl;
        }
            vector<string> tache;//Valeurs par défaut si certains attributs ne sont pas rentrés
            // tâche[0] est connu, c'est id
            tache[1] = "NoName";
            tache[2] = "NoDescription";
            tache[3] = creation_date();
            tache[4] = "NoDeadline";
            tache[5] = "NoProgression";
            tache[6] = "NoUrgency";

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
            /* maintenant, notre tableau tache contient tous les éléments (demandés ou par défaut)
            pour entrer la tâche dans la liste */
            
            string finaltache = to_string(id);  
            for(int i=0; i<=6; ++i) 
            {
                finaltache += tache[i];
                if(i!=6)
                {
                    finaltache += "/";
                }
                
                
        
                
            }
            monFlux << finaltache << endl;
            cout << "La tâche demandée a bien été créée." << endl;
            cout << finaltache << endl;
    }
    else
    {
        cout << "Ouverture du fichier impossible" << std::endl;
    }
};