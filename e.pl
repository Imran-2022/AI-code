% 1. Calculate Factorial

factorial(0, 1).                           % Base case
factorial(N, F) :-                         % Recursive case
    N > 0,
    N1 is N - 1,
    factorial(N1, F1),
    F is N * F1.


%  2. Find the Nth Fibonacci Number

fibonacci(0, 0).                     % Base
fibonacci(1, 1).                     % Base
fibonacci(N, F) :-                   % Recursive
    N > 1,
    N1 is N - 1,
    N2 is N - 2,
    fibonacci(N1, F1),
    fibonacci(N2, F2),
    F is F1 + F2.
