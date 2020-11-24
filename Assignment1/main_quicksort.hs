-- import predule and override filter function 
module FunctionsProducingLists where
import Prelude hiding (filter)

-- class defined filter , will return list with numbers less than argument 
-- e.g. fitler (<3) [0,2,4,6] returns [0,2]
-- Filter out all elements that have property p
filter p [] = []
filter p (x:xs) = if p x
  then x : filter p xs
  else     filter p xs


-- quicksort sorts a list using a pivot 
-- if list is empty return empty list
quicksort [] = []
-- else grab the first elment 'x' and remaing list 'xs'
-- concatenate the list using 'x' as pivot and filter smaller and greater values recursively
-- use <= on one case to ensure duplicate values are not omited 
quicksort (x:xs) =  filter (<=x) remaining ++ [x] ++ filter (>x) remaining
  -- define 'remaining' recursively with all remaining values in the list
  where
    remaining = quicksort xs


-- to run main.hs example in repl.it execute the following
-- :l main .hs
-- quicksort [4, 65, 2, -31, 0, 99, 2, 83, 782, 1]