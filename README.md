# ft_select

Sujet:
* Ecrire un programme "ft_select" qui prend en paramètre une série d’arguments. La liste d’arguments s’affiche.
* L’utilisateur peut alors se déplacer dans la liste des arguments à l’aide des flèches (la liste est circulaire).
• Un ou plusieurs choix peuvent être sélectionnés ou désélectionnés à l’aide de la touche espace. A chaque sélection effectuée, le curseur doit automatiquement se positionner sur l’élément suivant.
* Dès que l’utilisateur valide la sélection à l’aide de la touche return, la liste des choix doit être renvoyée au shell. Les choix renvoyés devront être separés par le caractère espace. Ceci permettra alors d’utiliser votre programme ft_select à l’intérieur d’un script shell (pour faire un "set", par exemple).

## Compiling

executer `make`, un exécutable nommé `ft_select` devrait compiler directement.

## Usage

`~ ./ft_select element1 element2 ...`

Exemple:

```c
./ft_select *
./ft_select Dossier1 Dossier2
ls `./ft_select *`
rm `./ft_select Fichier1 Fichier2
```

## Controle

* Ce déplacer `Fleche directionel`
* Selectionner `Espace`
* Deselectioner `Espace`
* Suprimer `Delete`
* Envoyer `Entrer`
