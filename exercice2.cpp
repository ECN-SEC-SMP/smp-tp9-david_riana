#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> prenoms = {"David", "Riana", "Vincent"};
    prenoms.push_back("Bonjour");
    prenoms.push_back("comment");
    prenoms.push_back("allez");
    prenoms.push_back("vous");
    prenoms.push_back("?");

    cout << "Taille prenoms   : " << prenoms.size()     << endl;
    /*
     *  Quantité d’espace mémoire alloué pour stocker des éléments
     * capacity() indique combien d’éléments pourraient être stockés sans réallouer la mémoire.
     */
    cout << "Capacité prenoms : " << prenoms.capacity() << endl;

    prenoms.push_back("Je");
    prenoms.push_back("vais");
    prenoms.push_back("bien");

    cout << "Taille prenoms   : " << prenoms.size()     << endl;
    cout << "Capacité prenoms : " << prenoms.capacity() << endl;

    prenoms.push_back("et");
    prenoms.push_back("vous ?");

    cout << "Taille prenoms   : " << prenoms.size()     << endl;
    cout << "Capacité prenoms : " << prenoms.capacity() << endl;

    cout << "=== Affichage version 1 ===" << endl;
    for (size_t i = 0; i < prenoms.size(); i++) {
        cout << prenoms[i] << " ";
    }
    cout << endl;

    cout << "=== Affichage version 2 ===" << endl;
    for (const auto& prenom : prenoms)
        cout << prenom << " ";
    cout << endl;

    cout << "=== Affichage version 3 ===" << endl;
    vector<string>::iterator it;

    for (it = prenoms.begin(); it != prenoms.end(); ++it)
        cout << *it << " ";
    cout << endl;

    auto it1 = prenoms.begin() + 1;
    auto it3 = prenoms.begin() + 3;

    it1->swap(*it3);

    cout << "=== Affichage après le swap ===" << endl;
    for (it = prenoms.begin(); it != prenoms.end(); ++it)
        cout << *it << " ";
    cout << endl;

    prenoms.insert(it1, "a tous");

    cout << "=== Affichage après l'ajout de 'a tous' en position 1 ===" << endl;
    for (it = prenoms.begin(); it != prenoms.end(); ++it)
        cout << *it << " ";
    cout << endl;

    auto it_point_interrogation = std::find(prenoms.begin(), prenoms.end(), "vous ?");

    if (it_point_interrogation != prenoms.end())
    {
        *it_point_interrogation = "vous ???";
    }

    cout << "=== Affichage remplacer le dernier ? par ??? ===" << endl;
    for (it = prenoms.begin(); it != prenoms.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << "=== Afficher la chaine séparer par ;  ===" << endl;







    return 0;
}