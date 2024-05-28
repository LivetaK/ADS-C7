// Parašykite programą, kuri sudarytų šachmatų varžybų tvarkaraštį. 
// Varžybose dalyvauja n>1 žaidėjų, kurie poromis turi sužaisti po vieną kartą. 
// Jei žaidėjų skaičius 2k+1, tai kiekvienas žaidėjas turi k partijų sužaisti balta ir k partijų juoda spalva (be to, kažkuris žaidėjas turi palaukti, kol kiti suloš vieną ratą). 
// Jei žaidėjų skaičius 2k, tai pirmoji pusė žaidėjų sulošia k partijų balta ir k-1 partijų juoda spalva.
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateSchedule(int n);
void printSchedule(const vector<vector<int>>& schedule);

int main() {
    int n;
    cout << "Kiek yra zaideju?: ";
    cin >> n;

    vector<vector<int>> schedule;
    schedule = generateSchedule(n);
    printSchedule(schedule);

    return 0;
}

vector<vector<int>> generateSchedule(int n) {
    vector<vector<int>> schedule;
    vector<int> players(n);

    for (int i = 0; i < n; ++i) { // inicializuojamas vektorius
        players[i] = i;
    }

    if (n % 2 == 1) { // jei skaicius nelyginis
        players.push_back(-1); // pridedamas vienas zaidejas, tam zaidejui, kuris pralesi raunda, butu "porininkas"
        n++;
    }

    int rounds = n - 1; // Kiek bus raundu

    for (int round = 0; round < rounds; round++) { // generuojamas tvarkarastis
        vector<int> matches;
        for (int i = 0; i < n / 2; i++) {
            matches.push_back(players[i]); // pirmas zaidejas poruojamas nuo galo
            matches.push_back(players[n - 1 - i]); // anntras zaidejas poruojamas nuo galo
        }
        schedule.push_back(matches);// ikeliamas visas didelis vektorius, kur zmones, esantys vienas salia kito, yra porininkai

        // Rotacija
        int last = players[n - 1];
        for (int i = n - 1; i > 1; i--) {
            players[i] = players[i - 1];
        }
        players[1] = last;
    }

    return schedule;
}

void printSchedule(const vector<vector<int>>& schedule) {
    for (int round = 0; round < schedule.size(); round++) {
        cout << "Round " << round + 1 << ": " << endl;
        for (int i = 0; i < schedule[round].size(); i += 2) { //imam po du zaidejus
            int player1 = schedule[round][i];
            int player2 = schedule[round][i + 1];
            if (player1 != -1 && player2 != -1) { // iliminuojam ta pora, kurioje yra -1, tas zaidejas praleidzia  raunda 
                cout << "Player " << player1 + 1 << " vs Player " << player2 + 1 << " " << endl;
            }
        }
        cout << endl;
    }
}
