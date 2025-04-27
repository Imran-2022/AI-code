% Lexicon
subject(john).
subject(mary).
verb(likes).
verb(eats).
object(pizza).
object(sushi).

% Parser: parses a sentence list
parse([S, V, O], S, V, O) :-
    subject(S),
    verb(V),
    object(O).

/*
?- parse([john, likes, pizza], S, V, O).

output:
    S = john,
    V = likes,
    O = pizza.
    true.
% 2
?- parse([pizza, eats, john], S, V, O).

output:

   false.
