#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Spell {
protected:
    string name;
    const string type;
    const string sort;
public:
    virtual void cast() = 0;
    virtual string get_type() = 0;
    string get_name() {
        return name;
    }
    string get_sort() {
        return sort;
    }

    Spell(string p_name, string p_sort) : name{ p_name }, sort{ p_sort } {}
};

class WeakSpell :public Spell {
protected:
    const string type = "weak";
public:
    WeakSpell(string p_name, string p_sort) : Spell(p_name, p_sort) {}
    string get_type() {
        return type;
    }
};

class StrongSpell :public Spell {
protected:
    const string type = "strong";
public:
    StrongSpell(string p_name, string p_sort) : Spell(p_name, p_sort) {}
    string get_type() {
        return type;
    }
};

class Strong_Attack_Spell : public StrongSpell {
protected:
    const string sort = "attack";
public:
    Strong_Attack_Spell(string p_name) : StrongSpell(p_name, "attack") {}
    void cast() {
        cout << "Strong Attack!" << " " << name << endl;
    }
    string get_sort() {
        return sort;
    }
};

class Weak_Attack_Spell : public WeakSpell {
protected:
    const string sort = "attack";
public:
    Weak_Attack_Spell(string p_name) : WeakSpell(p_name, "attack") {}
    void cast() {
        cout << "Weak Attack!" << " " << name << endl;
    }
};

class Strong_Defense_Spell : public StrongSpell {
protected:
    const string sort = "defence";
public:
    Strong_Defense_Spell(string p_name) : StrongSpell(p_name, "defence") {}
    void cast() {
        cout << "Strong Defense!" << " " << name << endl;
    }
};

class Weak_Defense_Spell : public WeakSpell {
protected:
    const string sort = "defence";
public:
    Weak_Defense_Spell(string p_name) : WeakSpell(p_name, "defence") {}
    void cast() {
        cout << "Weak Defense!" << " " << name << endl;
    }
};


class SpellFactory {
public:
    virtual Spell* createStrongSpell(string) = 0;
    virtual Spell* createWeakSpell(string) = 0;
};

class AttackSpellFactory : public SpellFactory {
public:
    Spell* createStrongSpell(string p_name) {
        return new Strong_Attack_Spell(p_name);
    }

    Spell* createWeakSpell(string p_name) {
        return new Weak_Attack_Spell(p_name);
    }
};

class DefenseSpellFactory : public SpellFactory {
public:
    Spell* createStrongSpell(string p_name) {
        return new Strong_Defense_Spell(p_name);
    }

    Spell* createWeakSpell(string p_name) {
        return new Weak_Defense_Spell(p_name);
    }
};



class SpellBook {
protected:
    static const int MAX = 10;
    Spell* attackSpells[MAX];
    Spell* defenseSpells[MAX];
    int attackSize;
    int defenseSize;
    const string type;

public:
    SpellBook() : attackSize(0), defenseSize(0) {
        for (int i = 0; i < MAX; ++i) {
            attackSpells[i] = nullptr;
            defenseSpells[i] = nullptr;
        }
    }

    ~SpellBook() {
        for (int i = 0; i < attackSize; ++i) {
            delete attackSpells[i];
        }
        for (int i = 0; i < defenseSize; ++i) {
            delete defenseSpells[i];
        }
    }


    virtual void addSpell(Spell* spell) {}

    void castAll() {
        cout << "Attack spells from the book:" << endl;
        for (int i = 0; i < attackSize; ++i) {
            attackSpells[i]->cast();
        }

        cout << "Defense spells from the book:" << endl;
        for (int i = 0; i < defenseSize; ++i) {
            defenseSpells[i]->cast();
        }
    }

    string get_type() {
        return type;
    }
    int getAttackSize() {
        return attackSize;
    }

    int getDefenseSize() {
        return defenseSize;
    }


    Spell* getAttackSpell(int index) {
        if (index >= 0 && index < attackSize) {
            return attackSpells[index];
        }
        return nullptr;
    }

