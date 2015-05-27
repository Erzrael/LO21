# LO21
Calendar and Project Management Project

## En cours
* Marie :
	* finir implémentation agenda
	* ajouterProgrammation
	* Revoir le tacheIterator car il ne fonctionne pas
* Lucas :
	* algorithme des précédences et des compositions
	* Vérifier que les fonctions implémentées fonctionnent dès que l'itérateur sera débuggé
	
## Notes
* Le template Factory Methode permet de tenir compte d'une agrégation. Dans le cas de la partie Tache du projet, nous n'avons que des compositions ce qui le rend peu utile dans la partie Projet du projet.
* On n'utilise pas de conteneurs map car nous aurions dupliquer les données de nos objets pour obtenir un identifiant. Les avantages de ce conteneur ne sont pas supérieurs aux désavantages qu'il induit (Marie, je ne me souviens plus exactement de ce que tu m'avais dit. Je te laisse le noter).
* Lors de l'usage d'un vector, les constructeurs, destructeurs et opérateurs de recopie doivent être public. (FAUX ! car on fait des vector de pointeurs)

## Questions
* Rajouter une fonction pour supprimer un projet en fonction de l'ID ?
* Rajouter une fonction pour supprimer une tâche en fonction de l'ID ?
* Rajouter dans la classe tache un attribut permettant de connaître le projet auquel la tâche appartient et la tâche père/mère ?

## Fait
* Vérifier que le projet n'existe pas déjà dans ProjetManager::ajoutProjet
* Vérifier que la tâche n'existe pas déjà dans Projet::AjoutTache
* Rajouter un ID pour projet ainsi qu'un titre.
* Rajouter un moyen de connaître le nombre de tâches dans un projet.
* Rajouter un moyen de connaître le nombre de projets dans l'application.
* Rajouter une méthode trouverTache(Qstring& id) et getTache dans ProjetManager.
* Rajouter une méthode trouverProjet(Qstring& id) et getProjet dans projetManager.