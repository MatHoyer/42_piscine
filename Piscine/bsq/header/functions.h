/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:33:35 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/27 09:33:36 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

// Taille de lecture pour le read
# define LECTURE 4096

// Nom du fichier par defaut de lecture dns le terminal
# define NOM_FICHIER "lecture.txt"

// ----------------------------STRUCTURES-------------------------

// Stocke toutes les donnees de la matrice
typedef struct memoire
{
	int		nb_ligne;
	int		nb_col;
	char	vide;
	char	obstacle;
	char	remp;
	char	**mat;
}t_memoire;

// Coordonnees d'un carre ([x,y] = haut_gauche | [xi,yi] = bas droite)
typedef struct carre
{
	int	x;
	int	xi;
	int	y;
	int	yi;
}t_carre;

// ----------------------------ALLOC------------------------------

// Alloue la bonne taille de memoire en plus au tableau
char		*ft_strdup(char *src, int ajout);

// ---------------------------AFFICHAGE----------------------------

// Affiche un caractere
void		ft_putchar(char lettre);

// Affiche une chaine de caracteres
void		ft_putstr(char *str);

// Affiche un nombre
void		ft_putnb(int nbr);

// Calcul de la taille d'une string
int			ft_strlen(char *str);

// Determine si un caractere est imprimable
int			ft_char_is_printable(char c);

// --------------TEST ET RECUPERATION DANS LE FICHIER--------------

// Recupere un caractere grace a sa position sur la premiere ligne du fichier
char		recup_carac(const char *file_name, int pos);

// Return le nombre de ligne
int			recup_nb_ligne(const char *file_name);

// Return le nombre de caractere sur chaque ligne
int			recup_nb_colone(char *buffer);

// Recupere le fichier dans une chaine de caractere
char		*take_map(const char *file_name);

// Verifie si la map contient que des caracteres predefinis
int			check_map(char *buffer, t_memoire mem);

// Verifie que chaque ligne se fini par un \n et le nb de carac par ligne
int			check_nb_carac(char *buffer, t_memoire mem);

// Compte le vrai nombre de ligne
int			count_line(char *buffer);

// -------------------PLACEMENT DANS LE FICHIER---------------------

// Renvoie l'indice du \n de la premiere ligne
int			go_last_n(char *buffer);

// ---------------------LIRE DANS LE TERMINAL------------------------

// Recupere le buffer danas le terminal
char		*recup_buffer(void);

// Appelle le programme visant a resoudre la map dans le terminal
void		appel_lecture_term(void);

// -------------------------EXTENSION MAIN---------------------------

// Initie la structure t_memoire avec les valeurs lues
t_memoire	init_mem(char *buffer, const char *argv);

// Execute toutes les fonctions pour resoudre le probleme
void		action(t_memoire mem, t_carre carre, char *buffer);

// ------------------------------ERREUR-----------------------------

// Regroupe la gestion des erreurs de map
int			regroup_error(char *buffer, t_memoire mem);

// Affiche un msg d'erreur
void		error(char *str);

// --------------------------GESTION MATRICE-------------------------

// Transforme une chaine de caractere en matrice
char		**map_matrice(int ligne, int colonne, char *buff, int k);

// Libere la memoire alloue a une matrice
void		free_mat(t_memoire mem);

// ---------------------------CALCUL SOLUTION------------------------

// Cherche le plus grand carre
t_carre		sol(t_memoire st, t_carre carre_mem, t_carre carre_act);

// Renvoie les coordonnees du dernier carre trouve
t_carre		bon(int x, int y, int i);

// Check si la case est vide ou s'il y a un obstacle
int			verif(char xy, t_memoire st);

// Initialise les coordonnees du carre a 0
t_carre		ini_carre(void);

// Avance jusqu'a arriver surune case vide
void		avance_jusqua_vide(int *x, int *y, t_memoire st, int pos[2]);

// Appel la fonction de resolution dans le main
t_carre		appel_sol(t_memoire st);

// Initialise les coordonnees d'un carre 1x1
void		init_pos_1x1(int pos_1x1[2]);

// Change le carre en point si aucun carre (min 2x2) n'a ete trouve
t_carre		carre_point(t_carre carre, int pos_1x1[2]);

// Calcul solution a partir du terminal
void		in_terminal(void);

// ----------------------------AFF SOLUTION--------------------------------

// Affiche une matrice de caractere
void		aff_matrice(char **matrice, int ligne, int colonne);

// Remplit la matrice avec la solution
t_memoire	remp(t_memoire mem, t_carre car);

#endif
