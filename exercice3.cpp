#include <iostream>
#include <list>


using namespace std;

int main(){
    list<int> lst; // Déclaration de la liste
    lst.resize(8); // Définir la taille pour les 8 elts
    int compt = 0;
    for(std::list<int>::iterator it = lst.begin();it != lst.end(); it++){
        *it = compt++ ; 
    }
    cout << "-- Affichage de la liste --" << endl ;
    for(std::list<int>::iterator it = lst.begin();it != lst.end(); it++){
        cout << *it << endl;
    }

    //Suppression du 3e elt
    auto it = lst.begin();
    advance(it,2);
    lst.erase(it);
    cout << "-- Affichage de la liste sans le 3e elt --" << endl ;
    for(std::list<int>::iterator it = lst.begin();it != lst.end(); it++){
        cout << *it << endl;
    }
    return 0;
}
