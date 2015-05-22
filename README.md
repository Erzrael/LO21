# LO21
Calendar and Project Management Project

## En cours
* Marie :
	* finir implémentation agenda
	* ajouterProgrammation
* Lucas :
	* raconte donc moi ce que tu fais en ce moment mon petit :)
## A Faire
	* Pour héritage des tâches :
		* Revoir l'algorithme des précédences pour ne pas avoir de boucles ou en éviter le plus possible. Idem pour l'ajout de composition. 
		En attente de la fin des classes projet et projetManager.
		```C++
		/*
		 * Cette fonction nécessite de faire appel au projet manager pour récupérer le tableau de taches du projet correspondant.
		 * Une fois ce tableau récupéré, on recherche la branche correspondante à la tache où l'on veut ajouter une précédence.
		 * Puis on applique l'algorithme ci-dessous à partir de la première tache de la branche correspondante
		*/
		bool Tache::verifierPrecedence(const Tache &t) const
		{
		    if(this->getPrecedence().empty())
		    {
		        qDebug()<<"Je retourne vrai";
		        return true;
		    }
		    else{
		        for(std::vector<Tache*>::const_iterator it = this->getPrecedence().begin(); it != this->getPrecedence().end(); ++it)
		        {
		            if(*it == &t)
		            {
		                qDebug()<<"Je retourne faux";
		                return false;
		            }
		            else
		            {
		                qDebug()<<"Je vérifie pour chacune des précédences";
		                (*it)->verifierPrecedence(t);
		            }
		        }
		    }
		    return true;
		}
## Notes
	- Le template Factory Methode permet de tenir compte d'une agrégation. Dans le cas de la partie Tache du projet, nous n'avons que des compositions ce qui le rend peut utile dans la partie Projet du projet.
	- On n'utilise pas de conteneurs map car nous aurions dupliquer les données de nos objets pour obtenir un identifiant. Les avantages de ce conteneur ne sont pas supérieurs aux désavantages qu'il induit (Marie, je ne me souviens plus exactement de ce que tu m'avais dit. Je te laisse le noter).
	- Lors de l'usage d'un vector, les constructeurs, destructeurs et opérateurs de recopie doivent être public. (FAUX ! car on fait des vector de pointeurs)

## Questions
