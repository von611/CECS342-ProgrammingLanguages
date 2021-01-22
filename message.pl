% CECS 342: Assignment 4
% Logic Puzzle: Star Tricked

% People 
person(ms_barrada).
person(ms_gort).
person(mr_klatu).
person(mr_nikto).

% Different object sightings
object(balloon).
object(clothesline).
object(frisbee).
object(watertower).

% Solve the puzzle.
solve :- 
		% Different objects seen by each person 
		object(ObjectOne), object(ObjectTwo), object(ObjectThree), object(ObjectFour),
		all_different([ObjectOne, ObjectTwo, ObjectThree, ObjectFour]),
    
    	person(PersonOne), person(PersonTwo), person(PersonThree), person(PersonFour),
    	all_different([PersonOne, PersonTwo, PersonThree, PersonFour]),

		Triples = [ [PersonOne, ObjectOne, tuesday],
                 	[PersonTwo, ObjectTwo, wednesday],
                 	[PersonThree, ObjectThree, thursday],
                 	[PersonFour, ObjectFour, friday] ],

		% 1. Mr. Klatu made his sighting at some point earlier in the week than the one who saw the balloon, but
		% at some point later in the week than the one who spotted the Frisbee (who isn't Ms. Gort)
		\+ member([mr_klatu, balloon, _], Triples),
		\+ member([mr_klatu, frisbee, _], Triples),
		\+ member([ms_gort, frisbee, _], Triples),
		earlier([mr_klatu, _, _], [_, balloon, _], Triples),
		earlier([_, frisbee, _], [mr_klatu, _, _], Triples),

		% 2. Friday's sighting was made by either Ms.Barrada or the one who saw a clothesline (or both). 
		(member([ms_barrada, _, friday], Triples) ; 
	 	 member([_, clothesline, friday], Triples)),
		
		% 3. Mr. Nikto did not make his sightings on Tuesday. 
		\+ member([mr_nikto, _, tuesday], Triples),

		% 4. Mr. Klatu isn't the one whose object turned out to be a water tower.
		 \+ member([mr_klatu, watertower, _], Triples),
    
		tell(PersonOne, ObjectOne, tuesday),
		tell(PersonTwo, ObjectTwo, wednesday),
		tell(PersonThree, ObjectThree, thursday),
		tell(PersonFour, ObjectFour, friday).

% Succeeds if all elements of the argument list are bound and different. 
% Fails if any elements are unbound or equal to some other element. 
all_different([H | T]) :- member(H, T), !, fail.
all_different([_ | T]) :- all_different(T).
all_different([_]).

% Succeeds if X occurred before Y.
% Fails if X occurred after Y.
earlier(X, _, [X | _]). 
earlier(_, Y, [Y | _]) :- !, fail. 
earlier(X, Y, [_ | T]) :- earlier(X, Y, T). 

% Write out the solution.
tell(X, Y, Z) :- 
	 write(X), write(' spotted a '), write(Y), write(' on '), write(Z), write('.'), nl.