    Spell* getDefenseSpell(int index) {
        if (index >= 0 && index < defenseSize) {
            return defenseSpells[index];
        }
        return nullptr;
    }
};
class BadSpellBook : public SpellBook {
protected:
    const string type = "bad";
public:
    BadSpellBook() : SpellBook() {}
    void addSpell(Spell* spell) {
        if (spell->get_sort() == "attack") {
            for (int i = 0; i < attackSize; ++i) {
                if (attackSpells[i]->get_name() == spell->get_name()) {
                    cout << "Warning! Spell " << spell->get_name() << " already exists in the spell book." << endl;
                    delete spell;
                    return;
                }
            }
            if (attackSize < MAX) {
                if (spell->get_type() == "weak") {
                    attackSpells[attackSize++] = spell;
                    cout << "Spell " << spell->get_name() << " added to the spell book (attack)." << endl;
                }
                else {
                    cout << "Spell " << spell->get_name() << " is too good." << endl;
                    delete spell;
                }
            }
            else {
                cout << "Warning! Spell book is full! Can't add more spells." << endl;
            }
        }
        else {
            for (int i = 0; i < defenseSize; ++i) {
                if (defenseSpells[i]->get_name() == spell->get_name()) {
                    cout << "Warning! Spell " << spell->get_name() << " already exists in the spell book." << endl;
                    delete spell;
                    return;
                }
            }
            if (defenseSize < MAX) {
                if (spell->get_type() == "weak") {
                    defenseSpells[defenseSize++] = spell;
                    cout << "Spell " << spell->get_name() << " added to the spell book (defense)." << endl;
                }
                else {
                    cout << "Spell " << spell->get_name() << " is too good." << endl;
                    delete spell;
                }
            }
            else {
                cout << "Warning! Spell book is full! Can't add more spells." << endl;
            }
        }
    }
};

class GoodSpellBook : public SpellBook {
protected:
    const string type = "good";
public:
    GoodSpellBook() : SpellBook() {}
    void addSpell(Spell* spell) {
        if (spell->get_sort() == "attack") {
            for (int i = 0; i < attackSize; ++i) {
                if (attackSpells[i]->get_name() == spell->get_name()) {
                    cout << "Warning! Spell " << spell->get_name() << " already exists in the spell book." << endl;
                    delete spell;
                    return;
                }
            }
            if (attackSize < MAX) {
                if (spell->get_type() == "strong") {
                    attackSpells[attackSize++] = spell;
                    cout << "Spell " << spell->get_name() << " added to the spell book (attack)." << endl;
                }
                else {
                    cout << "Spell " << spell->get_name() << " is too bad." << endl;
                    delete spell;
                }
            }
            else {
                cout << "Warning! Spell book is full! Can't add more spells." << endl;
            }
        }
        else {
            for (int i = 0; i < defenseSize; ++i) {
                if (defenseSpells[i]->get_name() == spell->get_name()) {
                    cout << "Warning! Spell " << spell->get_name() << " already exists in the spell book." << endl;
                    delete spell;
                    return;
                }
            }
            if (defenseSize < MAX) {
                if (spell->get_type() == "strong") {
                    defenseSpells[defenseSize++] = spell;
                    cout << "Spell " << spell->get_name() << " added to the spell book (defense)." << endl;
                }
                else {
                    cout << "Spell " << spell->get_name() << " is too bad." << endl;
                    delete spell;
                }
            }
            else {
                cout << "Warning! Spell book is full! Can't add more spells." << endl;
            }
        }
    }
};

//abstract class
class Character {
protected:
    float XP = 100;
    string name;
    int level;
    const string type;
public:
    Character(string p_name, string p_type, int p_level) : name{ p_name }, type{ p_type }, level{ p_level } {}
    virtual string get_type() = 0;

    int get_level() {
        return level;
    }
    float get_XP() {
        return XP;
    }
    string get_name() {
        return name;
    }
    void damage(float num) {
        if (XP > num) {
            XP = XP - num;
        }
        else {
            XP = 0;
        }
    }
    virtual float attack() = 0;
    virtual float defence() = 0;
    virtual void addSpellBook(SpellBook* newSpellBook) = 0;

};

class Monster : public Character {
protected:
    const string type = "monster";
public:
    Monster(string p_name, int p_level) : Character(p_name, "monster", p_level) {}
    string get_type() {
        return type;
    }


    float attack() {
        float life_num = XP / 200 + 0.5;
        float power = 20 * level * life_num;
        return power;
    }
    float defence() {
        return 0;
    }
    void addSpellBook(SpellBook* newSpellBook) {};

};

class Magician : public Character {
protected:
    SpellBook* spellbook;
    int attack_use_spell = 0;
    int defense_use_spell = 0;
    const string type = "mag";
public:
    Magician(string p_name, int p_level) : Character(p_name, "mag", p_level) {}
    string get_type() {
        return type;
    }



