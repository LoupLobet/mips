# Projet CS351 (2022-2023): Émulateur MIPS

---
title: Projet CS351 (2022-2023): Émulateur MIPS
author: [COMPLÉTER ICI]
date: [COMPLÉTER ICI]
---

## Rendu 1

* Cochez (en remplaçant `[ ]` par `[x]`) si vous avez :
  - [x] Vérifié que `make test-cli` ne renvoie pas d'erreur.
  - [x] Vérifié que `make tests` se plaint sur le nombre d'instructions et pas
      sur l'existence des fichiers de sortie.
  - [x] Vu que les soumissions se font avec `make tar`.


## Rendu 2

(Une dizaine de lignes devrait suffire à chaque fois)

* Comment avez-vous choisi de programmer l'analyse de texte (dont la lecture
des opérandes entières) ?

En séparant l'instruction en 4 strings { Operateur, Operande1, Operande2, Operande2 },
puis en vérifiant la nature des strings relativement au prototype de l'Operateur. Puis en encodant
l'instruction sous forme de 4 entiers.
Une methode preferee aurait ete d'utiliser lex(1).

* Avez-vous vu des motifs récurrents émerger ? Avez-vous "factorisé" ces motifs
pour éviter de les répéter ? Si non, serait-ce difficile ?

Nous n'avons pas factorise car cela fait peu de sens, au vu du nombre d'instructions non factorisables.
De plus des instructions factorisables n'ont parfois aucun lien semantique entre elles.
Nous avons plutot ecrit un "table d'instruction" (cf const Op oplst[OPNB] - inst.c).
De plus pour la partie execution des instructions, la factorisation ne sera pas possible, et nous avons voulu
garder une similarite entre le fonctionnement de l'exection et la generation de code.

* Comment avez-vous procédé pour écrire les tests ? Étes-vous confiants que
toutes les instructions gérées sont couvertes ?

Toutes les instructions ont été implementées, elles n'ont pas toutes été testés.

* Quelle a été votre expérience avec l'utilisation et la compréhension de la
documentation (ie. des annexes) ?

Bonne comprehension, sauf pour les instructions jump, qui sont assez mal décritent et dont le
fonctionnement reste obscure.

* Cochez (en remplaçant `[ ]` par `[x]`) si vous avez :
  - [X] Implémenté la traduction pour des instructions de toutes les catéories
      (calcul, comparaisons, sauts, HI/LO, mémoire)
  - [X] Implémenté la traduction pour toutes les instructions de l'annexe 2
  - [X] Pris en compte les cas particuliers : valeurs négatives, hors limites,
      noms d'instructions ou opérandes invalides...


## Rendu 3

(10/15 lignes devrait suffire à chaque fois)

* Quelle structure en modules planifiez-vous d'utiliser pour l'émulateur ?

[COMPLÉTER ICI]

* Quelles seront les fonctions principales de chaque module ?

[COMPLÉTER ICI]

* Quels avantages voyez vous à cette structure (à comparer à un unique fichier)?

[COMPLÉTER ICI]


## Rendu 4

* Avez-vous réussi à suivre la structure prévue au rendu 3 ? Quelles
modifications ont été nécessaires ? Rétrospectivement, est-ce que cette
structure était bien prévue ?

[COMPLÉTER ICI]

* Avez-vous compris le fonctionnement de chaque instruction à partir de la
documentation fournie ? Si non, quels sont les points obscurs ?

[COMPLÉTER ICI]

* Quels exemples de programmes avez-vous choisi pour tester le calcul ? Les
comparaisons et sauts ? La mémoire ?

[COMPLÉTER ICI]

* Le sujet spécifie-t-il tous les détails nécessaires pour bien implémenter la
mémoire ? Quels choix avec-vous faits ?

[COMPLÉTER ICI]

* Reste-t-il des bugs que vous avez découverts et pas corrigés ?

[COMPLÉTER ICI]

* D'autres remarques sur votre programme ?

[COMPLÉTER ICI]

* Cochez (en remplaçant `[ ]` par `[x]`) si vous avez :**
  - [ ] Implémenté l'émulation de toutes les instructions gérées par le rendu 2.
  - [ ] Implémenté l'émulation de toutes les instructions.
  - [ ] Tous vos tests qui passent.
  - [ ] Vérifié que vous tests couvrent toutes les instructions émulées.
  - [ ] Testé les cas particuliers : valeurs négatives, overflows...
  - [ ] Testé les cas d'erreur : division par zéro, sauts invalides...
  - [ ] Un port fonctionnel de DOOM pour votre émulateur.

* Des retours sur le projet en général ?

[COMPLÉTER ICI]
