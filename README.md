## Compiler

Pour compiler, il faut faire 
```
make prog
```
Puis,
```
.\prog test.graph
```
## Les tests

Les tests sont regroupés dans les fichiers `main.cpp`. Ils sont en commentaire, groupés par question.

## Réponses aux questions

Les algorithmes correpondant aux réponses aux questions sont dans les fichiers `.h` et `.cpp`.

## QUESTION 1 :

Création de la classe `AdjacenceMatrix` construite dans les fichiers `adjacence_matrix.h` et `adjacence_matrix.cpp`. Elle a 3 attributs : sa taille, la liste des sommets à laquelle elle fait référence et un tableau donnant les valeurs entre chaque sommet. 
L'`AdjacenceMatrix` possède une méthode `arete_list` qui à partir d'un nom de sommet permet d'accéder à la liste d'adjacence du sommet.
NB : j'ai mis à 0 les cases du tableau où il n'y a pas d'arête entre les deux noeuds ou entre deux mêmes noeuds


Création de la classe `AdjacenceList` qui a comme attribut un dictionnaire qui pour chacun des noms de sommets lui associe sa classe `Summit` dans laquelle est contenue le nom du sommet et sa liste d'adjacence sous la forme d'un vecteur d'`Arete`. La classe `Arete` donne la valeur de l'arête et le sommet sortant.
Les fichiers correspondants ici sont : `adjacence_list.h`, `adjacence_list.cpp`, `summit.h`, `summit.cpp`, `arrete.h`, `arrete.cpp`.
L'`AdjacenceList` possède une méthode `arete_list` qui à partir d'un nom de sommet permet d'accéder à la liste d'adjacence du sommet.
NB : la fonction print affiche le dictionnaire à l'envers

Les fonctions pour passer d'une représentation à l'autre sont contenues dans le fichier `graph.h` et `graph.cpp`.

## QUESTION 2 :

Les fichiers contenant la fonction `read` sont `read.h` et `read.cpp`. Dans ces fichiers, les deux fonctions principales sont `read` et `create_graph`.
`read` permet de convertir notre fichier en un vecteur de vecteur de string. Chaque ligne du fichier correspond à un vecteur qui lui même contient chaque élément de la ligne sous forme de string.
ex : Le fichier est : A B 3 -> le code doit renvoyer [["A"], ["B"], ["3"]]
A partir de cette fonction, on obtient donc quelque chose d'exploitable qu'on pourra utiliser pour créer la liste d'adjacence du graph. Avant cela, il faut vérifier qu'un fichier ait été donné lors de la compilation et que le fichier est de la forme `.graph`. Je n'ai pas réussi à insérer un retour d'erreur au sein de la fonction `create_graph`. Dans le `main.cpp` on vérifie donc que le fichier est conforme, s'il ne l'est pas ou qu'il n'y en a pas, on sort du code et on affiche le message d'erreur. Si le fichier est correct on crée la liste d'adjacence associée qu'on nomme `test_list`. 
On peut ensuite lancer le test1 de la question 1 et 2 (test de la fonction qui crée le graph à partir du ficheir, des représentations et du passage d'une représentation à l'autre) et lancer avec le fichier `test.graph`.

## QUESTION 3  et 4 :

Code du parcours en profondeur récursif et itératifdans les fichiers `ds.cpp` et `ds.h`.
Tests de la question 3 : dans le main en commentaire, lancer `test31` et `test32` pour tester avec les listes et avec les matrices la méthode récursive. Ils affichent les sommets parcourus à partir d'un sommet donné en argument et les arêtes parcourues.
Tests de la question 4 : lancer `test41` et `test42` pour tester avec la méthode récursive sous le même principe que précédemment.

## QUESTION 5 :

Code du parcours en largeur dans les fichiers `ls.h` et `ls.cpp`. Utiliser le fichier `test2.graph` par exemple.
Tests dans le main, lancer `test51` et `test52` pour tester l'algorithme respectivement les listes d'adjacence et les matrices d'adjacence. On donne en entrée le point dont on veut partir et à quel point on veut s'éloigner (n).

## QUESTION 6 et 7 :

Code dans le fichier `shortestpath.h` et `shortestpath.cpp`. Utiliser le fichier `test3.graph` par exemple.
Tests pour Dijkstra dans le main, lancer `test61` en utilisant une liste d'adjacence. On donne en entrée deux sommets pour trouver le chemin les plus courts pour les rejoindre.
Tests pour Floyd-Warshall dans le main, lancer `test71` en utilisant une représentation matricielle. Il renvoie la matrice avec la plus petite distance entre deux sommets. Si c'est l'infini, c'est que le sommet est inaccessible.