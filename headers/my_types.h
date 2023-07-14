/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:32:55 by heson             #+#    #+#             */
/*   Updated: 2023/07/12 19:40:12 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_TYPES_H
# define MY_TYPES_H

# include <stdbool.h>

# define ERROR_BOOL 0
# define ERROR_INT -1
# define ERROR_POINTER NULL

# define TILESIZE 64

# define ON_KEYDOWN 2
# define ON_DESTROY 17

enum e_keycode {
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_W = 13,
	KEY_S = 1,
	KEY_A = 0,
	KEY_D = 2,
	KEY_ESC = 53
};

enum e_tile_type {
	EMPTY = '0',
	WALL = '1',
	PLAYER = 'P'
};

enum e_direction {
	UP = 0,
	RIGHT,
	DOWN,
	LEFT,
	DIR_CNT
};

typedef struct s_vector {
	int	x;
	int	y;
}	t_vector;

typedef struct s_player {
	t_vector	dir;
	t_vector	loc;
}	t_player;

typedef struct s_map {
	char	**board;
	int		width;
	int		height;
}		t_map;

typedef struct s_game {
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
}	t_game;

#endif