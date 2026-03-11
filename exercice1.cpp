#include <vector>
#include <iostream>
#include "exercice1.h"

using namespace std;

int main(){
    vector<int> vect; //définition du vecteur
    vect.resize(3); //redimensionnement du vecteur
    vect = {1,2,3};

    //Affichage des valeurs du tableau avec des indices
    cout << "-- Affichage des valeurs du tableau avec des indices --" << endl ;
    for (int i = 0; i < 3; i++ ){
        cout << vect[i] << endl;
    }

    //Affichage des valeurs du tableau avec une boucle sur une plage de nb
    cout << "-- Affichage des valeurs du tableau avec une boucle sur une plage de nb --" << endl ;
    for (int k : vect){
        cout << k << endl;
    }

    //Affichage d'une plage
    cout << "-- Affichage des valeurs d'une plage --" << endl ;
    for (int k : vect){
        cout << k << endl;
    }

    //Affichage des valeurs à l'aide d'un itérateur
    cout << "-- Affichage des valeurs d'un itérateur --" << endl ;
    for(std::vector<int>::iterator it = vect.begin();it != vect.end(); it++){
        cout << *it << endl;
    }

    //Ajout d'un nouvel élément en fin de vector
    cout << "-- Ajout d'un nouvel élément en fin de vector --" << endl ;
    vect.push_back(4);
    cout << "Nv taille du vector = " << vect[3] << endl;
    //Affichage du nv vector
    cout << "-- Affichage du nouveau vector --" << endl ;
    for(std::vector<int>::iterator it = vect.begin();it != vect.end(); it++){
        cout << *it << endl;
    }
    return 0;
}
