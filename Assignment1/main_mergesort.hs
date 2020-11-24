module BasicLanguageConstructs where

--take two lists as input and merges both the lists
combine :: (Ord a) => [a]-> [a] ->[a]
--case where the first list is empty and the second list is not, return the second list
combine [] ys = ys
--case where the second list is empty and the first list is not, return the first list
combine xs [] = xs
combine (x:xs)(y:ys) =
  --compares both of the first elements in the lists
    if (x>=y)
    --if the first element is greater than or equal to the first element in the second list, then append append the y element in the beginning of the list and recursively call the function again but with the elements of the second list excluding the first element of that list and the first list
    then y:combine ys (x:xs)
    --else vice versa
    else x:combine xs (y:ys)

--take list of element and return the same type
msort:: (Ord a) => [a] -> [a]
--function to merge sort a list
msort xs =
  --checks if the list contains more than one element
   if (length xs)> 1
   --if the statement returns true it then recursively calls the sort function for both the first half and second half of the list
   --it will respectively half those lists until it returns only one element
   --once it returns with only one element for both halves of the list, it then calls the combine function and merges the two lists together
   --after it merges the lists it returns the new list and returns back to where they were halfed
   then combine(msort(take ((length xs) `div` 2) xs))(msort (drop((length xs) `div` 2) xs))
   --else if the list is empty or only has one it returns the list
   else xs

