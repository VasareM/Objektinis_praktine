#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
//#include <cctype>
//#include <regex>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;
using std::getline;

string zodzio_tvarkymas(string zodis)
{
    string sutvarkytas, lietuviskos_mazosios = "ąčęėįšųūž", lietuviskos_didziosios = "ĄČĘĖĮŠŲŪŽ";
    for (char temp : zodis)
    {
        size_t idx = lietuviskos_didziosios.find(temp);
        if (idx != string::npos) {
            sutvarkytas += lietuviskos_mazosios[idx];
        }
        else if (lietuviskos_mazosios.find(temp) != string::npos) {
            sutvarkytas += temp;
        }
        else if (std::isalnum(static_cast<unsigned char>(temp))) {
            sutvarkytas += std::tolower(static_cast<unsigned char>(temp));
        }
    }
    return sutvarkytas;
}

int main()
{
    std::ifstream in ("tekstinis_failas.txt");
    if (!in.is_open())
    {
        std::cerr << "Problema failo <tekstinis_failas.txt> nuskaityme" << endl;
        return 1;
    }
    map<string, int> zodziu_skaicius;
    map<string, vector<int>> zodziu_eilutes;

    string eile;
    int eiles_nr=0;

    while (getline(in, eile))
    {
        ++eiles_nr; //eilute iskart skaiciuojama nuo 1
        std::istringstream iss(eile);
        string zodis;
        while (iss >> zodis)
        {
            string sutvarkytas_zodis=zodzio_tvarkymas(zodis);
            if (sutvarkytas_zodis.empty()) continue;
            zodziu_skaicius[sutvarkytas_zodis]++;
            auto& lines = zodziu_eilutes[sutvarkytas_zodis];
            if (lines.empty() || lines.back() != eiles_nr)
            {
                lines.push_back(eiles_nr);
            }
        }
    }
    in.close();

    std::ofstream out ("pasikartojantys_zodziai.txt");
    if (!out.is_open())
    {
        std::cerr << "Problema failo spausdinime" << endl;
        return 1;
    }
    std::ofstream out2 ("cross-reference_lentel.txt");
    for (const auto& [zodis, pasikartojimas] : zodziu_skaicius)
    {
        if (pasikartojimas > 1)
        {
            out << zodis << ": " << pasikartojimas << " kartus, eilutėse: ";
            for (int eil : zodziu_eilutes[zodis])
            {
                out << eil << " ";
            }
            out << endl;
        }
    }
    out.close();



    return 0;

}