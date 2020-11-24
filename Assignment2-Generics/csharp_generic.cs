//Import statements
using System;
using System.Linq;
using System.Collections.Generic;

//Person Class declaration 
public class Person : IComparable{
  //The person's name
  public string name;
  //The person's age
  public int age;

  //Person constructor  
  public Person(string n, int a){
    //set the n parameter to name attribute
    name = n;
    //set the a parameter to the age attribute
    age = a;
  }//end person constructor

  //overide the toSting meathod for Person
  public override string ToString(){
    //return formated string of attributes as "name, age"
    return name + ", " + age;
  }//end ToString

  //define how Persons are compared for sorting
  public int CompareTo(object other){
    //if passed a null pointer return 1
    if (other == null) return 1;

    //attempt to cast the passed parameter as a Person object
    Person otherPerson = other as Person;

    //check if passed parameter was successfully casted as Person
    if (otherPerson != null)
      //compare the other person to this person by name
      return this.name.CompareTo(otherPerson.name);
    else
      //throw exception if the passed parameter could not be casted to a person
      throw new ArgumentException("Object is not a Person");
  }//end CompareTo

}//end Person class



//class to test the code
public class Lab3Driver
{
  //main meathod
	public static void Main()
	{
    //declare array of numbers 
    double[] numbers = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26};

    //sort the array of numbers using the built in Array.Sort()
    Array.Sort(numbers);

    //Print title for sorted list of numbers
    Console.WriteLine("-----------Sorted list of numbers-----------");
    //delcare string to format list of numbers
    String line = "[";
    //iterate through the array of numbers
    foreach (double num in numbers)
      //append the number and a comma
      line += num + ", ";
    //remove the last space and comma
    line = line.TrimEnd().Substring(0, line.Length - 2);
    //add a closing bracket
    line += "]";  
    //print the sorted list 
    Console.WriteLine(line + "\n");


    //declare an array of people
		List<Person> people = new List<Person>() {
      new Person("Hal", 20),
      new Person("Sussan", 31), 
      new Person("Dwight", 19),
      new Person("Kassandra", 21),
      new Person("Lawrence", 25),
      new Person("Cindy", 22),
      new Person("Cory", 27),
      new Person("Mac", 19 ),
      new Person("Romana", 27),
      new Person("Doretha", 32),
      new Person("Danna", 20 ),
      new Person("Zara", 23 ),
      new Person("Rosalyn", 26),
      new Person("Risa", 24),
      new Person("Benny",28 ),
      new Person("Juan", 33 ),
      new Person("Natalie", 25 ) };

    //sort the array using the CompareTo as defined in Person class
		people.Sort();
    
    //print the title for people sorted by name
    Console.WriteLine("-----------People sorted by name-----------");
		//iterate through the list of people
    foreach (Person p in people)
      //print the info for each person
      Console.WriteLine(p);

    //create IEnumerable object of type Person with the people sorted by age
    //note: people with same age will then be sorted by name as defined in CompareTo in Person class
    IEnumerable<Person> peopleByAge = people.OrderBy(person => person.age);

    //print the title for people sorted by age
    Console.WriteLine("\n-----------People sorted by age-----------");
    //iterate through the list of people sorted by age
    foreach (Person p in peopleByAge)
      //print the info for each person
      Console.WriteLine(p);
	}//end main
}//end class