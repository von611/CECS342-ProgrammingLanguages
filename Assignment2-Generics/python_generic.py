from operator import attrgetter

# Defining the sequence of floating point numbers into a python list
numbers = [645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26]

# Define a Person class
class Person:
  # Initialize the Person object with a given name and age
  def __init__(self, name, age): 
        self.name=name
        self.age=age

  # Define how to display a Person object to the console with a string representation
  def __str__(self):
      return self.name + ", " + str(self.age)

  # Define how people objects are compared, utilized by sorted() function call
  def __lt__(self, other):
    #compare this person object to the other person object
    return  self.name < other.name

# Defining the sequence of people as a python list of Person objects
people = [Person("Hal", 20),
      Person("Sussan", 31), 
      Person("Dwight", 19),
      Person("Kassandra", 21),
      Person("Lawrence", 25),
      Person("Cindy", 22),
      Person("Cory", 27),
      Person("Mac", 19 ),
      Person("Romana", 27),
      Person("Doretha", 32),
      Person("Danna", 20 ),
      Person("Zara", 23 ),
      Person("Rosalyn", 26),
      Person("Risa", 24),
      Person("Benny",28 ),
      Person("Juan", 33 ),
      Person("Natalie", 25 )]

# (i) # Sorting numbers ascending by numerical value 
print("Sorted Numbers:")
numbersSorted = sorted(numbers) # Sort float values in the numbers list
print(str(numbersSorted)) # Print the sorted values
print("\n----------------------------------------------------------------")

# (ii) # Sorting people alphabetically (lexicographically) by name 
print("Sorted People By Name:")
# Sort People object list by name as defined in class
peopleByName = sorted(people)
# Print Person objects in the sorted list
for person in peopleByName:
  print(person)
print("\n----------------------------------------------------------------")

# (iii) Sort people descending by age, then be sorted alphabetically (lexicographically) 
print("Sorted People Descending By Age:")
# Sort Person objects by eq method in the Person class, then by "age" attribute in reverse
peopleByAge = sorted(sorted(people), key = attrgetter("age"), reverse = True) 
# Print Person objects in the sorted list
for person in peopleByAge:
  print(person)

