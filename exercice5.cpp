#include <iostream>
#include <cassert>
#include <fstream>
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

    fstream file_timeline_2018("timeline_2018.csv", ios::in);
    assert(file_timeline_2018.is_open() && "Le fichier doit être créé et ouvert correctement");
    std::string content_timeline_2018, line;

    while (std::getline(file_timeline_2018, line)) {
        content_timeline_2018 += line + '\n';
    }
    assert(
        content_timeline_2018 == "2018;Victoire de la CDM;panthéonisation de Simone Veil et de son mari Antoine;\n" &&
           "Le contenu du fichier doit correspondre au calendrier sauvegardé");

    cout << "-- Test de la méthode load -- " << endl;
    bool isLoaded = false;
    auto calLoaded = Calendrier::load("../timeline_antiquite.csv", isLoaded);

    assert(isLoaded && "Le calendrier doit être chargé correctement");

    assert(calLoaded.getCalendrier().count(-776) == 1 && "L'année -776 doit être présente dans le calendrier");
    assert(
        find(calLoaded.getCalendrier()[-776].begin(), calLoaded.getCalendrier()[-776].end(), "Premiers Jeux olympiques en Grèce") !=
        calLoaded.getCalendrier()[-776].end()
        && "L'évènement doit être présent dans le calendrier");

    assert(calLoaded.getCalendrier().count(-146) == 1 && "L'année -146 doit être présente dans le calendrier");
    assert(
        find(calLoaded.getCalendrier()[-146].begin(),
            calLoaded.getCalendrier()[-146].end(), "Destruction de Carthage") != calLoaded.
        getCalendrier()[-146].end()
        && "L'évènement doit être présent dans le calendrier");

    assert(
       find(calLoaded.getCalendrier()[-146].begin(),
           calLoaded.getCalendrier()[-146].end(), "Fin des guerres puniques") != calLoaded.
       getCalendrier()[-146].end()
       && "L'évènement doit être présent dans le calendrier");

    cout << calLoaded << endl;

    return 0;
}