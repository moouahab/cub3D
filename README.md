# cub3D
Cube3D est un projet inspiré par le classique des jeux vidéo "Wolfenstein 3D". Ce projet a pour but de créer un moteur de rendu en 3D utilisant la technique du ray-casting à partir d'une carte en 2D. Ce document décrit les fonctionnalités, les technologies utilisées et la manière d'exécuter le projet.

## Objectifs
Le but principal de Cube3D est de comprendre les principes fondamentaux du rendu graphique en 3D et de la programmation en C 
à travers la création d'un jeu vidéo simplifié. Les compétences mises en avant comprennent :

- Utilisation de la bibliothèque miniLibX.
- Gestion des événements et de l'interaction utilisateur.
- Algorithmes de ray-casting pour le rendu des textures.
- Optimisation de la mémoire et de la performance.

## Texture
```.c
/**
 * Calcule la coordonnée X de la texture à afficher en fonction de la position du joueur et de la distance par rapport au mur.
 *
 * Cette fonction calcule la position exacte où la texture doit être échantillonnée pour un rayon donné, afin de rendre correctement la texture
 * sur le mur dans un moteur de rendu 3D de type raycasting.
 *
 * @param ray Un pointeur vers la structure t_ray contenant les informations sur le rayon, y compris sa direction, la distance perpendiculaire au mur, et le côté du mur touché.
 * @param texture Un pointeur vers la structure t_texture contenant les informations sur la texture (comme sa largeur).
 * @return La coordonnée X dans la texture correspondant à l'endroit où le rayon touche le mur.
 */
int	calculate_texture_x(t_ray *ray, t_texture *texture)
{
	double	wall_x;  // La position exacte du mur touché, dans les coordonnées de la texture.
	int		tex_x;   // La coordonnée X calculée dans la texture.

	// Détermine la position exacte du mur touché en fonction du côté du mur.
	if (ray->side == 0)
		wall_x = ray->map_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = ray->map_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);  // Garde seulement la partie fractionnaire de wall_x.
	tex_x = (int)(wall_x * (double)texture->width);  // Convertit la position en coordonnée de texture.

	// Ajuste la coordonnée X en fonction de la direction du rayon et du côté du mur.
	if (ray->side == 0 && ray->ray_dir_x > 0)
		tex_x = texture->width - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		tex_x = texture->width - tex_x - 1;

	return (tex_x);
}

/**
 * Sélectionne la texture appropriée en fonction de la direction du rayon et du côté du mur touché.
 *
 * Cette fonction détermine quelle texture doit être utilisée pour le mur touché par le rayon,
 * en fonction de la direction du rayon et du côté du mur (N, S, E, O) touché.
 *
 * @param ray Un pointeur vers la structure t_ray contenant les informations sur le rayon.
 * @param mlx Un pointeur vers la structure t_mlx contenant les informations globales, y compris les textures.
 * @param texture Un double pointeur vers la structure t_texture pour stocker la texture sélectionnée.
 */
static void	texture_position(t_ray *ray, t_mlx *mlx, t_texture **texture)
{
	// Détermine la texture à utiliser en fonction du côté du mur touché.
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			*texture = &mlx->texture_north;  // Mur nord
		else
			*texture = &mlx->texture_south;  // Mur sud
	}
	else
	{
		if (ray->ray_dir_y > 0)
			*texture = &mlx->texture_east;  // Mur est
		else
			*texture = &mlx->texture_west;  // Mur ouest
	}
}

/**
 * Calcule et ajuste la position de la texture en fonction de l'orientation du joueur et de la distance au mur.
 *
 * Cette fonction ajuste la position de la texture à utiliser pour le mur touché en fonction de l'orientation et de la position
 * du joueur, et de la distance au mur. Elle permet de s'assurer que la texture est correctement alignée avec le mur.
 *
 * @param ray Un pointeur vers la structure t_ray contenant les informations sur le rayon.
 * @param mlx Un pointeur vers la structure t_mlx contenant les informations globales, y compris les textures.
 * @param texture Un double pointeur vers la structure t_texture pour la texture sélectionnée.
 * @param tex_x Un pointeur vers un entier pour stocker la coordonnée X de la texture.
 */
static void	fixed_texture(t_ray *ray, t_mlx *mlx, t_texture **texture, int *tex_x)
{
	double	wall_x;  // La position exacte du mur touché, dans les coordonnées de la texture.

	// Détermine la position exacte du mur touché en fonction du côté du mur.
	if (ray->side == 0)
		wall_x = mlx->map.player.corrdone.axe_ord + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = mlx->map.player.corrdone.axe_abs + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);  // Garde seulement la partie fractionnaire de wall_x.
	*tex_x = (int)(wall_x * (double)(*texture)->width);  // Convertit la position en coordonnée de texture.

	// Ajuste la coordonnée X en fonction de la direction du rayon et du côté du mur.
	if (ray->side == 0 && ray->ray_dir_x > 0)
		*tex_x = (*texture)->width - *tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		*tex_x = (*texture)->width - *tex_x - 1;
}

/**
 * Fonction principale pour dessiner les textures sur les murs.
 *
 * Cette fonction gère l'affichage des textures sur les murs dans le moteur de rendu 3D. Elle calcule les positions
 * de texture à afficher pour chaque pixel vertical du mur, et affiche la texture correspondante à la position correcte
 * sur l'écran.
 *
 * @param ray Un pointeur vers la structure t_ray contenant les informations sur le rayon.
 * @param x La coordonnée X actuelle sur l'écran où dessiner la texture.
 * @param mlx Un pointeur vers la structure t_mlx contenant les informations globales, y compris les textures et l'image.
 * @param count Un entier représentant le compteur de pixels verticaux actuellement dessinés.
 */
void	display_of_wall(t_ray *ray, int x, t_mlx *mlx, int count)
{
	int			tex_x;    // La coordonnée X dans la texture.
	int			tex_y;    // La coordonnée Y dans la texture.
	int			d;        // La position calculée pour l'échantillonnage de la texture.
	t_texture	*texture; // La texture à utiliser pour ce mur.

	texture_position(ray, mlx, &texture);  // Sélectionne la texture appropriée.
	fixed_texture(ray, mlx, &texture, &tex_x);  // Calcule et ajuste la position de la texture.

	// Boucle pour dessiner chaque pixel vertical du mur.
	while (count < ray->draw_end)
	{
		d = count * 256 - HEIGHT * 128 + ray->line_height * 128;  // Calcule la position dans la texture.
		tex_y = ((d * texture->height) / ray->line_height) / 256;  // Convertit en coordonnée Y de texture.
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= texture->height)
			tex_y = texture->height - 1;

		// Récupère la couleur du pixel de la texture.
		mlx->pixel.color = texture->data[tex_y * texture->width + tex_x];

		// Dessine le pixel sur l'image.
		put_pixel_to_img(&mlx->img, x, count, mlx->pixel.color);

		count++;  // Incrémente le compteur de pixels verticaux.
	}
}
```
