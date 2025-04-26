grade(mark, 90).
grade(sam, 75).
grade(joe, 40).

result(X, pass) :- grade(X, N), N >= 50, !.
result(X, fail) :- grade(X, N), N < 50.

% result(sam,R).
