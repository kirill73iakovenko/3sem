#include <iostream>

using namespace std;



class Animal {
	friend class Vet;
protected:
	int age;
	string breed;
	string name;
public:
	Animal(int p_age, string p_breed, string p_name)
		: age{ p_age }, breed{ p_breed }, name{ p_name } {}
	virtual void MakeSound() = 0;
	virtual void Set_XP(int p_XP) = 0;
	virtual int Get_XP() = 0;
	void Get_animal() {
		cout << "Age: " << age << endl;
		cout << "Breed: " << breed << endl;
		cout << "Name: " << name << endl;

	}
};

class Dog : public Animal {
	friend class Vet;
private:
	int XP;
public:
	Dog(int p_age, string p_breed, string p_name) : Animal(p_age, p_breed, p_name){}
	void Set_XP(int p_XP) {
		XP = p_XP;
	}
	int Get_XP() {
		cout << name <<  " XP: " << XP << endl;
		return XP;
	}
	void MakeSound() {
		cout << "Gav" << "\n";
	}
};


class Cat : public Animal {
	friend class Vet;
private:
	int XP;
public:
	Cat(int p_age, string p_breed, string p_name) : Animal(p_age, p_breed, p_name) {}
	void Set_XP(int p_XP) {
		XP = p_XP;
	}
	int Get_XP() {
		cout << name <<  " XP: " << XP << endl;
		return XP;
	}
	void MakeSound() {
		cout << "Myau" << "\n";
	}
};

class Owner {
private:
	const string name;
	int age;
	int num_of_animals = 0;
	Animal** animals;

public:
	Owner(string p_name, int p_age) : name(p_name), age(p_age)
	{
		animals = new Animal * [5];
	}
	~Owner() {
		for (int i = 0; i < num_of_animals; ++i) {
			delete animals[i];
		}
		delete[] animals;
	}

	void Add_animal(Animal* animal) {
		if (num_of_animals < 5) {
			animals[num_of_animals] = animal;
			num_of_animals += 1;
		}
		else {
			cout << "Too much animals" << endl;
		}
	}

	void Get_owner() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Number of animals: " << num_of_animals << endl;
		cout << "Animals: " << endl;
		for (int i = 0; i < num_of_animals; ++i) {
			animals[i]->Get_animal();
		}

	}
	string Get_name() {
		return name;
	}
	int Get_num() {
		return num_of_animals;
	}
	Animal** Get_animals() {
		return animals;
	}
};

class Vet {
private:
	const string name;
	int expeience;
	int examination(Animal* animal) {
		return animal->Get_XP();
	}
	string treatment(Animal * animal) {
		string conc;
		int XP = examination(animal);
		if (XP < 10) {
			conc = " needs urgent help. XP is increased by 10.";
			animal->Set_XP(XP + 10);
		}
		else if (10 <= XP and XP < 30) {
			conc = " has problem. XP is increased by 3.";
			animal->Set_XP(XP + 3);
		}
		else {
			conc = " is alright";
		}
		return conc;
	}
		
	
public:
	Vet(string p_name, int p_exp) : name(p_name), expeience(p_exp) {}
	void Speech(Owner& owner) {
		Animal** arr = owner.Get_animals();
		int num = owner.Get_num();
		string res;
		string a_name;
		for (int i = 0; i < num; ++i) {
			Animal* panimal = arr[i];
			res = treatment(panimal);
			a_name = panimal->name;
			cout << a_name << res << endl;
		}
	}
	
};



int main() {
	Animal* Barbos = new Dog(2, "sheepdog", "Barbos");
	Barbos->Set_XP(17);
	Barbos->Get_animal();
	Barbos->Get_XP();
	Barbos->MakeSound();

	Animal* Vasya = new Cat(12, "Siberian cat", "Vasya");
	Vasya->Set_XP(70);
	Vasya->Get_animal();
	Vasya->Get_XP();
	Vasya->MakeSound();

	Owner Idrisov("Idrisov Sergey", 19);
	Idrisov.Add_animal(Barbos); 
	Idrisov.Add_animal(Vasya);  
	Idrisov.Get_owner();


	Vet Sakbaev("Sakbaev Vsevolod Janovich", 7);
	Sakbaev.Speech(Idrisov);
	Barbos->Get_XP();
	Vasya->Get_XP();

	return 0;
}