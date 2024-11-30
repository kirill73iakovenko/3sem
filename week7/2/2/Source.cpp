#include <iostream>
#include <string>

using namespace std;

class Spell {
protected:
    string name;
public:
    virtual void cast() = 0;
    string get_name() {
        return name;
    }
    Spell(string p_name): name{ p_name } {}
};

class Strong_Attack_Spell : public Spell {
public:
    Strong_Attack_Spell(string p_name) : Spell(p_name) {}
        
    void cast() {
        cout << "Strong Attack!" << " "<< name <<endl;
    }
};

class Weak_Attack_Spell : public Spell {
public:
    Weak_Attack_Spell(string p_name) : Spell(p_name) {}
    void cast()  {
        cout << "Weak Attack!" << " " << name  << endl;
    }
};

class Strong_Defense_Spell : public Spell {
public:
    Strong_Defense_Spell(string p_name) : Spell(p_name) {}
    void cast() {
        cout << "Strong Defense!" << " " << name << endl;
    }
};

class Weak_Defense_Spell : public Spell {
public:
    Weak_Defense_Spell(string p_name) : Spell(p_name) {}
    void cast()  {
        cout << "Weak Defense!" << " " << name  << endl;
    }
};



class Strong_Household_Spell : public Spell {
public:
    Strong_Household_Spell(string p_name) : Spell(p_name) {}
    void cast() {
        cout << "Strong household spell!" << " " << name << endl;
    }
};

class Weak_Household_Spell : public Spell {
public:
    Weak_Household_Spell(string p_name) : Spell(p_name) {}
    void cast() {
        cout << "Weak household Spell!" << " " << name << endl;
    }
};

class Strong_Unforgiven_Spell : public Spell {
public:
    Strong_Unforgiven_Spell(string p_name) : Spell(p_name) {}
    void cast() {
        cout << "Strong unforgiven spell!" << " " << name << endl;
    }
};

class Weak_Unforgiven_Spell : public Spell {
public:
    Weak_Unforgiven_Spell(string p_name) : Spell(p_name) {}
    void cast() {
        cout << "Weak unforgiven spell!" << " " << name << endl;
    }
};


class SpellFactory {
public:
    virtual Spell* createStrongSpell( string) = 0;
    virtual Spell* createWeakSpell(const string) = 0;
};

class AttackSpellFactory : public SpellFactory {
public:
    Spell* createStrongSpell(string p_name)  {
        return new Strong_Attack_Spell(p_name);
    }

    Spell* createWeakSpell(string p_name)  {
        return new Weak_Attack_Spell(p_name);
    }
};

class DefenseSpellFactory : public SpellFactory {
public:
    Spell* createStrongSpell(string p_name)  {
        return new Strong_Defense_Spell(p_name);
    }

    Spell* createWeakSpell(string p_name)  {
        return new Weak_Defense_Spell(p_name);
    }
};

class HouseholdSpellFactory : public SpellFactory {
public:
    Spell* createStrongSpell(string p_name) {
        return new Strong_Household_Spell(p_name);
    }

    Spell* createWeakSpell(string p_name) {
        return new Weak_Household_Spell(p_name);
    }
};

class UnforgivenSpellFactory : public SpellFactory {
public:
    Spell* createStrongSpell(string p_name) {
        return new Strong_Unforgiven_Spell(p_name);
    }

    Spell* createWeakSpell(string p_name) {
        return new Weak_Unforgiven_Spell(p_name);
    }
};

class SpellBook {
private:
    static const int MAX = 10;
    Spell* spells[MAX];
    int size;

public:
    SpellBook() : size(0) {
        for (int i = 0; i < MAX; ++i) {
            spells[i] = nullptr;
        }
    }

    ~SpellBook() {
        for (int i = 0; i < size; ++i) {
            delete spells[i];
        }
    }
    template <typename T>
    void addSpell(T* spell) {
        for (int i = 0; i < size; ++i) {
            if (spells[i]->get_name() == spell->get_name()) {
                cout << "Warning! Spell " << spell->get_name() << " already exists in the spell book." << endl;
                delete spell;
                return;
            }
        }
        if (size < MAX) {
            spells[size++] = spell;
            cout << "Spell " << spell->get_name() << " add to the spell book." << endl;
        }
        else {
            cout << "Warning! Spell book is full! Can't add more spells." << endl;
        }
    }
    
    void castAll() {
        cout << "Spells from the book: " << endl;
        for (int i = 0; i < size; ++i) {
            spells[i]->cast();
        }
    }
};

int main() {
    SpellBook spellBook; 

    SpellFactory* attackFactory = new AttackSpellFactory();
    SpellFactory* defenseFactory = new DefenseSpellFactory();
    SpellFactory* householdFactory = new HouseholdSpellFactory();
    SpellFactory* unforgivenFactory = new UnforgivenSpellFactory();


    spellBook.addSpell(attackFactory->createStrongSpell("Attack in head"));
    spellBook.addSpell(attackFactory->createWeakSpell("Attack in leg"));
    spellBook.addSpell(attackFactory->createStrongSpell("Nut"));
    spellBook.addSpell(attackFactory->createWeakSpell("Nut"));

    spellBook.addSpell(defenseFactory->createStrongSpell("Secret defense"));
    spellBook.addSpell(defenseFactory->createStrongSpell("Impact protection"));
    spellBook.addSpell(defenseFactory->createWeakSpell("Run out"));

    spellBook.addSpell(householdFactory->createStrongSpell("Clean room"));
    spellBook.addSpell(householdFactory->createWeakSpell("Clean table"));

    spellBook.addSpell(unforgivenFactory->createStrongSpell("Kill human"));
    spellBook.addSpell(unforgivenFactory->createStrongSpell("Kill mosquito"));

    spellBook.addSpell(unforgivenFactory->createStrongSpell("Kill fish"));



    delete attackFactory; 
    delete defenseFactory; 
    delete householdFactory;
    delete unforgivenFactory;

    spellBook.castAll(); 

    return 0;
}