//
// Created by David PROSPÉRIN on 15/03/2026.
//

#ifndef SMP_TP9_DAVID_RIANA_CALENDAR_H
#define SMP_TP9_DAVID_RIANA_CALENDAR_H

#include <map>
#include <list>
#include <string>
#include <iostream>

using namespace std;
using evenement_t = list<string>;
using calendrier_t = map<int, evenement_t>;
using calendrier_it = calendrier_t::iterator;

class Calendrier {
    calendrier_t calendrier_;

public:
    Calendrier() {
        //rien à faire
    };

    void save(const string & filename) const;
    void load(string & filename);

    calendrier_t &getCalendrier() {
        return calendrier_;
    };

    bool ajoute_evenement(int annee, string intitule) {
        auto it = calendrier_.find(annee);
        evenement_t::iterator it_event;

        if (it == calendrier_.end()) {
            list<string> evenement = {intitule};
            calendrier_[annee] = evenement;
            return true;
        }

        it_event = find(calendrier_[annee].begin(), calendrier_[annee].end(), intitule);

        if (it_event == calendrier_[annee].end()) {
            calendrier_[annee].push_back(intitule);
            return true;
        }
        return false;
    }

    static void affiche_liste(evenement_t &lst) {
        cout << '[';
        for(auto it = lst.begin(); it != lst.end(); it++){
            cout << *it;

            if (next(it) != lst.end()) cout << ", ";
        }
        cout << ']' << endl;
    }

};

ostream &operator<<(ostream &os, Calendrier &calendrier);

#endif //SMP_TP9_DAVID_RIANA_CALENDAR_H