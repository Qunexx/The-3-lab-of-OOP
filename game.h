#include <iostream>
#include <string>

using namespace std;

class Element
{
protected:
    string name, racca, gender, clas, age, religion, height, weight, nationality, profession;

    class Element* next = NULL;

public:

    Element(string name, string racca, string gender, string clas, string age, string religion, string height, string weight, string nationality, string profession);
    string getName() { return this->name; };
    string getRacca() { return this->racca; };
    string getGender() { return this->gender; };
    string getClas() { return this->clas; };
    string getAge() { return this->age; };
    string getReligion() { return this->religion; };
    string getHeight() { return this->height; };
    string getWeight() { return this->weight; };
    string getNationality() { return this->nationality; };
    string getProfession() { return this->profession; };
    
    void setName(string name) { this->name = name; }
    void setRacca(string racca) { this->racca = racca; }
    void setGender(string gender) { this->gender = gender; }
    void setClas(string clas) { this->clas = clas; }
    void setAge(string age) { this->age = age; }
    void setReligion(string religion) { this->religion = religion; }
    void setHeight(string height) { this->height = height; }
    void setWeight(string weight) { this->weight = weight; }
    void setNationality(string nationality) { this->nationality = nationality; }
    void setProfession(string profession) { this->profession = profession; }

    int amount();
    void addElement(class Element* element);
    class Element* getPrevios();
    void insertElement(class Element* element);
    class Element* deleteElement(class Element* now);
    void deleteAll();
    class Element* getNext(class Element* start);

    //����������
    class Element* operator = (Element* element); // ����������, �������� ������������

    bool operator == (Element& element);
    bool operator != (Element& element);
    // ��������� ��������� ��������� ������
    bool operator < (Element& element);
    bool operator <= (Element& element);
    bool operator > (Element& element);
    bool operator >= (Element& element);
    // ���� �� ������ ��������� ��������� ������
    friend std::istream& operator >> (std::istream& in, Element& element);
    // ����� � ����� ��������� ��������� ������
    friend std::ostream& operator << (std::ostream& out, Element& element);
    
};

Element::Element(string name, string racca, string gender, string clas, string age, string religion, string height, string weight, string nationality, string profession)
{
    this->name = name;
    this->racca = racca;
    this->gender = gender;
    this->clas = clas;
    this->age = age;
    this->religion = religion;
    this->height = height;
    this->weight = weight;
    this->nationality = nationality;
    this->profession = profession;

    this->next = NULL;

    cout << "������ ������� � ������� " << this << endl;

}

Element* Element::operator = (Element& element)
{
    this->name = element.name;
    this->racca = element.racca;
    this->gender = element.gender;
    this->clas = element.clas;
    this->age = element.age;
    this->religion = element.religion;
    this->height = element.height;
    this->weight = element.weight;
    this->nationality = element.nationality;
    this->profession = element.profession;
}

bool Element::operator != (Element& element)
{
    if (this->name != element.name &&
        this->racca != element.racca &&
        this->gender != element.gender &&
        this->clas != element.clas &&
        this->age != element.age &&
        this->religion != element.religion &&
        this->height != element.height &&
        this->weight != element.weight &&
        this->nationality != element.nationality &&
        this->profession != element.profession)
    {
        return true;
    }
    else return false;

}

bool Element::operator == (Element& element)
{
    if (this->name == element.name &&
        this->racca == element.racca &&
        this->gender == element.gender &&
        this->clas == element.clas &&
        this->age == element.age &&
        this->religion == element.religion &&
        this->height == element.height &&
        this->weight == element.weight &&
        this->nationality == element.nationality &&
        this->profession == element.profession)
    {
        return true;
    }
    else return false;

}

bool Element::operator < (Element& element)
{
    if (this->getHeight() < element.getHeight())
    {
        return true;
    }
    else return true;
}

bool Element::operator <= (Element& element)
{
    if (this->getHeight() <= element.getHeight())
    {
        return true;
    }
    else return true;
}

bool Element::operator > (Element& element)
{
    if (this->getHeight() > element.getHeight())
    {
        return true;
    }
    else return true;
}

bool Element::operator >= (Element& element)
{
    if (this->getHeight() >= element.getHeight())
    {
        return true;
    }
    else return true;
}

