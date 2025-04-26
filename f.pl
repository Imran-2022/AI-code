% --- Symptoms for each disease ---

illness(flu) :-
    has_symptom(fever),
    has_symptom(cough),
    has_symptom(sore_throat),
    has_symptom(body_ache).

illness(covid19) :-
    has_symptom(fever),
    has_symptom(cough),
    has_symptom(loss_of_taste_smell),
    has_symptom(shortness_of_breath).


% --- Treatment advice ---
treatment(flu, 'Rest and paracetamol.').
treatment(covid19, 'Isolate yourself, consult a doctor, and monitor oxygen level.').

% --- Main diagnostic predicate ---

diagnose :-
    retractall(has_symptom(_)),
    write('Enter symptoms one by one (type done to finish):'), nl,
    repeat,
    read(S),
    ( S == done -> !
    ; assertz(has_symptom(S)), fail ),
    ( illness(D) ->
        format('~nPossible illness: ~w~n', [D]),
        treatment(D, T),
        format('Treatment: ~w~n', [T])
    ; write('No matching illness found.') ).

