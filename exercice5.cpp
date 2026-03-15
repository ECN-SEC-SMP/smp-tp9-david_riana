#include <iostream>
#include <cassert>
#include "Calendrier.h"

int main(void) {
    Calendrier cal;

    cout << "-- TEST DE L'AJOUT D'ÉVÈNEMENT DANS UN DICTIONNAIRE --" << endl ;

    assert(cal.ajoute_evenement(2018,"Victoire de la CDM") && "L'évènement doit être ajouté dans le calendrier");
    assert(cal.getCalendrier().count(2018) == 1 && "L'année 2018 doit être présente dans le calendrier");
    assert(
        find(cal.getCalendrier()[2018].begin(), cal.getCalendrier()[2018].end(), "Victoire de la CDM") != cal.
        getCalendrier()[2018].end()
        && "L'évènement doit être présent dans le calendrier");

    // On ajoute un autre evenement pour la même année
    assert(cal.ajoute_evenement(2018,"panthéonisation de Simone Veil et de son mari Antoine") && "L'évènement doit être ajouté dans le calendrier");
    assert(cal.getCalendrier().count(2018) == 1 && "L'année 2018 doit être présente dans le calendrier");
    assert(find(cal.getCalendrier()[2018].begin(), cal.getCalendrier()[2018].end(), "panthéonisation de Simone Veil et de son mari Antoine")
        != cal.getCalendrier()[2018].end()
        && "L'évènement doit être présent dans le calendrier");

    // On ajoute un évènement qui existe déjà
    assert(
        !cal.ajoute_evenement(2018,"Victoire de la CDM") &&
        "L'évènement ne doit pas être ajouté dans le calendrier");
    assert(cal.getCalendrier().count(2018) == 1 && "L'année 2018 doit être présente dans le calendrier");
    assert(count(cal.getCalendrier()[2018].begin(), cal.getCalendrier()[2018].end(), "Victoire de la CDM") == 1
        && "L'évènement doit être présent une seule fois dans le calendrier");

    cal.save("timeline_2018.csv");

    return 0;
}