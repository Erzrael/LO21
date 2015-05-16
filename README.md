# LO21
Calendar and Project Management Project

## Notes
	- Le template Factory Methode permet de tenir compte d'une agrégation. Dans le cas de la partie Tache du projet, nous n'avons que des compositions ce qui le rend peut utile dans la partie Projet du projet.
	- On n'utilise pas de conteneurs map car nous aurions dupliquer les données de nos objets pour obtenir un identifiant. Les avantages de ce conteneur ne sont pas supérieurs aux désavantages qu'il induit (Marie, je ne me souviens plus exactement de ce que tu m'avais dit. Je te laisse le noter).
	- Lors de l'usage d'un vector, les constructeurs, destructeurs et opérateurs de recopie doivent être public. 

## A Faire
	Pour héritage des tâches :
		 - Revoir l'algorithme des précédences pour ne pas avoir de boucles ou en éviter le plus possible. Idem pour l'ajout de composition. 
		 - Puisque composition entre les différentes instances de la partie projet, rajouter dans le destructeur la destruction du vector. 

## Questions