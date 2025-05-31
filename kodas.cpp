#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <cctype>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;
using std::getline;
using std::set;

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

set<string> TLDnuskaitymas(const string& failo_pavadinimas)
{
    set<string> domenai;
    std::ifstream in3(failo_pavadinimas);
    string line;
    while (getline(in3, line))
    {
        line.erase(std::remove_if(line.begin(), line.end(),
            [](unsigned char c) { return std::isspace(c); }), line.end());

        if (!line.empty())
        {
            std::transform(line.begin(), line.end(), line.begin(), ::tolower);
            domenai.insert("." + line);
        }
    }
    return domenai;
}
bool ar_zodis_turi_tld(const string& zodis, const set<string>& domenai)
{
    size_t tasko_vieta = zodis.find('.');
    if (tasko_vieta == string::npos) return false;
    //galune
    size_t pask_task_vt= zodis.rfind('.');
    std::string pabaiga = zodis.substr(pask_task_vt); // įskaitant tašką

    // Patikriname ar ending yra tarp mūsų žinomų TLD
    return domenai.find(pabaiga) != domenai.end();
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
    // <-- asociatyvus konteineriai, iškart sortina

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

    // URL paieska
    std::ifstream in2("tekstas_su_url.txt");
    std::ofstream out2("surasti_url.txt");
    if (!in2.is_open() || !out2.is_open()) {
        std::cerr << "Klaida atidarant URL tekstą ar išvedimo failą\n";
        return 1;
    }
    set<string> domenai=TLDnuskaitymas("tlds.txt");

    string url_zodis;
    while (in2 >> url_zodis)
    {
        if (ar_zodis_turi_tld(url_zodis, domenai)) {
            out2 << url_zodis << endl;
        }
    }

    in2.close();
    out2.close();

    return 0;

}