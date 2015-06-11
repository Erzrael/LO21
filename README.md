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
	** Evènements qui ne sont pas des tâches.
	** implémenter ajouterProgWindow
	** vu graphique semaine :
		*** double clic sur case normale --> ajouterProgrammation (tab view) (DONE)
		*** case de plus en plus sombre (4 nuances) --> test chevaucheHoraire !
		*** double clic : affichage des programmations + Case ajouterProgrammation
		*** (optionnel) empêcher modification

#Hypothèses
* L'ID d'une tâche est unique dans l'ensemble des projets.
* Une tâche ne peut être la précédence que d'une seule autre tâche et en composition avec une seule autre tâche

#Problèmes connus et mis de côté pour le moment


* RapidXML et la gestion des accents