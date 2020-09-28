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
    vector<int> paz;
    vector<int> mediana;
    int egz;
    double GP = 0;
    double medianai;
};

int main()
{
    srand(time(NULL));
    vector<duomuo> Eil_vect;
    int n;
    cout<<std::endl<<"Iveskite kiek studentu ";
    cin>>n;
    if (n > 0 ) {
    string vardas, pavarde;
    int integer;
    int pazym;
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
          cout<<"Iveskite pazymiu/us (kai nuspresite, kad ivedet visus, iveskite '-1' ) "<<std::endl;
          if (integer >= 1 && integer <= 10){
            Eil_vect[i].egz = integer;
            Eil_vect[i].mediana.push_back(integer);
            cin>>pazym;
            int p = 0;
            while (pazym != -1)
            {
              Eil_vect[i].paz.push_back(pazym);
              Eil_vect[i].GP+=Eil_vect[i].paz[p];
              Eil_vect[i].mediana.push_back(pazym);
              p+=1;
              if ((pazym >=1 && pazym <=10) || pazym == -1){cin>>pazym;}
              else {printf("Ivedete pazymi netinkamu formatu, bandykite dar karta");
              return 0;}
            }
            el_sk = p+1;
          }
        else {printf("Ivedete egzamino pazymi netinkamu formatu, bandykite dar karta");
        return 0; }
        }
        else if (veiksmas == "G"){
          Eil_vect[i].egz= 1 + ( std::rand() % ( 10 ) );
          Eil_vect[i].mediana.push_back(Eil_vect[i].egz);
          cout<<"Egzamino paz. = "<< Eil_vect[i].egz<<std::endl;
          int sk;
          sk = 0 + ( std::rand() % ( 15 ) );
          cout<<"Pazymiu skaicius = "<< sk <<std::endl;
          for(int k=0;k<sk;k++)
          {
            Eil_vect[i].paz.push_back(1 + ( std::rand() % ( 10 ) ));
            Eil_vect[i].mediana.push_back(Eil_vect[i].paz[k]);
            Eil_vect[i].GP+=Eil_vect[i].paz[k];
          }
          el_sk = sk + 1;
          }
        else {
          printf("Tokio veiksmo nera, bandykite dar karta");
          return 0;}
        if (Eil_vect[i].GP != 0){
        Eil_vect[i].GP = Eil_vect[i].GP / (el_sk-1)/1.0;}
        Eil_vect[i].GP = Eil_vect[i].GP * 0.4 + 0.6 * Eil_vect[i].egz;
        //medianai skaiciuot
        std::sort(Eil_vect[i].mediana.begin(), Eil_vect[i].mediana.end()); 
        if ((el_sk) % 2 != 0) 
        Eil_vect[i].medianai = Eil_vect[i].mediana[(el_sk - 1) / 2]; 
        else Eil_vect[i].medianai = (Eil_vect[i].mediana[(el_sk) / 2] + Eil_vect[i].mediana[ el_sk / 2 - 1]) / 2.0;
    }
    //ivedimas virsuj
    cout<<std::endl<< "Iveskite ka norite pamatyti: jei mediana iveskite 'M', jei galutini rezultata iveskite 'R' ";
    string ats;
    cin>>ats;
    cout << std::left << std::setw(15)<< "Vardas" <<std::left <<std::setw(15)<< "Pavarde ";
    if (ats == "R") cout<<"Galutinis paz"<<std::endl;
    else if (ats =="M") cout<<"Mediana"<<std::endl;
    else {
      printf("Tokio veiksmo nera, bandykite dar karta");}
    cout<<std::endl<<"___________________________________________"<<std::endl;
    for(int i=0;i<n;i++)
    { 
      cout << std::left << std::setw(15)<< Eil_vect[i].Vard <<std::left <<std::setw(15)<< Eil_vect[i].Pav;
      if (ats == "R") cout<< std::setprecision(3)<<Eil_vect[i].GP <<std::endl;
      else if (ats =="M") cout<< std::setprecision(3) << Eil_vect[i].medianai <<std::endl;
    }
    }
    else{
      printf("Studentu skaicius negali buti neigiamas arba didesnis uz 10");
      return 0;}
}
