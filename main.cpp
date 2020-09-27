#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <bits/stdc++.h>

using std::cout;
using std::cin;
using std::string;
using std::vector;
struct duomuo {
    string Vard;
    string Pav;
    int paz[10];
    int egz;
    float GP = 0;
};

int main()
{
    duomuo Eil; duomuo Eil_mas[5];
    vector<duomuo> Eil_vect;
    int n;
    cout<<"Iveskite kiek studentu ";
    cin>>n;
    string vardas, pavarde;
    int integer;
    int pazym;
    int mediana[15]={0};
    double medianai;
    for(int i=0;i<n;i++)
    {
        Eil_vect.push_back(duomuo());
        cout<<"Iveskite varda ir pavarde ";
        cin>>vardas;
        cin>>pavarde;
        Eil_vect[i].Vard = vardas;
        Eil_vect[i].Pav = pavarde;
        cout<<"Iveskite egzamino paz. ";
        cin>>integer;
        cout<<"Iveskite kiek pazymiu bus "; 
        int k;
        cin>>k;
        cout<<"Iveskite " <<k << " pazymiu/us ";
        Eil_vect[i].egz = integer;
        mediana[0]=integer;
        for (int j = 0; j < k; j++) 
        {
            cin>>pazym;
            Eil_vect[i].paz[j]=pazym;
            Eil_vect[i].GP+=Eil_vect[i].paz[j];
            mediana[j+1]= pazym;
        }
        
        Eil_vect[i].GP = Eil_vect[i].GP / (k+1)/1.0;
        Eil_vect[i].GP = Eil_vect[i].GP * 0.4 + 0.6 * Eil_vect[i].egz;
        //medianai skaiciuot
        for (int g=0; g<(k+1); g++) {
          cout<<mediana[g]<<" ";
        }
        cout<<std::endl;
        std::sort(mediana,mediana + (k+1));
        if ((k+1) % 2 != 0) 
        medianai = mediana[k / 2]; 
        else medianai = (mediana[(k - 1) / 2] + mediana[(k+1) / 2]) / 2.0;

    }
    //ivedimas virsuj
    cout<< "Iveskite ka norite pamatyti: jei mediana iveskite 'M', jei galutini rezultata iveskite 'R' ";
    string ats;
    cin>>ats;
    cout << std::left << std::setw(15)<< "Vardas" <<std::left <<std::setw(15)<< "Pavarde ";
    if (ats == "R") cout<<"Galutinis paz"<<std::endl;
    else if (ats =="M") cout<<"Mediana"<<std::endl;
    cout<<"___________________________________________"<<std::endl;
    for(int i=0;i<n;i++)
    { 
      cout << std::left << std::setw(15)<< Eil_vect[i].Vard <<std::left <<std::setw(15)<< Eil_vect[i].Pav;
      if (ats == "R") cout<< Eil_vect[i].GP <<std::endl;
      else if (ats =="M") cout<< medianai <<std::endl;
    }
}
