#include <iostream>
#include <map>
#include <string>

using namespace std;

class Person {
private:
	string name;
	int age;

public:

	Person() :
			name(""), age(0) {

	}

	Person(string name, int age) :
			name(name), age(age) {

	}

	Person(const Person& other) {
		name = other.name;
		age = other.age;
	}

	void print() const {
		cout << name << ": " << age << flush;
	}

	bool operator<(const Person &other) const {

		if (name == other.name) {
			return age < other.age;
		} else {
			return name < other.name;
		}
	}
};

int main() {
	map<Person, int> people;

	people[Person("Mike", 40)] = 40;
	people[Person("Mike", 444)] = 123;
	people[Person("Sue", 30)] = 30;
	people[Person("Raj", 40)] = 20;

	for (map<Person, int>::iterator it = people.begin(); it != people.end();
			it++) {
		cout << it->second << ": " << flush;
		it->first.print();
		cout << endl;
	}

	return 0;
}
