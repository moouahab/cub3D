# cub3D
Cube3D est un projet inspiré par le classique des jeux vidéo "Wolfenstein 3D". Ce projet a pour but de créer un moteur de rendu en 3D utilisant la technique du ray-casting à partir d'une carte en 2D. Ce document décrit les fonctionnalités, les technologies utilisées et la manière d'exécuter le projet.

## Objectifs
Le but principal de Cube3D est de comprendre les principes fondamentaux du rendu graphique en 3D et de la programmation en C 
à travers la création d'un jeu vidéo simplifié. Les compétences mises en avant comprennent :

- Utilisation de la bibliothèque miniLibX.
- Gestion des événements et de l'interaction utilisateur.
- Algorithmes de ray-casting pour le rendu des textures.
- Optimisation de la mémoire et de la performance.
## Raycasting
### Algorithme DDA (Digital Differential Analyzer)

L'algorithme DDA (Digital Differential Analyzer) est une méthode informatique utilisée pour tracer des lignes droites sur des dispositifs d'affichage numériques tels que des écrans d'ordinateur. Il est particulièrement utile dans la génération de graphiques et d'images.

#### Principe de l'algorithme DDA

L'algorithme DDA fonctionne en incrémentant une variable par une valeur fixe à chaque étape pour approcher la ligne à tracer. Il utilise la formule de l'équation de la ligne \(y = mx + c\) pour déterminer les points successifs de la ligne. Les étapes principales de l'algorithme sont les suivantes :

1. **Calcul de l'incrément** :
   - On commence par calculer la différence entre les coordonnées des points de départ et d'arrivée de la ligne : 
     \[
     \Delta x = x_2 - x_1
     \]
     \[
     \Delta y = y_2 - y_1
     \]

2. **Détermination du nombre d'étapes** :
   - Le nombre d'étapes nécessaires pour tracer la ligne est déterminé par la plus grande des valeurs absolues de \(\Delta x\) et \(\Delta y\) :
     \[
     \text{steps} = \max(|\Delta x|, |\Delta y|)
     \]

3. **Calcul des incréments par étape** :
   - Les incréments à chaque étape pour les coordonnées \(x\) et \(y\) sont calculés comme suit :
     \[
     x_{\text{increment}} = \frac{\Delta x}{\text{steps}}
     \]
     \[
     y_{\text{increment}} = \frac{\Delta y}{\text{steps}}
     \]

4. **Initialisation des points de départ** :
   - On initialise les coordonnées des points de départ \(x = x_1\) et \(y = y_1\).

5. **Génération des points de la ligne** :
   - On génère les points de la ligne en ajoutant les incréments calculés à chaque étape :
     \[
     x = x + x_{\text{increment}}
     \]
     \[
     y = y + y_{\text{increment}}
     \]
   - Ces coordonnées sont arrondies à l'entier le plus proche pour correspondre aux pixels de l'écran.

#### Exemple d'implémentation en pseudo-code

Voici un exemple de l'algorithme DDA en pseudo-code :

