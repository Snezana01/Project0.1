#include <iomanip>
#include <bits/stdc++.h>
#include <random>

using std::cout;
using std::cin;
using std::string;
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
    int n;
    cout<<std::endl<<"Iveskite kiek studentu ";
    cin>>n;
    if (n > 0) {
    string vardas, pavarde;
    int integer;
    int pazym;
    int mediana[21]={0};
    struct duomuo *stud = new struct duomuo[n];
    for(int i=0;i<n;i++)
    {
        //Eil_vect.push_back(duomuo());
        //stud = duomuo + stud;
        cout<<"Iveskite varda ir pavarde ";
        cin>>vardas;
        cin>>pavarde;
        stud[i].Vard = vardas;
        stud[i].Pav = pavarde;
        string veiksmas;
        cout<<"Iveskite, ka norite, kad darytu programa: Skaiciuotu jusu ivestus duomenis (iveskite 'S') ar generuotu atsitiktinus pazymius (iveskite 'G')";
        cin>>veiksmas;
        int el_sk;
        if (veiksmas == "S"){
          cout<<"Iveskite egzamino paz. ";
          cin>>integer;
          cout<<"Iveskite pazymiu/us (kai nuspresite, kad ivedet visus, iveskite '-1' ) "<<std::endl;
          if (integer >= 1 && integer <= 10){
          stud[i].egz = integer;
          mediana[0]=integer;
          cin>>pazym;
          int p = 0;
          while (pazym != -1)
          {
            stud[i].paz[p]=pazym;
            stud[i].GP+=stud[i].paz[p];
            mediana[p+1]= pazym;
            p+=1;
            if ((pazym >=1 && pazym <=10) || pazym == -1) cin>>pazym;
            else {printf("Ivedete pazymi netinkamu formatu, bandykite dar karta");
            return 0;}
          el_sk = p+1;
          }
          }
          else {printf("Ivedete egzamino pazymi netinkamu formatu, bandykite dar karta"); }
        }
        else if (veiksmas == "G"){
          stud[i].egz= 1 + ( std::rand() % ( 10 ) );
          mediana[0]=stud[i].egz;
          cout<<"Egzamino paz. = "<< stud[i].egz<<std::endl;
          int sk;
          sk = ( std::rand() % ( 15 ) );
          cout<<"Pazymiu skaicius = "<< sk <<std::endl;
          for(int k=0;k<sk;k++)
          {
            stud[i].paz[k]= 1 + ( std::rand() % ( 10 ) );
            mediana[k+1]=stud[i].paz[k];
            stud[i].GP+=stud[i].paz[k];
          }
          el_sk = sk + 1;
        }
        else {
          printf("Tokio veiksmo nera, bandykite dar karta");}
        if (stud[i].GP != 0){
        stud[i].GP = stud[i].GP / (el_sk-1)/1.0;}
        stud[i].GP = stud[i].GP * 0.4 + 0.6 * stud[i].egz;
        //medianai skaiciuot
        std::sort(mediana,mediana + (el_sk));
        if ((el_sk) % 2 != 0)
        stud[i].medianai = mediana[(el_sk - 1) / 2];
        else stud[i].medianai = (mediana[(el_sk) / 2] + mediana[ el_sk / 2 - 1]) / 2.0;

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
      cout << std::left << std::setw(15)<< stud[i].Vard <<std::left <<std::setw(15)<< stud[i].Pav;
      if (ats == "R") cout<< std::setprecision(3)<<stud[i].GP <<std::endl;
      else if (ats =="M") cout<< std::setprecision(3) << stud[i].medianai <<std::endl;
    }
    }
    else{
    printf("Studentu skaicius negali buti neigiamas");
      return 0;}
}
