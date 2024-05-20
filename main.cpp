// Parašykite programą, kuri sudarytų šachmatų varžybų tvarkaraštį. 
// Varžybose dalyvauja n>1 žaidėjų, kurie poromis turi sužaisti po vieną kartą. 
// Jei žaidėjų skaičius 2k+1, tai kiekvienas žaidėjas turi k partijų sužaisti balta ir k partijų juoda spalva (be to, kažkuris žaidėjas turi palaukti, kol kiti suloš vieną ratą). 
// Jei žaidėjų skaičius 2k, tai pirmoji pusė žaidėjų sulošia k partijų balta ir k-1 partijų juoda spalva.
#include <iostream>
#include <vector>

void lyginis(std::vector<int> &zaidejai);
void nelyginis(std::vector<int> &zaidejai);

int main()
{
    int n;
    std::cout << "Kiek zaideju dalyvauja varzybose?" << std::endl;
    while (!(std::cin >> n) || n < 1) {
        std::cout << "Neteisinga ivestis, bandykite dar karta." << std::endl;
        std::cin.clear();
        std::cin.ignore();
    }
    std:: vector <int> zaidejai(n);
    for (int i = 0; i < n; i++) {
        zaidejai[i] = i + 1;
    }

        
    if (n % 2 == 0) {
        lyginis(zaidejai);
    }
    else {
        nelyginis(zaidejai);
    }
    std::cout << "Pirmas ratas:" << std::endl;

}
void lyginis(std::vector<int> &zaidejai) {
    int kazkas = zaidejai.size()/2;
    
}

void nelyginis(std::vector<int> &zaidejai) {

}
