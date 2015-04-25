#pragma once

// screen size
#define SCREEN_WIDTH               (const int) 79
#define SCREEN_HEIGHT              (const int) 25

// game controls
#define GAME_CONTROL_ABDUCT        (int) 69
#define GAME_CONTROL_LEFT          (int) VK_LEFT
#define GAME_CONTROL_RIGHT         (int) VK_RIGHT
#define GAME_CONTROL_HIDE          (int) VK_SPACE

// time settings
#define TIMER_MAX_TIME             (int) 99
#define TIMER_STARTING_TIME        (int) 10
#define TIMER_BONUS_PER_ANIMAL     (int) 3

// score settings
#define SCORE_BONUS_PER_ANIMAL     (int) 50
#define SCORE_MAX_LENGTH           (int) 5
#define SCORE_MAX_SCORE            (int) 99999

// animals settings
#define CHICK_DEFAULT_MOVESPEED    (unsigned) 120
#define COW_DEFAULT_MOVESPEED      (unsigned) 35
#define PIG_DEFAULT_MOVESPEED      (unsigned) 50
#define ANIMAL_MAX_SPEED_BOOST     (unsigned) 55 // percent

// enemy settings
#define FARMER_DEFAULT_MOVESPEED   (unsigned) 100
#define FARMER_STARTING_POS_X      (int) 25
#define FARMER_STARTING_POS_Y      (int) 11
#define FARMER_MAX_SUSPICIOUS_TIME (int) 1500

// player settings
#define PLAYER_MOVE_SPEED          (int) 250
#define PLAYER_BEAM_SPEED          (int) 720
#define PLAYER_ANIMATION_SPEED     (int) 100
#define PLAYER_STARTING_POS_X      (int) 2
#define PLAYER_STARTING_POS_Y      (int) 2
#define PLAYER_STARTING_LIVES      (int) 3
#define PLAYER_LIFE_ICON_CODE      (char) 127
#define PLAYER_MAX_REACTION_TIME   (int) 500
#define PLAYER_ABDUCT_RADIUS	   (int) 3

// stage settings
#define STAGE_LORE_TEXT_SPEED      (int) 250
#define STAGE_MIN_SPAWN_TIME       (int) 1750
#define STAGE_MAX_SPAWN_TIME       (int) 3500
#define STAGE_STARTING_ANIMALS     (int) 2
#define STAGE_MAX_ANIMALS_ON_STAGE (int) 5
#define STAGE_CLOUDS_NUM_SPRITES   (int) 5
#define STAGE_CLOUDS_BASE_SPEED    (int) 12
#define STAGE_CLOUDS_STARTING_NUM  (int) 3
#define STAGE_CLOUDS_POS_Y		   (int) 3
#define STAGE_HANGING_TIME         (int) 1500 // time the stage stands still after player's death

// misc
#define ANIMATION_BASE_INTERVAL    (int) 10000