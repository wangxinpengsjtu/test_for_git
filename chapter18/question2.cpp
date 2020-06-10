#include <iostream>
#include <string>

using namespace std;
class Cpmv
{
public:
    struct Info
    {
        string qcode;
        string zcode;
    };
private:
    Info* pi;
    static int count;
public:
    Cpmv();
    Cpmv(string q, string z);
    Cpmv(const Cpmv& cp);
    Cpmv(Cpmv&& mv);
    ~Cpmv();
    Cpmv& operator=(const Cpmv& cp);
    Cpmv& operator=(Cpmv&& mv);
    Cpmv operator+(const Cpmv& obj) const;
    void Display() const;
};

int Cpmv::count = 0;

Cpmv::Cpmv()
{
    ++count;
    pi = new Info;
    pi->qcode = "null";
    pi->zcode = "null2";
    cout << "default constructor..." << count << " objects" << endl;
}

Cpmv::Cpmv(string q, string z)
{
    ++count;
    pi = new Info;
    pi->qcode = q;
    pi->zcode = z;
    cout << "qz cons..." << count << " objects" << endl;
}

Cpmv::Cpmv(const Cpmv& cp)
{
    ++count;
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
    cout << "copy constructor..." << count << " objects" << endl;
}

Cpmv::Cpmv(Cpmv&& mv)
{
    ++count;
    pi = new Info;
    pi = mv.pi;
    mv.pi = nullptr;
    cout << "move copy constructor..." << count << " objects" << endl;
}

Cpmv::~Cpmv()
{
    cout << "decons..." << --count << " objects left" << endl;
    //Display();
    delete pi;
}

Cpmv& Cpmv::operator=(const Cpmv& cp)
{
    if (&cp == this)
        return *this;
    delete pi;
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
    cout << "normal = cons..." << endl;
    return *this;
}

Cpmv& Cpmv::operator=(Cpmv&& mv)
{
    if (&mv == this)
        return *this;
    delete pi;
    pi = mv.pi;
    mv.pi = nullptr;
    cout << "move = cons..." << endl;
    return *this;
}

//Cpmv Cpmv::operator+(const Cpmv& obj) const
//{
//    Cpmv p;
//    p.pi->qcode = pi->qcode + obj.pi->qcode;
//    p.pi->zcode = pi->zcode + obj.pi->zcode;
//    cout << "normal + ..." << endl;
//    return p;
//}

Cpmv Cpmv::operator+(const Cpmv& obj) const
{
    pi->qcode += obj.pi->qcode;
    pi->zcode += obj.pi->zcode;
    cout << "normal + ..." << endl;
    return *this;
}

void Cpmv::Display() const
{
    cout << "qcode is: " << pi->qcode << endl;
    cout << "zcode is: " << pi->zcode << endl;
}

int main()
{
    Cpmv temp;
    cout << "Object 0:\n";
    temp.Display();
    cout << endl;

    Cpmv temp1("number one", "number two");
    cout << "Object 1:\n";
    temp1.Display();
    cout << endl;

    Cpmv temp2(temp);
    cout << "Object 2:\n";
    temp2.Display();
    cout << endl;

    cout << "Object 3 = Object 1:\n";
    Cpmv temp3;
    temp3 = temp1;
    cout << "Object 3:\n";
    temp3.Display();
    cout << endl;

    cout << "Object 1:\n";
    temp1.Display();
    cout << endl;

    cout << "Object 4 = move(Obejct 2):\n";
    Cpmv temp4;
    temp4 = move(temp2);
    cout << "Object 4:\n";
    temp4.Display();
    cout << endl;

    //cout << "Object 2:\n";
    //temp2.Display();
    //cout << endl;

    cout << "Obejct 5 = Object 3 + Obejct 4:\n";
    Cpmv temp5 = temp3 + temp4;
    cout << "Obejct 5:\n";
    temp5.Display();

    return 0;
}
