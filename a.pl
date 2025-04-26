% family relations 

parent(john,bob).
parent(bob,sum).
parent(koli,moli).
parent(moli,nodi).

% Food preferences 

likes(john,pizza).
likes(moli,pasta). 
likes(bob,soshi). 

grandParent(X,Y):-parent(X,Z),parent(Z,Y).
