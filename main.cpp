#include <iostream>
#include <string>
#include <vector>

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
    for(int i=0;i<n;i++)
    {
        Eil_vect.push_back(duomuo());
        cin>>vardas;
        cin>>pavarde;
        Eil_vect[i].Vard = vardas;
        Eil_vect[i].Pav = pavarde;
        cin>>integer;
        Eil_vect[i].egz = integer;
        for (int j = 0; j < 5; j++) 
        {
            cin>>pazym;
            Eil_vect[i].paz[j]=pazym;
            Eil_vect[i].GP+=Eil_vect[i].paz[j];
        }
        Eil_vect[i].GP = Eil_vect[i].GP / 5.0;
        Eil_vect[i].GP = Eil_vect[i].GP * 0.4 + 0.6 * Eil_vect[i].egz;
    }
    //ivedimas virsuj
    int bonus_tarpai1, bonus_tarpai2;
    for(int i=0;i<n;i++)
    {
      bonus_tarpai1 = 10-Eil_vect[i].Vard.length();
      bonus_tarpai2 = 10-Eil_vect[i].Pav.length();
      cout << Eil_vect[i].Vard;
       for(int j=0;j<bonus_tarpai1;j++)
       {
         cout<<" ";
       } 
       cout << Eil_vect[i].Pav;
       for(int j=0;j<bonus_tarpai2;j++)
       {
         cout<<" ";
       } 
       cout<<Eil_vect[i].GP<<std::endl;
    }
}
