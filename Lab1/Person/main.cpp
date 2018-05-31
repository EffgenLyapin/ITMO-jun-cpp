#include <QCoreApplication>
#include <vector>
#include <iostream>
using namespace std;
class Person {
public:
  Person(int BirthDay,string First_Name,string Last_Name)
      :Dates{(BirthDay)},First_Names{(First_Name)},Last_Names{(Last_Name)}
  {
      cout<<"Create "<<Dates[0]<<" "<<First_Names[0]<<" "<<Last_Names[0]<<endl;
  }

  void Print_Vectors()
  {
      for (int i=0;i<Dates.size();i++) cout<<Dates[i]<<" "<<First_Names[i]<<" "<<Last_Names[i]<<endl;
  }
  int Find_Not_Find_String(vector<string> Vector,int k, const string& find_string)
  {
      while (Vector[k]==find_string && k>0)
      {
          k--;
      }
      return k;
  }
  int Find_Next_Element(vector<int> Vector, int year)
  {
      int k=Vector.size();
      for (int i=1;i<Vector.size();i++)
      {
          if(Vector[i]>year)
          {k=i;break;}
      }
      return k;
  }

  int Find_Years(int year)
    {
      int k;
      for  (int i=0;i<Dates.size();i++)
      {
          if (Dates[i]==year) {k=i; break;}
          else k=-1;

      }
      return k;
    }

  void ChangeFirstName(int year, const string& first_name) {
    auto iter_Dates = Dates.cbegin();
    auto iter_FN = First_Names.cbegin();
    auto iter_LN = Last_Names.cbegin();
    if (year>=Dates[0])
    {
        int i=Find_Years(year);
        if (i!=-1)
        {
            if (First_Names[i]!="unknown") cout<<"Uzhe bilo izmeneniye First_Name"<<endl;
            else First_Names[i]=first_name;
        }
        else
        {
            int k=Find_Next_Element(Dates,year);
            if (k==Dates.size())
            {
                Dates.emplace_back(year);
                First_Names.emplace_back(first_name);
                Last_Names.emplace_back("unknown");
            }
            else
            {
                Dates.emplace(iter_Dates+k,year);
                First_Names.emplace(iter_FN+k,first_name);
                Last_Names.emplace(iter_LN+k,"unknown");
            }
        }
    }
  }
  void ChangeLastName(int year, const string& last_name) {
      auto iter_Dates = Dates.cbegin();
      auto iter_FN = First_Names.cbegin();
      auto iter_LN = Last_Names.cbegin();
      if (year>=Dates[0])
      {
          int i=Find_Years(year);
          if (i!=-1)
          {
              if (Last_Names[i]!="unknown") cout<<"Uzhe bilo izmeneniye Last_Name"<<endl;
              else Last_Names[i]=last_name;
          }
          else
          {
              int k=Find_Next_Element(Dates,year);
              if (k==Dates.size())
              {
                  Dates.emplace_back(year);
                  Last_Names.emplace_back(last_name);
                  First_Names.emplace_back("unknown");
              }
              else
              {
                  Dates.emplace(iter_Dates+k,year);
                  First_Names.emplace(iter_FN+k,"unknown");
                  Last_Names.emplace(iter_LN+k,last_name);
              }
          }
      }
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
      if (year>=Dates[0])
      {
          int i=Find_Years(year);
          if (i!=-1) return First_Names[Find_Not_Find_String(First_Names,i,"unknown")]+" "+Last_Names[Find_Not_Find_String(Last_Names,i,"unknown")];
          if (year>Dates[Dates.size()-1]) return First_Names[Find_Not_Find_String(First_Names,First_Names.size()-1,"unknown")]+" "+Last_Names[Find_Not_Find_String(Last_Names,Last_Names.size()-1,"unknown")];
          if (i==-1&&year<Dates[Dates.size()-1]&&year>Dates[0])
          {
              int k=Find_Next_Element(Dates,year);
              return First_Names[Find_Not_Find_String(First_Names,k-1,"unknown")]+" "+Last_Names[Find_Not_Find_String(Last_Names,k-1,"unknown")];
          }
          if (i==-1 || year<Dates[0]) return "Incognito";
      }
      return "No Person";
  }
  string History (int x)
  {
      string first_name_History="";
      string last_name_History="";
      first_name_History=First_Names[Find_Not_Find_String(First_Names,x,"unknown")];
      last_name_History=Last_Names[Find_Not_Find_String(Last_Names,x,"unknown")];
      int m=Find_Not_Find_String(First_Names,Find_Not_Find_String(First_Names,x,"unknown")-1,"unknown");
      int n=Find_Not_Find_String(Last_Names,Find_Not_Find_String(Last_Names,x,"unknown")-1,"unknown");
      while (m>=0)
      {
          first_name_History=first_name_History+"("+First_Names[Find_Not_Find_String(First_Names,m,"unknown")]+")";
          m=Find_Not_Find_String(First_Names,m-1,"unknown");
      }
      while (n>=0)
      {
          last_name_History=last_name_History+"("+Last_Names[Find_Not_Find_String(Last_Names,n,"unknown")]+")";
          n=Find_Not_Find_String(Last_Names,n-1,"unknown");
      }
      return first_name_History+" "+last_name_History;

  }

  string GetFullNameWithHistory(int year) {
    // получить имя и фамилию по состоянию на конец года year
      if (year>=Dates[0])
      {
          int i=Find_Years(year);
          if (i!=-1)
          {
              return History(i);
          }
          if (year>Dates[Dates.size()-1])
          {
              return History(Dates.size()-1);
          }
          if (i==-1&&year<Dates[Dates.size()-1]&&year>Dates[0])
          {
              int k=Find_Next_Element(Dates,year);
              return History(k-1);
          }
          if (i==-1 || year<Dates[0]) return "Incognito";
      }
      return "No Person";
  }
private:
  vector <int> Dates={0};
  vector <string> First_Names{""};
  vector <string> Last_Names{""};
};

int main()
{
   // Person person (1960,"Ivan","Ivanov");
   // person.ChangeFirstName(1965, "Polina");
  //  person.Print_Vectors();
  //  person.ChangeLastName(1967, "Sergeeva");
  //  person.Print_Vectors();
  //  person.ChangeLastName(1967, "Ivanova");
 //   person.Print_Vectors();

      //person.Print_Vectors();
   //   for (int year : {1900, 1965, 1990}) {
  //      cout << person.GetFullName(year) << endl;
  //    }

  //    person.ChangeFirstName(1970, "Appolinaria");
  //    for (int year : {1969, 1970}) {
  //      cout << person.GetFullName(year) << endl;
  //    }

  //    person.ChangeLastName(1968, "Volkova");
  //    for (int year : {1969, 1970}) {
  //      cout << person.GetFullName(year) << endl;
  //   }
    Person person(1960,"Polina", "Sergeeva");
    //  for (int year : {1959, 1960,1961}) {
    //    cout << person.GetFullNameWithHistory(year) << endl;
    //  }
    person.ChangeFirstName(1963, "Margarita");
    person.ChangeLastName(1963, "Roberts");
    person.ChangeLastName(1964, "Ivanova");
    person.ChangeLastName(1964, "Petrova");
    person.ChangeLastName(1967, "Turman");
    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeFirstName(1980, "Uma");
    person.Print_Vectors();
    for (int year : {1965, 1967,1962,1981,1950}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
}
