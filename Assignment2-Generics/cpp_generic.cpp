#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//create struct for a Person
struct Person {
  string name;
  int age;
};

//comparison function for name
bool sortByName(const Person &firstPerson, const Person &secondPerson) {
  //return true if the person's name 
  return firstPerson.name < secondPerson.name;
}

bool sortByAge(const Person &firstPerson, const Person &secondPerson) {
  return firstPerson.age <= secondPerson.age;
}

//comparison function for both age and name
bool sortByAgeAndName(const Person &firstPerson, const Person &secondPerson) {
  if(firstPerson.age > secondPerson.age) {
      return true;
      //if the persons ages equal to each other compare their names then return
  } else if(firstPerson.age == secondPerson.age) {
    return firstPerson.name < secondPerson.name;
  }
  
  return false;
}

int main() {
    //initialize array
    float numbers[12] = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26};

    cout << "Sorting numbers..." << endl;
    //start sort from the beginning of the array upto the end last element
    sort(numbers, numbers + 12);
    //iterate through each element in the array and print
    for (int i = 0; i != 12; ++i) {
        cout << numbers[i] << ", ";
    }
    cout << endl;
    
    //initialize vector array that holds Person structs
    vector<Person> people;
    //add Person objects to the back of the vector array
    people.push_back({"Hal", 20});
    people.push_back({"Susann", 31});
    people.push_back({"Dwight", 19});
    people.push_back({"Kassandra", 21});
    people.push_back({"Lawrence", 25});
    people.push_back({"Cindy", 22});
    people.push_back({"Cory", 27});
    people.push_back({"Mac", 19});
    people.push_back({"Romana", 27});
    people.push_back({"Doretha", 32});
    people.push_back({"Dana", 20});
    people.push_back({"Zara", 23});
    people.push_back({"Rosalyn", 26});
    people.push_back({"Risa", 24});
    people.push_back({"Benny", 28});
    people.push_back({"Juan", 33});
    people.push_back({"Natalie", 25});
    
    cout << "Sorting people by name..." << endl;
    //pass pointers of the first and last element and the comparison function
    //the value returned indicates if the first element is to go before the second element
    sort(people.begin(), people.end(), sortByName);
    for(Person &p : people) {
      cout << p.name << ", " << p.age << "; ";
    }
    cout << endl;

    cout << "Sorting people by age..." << endl;
    sort(people.begin(), people.end(), sortByAgeAndName);
    for(Person &p : people) {
      cout << p.name << ", " << p.age << "; ";
    }

    return 0;
}