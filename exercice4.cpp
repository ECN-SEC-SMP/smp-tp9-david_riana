#include <cassert>
#include <map>
#include <list>
#include <string>
#include <iostream>

using namespace std;
using evenement_t = list<string>;
using calendrier_t = map<int, evenement_t>;

bool ajoute_evenement(calendrier_t &cal, int annee, string intitule) {
    auto it = cal.find(annee);
    evenement_t::iterator it_event;

    if (it == cal.end()) {
        list<string> evenement = {intitule};
        cal[annee] = evenement;
        return true;
    }

    it_event = find(cal[annee].begin(), cal[annee].end(), intitule);

    if (it_event == cal[annee].end()) {
        cal[annee].push_back(intitule);
        return true;
    }
    return false;
}

void affiche_liste(evenement_t &lst) {
    cout << '[';
    for(auto it = lst.begin(); it != lst.end(); it++){
        cout << *it;

        if (next(it) != lst.end()) cout << ", ";
    }
    cout << ']' << endl;
}

void affiche_calendrier(calendrier_t &cal) {
    cout << "-- Calendrier --" << endl;
    for(auto it = cal.begin(); it != cal.end(); it++) {
        cout << "en " << it->first << " : ";
        affiche_liste(it->second);
    }
    cout << "----------------" << endl;
}

int main(){
    calendrier_t calendrier;

    cout << "-- TEST DE L'AJOUT D'ÉVÈNEMENT DANS UN DICTIONNAIRE --" << endl ;

    assert(ajoute_evenement(calendrier,2018,"Victoire de la CDM") && "L'évènement doit être ajouté dans le calendrier");
    assert(calendrier.count(2018) == 1 && "L'année 2018 doit être présente dans le calendrier");
    assert(find(calendrier[2018].begin(), calendrier[2018].end(), "Victoire de la CDM") != calendrier[2018].end()
        && "L'évènement doit être présent dans le calendrier");

    // On ajoute un autre evenement pour la même année
    assert(ajoute_evenement(calendrier,2018,"panthéonisation de Simone Veil et de son mari Antoine") && "L'évènement doit être ajouté dans le calendrier");
    assert(calendrier.count(2018) == 1 && "L'année 2018 doit être présente dans le calendrier");
    assert(find(calendrier[2018].begin(), calendrier[2018].end(), "panthéonisation de Simone Veil et de son mari Antoine") != calendrier[2018].end()
        && "L'évènement doit être présent dans le calendrier");

    // On ajoute un évènement qui existe déjà
    assert(
        !ajoute_evenement(calendrier,2018,"Victoire de la CDM") &&
        "L'évènement ne doit pas être ajouté dans le calendrier");
    assert(calendrier.count(2018) == 1 && "L'année 2018 doit être présente dans le calendrier");
    assert(count(calendrier[2018].begin(), calendrier[2018].end(), "Victoire de la CDM") == 1
        && "L'évènement doit être présent une seule fois dans le calendrier");

    affiche_calendrier(calendrier);
    return 0;
}