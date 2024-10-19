#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    const string name;
    const string surname;
    int group;
    int age;
    double XP;
    double money;
    double student_time;
    double time;
    // знания измеряются в часах учебы
    double knowlenge=0; 
    // опыт работы измеряются в рабочих часах
    double work_experience=0;
public:
    int mark;

 
    Student(string p_name, string p_surname, int p_group, int p_age, double p_XP, double p_money, int p_mark)
        : name{ p_name }, surname{ p_surname }, group{ p_group }, age{ p_age }, XP{ p_XP }, money{ p_money }, student_time{ 0 }, time{ 24 }, mark{ p_mark } {}
    Student(string p_name, string p_surname, int p_group, double p_XP, double p_money, int p_mark)
        : Student(p_name, p_surname, p_group, 19, p_XP, p_money, p_mark) {}
    Student(string p_name, string p_surname, int p_group, int p_age, double p_XP, double p_money)
        : Student(p_name, p_surname, p_group, p_age, p_XP, p_money, 10) {}
    Student(string p_name, string p_surname, int p_group, double p_XP, double p_money)
        : Student(p_name, p_surname, p_group, 19, p_XP, p_money, 10) {}


    void Check() {
        if (XP < 0) {
            cout << "The student went to the academic leave" << endl;
        }
        if (time < 0) {
            cout << "The next day starts" << endl;
            time += 24;
        }
    }

    void Get_student() {
        cout << "Name and surname: " << name << " " << surname << endl;
        cout << "Group: " << group << endl;
        cout << "Age: " << age << endl;
        cout << "XP: " << XP << endl;
        cout << "Money: " << money << endl;
        cout << "Student time: " << student_time << endl;
        cout << "Knoweledge: " << knowlenge << endl;
        cout << "Work experience: " << work_experience << endl;
        cout << "Time: " << time << endl;
        cout << "Mark: " << mark << endl;
        Check();
    }

    double Get_XP() {
        return XP;
        Check();
    }

    double Get_money() {
        return money;
        Check();
    }

    double Get_time() {
        return time;
        Check();
    }

    void Food(double v_money) {
        if (v_money == 0 || v_money > money) {
            cout << "Error: no money" << endl;
        }
        else {
            XP += v_money / 10;
            time += v_money / 1000;
            money -= v_money;
        }
        Check();
    }

    void Studing(double v_time) {
        time -= v_time;
        student_time += v_time;
        knowlenge += v_time;
        if (student_time > 24) {
            XP -= 3 * v_time * 7.5;
        }
        else {
            XP -= v_time * 7.5;
        }
        Check();
    }
    void Working(double v_time) {
        time -= v_time;
        student_time += v_time;
        work_experience += v_time;
        money = money + 500 * v_time;
        if (student_time > 24) {
            XP -= 3 * v_time * 10;
        }
        else {
            XP -= v_time * 10;
        }
        Check();
    }
    

    void Sleep(double v_time) {
        if (v_time > 6) {
            student_time = 0;
        }
        XP += v_time * 10;
        time -= v_time;
        Check();
    }

    void Relax(double v_money) {
        if (v_money == 0 || v_money > money) {
            cout << "Error: no money" << endl;
        }
        else {
            if (student_time > 24) {
                XP += v_money / 60;
            }
            else {
                XP += v_money / 20;
            }
        time += v_money / 1000;
        money -= v_money;
        Check();
        }
    }
};

int main() {
    string name1 = "Ivan";
    string surname1 = "Ivanov";
    int group1 = 304;
    int age1 = 20;
    double XP1 = 100000;
    double money1 = 1000000;
    Student Student1{ name1, surname1, group1, age1, XP1, money1, 9};
    Student1.Get_student();
    Student1.Studing(24);
    cout << "Student1 XP after 24 hours studying: " << Student1.Get_XP() << endl;
    
    string name2 = "Sergey";
    string surname2 = "Idrisov";
    int group2 = 306;
    double XP2 = 500;
    double money2 = 1000;
    
    Student Idrisov{ name2, surname2, group2,XP2, money2};
    Idrisov.Get_student();
    Idrisov.Food(500);
    cout << "Idrisov after dinner: " << endl;
    cout << "XP: " << Idrisov.Get_XP() << endl;
    cout << "money: " << Idrisov.Get_money() << endl;
    Idrisov.Studing(2.5);
    cout << "Idrisov after studing: " << endl;
    cout << "XP: " << Idrisov.Get_XP() << endl;
    Idrisov.Working(3);
    cout << "Idrisov after working: " << endl;
    cout << "XP: " << Idrisov.Get_XP() << endl;
    cout << "money: " << Idrisov.Get_money() << endl;
    cout << "Idrisov after studing: " << endl;
    Idrisov.Studing(20);
    Idrisov.Sleep(7);
    cout << "Idrisov after sleep: " << endl;
    Idrisov.Get_student();
    cout << "Idrisov want to eat: " << endl;
    Idrisov.Food(7000);
    cout << "Idrisov after work: " << endl;
    Idrisov.Working(16);
    cout << "XP: " << Idrisov.Get_XP() << endl;


    
    return 0;
}