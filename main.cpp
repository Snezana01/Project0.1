#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <bits/stdc++.h>
#include <random>

using std::cout;
using std::cin;
using std::string;
using std::vector;
struct duomuo {
    string Vard;
    string Pav;
    int paz[20];
    int egz;
    double GP = 0;
    double medianai;
};

int main()
{
    srand(time(NULL));
    vector<duomuo> Eil_vect;
    int n;
    cout<<"Iveskite kiek studentu ";
    cin>>n;
    if (n < 0 || n > 10) cout<< "Studentu skaicius negali buti neigiamas arba didesnis uz 10"<<std::endl;
    string vardas, pavarde;
    int integer;
    int pazym;
    int mediana[15]={0};
    for(int i=0;i<n;i++)
    {
        Eil_vect.push_back(duomuo());
        cout<<"Iveskite varda ir pavarde ";
        cin>>vardas;
        cin>>pavarde;
        Eil_vect[i].Vard = vardas;
        Eil_vect[i].Pav = pavarde;
        string veiksmas;
        cout<<"Iveskite, ka norite, kad darytu programa: Skaiciuotu jusu ivestus duomenis (iveskite 'S') ar generuotu atsitiktinus pazymius (iveskite 'G')";
        cin>>veiksmas;
        int el_sk;
        if (veiksmas == "S"){
          cout<<"Iveskite egzamino paz. ";
          cin>>integer;
          cout<<"Iveskite kiek pazymiu bus "; 
          int k;
          cin>>k;
          cout<<"Iveskite " <<k << " pazymiu/us ";
          if ((integer >= 0 && integer <= 10) && k >= 0){
          Eil_vect[i].egz = integer;
          mediana[0]=integer;
          
          for (int j = 0; j < k; j++) 
          {
            cin>>pazym;
            Eil_vect[i].paz[j]=pazym;
            Eil_vect[i].GP+=Eil_vect[i].paz[j];
            mediana[j+1]= pazym;
          }
          el_sk = k+1;
          }
          else cout<<"Ivedete egzamino pazymi arba pazymiu skaiciu netinkamu formatu, bandykite dar karta";
        }
        
        else if (veiksmas == "G"){
          Eil_vect[i].egz= 0 + ( std::rand() % ( 11 ) );
          mediana[0]=Eil_vect[i].egz;
          cout<<"Egzamino paz. = "<< Eil_vect[i].egz<<std::endl;
          int sk;
          sk = 0 + ( std::rand() % ( 15 ) );
          cout<<"Pazymiu skaicius = "<< sk <<std::endl;
          //cout<<Eil_vect[i].paz[0]<<" ";
          for(int k=0;k<sk;k++)
          {
            Eil_vect[i].paz[k]= 0 + ( std::rand() % ( 11 ) );
            mediana[k+1]=Eil_vect[i].paz[k];
            Eil_vect[i].GP+=Eil_vect[i].paz[k];
            //cout<<Eil_vect[i].paz[k+1]<<" ";
          }
          el_sk = sk + 1;
        }
        else
        {cout << "Tokio veiksmo nera, bandykite dar karta"; }
        if (Eil_vect[i].GP != 0){
        Eil_vect[i].GP = Eil_vect[i].GP / (el_sk-1)/1.0;}
        Eil_vect[i].GP = Eil_vect[i].GP * 0.4 + 0.6 * Eil_vect[i].egz;
        //medianai skaiciuot
        std::sort(mediana,mediana + (el_sk));
        if ((el_sk) % 2 != 0) 
        Eil_vect[i].medianai = mediana[(el_sk - 1) / 2]; 
        else Eil_vect[i].medianai = (mediana[(el_sk) / 2] + mediana[ el_sk / 2 - 1]) / 2.0;

    }
    //ivedimas virsuj
    cout<< "Iveskite ka norite pamatyti: jei mediana iveskite 'M', jei galutini rezultata iveskite 'R' ";
    string ats;
    cin>>ats;
    cout << std::left << std::setw(15)<< "Vardas" <<std::left <<std::setw(15)<< "Pavarde ";
    if (ats == "R") cout<<"Galutinis paz"<<std::endl;
    else if (ats =="M") cout<<"Mediana"<<std::endl;
    else cout<<std::endl<<"Tokio veiksmo nera, bandykite dar karta"<<std::endl;
    cout<<"___________________________________________"<<std::endl;
    for(int i=0;i<n;i++)
    { 
      cout << std::left << std::setw(15)<< Eil_vect[i].Vard <<std::left <<std::setw(15)<< Eil_vect[i].Pav;
      if (ats == "R") cout<< std::setprecision(3)<<Eil_vect[i].GP <<std::endl;
      else if (ats =="M") cout<< std::setprecision(3) << Eil_vect[i].medianai <<std::endl;
    }

}
