/**1. Realizati o aplicatie de cautare si rezervare zboruri. Aplicatia trebuie sa aiba urmatorii actori:
- Operator: activităti de login si adaugare/stergere zboruri (contul este deja existent in sistem cu user si
parola)
- Utilizator: activitati de creare cont, autentificare, cautare zbor, rezervare

Implementati metodele de management a exceptiilor pentru actiunile urmatoare:
- Operator: login nereusit (user sau parola gresita), adaugare detalii gresite la zbor
(format data gresit, data in trecut, tara sa aiba caractere neexistente in numele tarilor)
- Utilizator: login nereusit, autentificare nereusita (format email necorect, parola prea slaba, parola
repetata nu e corecta), zbor inexistent, introducere detalii gresite la rezervare zbor
Read me - in care sa prezentati cum se face login-ul, autentificarea in mod normal**/

#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <ctime>
#include <chrono>
#include <stdlib.h>

using namespace std;

class Operator
{
private:
    string username;
    string password;

public:
    Operator()
    {
        username = "larisa01";
        password = "a2410";
    }

    string get_username() const
    {
        return this->username;
    }
    string get_password() const
    {
        return this->password;
    }
    void set_username(string usr)
    {
        username = usr;
    }
    void set_password(string pas)
    {
        password = pas;
    }

    friend istream &operator>>(istream &in, Operator &c);
};

istream &operator>>(istream &in, Operator &c)
{
    string usr, prl;

    cout << "Introduceti username-ul: ";
    getline(in, usr);
    //cout<<'\n';

    cout << "Introduceti parola: ";
    getline(in, prl);
    cout << '\n';

    c.set_password(prl);
    c.set_username(usr);

    return in;
}

class User
{
private:
    string username;
    string password;
    bool rezervari[1001]={0};

public:
    User()
    {
        username = "";
        password = "";
    }

    string get_username() const
    {
        return this->username;
    }
    string get_password() const
    {
        return this->password;
    }
    void set_username(string usr)
    {
        username = usr;
    }
    void set_password(string pas)
    {
        password = pas;
    }
    void set_rezervari(int i)
    {
        rezervari[i]=1;
    }
    friend istream &operator>>(istream &in, User &c);
};

istream &operator>>(istream &in, User &c)
{
    string usr, prl;

LOOP8:
    try
    {
        cout << "Introduceti username-ul: ";
        getline(in, usr);
        //cout<<'\n';
        if(usr[0]<'a' ||usr[0]>'z')
            throw 0;
        int arond = -1, punct = -1;
        for(int i=0; i<usr.length(); i++)
        {
            if(usr[i]=='@')
                if(arond != -1)
                    throw 0;
                else
                    arond = i;
            if(usr[i]=='.')
                punct = i;
        }
        if(arond == -1 || punct == -1)
            throw 0;
        if(punct < arond)
            throw 0; ///nu avem punct dupa @
        if(punct >= (usr.length() -1))
            throw 0;

    }
    catch(int x)
    {
        cout<<"Dati un email valid\n";
        goto LOOP8;
    }


LOOP9:
    try
    {
        cout << "Introduceti parola: ";
        getline(in, prl);
        //cout << '\n';
        if(prl.length()<8)
            throw 0;
    }
    catch(int x)
    {
        cout<<"Dati o parola cu minim 8 caractere\n";
        goto LOOP9;
    }


    c.set_password(prl);
    c.set_username(usr);

    return in;
}

class Flight
{
private:
    string destinatie;
    string plecare;
    string ora_plecare;
    string ora_sosire;
    string nr_escale;
    string data;
    int id;
    static int cnt;

public:
    Flight(string d, string p, string op, string os, string n, string dt);

    int get_id() const
    {
        return this->id;
    }
    string get_destinatie() const
    {
        return this->destinatie;
    }
    string get_plecare() const
    {
        return this->plecare;
    }
    string get_ora_plecare() const
    {
        return this->ora_plecare;
    }
    string get_ora_sosire() const
    {
        return this->ora_sosire;
    }
    string get_data() const
    {
        return this->data;
    }
    string get_nr_escale() const
    {
        return this->nr_escale;
    }
    void set_data(string dt)
    {
        data = dt;
    }
    void set_destinatie(string dest)
    {
        destinatie = dest;
    }
    void set_plecare(string plec)
    {
        plecare = plec;
    }
    void set_ora_plecare(string oraplec)
    {
        ora_plecare = oraplec;
    }
    void set_ora_sosire(string orasos)
    {
        ora_sosire = orasos;
    }
    void set_nr_escale(string esc)
    {
        nr_escale = esc;
    }

