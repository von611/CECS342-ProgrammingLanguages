#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Struct declaration.
struct person{ 
  char name[20];
  int age;
};

// Prototype Declarations
int numCompare(const void*, const void*);     //Number comparator
int pplNameCompare(const void*, const void*);  //Person comparator by name.
int pplAgeCompare(const void*, const void*);  //Person comparator by age.
void printNum(float * arr, int n);            //Print number array.
void printPeople(struct person * arr, int n); //Print people array

int main(void) {
  //Array of floats.
  float numbers[] = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26}; 
  //Size of float type.
  int numbersSize = sizeof numbers[0];
  //Size of array "numbers".
  int numbersLength = sizeof numbers/numbersSize;

  //Fill the array of structs with the people.
  struct person people[] = {{"Hal", 20}, {"Susann", 31}, {"Dwight", 19}, {"Kassandra", 21}, {"Lawrence", 25}, {"Cindy", 22}, 
  {"Cory", 27}, {"Mac", 19}, {"Romana", 27}, {"Doretha", 32}, {"Danna", 20}, {"Zara", 23}, {"Rosalyn", 26}, {"Risa", 24}, {"Benny", 28},
  {"Juan", 33}, {"Natalie", 25}}; 
  //The size of the struct "person"
  int peopleSize = sizeof people[0];
  //Length of the people array.
  int peopleLength = sizeof people/peopleSize;

  //Sort numbers ascending.
  qsort(numbers, numbersLength, numbersSize, numCompare);
  //Print Array
  printf("Sort numbers:\n");
  printNum(numbers, numbersLength);
  
  //Sort people alphabetically by name.
  qsort(people, peopleLength, peopleSize, pplNameCompare);
  //Print Array
  printf("\nSort by Name:\n");
  printPeople(people, peopleLength);

  //Create new array with duplicates to reset sort.
  struct person people2[] = {{"Hal", 20}, {"Susann", 31}, {"Dwight", 19}, {"Kassandra", 21}, {"Lawrence", 25}, {"Cindy", 22}, 
  {"Cory", 27}, {"Mac", 19}, {"Romana", 27}, {"Doretha", 32}, {"Danna", 20}, {"Zara", 23}, {"Rosalyn", 26}, {"Risa", 24}, {"Benny", 28},
  {"Juan", 33}, {"Natalie", 25}}; 

  //Sort people2 descending by age, same age are sorted alphabetically.
  qsort(people2, peopleLength, peopleSize, pplAgeCompare);
  //Print Array
  printf("\nSort by Age:\n");
  printPeople(people2, peopleLength);

  return 0;
}

//Compare element A and element B, reuturning a positive, a negative, or 0.
int numCompare(const void * eleA, const void * eleB){
  return (*(float*)eleA-*(float*)eleB) * 100; //Multiply by 100 to ensure that doubles are not truncated, and returned as 0 on accident.
}

//Sort people by name.
int pplNameCompare(const void * eleA, const void * eleB){
  while ( *(char*)eleA != '\0'          //Test if first element is not null.
    && *(char*)eleA == *(char*)eleB ){  //If element A and B are equal iterate through list.  
    ++eleA; //Pre-increment since previous element has been compared alread.
    ++eleB; //Moves to next element in both A and B.
  }
  return (*(char*)eleA - *(char*)eleB); //Compares both values acii values and returns the difference.
}

//People sorted by age.
int pplAgeCompare(const void * eleA, const void * eleB){
  //Create a copy of each struct for accessing elements.
  //This was required to access struct elements.
  struct person a = *(struct person*) eleA;
  struct person b = *(struct person*) eleB;
  //Output of comparisons.
  int output;

  if(a.age == b.age){ //If element A and B are the same Age compare names.
    output = strcmp(a.name, b.name); //Simple string compare version.
  }
  else //Else difference in age.
    output = b.age-a.age;
//Return the output.
return output;
}

// Print number method.
void printNum(float* arr, int n){
  // Starting bracket.
  printf("[ ");
  // For loop equal to the length of the array.
  for(int i = 0; i < n; i++){
    //Print the element at the ith position.
    printf("%.2f", arr[i]); 
    //If that element is not the last element add a comma and space for formatting.
    if(n > 0 && i < n-1)
      printf(", ");
  }
  // Ending bracket.
  printf(" ]\n"); 
} 

// Print people structs.
void printPeople(struct person * arr, int n){
  //Pritn all structs.
  for(int i = 0; i < n; i++){
    printf("Name: %-10s \tAge: %d\n", arr[i].name, arr[i].age);
  }
}