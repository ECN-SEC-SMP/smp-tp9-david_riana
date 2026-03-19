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

/**
 * Charge le calendrier à partir d'un fichier CSV séparé par des points virgules
 * @param isOk Indique si le chargement du calendrier a réussi ou non
 * @param filename Le nom du fichier à partir duquel le calendrier doit être chargé
 */
Calendrier Calendrier::load(const string &filename, bool & isOk) {
    fstream file(filename, ios::in);
    Calendrier cal;
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            // Trouver l'annee
            auto it = find(line.begin(), line.end(), ';');
            if (it != line.end()) {
                int annee = stoi(string(line.begin(), it));

                // Avancer après le séparateur de l'année
                ++it;
                while (it != line.end()) {
                    auto prochain_sep = find(it, line.end(), ';');

                    if (prochain_sep == line.end()) break;

                    string evenement(it, prochain_sep);

                    if (!evenement.empty()) {
                        cal.ajoute_evenement(annee, evenement);
                    }
                    it = prochain_sep;
                    ++it;
                }

                isOk = true;
            }
        }
        file.close();
    } else {
        cerr << "Unable to open file " << filename << endl;
        isOk = false;
    }
    return cal;
}