std::istream& operator >> (std::istream& in, Element* element)
{
    cout << "name, racca, gender, clas, age, religion, height, weight, nationality, profession" << endl;
    string name, racca, gender, clas, age, religion, height, weight, nationality, profession;


    in >> name;
    in >> racca;
    in >> gender;
    in >> clas;
    in >> age;
    in >> religion;
    in >> height;
    in >> weight;
    in >> nationality;
    in >> profession;

    element->setName(name);
    element->setRacca(racca);
    element->setGender(gender);
    element->setClas(clas);
    element->setAge(age);
    element->setReligion(religion);
    element->setHeight(height);
    element->setWeight(weight);
    element->setNationality(nationality);
    element->setProfession(profession);

    return in;
}

std::ostream& operator << (std::ostream& out, Element* element)
{
    out << "��� - " << element->getName() << endl;
    out << "��� - " << element->getGender() << endl;
    out << "����� - " << element->getRacca() << endl;
    out << "����� - " << element->getClas() << endl;
    out << "������� - " << element->getAge() << endl;
    out << "������� - " << element->getReligion() << endl;
    out << "���� - " << element->getHeight() << endl;
    out << "��� - " << element->getWeight() << endl;
    out << "�������������� - " << element->getNationality() << endl;
    out << "��������� - " << element->getProfession() << endl;
    
    return out;
}

int Element::amount()
{
    class Element* tmp;
    tmp = this;
    int count = 0;
    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    return count;
}

class Element* Element::getPrevios()
{
    class Element* tmp;
    tmp = this;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    return tmp;
}

void Element::addElement(class Element* element)
{
    this->getPrevios()->next = element;
}

void Element::insertElement(class Element* element)
{
    class Element* oldNext = this->next;
    this->next = element;
    element->next = oldNext;
}

class Element* Element::deleteElement(class Element* now)
{
    class Element* tmp = this;
    class Element* previos;
    while (tmp->next != NULL)
    {
        if (tmp->next == now)
        {
            previos = tmp;
            previos->next = now->next;
            delete now;
            return previos;
        }
        tmp = tmp->next;
    }
}

void Element::deleteAll()
{
    class Element* next;
    class Element* tmp = this;
    do
    {
        next = tmp->next;
        cout << "������" << tmp << endl;
        delete tmp;
        tmp = next;

    } while (tmp != NULL);
    cout << "��������� �������� ���������" << endl;
    exit(0);
}

class Element* Element::getNext(class Element* start)
{
    cout << "�� ���������� � " << this << endl;

    if (this->next == NULL)
    {
        return start;
    }
    else
    {
        return this->next;
    }
}

class spisok
{
protected:
    class Element* start;
    class Element* now;

public:
    spisok();
    ~spisok();

    void initStruct();
    void checkStruct();
    int amount();
    void append();
    void insert();
    void deleteElem();
    void deleteAll();
    void changePosition();
    void getInfo();


    class Element* getStart() { return this->start; };

    //����������
    //������������ ����� ��������� ������ ������
    spisok* operator = (spisok* spis);
    //��������� ��������� ��������� ������
    bool operator < (spisok& spis);
    bool operator <= (spisok& spis);
    bool operator > (spisok& spis);
    bool operator >= (spisok& spis);
    //��������� �� ��������� �������� ������
    bool operator == (spisok& spis);
    bool operator != (spisok& spis);
};

spisok::spisok()
{
    this->start = NULL;
    this->now = NULL;
}

spisok::~spisok()
{
    this->deleteAll();
}

spisok* spisok::operator = (spisok* spis)
{
    this->start = spis->getStart();
    return this;
}

