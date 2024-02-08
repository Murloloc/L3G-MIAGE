Create DATABASE bdContacts;
Use bdContacts;


CREATE TABLE entreprise
(id INT NOT NULL AUTO_INCREMENT,
raisonSociale VARCHAR(40) NOT NULL,
ville VARCHAR(40),
PRIMARY KEY (id)
)ENGINE=INNODB CHARACTER SET utf8;

CREATE TABLE contact
(id INT NOT NULL AUTO_INCREMENT,
nom VARCHAR(30) NOT NULL,
mail VARCHAR(50),
photo VARCHAR(30),
idEntreprise int,
PRIMARY KEY (id),
FOREIGN KEY (idEntreprise) REFERENCES entreprise(id)
)ENGINE=INNODB CHARACTER SET utf8;


SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
insert into entreprise(raisonSociale,ville) values("Entreprise1","Marseille");
insert into entreprise(raisonSociale,ville) values("Entreprise2","Marseille");
insert into entreprise(raisonSociale,ville) values("Entreprise3","Aix en Provence");
insert into entreprise(raisonSociale,ville) values("Entreprise4","Aix en Provence");
insert into entreprise(raisonSociale,ville) values("Entreprise5","Marseille");

insert into contact(nom,mail,photo,idEntreprise) values("personne1","personne1@mail.fr","images/img1.jpg",null);
insert into contact(nom,mail,photo,idEntreprise) values("personne2","personne2@mail.fr","images/img2.jpg",null);
insert into contact(nom,mail,photo,idEntreprise) values("personne3","personne3@mail.fr","images/img3.jpg",1);
insert into contact(nom,mail,photo,idEntreprise) values("personne4","personne4@mail.fr","images/img4.jpg",2);
insert into contact(nom,mail,photo,idEntreprise) values("personne5","personne5@mail.fr","images/img5.jpg",3);
insert into contact(nom,mail,photo,idEntreprise) values("personne6","personne6@mail.fr","images/img6.jpg",3);