    void castOffensiveSpell(int index) {
        if (spellbook && index >= 0 && index < spellbook->getAttackSize()) {
            cout << name << " casts offensive spell" << endl;

            attack_use_spell += 1;
        }
        else {
            cout << "Invalid offensive spell index." << endl;

        }
    }

    void castDefensiveSpell(int index) {
        if (spellbook && index >= 0 && index < spellbook->getDefenseSize()) {
            cout << name << " casts defensive spell" << endl;

            defense_use_spell += 1;
        }
        else {
            cout << "Invalid defensive spell index." << endl;

        }
    }
    float attack() {
        if (spellbook->get_type() == "good") {
            if (attack_use_spell < spellbook->getAttackSize()) {
                castOffensiveSpell(attack_use_spell);
                float power = 50 + XP / 10;
                return power;
            }
            else
            {
                cout << "The spells are over.Hand-to-hand combat."<< endl;
                return 1;
            }
        }
        else {
            if (attack_use_spell < spellbook->getAttackSize()) {

                castOffensiveSpell(attack_use_spell);
                float power = 25 + XP / 10;
                return power;

            }
            else
            {
                cout << "The spells are over.Hand-to-hand combat."<< endl;
                return 1;
            }
        }
    }
    float defence() {
        if (spellbook->get_type() == "good") {
            if (attack_use_spell < spellbook->getDefenseSize())
            {
                castDefensiveSpell(defense_use_spell);
                float power = 0.6;
                return power;

            }
            else
            {
                cout << "The spells are over. No defence."<< endl;
                return 0;
            }
        }
        else {
            if (attack_use_spell < spellbook->getDefenseSize()) {
                castDefensiveSpell(defense_use_spell);
                float power = 0.3;
                return power;

            }
            else
            {
                cout << "The spells are over. No defence."<<endl;
                return 0;
            }
        }
    }
    void addSpellBook(SpellBook* newSpellBook) {
        if (spellbook != nullptr) {
            delete spellbook;
        }
        if (newSpellBook->get_type() == "good" and level == 1) {
            cout << "Too good book" << endl;
        }
        else {
            cout << "Book add" << endl;
            spellbook = newSpellBook;
        }
    }

};

// fabric method
class CharacterFactory {
public:
    virtual Character* createCharacter(string , int) = 0;
};
class MonsterFactory : public CharacterFactory {
public:
    Character* createCharacter(string name, int level) override {
        return new Monster(name, level);
    }
};

class MagicianFactory : public CharacterFactory {
public:

    Character* createCharacter(string name, int level) override {
        return new Magician(name, level);
    }
};




Character* Duel(Character* fighter_1, Character* fighter_2) {
    float attack_num = 0;
    float defence_num = 0;
    cout << "Duel between " << fighter_1->get_name() << " and " << fighter_2->get_name() << " starts" << endl;
    while (fighter_1->get_XP() != 0 or fighter_2->get_XP() != 0) {
        attack_num = fighter_1->attack();
        
        defence_num = fighter_2->defence();
        fighter_2->damage(attack_num * (1 - defence_num));
        
        if (fighter_2->get_XP() == 0) {
            cout << "Winner: " << fighter_1->get_name() << endl;
            cout << "Duel end" << endl;
            return fighter_1;
            break;
        }
        attack_num = fighter_2->attack();
        
        defence_num = fighter_1->defence();
        fighter_1->damage(attack_num * (1 - defence_num));

        
        if (fighter_1->get_XP() == 0) {
            cout << "Winner: " << fighter_2->get_name() << endl;
            cout << "Duel end" << endl;
            return fighter_2;
            break;
            
        }
    }

    if (fighter_2->get_XP() == 0) {
        cout << "Winner: " << fighter_1->get_name() << endl;
        cout << "Duel end" << endl;
        return fighter_1;
    }
    if (fighter_1->get_XP() == 0) {
        cout << "Winner: " << fighter_2->get_name() << endl;
        cout << "Duel end" << endl;
        return fighter_2;
    }
}

class Army {
private:
    string name;
    Character** characters;
    int count;
    int capacity;
public:
    Army(string p_name) : name(p_name), characters(nullptr), count(0), capacity(1) {
        characters = new Character * [capacity];
    }
    

    ~Army() {
        for (int i = 0; i < count; ++i) {
            delete characters[i];
        }
        delete[] characters;
    }
    string get_name() {
        return name;
    }