bool spisok::operator < (spisok& spis)
{
    if (this->amount() < spis.amount())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool spisok::operator <= (spisok& spis)
{
    if (this->amount() <= spis.amount())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool spisok::operator > (spisok& spis)
{
    if (this->amount() > spis.amount())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool spisok::operator >= (spisok& spis)
{
    if (this->amount() >= spis.amount())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool spisok::operator == (spisok& spis)
{
    if (this->amount() == spis.amount())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool spisok::operator != (spisok& spis)
{
    if (this->amount() != spis.amount())
    {
        return true;
    }
    else
    {
        return false;
    }
}
void spisok::initStruct()
{
    string name, racca, gender, clas, age, religion, height, weight, nationality, profession;


    cout << "������� ��� : ";
    cin >> name;
    cout << "������� ����� : ";
    cin >> racca;
    cout << "������� ��� : ";
    cin >> gender;
    cout << "������� ����� : ";
    cin >> clas;
    cout << "������� ������� : ";
    cin >> age;
    cout << "������� ������� : ";
    cin >> religion;
    cout << "������� ���� : ";
    cin >> height;
    cout << "������� ��� : ";
    cin >> weight;
    cout << "������� �������������� : ";
    cin >> nationality;
    cout << "������� ��������� : ";
    cin >> profession;

    this->start = new Element(name, racca, gender, clas, age, religion, height, weight, nationality, profession);

    this->now = this->start;
}



void spisok::checkStruct()
{
    if (this->start != NULL)
    {
        cout << "� ������ ���� ��������" << endl;
    }
    else
    {
        cout << "� ������ ��� ���������" << endl;
    }
}

int spisok::amount()
{
    return this->start->amount();
}

void spisok::append()
{
    string name, racca, gender, clas, age, religion, height, weight, nationality, profession;

    cout << "������� ��� : ";
    cin >> name;
    cout << "������� ����� : ";
    cin >> racca;
    cout << "������� ��� : ";
    cin >> gender;
    cout << "������� ����� : ";
    cin >> clas;
    cout << "������� ������� : ";
    cin >> age;
    cout << "������� ������� : ";
    cin >> religion;
    cout << "������� ���� : ";
    cin >> height;
    cout << "������� ��� : ";
    cin >> weight;
    cout << "������� �������������� : ";
    cin >> nationality;
    cout << "������� ��������� : ";
    cin >> profession;

    class Element* freshElem = new Element(name, racca, gender, clas, age, religion, height, weight, nationality, profession);

    this->start->addElement(freshElem);
}

void spisok::insert()
{
    string name, racca, gender, clas, age, religion, height, weight, nationality, profession;

    cout << "������� ��� : ";
    cin >> name;
    cout << "������� ����� : ";
    cin >> racca;
    cout << "������� ��� : ";
    cin >> gender;
    cout << "������� ����� : ";
    cin >> clas;
    cout << "������� ������� : ";
    cin >> age;
    cout << "������� ������� : ";
    cin >> religion;
    cout << "������� ���� : ";
    cin >> height;
    cout << "������� ��� : ";
    cin >> weight;
    cout << "������� �������������� : ";
    cin >> nationality;
    cout << "������� ��������� : ";
    cin >> profession;

    class Element* freshElem = new Element(name, racca, gender, clas, age, religion, height, weight, nationality, profession);

    this->now->insertElement(freshElem);
}

void spisok::deleteElem()
{
    this->now = this->start->deleteElement(this->now);
}

void spisok::deleteAll()
{
    this->start->deleteAll();
}

void spisok::changePosition()
{
    this->now = this->now->getNext(this->start);
    cout << "�� ������� � " << this->now << endl;
}

void spisok::getInfo()
{
    cout << this->now << endl;
    cout << "��� : " << this->now->getName() << endl;
    cout << "����� : " << this->now->getRacca() << endl;
    cout << "��� : " << this->now->getGender() << endl;
    cout << "����� : " << this->now->getClas() << endl;
    cout << "������� : " << this->now->getAge() << endl;
    cout << "������� : " << this->now->getReligion() << endl;
    cout << "���� : " << this->now->getHeight() << endl;
    cout << "��� : " << this->now->getWeight() << endl;
    cout << "�������������� : " << this->now->getNationality() << endl;
    cout << "��������� : " << this->now->getProfession() << endl;
}

void menu()
{
    cout << "1)�������� �� ������� ��������� � ��������� ������       " << endl;
    cout << "2)��������� ���������� ���������  � ��������� ������     " << endl;
    cout << "3)���������� ��������  � ��������� ������                " << endl;
    cout << "4)������� �������� � ��������� ������ ����� ��������     " << endl;
    cout << "5)�������� �������� �������� ��������� ������            " << endl;
    cout << "6)������� ��������� ������                               " << endl;
    cout << "7)����������� �� ��������� ��������� ������(�� ���������)" << endl;
    cout << "8)������ ���������� �� �������� �������� ��������� ������" << endl;
    cout << "9)����� �� ���������                                     " << endl;
    cout << endl;
}
