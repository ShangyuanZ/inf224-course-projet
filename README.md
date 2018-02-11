# INF224 multimedia

Shangyuan Zhang

## Demarrage

Dans le terminal, taper 
```
$ cd Zhang_Shangyuan/cpp
$ make run
```
Pour exécuter le serveur (en C++)

et puis, pour exécuter le client (en Java), taper
```
$ cd Zhang_Shangyuan/swing
$ make run
```

Il vas afficher un interface client qui peux communiquer avec serveur.

Note: Il n'y a que "flower" et "drop" dans notre database du test.

## Questions traités
* Partie C++: 1-11
* Partie Java swing : 1-4

## Questions pour répondre

* 4e: Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ? Si vous avez fait correctement ce qui précède, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ? 
```
C'est une méthode vitruelle, on mettre un "virtuel" devant la méthode et "= 0" en dernier.
Parce que la classe est virtuelle maintenant.
```
      
* 5e: Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ? Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ? Quel est le type des éléments du tableau : est-ce que ce tableau contient les objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java. 
```
Le polymorphisme. Il faut mettre virtuel devant les méthodes.
Le type des éléments est pointeur. Java n'a pas de pointeur, 
et il utilise les réference. les fonctions sont virtuelles par defaut.
```

* 6e: Que faut-il faire pour que l'objet Film ait plein contrôle sur ses données et que son tableau de durées des chapitres ne puisse pas être modifié (ou pire, détruit) à son insu ?
```
On peut mettre le "const" devant les methodes ou paramètres pour le proteger.
```

* 7e: Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit leurs instances ? De même, la copie d'objets peut poser problème dans certains cas. Pourquoi et que faudrait-il faire ?
```
La classe film. On doit faire une copie profonde, car il peut copier le contenue mais pas le pointeur.
```

* 8e: Le groupe ne doit pas détruire les objets quand il est détruit car un objet peut appartenir à plusieurs groupes (on verra ce point à la question suivante). On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.
```
parce que l'on ne peut pas mettre les contenues dans la liste à cause de la taille de mémoire, en Java, on passe par référence.
```

* 10e:  Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux ? 
```
On remplace tous les pointeurs avec le smart pointeur.
```





