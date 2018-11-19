Snell-Descartes
---------------

Voici la version Qt de mon outil de visualisation du comportement d'une onde au changement de milieu.
Version Qt pour une utilisation plus facile sous windows sans dépendre du package Gtk.

Si vous avez besoin de l'avoir sur le bureau créez un raccourci, l'application ne fonctionnera pas si vous la déplacez hors du dossier.

![Application screenshot](/Snell-Descartes.png?raw=true)


Installation
---------------

Sous Windows il suffit de télécharger et décompresser l'archive .zip


Compilation
---------------

Sous windows comme sous linux vous aurez besoin du package Qt. La version utilisée ici est la 5.11.1.

Sous windows, rien de spécial.

Sous linux vous aurez probablement besoin d'éditer le makefile et ajouter l'option -no-pie à la ligne :
LINK = g++
sans quoi la compilation génèrera une bibliothèque partagée au lieu d'un exécutable.
