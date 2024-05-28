// Parašykite programą, kuri sudarytų šachmatų varžybų tvarkaraštį. 
// Varžybose dalyvauja n>1 žaidėjų, kurie poromis turi sužaisti po vieną kartą. 
// Jei žaidėjų skaičius 2k+1, tai kiekvienas žaidėjas turi k partijų sužaisti balta ir k partijų juoda spalva (be to, kažkuris žaidėjas turi palaukti, kol kiti suloš vieną ratą). 
// Jei žaidėjų skaičius 2k, tai pirmoji pusė žaidėjų sulošia k partijų balta ir k-1 partijų juoda spalva.
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void printSchedule(const vector<vector<pair<int, int>>>& schedule, int n) {
    for (int round = 0; round < schedule.size(); ++round) {
        cout << "Round " << round + 1 << ":" << endl;
        for (auto match : schedule[round]) {
            if (match.first == -1 || match.second == -1) {
                continue;
            }
            cout << "Player " << match.first + 1 << " vs Player " << match.second + 1 << "\n";
        }
        cout << endl;
    }
}

vector<vector<pair<int, int>>> generateSchedule(int n) {
    vector<vector<pair<int, int>>> schedule;
    vector<int> players(n);
    for (int i = 0; i < n; ++i) {
        players[i] = i;
    }

    if (n % 2 == 1) {
        players.push_back(-1);  // Pridedame fiktyvų žaidėją, jei žaidėjų skaičius nelyginis
        n++;
    }

    int rounds = n - 1;
    for (int round = 0; round < rounds; ++round) {
        vector<pair<int, int>> matches;
        for (int i = 0; i < n / 2; ++i) {
            if (players[i] != -1 && players[n - 1 - i] != -1) {
                matches.push_back({ players[i], players[n - 1 - i] });
            }
        }
        schedule.push_back(matches);

        // Sukamasis ratas
        int last = players[n - 1];
        for (int i = n - 1; i > 1; --i) {
            players[i] = players[i - 1];
        }
        players[1] = last;
    }

    return schedule;
}

int main() {
    int n;
    cout << "Enter the number of players: ";
    cin >> n;

    if (n <= 1) {
        cout << "Number of players must be greater than 1." << endl;
        return 1;
    }

    vector<vector<pair<int, int>>> schedule = generateSchedule(n);
    printSchedule(schedule, n);

    return 0;
}
