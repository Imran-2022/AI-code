% family relations 

parents(john,bob).
parents(bob,sum).
parents(koli,moli).
parents(moli,nodi).

% Food preferences 

likes(john,pizza).
likes(moli,pasta). 
likes(bob,soshi). 

grandParent(X,Y):-parents(X,Z),parents(Z,Y).