    friend ostream &operator<<(ostream &out, const Flight &c);
    friend istream &operator>>(istream &in, Flight &c);
};

int Flight::cnt = 0;

Flight::Flight(string d = "", string p = "", string op = "", string os = "", string n = "", string dt = "")
{
    destinatie = d;
    plecare = p;
    ora_plecare = op;
    ora_sosire = os;
    nr_escale = n;
    data = dt;
    cnt++;
    id = cnt;
}

ostream &operator<<(ostream &out, const Flight &c)
{
    out << "Zborul " << c.get_id() << '\n';
    out << "Plecare din: " << c.get_plecare() << '\n';
    out << "Aterizare in: " << c.get_destinatie() << '\n';
    out << "Data zborului: " << c.get_data() << '\n';
    out << "Numarul de escale al zborului: " << c.get_nr_escale() << '\n';
    out << "Ora de plecare: " << c.get_ora_plecare() << " || Ora de sosire: " << c.get_ora_sosire() << '\n';

    return out;
}

istream &operator>>(istream &in, Flight &c)
{
    string plec, ajung, dt, ora_plec, ora_ajung, escale;

LOOP:
    try
    {
        cout << "Introduceti orasul de plecare: ";
        getline(in, plec);
        int lg = plec.length();
        for (int i = 0; i < lg; i++)
            if (!isalpha(plec[i]))

                throw 0;
    }
    catch (int x)
    {
        cout << "Dati un oras de plecare valid\n";
        goto LOOP;
    }

LOOP2:
    try
    {
        cout << "Introduceti orasul destinatie: ";
        getline(in, ajung);
        int lg = ajung.length();
        for (int i = 0; i < lg; i++)
            if (!isalpha(ajung[i]))
                throw 0;
    }
    catch (int x)
    {
        cout << "Dati un oras destinatie valid\n";
        goto LOOP2;
    }

    ///time_t data_actuala = chrono::system_clock::to_time_t(chrono::system_clock::now()); daca fac asta imi da data curent in milisecunde
    ///setez o variabila data_curenta pentru usurinta
    string data_curenta = "2020.12.06";
LOOP3:
    try
    {
        cout << "Introduceti data zborului (formatul AAAA.LL.ZZ): ";
        getline(in, dt);

        string y = dt.substr(0,4);
        string m = dt.substr(5,2);
        string d = dt.substr(8,2);

        if (y > "9999" || y < "1800")
            throw 0;
        if (m < "01" || m > "12")
            throw 0;
        if (d < "01" || d > "31")
            throw 0;
        if (m == "02")
            if(d>"29")
                throw 0;
        if (m == "04" || m == "06" || m == "09" || m == "11")
            if(d>"30")
                throw 0;

        if(dt.compare(data_curenta)<0)
            throw 0; ///data e in trecut
    }
    catch (int x)
    {
        cout << "Dati o data valida\n";
        goto LOOP3;
    }
LOOP4:
    try
    {
        cout << "Introduceti ora de plecare (hh:mm): ";
        getline(in, ora_plec);

        string h = ora_plec.substr(0,2);
        string m = ora_plec.substr(3,2);

        if(h<"00" || h> "23")
            throw 0;
        if(m<"00" || m> "59")
            throw 0;

    }
    catch(int x)
    {
        cout<<"Dati o ora valida\n";
        goto LOOP4;
    }


LOOP5:
    try
    {
        cout << "Introduceti ora la care se ajunge (hh:mm): ";
        getline(in, ora_ajung);

        string h = ora_ajung.substr(0,2);
        string m = ora_ajung.substr(3,2);

        if(h<"00" || h> "23")
            throw 0;
        if(m<"00" || m> "59")
            throw 0;

    }
    catch(int x)
    {
        cout<<"Dati o ora valida\n";
        goto LOOP5;
    }

LOOP6:
    try
    {
        cout << "Introduceti numarul de escale: ";
        getline(in, escale);

        for(int i=0; i<escale.length(); i++)
            if(escale[i]<'0' ||escale[i] > '9')
                throw 0;

    }

    catch(int x)
    {
        cout<<"Dati un numar valid de escale\n";
        goto LOOP6;
    }
    cout << '\n';
    c.set_plecare(plec);
    c.set_destinatie(ajung);
    c.set_data(dt);
    c.set_ora_plecare(ora_plec);
    c.set_ora_sosire(ora_ajung);
    c.set_nr_escale(escale);

    return in;
}

