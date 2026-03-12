#include <map>
#include <list>
#include <string>
#include <iostream>


using namespace std;

//Il y a des chances que les deux méthodes utilisées soient équivalentes...

void ajoute_evenement(std::map<int,list<string>> dico,int date,string intitule){
    if(dico.find(date) != dico.end()){
        dico[date].push_back(intitule);
    }
    else{
        dico.insert({date,{intitule}});
    }  
}

void affiche_liste(list<string> lst){ //Fonction qui permet l'affichage des listes (et donc permet de tester notre map)
    cout << '[';
    for(std::list<string>::iterator it = lst.begin(); it != lst.end(); it++){
        cout << *it;
    }
    cout << ']' << endl;
}

int main(){
    std::map<int,list<string>> dico_event;
    cout << "-- TEST DE L'AJOUT D'ÉVÈNEMENT DANS UN DICTIONNAIRE --" << endl ;
    ajoute_evenement(dico_event,2018,"Victoire de la CDM");
      for (std::map<int,list<string>>::iterator it = dico_event.begin(); it!=dico_event.end(); ++it){
        std::cout << it->first << " => ";
        affiche_liste(it->second);
      }
    

    return 0;
}