//Exercice 6 :
//Gestion de stock d’un magasin de bricolages. On vous demande d’écrire un programme qui
//gère le stock d’un magasin de bricolage. Le stock contient au plus 1000 objets. Chaque objet
//correspond à un modèle d’outil qui est décrit par les informations suivantes :
//• La référence (un entier)
//• Le nom du modèle (par exemple, Clé à molette)
//• Le prix hors taxe à l’unité
//• Le nombre d’outils de ce modèle présentes dans le stock.
//Les sous-programmes suivants seront proposés au choix au manager du magasin et utilisables
//dans l’ordre que le manager souhaite, autant de fois qu’il le souhaite :
//- Ajouter un modèle dans le stock
//- Ajouter des unités d’un modèle d’outils déjà présent dans le stock
//- Calculer le coût moyen des outils présents dans le stock
//- Effectuer une commande d’un client en 3 étapes : remplir le panier, trier le panier,
//afficher le panier.
//Ce sous-programme devra demander au client quel produit (nom du modèle) il veut acheter, en
//quelle quantité, et cela tant que le client veut continuer à ajouter des produits dans son panier.
//Si le client ajoute un produit déjà présent dans son panier, c’est la quantité présente dans le
//panier qui est modifiée. Pour chaque produit acheté, le programme vérifiera que le modèle et le
//nombre d’unités demandé sont bien présents dans le stock.
//Lorsque le client a fini de remplir son panier, le programme lui demande de le valider et s’il le
//valide, le stock est diminué de tout ce qui se trouve dans le panier. Si le nombre d’unités d’un
//modèle tombe à 0 dans le stock, le modèle est supprimé du stock.
//Ensuite, le panier est trié dans l’ordre croissant des prix et affiché ainsi que le montant total
//TTC de la commande.
//Attention : une attention particulière doit être portée aux cas particuliers. N’hésitez pas à définir
//des sous-programmes supplémentaires si besoin pour rendre le code plus clair, par exemple un
//sous-programme de suppression.
//Vous ferez les déclarations nécessaires et écrirez le programme principal qui contiendra le menu
//permettant d’utiliser chacune des fonctionnalités à volonté, la saisie des informations au clavier
//chaque fois que nécessaire, l’appel aux sous-programmes qui effectueront les fonctionnalités et
//l’affichage des résultats si nécessaire.

//Pas commencer