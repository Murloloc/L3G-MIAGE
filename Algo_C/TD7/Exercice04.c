//Exercice 4 : Une imprimante en réseau reçoit des travaux d’un ensemble d’ordinateurs et elle
//doit donc gérer un ordre de passage pour les demandes qu’elle reçoit. On va supposer que
//l’ordre choisi par l’imprimante est le suivant :
//- Les travaux courts (moins de 10 pages) passent toujours devant les autres (les
//« longs »), et ils passent en fonction de leur taille (les plus courts passent en
//premier). Deux travaux de même taille passent en fonction de leur ordre d’arrivée.
//- Les travaux longs sont traités en fonction de leur ordre d’arrivée.
//On vous demande d’écrire un programme qui gère l’arrivée des demandes d’impression et
//présente le document suivant à l’imprimante quand celle-ci est libre. Chaque document est
//identifié par le nom du fichier qui le contient (une chaîne de caractères).
//1°) Décrivez précisément en français comment vous envisagez d’organiser les informations
//nécessaires à ce programme et quelles sont les opérations que vous prévoyez et comment elles
//se déroulent sur cette organisation des données.
//2°) Décrivez les structures informatiques que vous allez utiliser et montrer comment marchent
//sur ces structures les opérations que vous avez citées précédemment. N’hésitez pas à faire des
//dessins. Si vous utilisez des structures de données abstraites connues, citez-les.
//3°) Ecrivez le programme complet comportant deux choix principaux : « un nouveau
//document arrive » et « l’imprimante est libre ».