int main()
{

    vector<Flight> zboruri;
    vector<User *> conturi;

    Flight z1("Londra", "Bucuresti", "14:25", "13:25", "1", "2021.02.14");
    zboruri.push_back(z1);

    Flight z2("Bahamas", "Puerto Rico", "15:17", "14:18", "0", "2021.01.16");
    zboruri.push_back(z2);

    char op;

    do
    {
        cout << "Introduceti optiunea:\nu -> register/login pentru utilizator\no -> login pentru operator\n";
        cin >> op;

        switch (op)
        {
        case 'o':
        {

            char *enter = new char;
            gets(enter);
            delete enter; ///astea ca sa nu avem probleme cu enterul de la final(de la u sau o)
            try
            {
                Operator usr_operator;

                cin >> usr_operator;

                if (usr_operator.get_password() == "a2410" && usr_operator.get_username() == "larisa01")
                    cout << "Autentificare reusita! Va rugam, continuati...\n";
                else
                    throw 0;
            }
            catch (int x)
            {
                cout << "Username sau parola gresita.\nVa rugam incercati din nou.\n\n\n";
                break;
            }

            int op_operator;
            do
            {
                cout << "Introduceti o optiune (1-4) :\n 1.Citire a n zboruri \n 2.Adaugare zbor nou \n 3.Sterge zbor dupa numar \n 4.Afisare zboruri \n Sau orice altceva pentru a iesi\n";
                cin >> op_operator;

                char *enter = new char;
                gets(enter);
                delete enter;

                switch (op_operator)
                {
                case 1:
                {
                    cout << "Introduceti cate zboruri doriti...\n";
                    int n;
                    cin >> n;
                    char *enter = new char;
                    gets(enter);
                    delete enter;
                    for (int i = 0; i < n; i++)
                    {
                        Flight p;
                        cin >> p;
                        zboruri.push_back(p);
                    }
                    break;
                }
                case 2:
                {
                    Flight p;
                    cin >> p;
                    zboruri.push_back(p);
                    break;
                }
                case 3:
                {
                    int id_to_search;
                    int ok = 0;
                    try
                    {

                        cout << "ID = ";
                        cin >> id_to_search;
                        for (unsigned int i = 0; i < zboruri.size(); i++)
                        {
                            if (zboruri[i].get_id() == id_to_search)
                            {
                                zboruri.erase(zboruri.begin() + i);
                                ok=1;
                            }
                        }
                        if(ok==0)
                            throw 0;
                    }
                    catch(int x)
                    {
                        cout<<"Nu exista un zbor cu id-ul dat.\n";
                        break;
                    }
                    break;
                }
                case 4:
                {
                    try
                    {
                        if(zboruri.size()==0)
                            throw 0;
                        for (unsigned int i = 0; i < zboruri.size(); i++)
                            cout << zboruri[i] << '\n';
                        break;
                    }
                    catch(int x)
                    {
                        cout<<"Nu exista zboruri.\n";
                        break;
                    }
                }
                default:
                {
                    cout<<"Iesim din meniul operatorului.\n";
                    break;
                }
                }

            }
            while (op_operator >= 1 && op_operator <= 4);
            break;
        }

        case 'u':
        {
            //char * enter = new char;
            //gets(enter);
            //delete enter;

            int opt_usr;
            cout << "Introduceti optiunea (1-3):\n 1 -> Register\n 2 -> Login\n 3-> Instructiuni autentificare\n";
            cin >> opt_usr;

            //char * enter1 = new char;
            //gets(enter1);
            //delete enter1;

            if (opt_usr != 1 && opt_usr != 2 && opt_usr != 3)
            {
                cout << "Dati un numar de la 1 la 3!!!\n";
                break;
            }
            if (opt_usr == 3)
            {
                cout << "Atunci cand programul ruleaza pentru prima data se deschide un meniu in care putem alege sa lucram ca si Operator \nsau ca si Utilizator normal. ";
                cout << "Pentru optiunea \"o\" ne vom loga ca si Operator si putem modifica anumite date importante.\n";
                cout << "Pentru cealalta optiune, ne putem inregistra sau loga ca si Utilizatori normali.\n";
                break;
            }
            else if (opt_usr == 1)
            {
                char *enter = new char;
                gets(enter);
                delete enter;

LOOP7:
                try
                {
                    User *p = new User;
                    cin >> *p;
                    for (unsigned int i = 0; i < conturi.size(); i++)
                        if (p->get_username() == conturi[i]->get_username())
                            throw 0;
                    conturi.push_back(p);
                }
                catch(int x)
                {
                    cout<<"Username-ul deja exista, dati altul!\n\n";
                    goto LOOP7;
                }
            }
            else
            {
                char *enter = new char;
                gets(enter);
                delete enter;
                try
                {

                    Operator usr_user;
                    cin >> usr_user;

                    int ok = 0;
                    for (unsigned int i = 0; i < conturi.size(); i++)
                    {
                        if (conturi[i]->get_username() == usr_user.get_username() && conturi[i]->get_password() == usr_user.get_password())
                        {
                            cout << "Autentificare reusita! Va rugam, continuati...\n";
                            ok = 1;
                            continue;
                        }
                    }
                    if(ok==0)
                        throw 0;
                }


                catch(int x)
                {
                    cout << "Username sau parola gresita.\nVa rugam incercati din nou.\n\n\n";
                    break;
                }
            }
            int op_user;
            do
            {
                cout << "Introduceti o optiune (1,2 sau 3) :\n 1.Cautare zbor dupa numar\n 2.Rezervare zbor\n 3.Afisare zboruri \nAltceva = LOGOUT\n";
                cin >> op_user;

                char *enter = new char;
                gets(enter);
                delete enter;

                switch (op_user)
                {
                case 1:
                {
                    int id_to_search, ok=0;
                    try
                    {
                        cout << "ID = ";
                        cin >> id_to_search;
                        for (unsigned int i = 0; i < zboruri.size(); i++)
                        {
                            if (zboruri[i].get_id() == id_to_search)
                            {
                                cout << zboruri[i] << endl;
                                ok=1;
                                break;
                            }

                        }
                        if(ok==0)
                            throw 0;
                    }
                    catch(int x)
                    {
                        cout<<"Nu exista un zbor cu id-ul dat.\n";
                        break;
                    }
                    break;
                }
                case 2:
                {

                    int id_to_search;
                    int ok=0;

                    try{

                    cout << "Introduceti ID-ul zborului pentru rezervare: ";
                    cin >> id_to_search;
                    for (unsigned int i = 0; i < zboruri.size(); i++)
                    {
                        if (zboruri[i].get_id() == id_to_search)
                        {
                            conturi[i]->set_rezervari(id_to_search);
                            cout<<"Rezervarea pentru zborul "<<id_to_search<<" a fost creata cu success!\n";
                            ok = 1;
                            break;
                        }
                    }
                    if(ok == 0)
                        throw 0;
                    //break;
                    }

                    catch(int x)
                    {
                        cout<<"Zborul cu id-ul dat nu exista.\n";
                        break;
                    }
                    break;
                }
                case 3: ///Afisare zboruri
                {
                    try
                    {
                        if(zboruri.size()==0)
                            throw 0;
                        for (unsigned int i = 0; i < zboruri.size(); i++)
                            cout << zboruri[i] << '\n';
                        break;
                    }
                    catch(int x)
                    {
                        cout<<"Nu exista zboruri\n";
                        break;
                    }
                    break;
                }
                default:
                {
                    cout << "Ati iesit din modul utilizator.\n";
                    break;
                }
                }

            }
            while (op_user >= 1 && op_user <= 3);
            break;
        }

        default:
        {
            cout << "Nu ati introdus o optiune valida." << endl;
        }
        }
    }
    while (op == 'u' || op == 'o');

    return 0;
}
