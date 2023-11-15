//Exercice 5 : GESTION D’UNE BIBLIOTHEQUE
// Une bibliothèque vous demande de créer un logiciel de gestion de ses abonnés, de ses livres et
//des emprunts.
//Chaque abonné est décrit par son nom, son code (un entier), sa date d’abonnement (par exemple
//Décembre 2007) et le nombre de livres que l’abonné a actuellement empruntés. Un abonné ne
//peut pas emprunter plus de 3 livres à la fois et son abonnement a une durée de 1 an.
//Chaque livre est décrit par son titre, son auteur, son code et un champ contenant le code de la
//personne qui l’a emprunté. Ce champ vaudra -1 si le livre n’est pas emprunté et permettra donc
//de savoir si le livre est disponible ou pas à un moment donné.
//Chaque retour de livre est décrit par le code du livre rendu.
//Ce logiciel comporte un menu principal qui permet d'accéder aux 4 fonctions suivantes :
//Un menu « gestion des abonnés » permettant
//- l'ajout d'un abonné
//- l'affichage dans l'ordre alphabétique des abonnés
//- l’affichage des abonnés dont l’abonnement a expiré.
//Un menu « gestion des livres » qui permet l’ajout d’un livre.
//Une fonctionnalité « emprunt ». Elle permettra à un abonné (dont on connaît le code)
//d’emprunter un livre (dont on connaît le code). Pour cela, vous devez vérifier :
//- Que le livre est disponible
//- Que l’abonné peut encore emprunter des livres (abonnement à jour et nombre de
//livres empruntés inférieur à 3)
//Si ces conditions sont remplies, les informations concernant le livre et l’abonné sont mises à
//jour.
//Une fonction « retour d’un livre ». Cette fonction permettra de mettre à jour les informations
//concernant le livre qui est revenu et l’abonné qui l’avait emprunté.
//Remarques :
//Pour les dates, je vous conseille un codage sous forme d’entier (par exemple, 07 12 2018 sera
//codé 20181207, 15 06 2019 sera codé 20190615). Ce codage permet de comparer les dates
//simplement. Si le passage d’une date à son codage vous pose des problèmes, vous pouvez
//supposer que l’utilisateur entre directement le codage de la date à la place de la date.
//Si vous en avez besoin, la date du jour sera demandée à l’utilisateur du programme.
//Vérifiez bien tous les cas particuliers (par exemple, si pour un emprunt, le code de l’abonné
//n’existe pas).
//On supposera qu’il y a au maximum 100 abonnés et 500 livres. On suppose qu’au démarrage
//du logiciel, il n’y a aucun abonné et aucun livre. Un ensemble de données initiales (base
//d’adhérents, base de livres) sera lu dans des fichiers.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

typedef struct {


}ABONNE;

typedef struct{


}LIVRE;

int main(){






    return 0;
}