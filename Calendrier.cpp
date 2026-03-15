//
// Created by David PROSPÉRIN on 15/03/2026.
//

#include "Calendrier.h"
#include <fstream>

ostream &operator<<(ostream &os, Calendrier &calendrier) {
    cout << "-- Calendrier --" << endl;
    for(auto it = calendrier.getCalendrier().begin(); it != calendrier.getCalendrier().end(); it++) {
        cout << "en " << it->first << " : ";
        Calendrier::affiche_liste(it->second);
    }
    cout << "----------------" << endl;

    return os;
}

/**
 * Enregistre au format CSV séparé par des points virgules le calendrier dans un fichier
 * Créée le fichier si celui-ci n'existe pas
 * @param filename Le nom du fichier dans lequel le calendrier doit être sauvegardé
 */
void Calendrier::save(const string & filename) const {
    fstream file(filename, ios::out);

    for (auto it_cal = calendrier_.begin(); it_cal != calendrier_.end(); it_cal++) {
        file << it_cal->first << ";";
        for (string s : it_cal->second) {
            file << s << ";";
        }
        file << endl;
    }
}