```pseudo
procedure DDA(x1, y1, x2, y2)
    Δx := x2 - x1
    Δy := y2 - y1
    
    steps := max(abs(Δx), abs(Δy))
    
    x_increment := Δx / steps
    y_increment := Δy / steps
    
    x := x1
    y := y1
    
    for i from 0 to steps do
        plot(round(x), round(y))  // Plot the pixel at the current point
        x := x + x_increment
        y := y + y_increment
end procedure
```
```.c
/**
 * Initialise les paramètres du rayon pour un certain pixel de l'écran.
 *
 * Cette fonction initialise les paramètres nécessaires pour tracer un rayon depuis la position du joueur
 * jusqu'à une certaine colonne de l'écran, en calculant la direction du rayon et d'autres paramètres nécessaires
 * pour le raycasting.
 *
 * @param ray Un pointeur vers la structure t_ray pour stocker les informations du rayon.
 * @param mlx Un pointeur vers la structure t_mlx contenant les informations globales, y compris le joueur et la carte.
 * @param x La coordonnée X de la colonne de l'écran pour laquelle le rayon est initialisé.
 */
void	init_ray(t_ray *ray, t_mlx *mlx, int x)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;  // Coordonnée X de la caméra dans l'espace de la caméra.
	ray->ray_dir_x = mlx->map.player.direction.dir_x + mlx->map.player.camera.planex * ray->camera_x;
	ray->ray_dir_y = mlx->map.player.direction.dir_y + mlx->map.player.camera.planey * ray->camera_x;
	ray->map_x = (int)mlx->map.player.corrdone.axe_abs;  // Coordonnée X sur la carte.
	ray->map_y = (int)mlx->map.player.corrdone.axe_ord;  // Coordonnée Y sur la carte.
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);  // Distance parcourue dans le monde réel pour passer d'un côté X à l'autre.
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);  // Distance parcourue dans le monde réel pour passer d'un côté Y à l'autre.
	ray->hit = 0;  // Indique si un mur a été touché.
}

/**
 * Exécute l'algorithme Digital Differential Analyzer (DDA) pour trouver la première intersection de mur.
 *
 * Cette fonction utilise l'algorithme DDA pour avancer le long du rayon et déterminer quelle case de la carte
 * est la première à être traversée par le rayon, en identifiant ainsi la distance perpendiculaire au mur.
 *
 * @param ray Un pointeur vers la structure t_ray contenant les informations du rayon.
 * @param mlx Un pointeur vers la structure t_mlx contenant les informations globales, y compris la carte.
 */
void	perform_dda(t_ray *ray, t_mlx *mlx)
{
	while (ray->hit == 0)
	{
		// Avance le long de l'axe X ou Y en fonction de la distance la plus courte.
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		// Vérifie si le rayon a touché un mur.
		if (mlx->map.map[ray->map_x][ray->map_y] == '1')
			ray->hit = 1;
	}
	// Calcule la distance perpendiculaire au mur touché.
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - mlx->map.player.corrdone.axe_abs + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - mlx->map.player.corrdone.axe_ord + (1 - ray->step_y) / 2) / ray->ray_dir_y;
}

/**
 * Calcule les étapes et les distances initiales pour l'algorithme DDA.
 *
 * Cette fonction détermine dans quelle direction
 * le rayon doit avancer dans la grille de la carte
 * et calcule les distances initiales aux premières
 * intersections de grille.
 *
 * @param ray Un pointeur vers la structure t_ray contenant
 * les informations du rayon.
 * @param mlx Un pointeur vers la structure t_mlx contenant les
 * informations globales, y compris la position du joueur.
 */
void	calculate_step_and_side_dist(t_ray *ray, t_mlx *mlx)
{
	// Calcule les étapes et les distances initiales pour l'axe X.
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (mlx->map.player.corrdone.axe_abs - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - mlx->map.player.corrdone.axe_abs) * ray->delta_dist_x;
	}
	// Calcule les étapes et les distances initiales pour l'axe Y.
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (mlx->map.player.corrdone.axe_ord - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - mlx->map.player.corrdone.axe_ord) * ray->delta_dist_y;
	}
}

/**
 * Calcule les limites de dessin pour la ligne verticale représentant un mur.
 *
 * Cette fonction détermine la hauteur de la ligne à dessiner
 * pour représenter un mur sur l'écran,
 * ainsi que les positions de début et de fin pour cette ligne.
 *
 * @param ray Un pointeur vers la structure t_ray contenant
 * les informations du rayon.
 */
void	calculate_draw_limits(t_ray *ray)
{
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);  // Calcule la hauteur de la ligne en fonction de la distance au mur.
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;  // Calcule la position de début du dessin.
	if (ray->draw_start < 0)
		ray->draw_start = 0;  // S'assure que la position de début n'est pas hors de l'écran.
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;  // Calcule la position de fin du dessin.
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;  // S'assure que la position de fin n'est pas hors de l'écran.
}

/**
 * Effectue le raycasting pour chaque colonne de l'écran et dessine les murs.
 *
 * Cette fonction est la boucle principale de raycasting. Elle initialise
 * les rayons, calcule les intersections
 * avec les murs, et dessine les murs pour chaque colonne de l'écran.
 *
 * @param mlx Un pointeur vers la structure t_mlx contenant les informations
 * globales, y compris les textures, l'image et la fenêtre.
 */
void	raycasting(t_mlx *mlx)
{
	int		x;  // Coordonnée X de la colonne actuelle.
	t_ray	ray;  // Structure pour stocker les informations du rayon.

	// Dessine le plafond et le sol avant de tracer les murs.
	draw_ceiling(&mlx->map, &mlx->img);
	draw_sol(&mlx->map, &mlx->img);
	x = 0;
	while (x < WIDTH)
	{
		init_ray(&ray, mlx, x);  // Initialise le rayon pour la colonne actuelle.
		calculate_step_and_side_dist(&ray, mlx);  // Calcule les étapes et les distances initiales.
		perform_dda(&ray, mlx);  // Effectue l'algorithme DDA pour trouver les intersections de mur.
		calculate_draw_limits(&ray);  // Calcule les limites de dessin pour le mur.
		display_of_wall(&ray, x, mlx, ray.draw_start);  // Dessine le mur pour la colonne actuelle.
		x++;
	}
	// Affiche l'image finale sur la fenêtre.
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img_ptr, 0, 0);
}
```
