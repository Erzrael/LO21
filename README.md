# LO21
Calendar and Project Management Project

Note : Le template Factory Methode permet de tenir compte d'une agrégation. Dans le cas de la partie Tache du projet, nous n'avons que des compositions ce qui le rend peut utile dans la partie Projet du projet.

Note : On n'utilise pas de conteneurs map car nous aurions dupliquer les données de nos objets pour obtenir un identifiant. Les avantages de ce conteneur ne sont pas supérieurs aux désavantages qu'il induit (Marie, je ne me souviens plus exactement de ce que tu m'avais dit. Je te laisse le noter).

Note : Lors de l'usage d'un vector, les constructeurs, destructeurs et opérateurs de recopie doivent être public. 

A faire :
	Revoir l'algorithme des précédences pour ne pas avoir de boucles ou en éviter le plus possible. Idem pour l'ajout de composition. 

Questions :
	Dans la fonction ajouterTache de la classe projet, pourquoi reporter l'échéance du projet ? L'échéance est définie en début de projet et ne se reporte pas en fonction des taches qu'on lui ajoute nan ?