// Parašykite programą, kuri sudarytų šachmatų varžybų tvarkaraštį. 
// Varžybose dalyvauja n>1 žaidėjų, kurie poromis turi sužaisti po vieną kartą. 
// Jei žaidėjų skaičius 2k+1, tai kiekvienas žaidėjas turi k partijų sužaisti balta ir k partijų juoda spalva (be to, kažkuris žaidėjas turi palaukti, kol kiti suloš vieną ratą). 
// Jei žaidėjų skaičius 2k, tai pirmoji pusė žaidėjų sulošia k partijų balta ir k-1 partijų juoda spalva.
#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> generateSchedule(int n) {
    vector<vector<int>> schedule; // This will store the schedule
    vector<int> players(n); // This will store the players' indices

    for (int i = 0; i < n; ++i) {
        players[i] = i;
    }

    if (n % 2 == 1) { // jei skaicius nelyginis
        players.push_back(-1); // 
        n++;
    }

    int rounds = n - 1; // Kiek bus roundu

    for (int round = 0; round < rounds; round++) {
        vector<int> matches;
        for (int i = 0; i < n / 2; i++) {
            matches.push_back(players[i]);
            matches.push_back(players[n - 1 - i]);
        }
        schedule.push_back(matches); // Add the matches of this round to the schedule

        // Rotate players to generate the next round's matches
        int last = players[n - 1];
        for (int i = n - 1; i > 1; i--) {
            players[i] = players[i - 1];
        }
        players[1] = last;
    }

    return schedule;
}

// Function to print the schedule of matches
void printSchedule(const vector<vector<int>>& schedule) {
    for (int round = 0; round < schedule.size(); round++) {
        cout << "Round " << round + 1 << ": " << endl;
        for (int i = 0; i < schedule[round].size(); i += 2) {
            int player1 = schedule[round][i];
            int player2 = schedule[round][i + 1];
            if (player1 != -1 && player2 != -1) {
                cout << "Player " << player1 + 1 << " vs Player " << player2 + 1 << "\n";
            }
        }
        cout << endl;
    }
}



int main() {
    int n;
    cout << "Kiek yra zaideju?: ";
    cin >> n;

    vector<vector<int>> schedule;
    schedule = generateSchedule(n);
    printSchedule(schedule); 

    return 0;
}
