#A Faire
* Lucas : 
	** Finir la partie projet
	** Revoir la partie gestion de la mémoire lors de la destruction. Vérifier le bon fonctionnement dans tous les cas envisageables (DONE)
		FONCTIONNE !
		*** SupprimerTache, faire appel à une fonction père dans le cas de tache composite (DONE)
		*** SupprimerProjet a été revu dans le cadre de la segmentation fault.
		*** Rajouter une fonction supprimer tache depuis le ProjetManager.
	** Rajouter des fonctions getTache dans projet (DONE)
* Marie :
	** implémenter l'ajout de programmation d'évènements qui ne sont pas des taches
		*** revoir l'héritage du bordel (notamment l'id cf debut de agenda.h)
		*** revoir ajoutProgrammation, chercherProgrammation
	** ajouter l'ajout de programmation à xml::load
	** Rendre save fonctionnel (pb mémoire rapidxml)
	** vu graphique semaine

#Hypothèses
* L'ID d'une tâche est unique dans l'ensemble des projets.
* Une tâche ne peut être la précédence que d'une seule autre tâche et en composition avec une seule autre tâche