    void addCharacter(Character* character) {
        if (count >= capacity) {
            capacity += 1 ;
            Character** newCharacters = new Character * [capacity];
            for (int i = 0; i < count; ++i) {
                newCharacters[i] = characters[i];
            }
            delete[] characters;
            characters = newCharacters;
        }
        characters[count++] = character;
    }

    Character& getCharacter(int index) {
        return *characters[index];
    }
    int getCount() {
        return count;
    }
};




void War(Army* army1, Army* army2) {
    int index1 = 0;
    int index2 = 0;

    while (index1 < army1->getCount() && index2 < army2->getCount()) {
        Character* winner = Duel(&army1->getCharacter(index1), &army2->getCharacter(index2));

        if (winner == &army1->getCharacter(index1)) {
            index2++; 
        }
        else {
            index1++; 
        }
    }

    if (index1 < army1->getCount()) {
        cout << army1->get_name() << " win." << endl;
    }
    else {
        cout << army2 -> get_name() << " win." << endl;
    }
}
// func read a file and create army
Army createArmy(ifstream& file) {
    CharacterFactory* monster_factory = new MonsterFactory();
    CharacterFactory* magician_factory = new MagicianFactory();
    string armyName;
    getline(file, armyName);
    string line;
    Army army(armyName);

    int numMonsters = 0;
    file >> ws;
    file >> numMonsters;
    cout << "a: " << numMonsters << endl;

    for (int i = 0; i < numMonsters; ++i) {
        string name;
        int level;
        file >> ws;
        file >> name >> level;
        army.addCharacter(monster_factory->createCharacter(name, level));
    }

    int numMagicians = 0;
    file >> ws;
    file >> numMagicians;
    cout << "a: " << numMagicians << endl;
    for (int i = 0; i < numMagicians; ++i) {
        string name;
        int level;
        file >> ws;
        file >> name >> level;
        army.addCharacter(magician_factory->createCharacter(name, level));
     }

    return army;
}
void addSpellBook(Army* army, int magicianIndex, SpellBook* spellBook) {
    if (magicianIndex < army->getCount()) {
        Character* character = &army->getCharacter(magicianIndex);
        if (character->get_type() == "mag") {
            character->addSpellBook(spellBook);
        }
        else {
            cout << "Monster cannot have spell book " << endl;
        }
    }
    else {
        cout << "Mistake in index" << endl;
    }
        
}





int main() {
    GoodSpellBook* NewSpellBook_1 = new GoodSpellBook();
    BadSpellBook* OldSpellBook_1 = new BadSpellBook();
    GoodSpellBook* NewSpellBook_2 = new GoodSpellBook();
    SpellFactory* attackFactory = new AttackSpellFactory();
    SpellFactory* defenseFactory = new DefenseSpellFactory();



    NewSpellBook_1->addSpell(attackFactory->createStrongSpell("Attack in head"));
    NewSpellBook_1->addSpell(defenseFactory->createStrongSpell("Secret defense"));
    NewSpellBook_1->addSpell(attackFactory->createStrongSpell("Attack in heart"));
    NewSpellBook_1->addSpell(attackFactory->createStrongSpell("Attack1"));
    OldSpellBook_1->addSpell(attackFactory->createWeakSpell("Weak_Attack1"));
    OldSpellBook_1->addSpell(attackFactory->createWeakSpell("Weak_Attack2"));
    OldSpellBook_1->addSpell(defenseFactory->createWeakSpell("Weak_defense1"));
    NewSpellBook_2->addSpell(attackFactory->createStrongSpell("Attack in head"));
    ifstream inputFile1("army1.txt");

    if (!inputFile1) {
        cerr << "Unable to open file";
        return 1; 
    }

   
    Army* White_Army = new Army(createArmy(inputFile1));
    

    inputFile1.close();

    ifstream inputFile2("army2.txt");

    if (!inputFile2) {
        cerr << "Unable to open file";
        return 1;
    }


    Army* Red_Army = new Army(createArmy(inputFile2));


    inputFile2.close();

    addSpellBook(White_Army, 1, NewSpellBook_1);
    addSpellBook(White_Army, 2, NewSpellBook_2);
    addSpellBook(Red_Army, 1, OldSpellBook_1);

   

    
    War(White_Army, Red_Army);

    return 0;


    delete attackFactory;
    delete defenseFactory;
    delete White_Army;
    delete Red_Army;

    return 0;
}