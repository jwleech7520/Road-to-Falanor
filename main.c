#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct weapon{
  char* name;
  char type;
  int damage;
  int strengthbuff;
  int intelbuff;
  int agilitybuff;
  int weight;
  int value;
  int attacks;
} weapon;

typedef struct item{
  char* name;
  int value;
  double weight;
  int strengthbuff;
  int intelbuff;
  int agilitybuff;
  int armourbuff;
  int dodgebuff;
  int stealthbuff;
  int speedbuff;
} item;

typedef struct creature{
  char name[32];
  double health;
  double maxHealth;
  int strength;
  int intelligence;
  int agility;
  int armour;
  int dodge;
  int stealth;
  int capacity;
  int speed;
  weapon weapon;
  item inventory[10];
} Creature;

weapon bronzeDagger = {
  .name = "bronze dagger",
  .type = 's',
  .damage = 5,
  .weight = 10,
};

weapon goblinAttack = {
  .name = "goblin attack",
  .type = 's',
  .damage = 3,
  .weight = 10,
};

Creature playerTemplate = {
  .name = "player",
  .health = 100,
  .maxHealth = 100,
  .strength = 10,
  .intelligence = 10,
  .agility = 10,
  .armour = 10,
  .dodge = 10,
  .stealth = 10,
  .capacity = 100,
};

Creature goblinTemplate = {
  .name = "goblin",
  .health = 50,
  .maxHealth = 50,
  .strength = 5,
  .intelligence = 0,
  .agility = 10,
  .armour = 5,
  .dodge = 10,
  .stealth = 10,
  .capacity = 50,
};

void equip_weapon(Creature *c, const weapon *w) {
    c->weapon = *w;
}

int main(void) {
    srand(time(NULL));

    printf("______________________________________________________________________________________________________________________________________\n");
    printf(" /$$$$$$$                            /$$         /$$                     /$$$$$$$$       /$$\n");
    printf("| $$__  $$                          | $$        | $$                    | $$_____/      | $$\n");
    printf("| $$  \\ $$  /$$$$$$   /$$$$$$   /$$$$$$$       /$$$$$$    /$$$$$$       | $$    /$$$$$$ | $$  /$$$$$$  /$$$$$$$   /$$$$$$   /$$$$$$\n");
    printf("| $$$$$$$/ /$$__  $$ |____  $$ /$$__  $$      |_  $$_/   /$$__  $$      | $$$$$|____  $$| $$ |____  $$| $$__  $$ /$$__  $$ /$$__  $$\n");
    printf("| $$__  $$| $$  \\ $$  /$$$$$$$| $$  | $$        | $$    | $$  \\ $$      | $$__/ /$$$$$$$| $$  /$$$$$$$| $$  \\ $$| $$  \\ $$| $$  \\__/\n");
    printf("| $$  \\ $$| $$  | $$ /$$__  $$| $$  | $$        | $$ /$$| $$  | $$      | $$   /$$__  $$| $$ /$$__  $$| $$  | $$| $$  | $$| $$\n");
    printf("| $$  | $$|  $$$$$$/|  $$$$$$$|  $$$$$$$        |  $$$$/|  $$$$$$/      | $$  |  $$$$$$$| $$|  $$$$$$$| $$  | $$|  $$$$$$/| $$\n");
    printf("|__/  |__/ \\______/  \\_______/ \\_______/         \\___/   \\______/       |__/   \\_______/|__/ \\_______/|__/  |__/ \\______/ |__/\n");
    printf("______________________________________________________________________________________________________________________________________\n\n");

    // Opening monologue
    printf("A great evil has swept across the land. The Black Emperor's dark legions are pillaging and ransacking their way through our great nation.\n");
    printf("It is up to you to make it to our magnificent capital Falanor to warn the royal army before the Dark Legions destroy the city!\n\n");

    printf("Do you think you have what it takes to defeat the dark legions? (y/n): ");

    char ready;
    scanf(" %c", &ready);

    if (tolower(ready) == 'y') {
        printf("So you believe you have what it takes. Very well then...\n");
    } else {
        printf("Then the darkness will consume us all...\n");
        return 0;
    }

    // Tutorial and shit

    //start of the actual game
    
    Creature player = playerTemplate;

    equip_weapon(&player, &bronzeDagger);

    //game loop

    int level;

    while(level < 48){
      if(generateEncounter(level, player) == -1){
        printf("Game Over!\n");
        return 0;
      }



      level++;
    }
    

    return 0;
}

int generateEncounter(int level, Creature player) {
  int randomEncounter = rand() % 100 + 1; // Generate a random number between 1 and 100
  if(randomEncounter <= 50){
    printf("You encounter an enemy!\n");
    printf("Do you try to fight or sneak past? (f/s): ");
    char choice;
    scanf(" %c", &choice);
    if(choice == 'f') {
      int difficulty = rand() % 10 + 1 + level; // Difficulty scales with level
      if(difficulty < 10){
        Creature enemy = goblinTemplate;
        if(combat(&player, &enemy) == 1){
          printf("You defeated the enemy!\n");
        } else {
          printf("You were defeated by the enemy...\n");
          return -1; // player is dead
        }
      } else {
        // other enemies when i add them
      }
    }else if(choice == 's') {
      int sneakChance = rand() % 100 + 1;
      if(sneakChance <= player.stealth) {
        printf("You successfully sneak past the enemy!\n");
      } else {
        printf("You fail to sneak past the enemy and are forced to fight!\n");
        Creature enemy = goblinTemplate;
        enemy.weapon = goblinAttack;
        combat(&player, &enemy);
      }
    }
  }else if(randomEncounter <= 80){
    printf("You come across a village!\n"); 
  }else if(randomEncounter <= 90){
    printf("You meet a strange man who offers you a some mysterious liquid!\n");
  }else if(randomEncounter <= 99){
    printf("You find a chest on the side of the road!\n");
  }else{
    //some kind of secret or something
  }
}

double calculate_damage(const Creature *attacker, const Creature *defender) {
    double base = attacker->weapon.damage;
    double stat_mult = 1.0;

    switch (attacker->weapon.type) {
        case 's': stat_mult = 1.0 + attacker->strength / 100.0;   break;
        case 'a': stat_mult = 1.0 + attacker->agility   / 100.0;   break;
        case 'i': stat_mult = 1.0 + attacker->intelligence / 100.0; break;
        default:  stat_mult = 1.0;
    }

    double reduction = 1.0 + defender->armour / 100.0;
    return base * stat_mult / reduction;
}

int combat(Creature *player, Creature *enemy) {
  while (player->health > 0 && enemy->health > 0) {
    // Player's turn
    if (player->health > 0) {
        double dmg = calculate_damage(player, enemy);
        if (rand() % 100 + 1 > enemy->dodge) {
            enemy->health -= dmg;
            printf("You hit for %.1f damage. Enemy HP: %.1f\n", dmg, enemy->health);
        } else {
            printf("Enemy dodged!\n");
        }
    }else{
      return -1; // player is dead
    }

    // Enemy's turn (if still alive)
    if (enemy->health > 0 && player->health > 0) {
        double dmg = calculate_damage(enemy, player);
        if (rand() % 100 + 1 > player->dodge) {
            player->health -= dmg;
            printf("Enemy hits for %.1f damage. Your HP: %.1f\n", dmg, player->health);
        } else {
            printf("You dodged!\n");
        }
    }else{
      printf("Enemy defeated!\n");
      return 1; // enemy is dead
    }
  }
}