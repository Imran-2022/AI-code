% Lexicon
subject(john).
subject(mary).
verb(likes).
verb(eats).
object(pizza).
object(sushi).

% Sentence structure
sentence(S, V, O) :- subject(S), verb(V), object(O).

% Sample queries:
% ?- sentence(john, likes, pizza).
% ?- sentence(X, likes, sushi).
