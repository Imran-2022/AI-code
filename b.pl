% Basic parent relationships

parent(john, mary).
parent(mary, susan).
parent(john, bob).
parent(bob, lisa).
parent(anna, john).
parent(anna, joe).
parent(joe, emma).

% Complex Relationships

grandParent(X,Y):-parent(X,Z),parent(Z,Y).

sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.

aunt_or_uncle(X, Y) :- parent(Z, Y), sibling(X, Z).

cousin(X, Y) :- parent(A, X), parent(B, Y), sibling(A, B).
