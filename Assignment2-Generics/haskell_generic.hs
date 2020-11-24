import Data.List (sort, sortOn)

-- Define a Person data type 
data Person = Person { 
    name :: String, -- name projections 
    age :: Int } -- age projections
    deriving (Eq) -- deriving clause

-- Declare an order on Persons 
instance Ord Person where
   compare p q  -- Compare Person 1 and Person 2
    | ageCompare == EQ = compare (name p) (name q) -- If the ages are equal, then compare the names
    | otherwise = ageCompare -- If the ages are not equal, then compare the ages
    where ageCompare = compare (age q) (age p) -- define ageCompare function

-- Declare a custom Show instance to print a Person data type to console
instance Show Person where
  show p = " " ++ (name p) ++ " " ++ (show(age p)) -- custom print statement for a Person data type

-- Define main program
main = do
  -- Declare numbers list
  let numbers = [645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26]
  putStrLn "Sorted Numbers Ascending by Numerical Value:"  -- Print sorted statement
  print (sort numbers) -- Print sorted numbers 
  putStrLn("----------------------------------------------------------------") -- Print divider statement

  -- Declare people list
  let people = [Person "Hal" 20, Person "Susann" 31, Person "Dwight" 19, Person "Kassandra" 21, Person "Lawrence" 25, Person "Cindy" 22, Person "Cory" 27, Person "Mac" 19, Person "Romana" 27,Person "Doretha" 32, Person "Danna" 20, Person "Zara" 23, Person "Rosalyn" 26, Person "Risa" 24,Person "Benny" 28, Person "Juan" 33, Person "Natalie" 25 ]
  putStrLn "Sorted People Alphabetically by Name:" -- Print sorted statement
  print(sortOn name people) -- Print sorted People by name 
  putStrLn("----------------------------------------------------------------") -- Print divider statement
  putStrLn "Sort People by Age (descending):" -- Print sorted statement
  print(sort people) -- Print sorted People by age 
