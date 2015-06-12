#A Faire
* Lucas : 
	** Remodifier les fenetres d'ajout des précédences pour n'afficher que les taches elligibles (DONE)
	** Modifier les précédences en trandformant le tout en vector
	** Suppression des précédences
	** Rajouter des popups partout lors de l'échec ou de la réussite (DONE, pour le moment)
	** TreeView :
		*** Ajouter les évènements d'édition si double click 
			**** Si un projet : Edition du titre, de la date de disponibilité
			**** Si une tache : Edition du titre, de la date de dispo et de la date d'échéance (vérifier que les nouvelles dates sont correctes)
* Marie :
	** faire fenêtre load / save (too easy sisi)
	** Evènements qui ne sont pas des tâches. (MOTHERFUCKING PUTAIN DE DONE)
	** suppression de prog (fucking DONE)
	** implémenter ajouterProgWindow (DONE)
	** vu graphique semaine :
		*** double clic sur case normale --> ajouterProgrammation (tab view) (DONE)
		*** case de plus en plus sombre (4 nuances) --> test chevaucheHoraire ! (DONE)
		*** double clic : affichage des programmations + Case ajouterProgrammation (DONE)
		*** ajout programmation venant d'une fenêtre : load tab (RAB : rien à branler)

#Hypothèses
* L'ID d'une tâche est unique dans l'ensemble des projets.
* Une tâche ne peut être la précédence que d'une seule autre tâche et en composition avec une seule autre tâche

#Problèmes connus et mis de côté pour le moment


* RapidXML et la gestion des accents

#Notes

* const cast destructeur programmation
