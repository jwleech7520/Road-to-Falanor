#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

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

item testItem = {
  .name = "test item",
  .value = 10,
  .weight = 5.0,
  .strengthbuff = 200,
};

item ringofstrength = {
  .name = "ring of strength",
  .value = 100,
  .weight = 1.0,
  .strengthbuff = 10,
};

void printStats(const Creature *c);
void printInventory(Creature *c);
void adjustStats(Creature *c, item *it, int equip);
int equipItem(Creature *c, item *newItem);
void unequipItem(Creature *c, int slot);
int combat(Creature *player, Creature *enemy);
int generateEncounter(int level, Creature *player);
double calculate_damage(const Creature *attacker, const Creature *defender);

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
    printf("______________________________________________________________________________________________________________________________________\n");

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

    Creature player = playerTemplate;
    equip_weapon(&player, &bronzeDagger);

    int level = 1;   // better to start at level 1

    // Test sequence
    printf("\nInitial stats:\n");
    printStats(&player);

    equipItem(&player, &testItem);       // STR += 200
    printInventory(&player);

    unequipItem(&player, 1);             // STR -= 200
    printInventory(&player);

    // Game loop
    while (level < 48) {
        printf("\n--- Level %d ---\n", level);
        printStats(&player);   // optional: always show stats before encounter

        printf("When ready: 'n' = next, 'i' = inventory, 'q' = quit\n> ");
        char input;
        while (1) {
            scanf(" %c", &input);
            input = tolower(input);

            if (input == 'n') {
                printf("Continuing...\n");
                break;
            } else if (input == 'i') {
                printInventory(&player);
                printStats(&player);
            } else if (input == 'q') {
                printf("Quit game.\n");
                return 0;
            } else {
                printf("Invalid. Try again: ");
            }
        }

        if (generateEncounter(level, &player) == 0) {   // ← changed to == 0 (loss)
            printf("Game Over!\n");
            return 0;
        }

        level++;
    }

    printf("You reached the end!\n");
    return 0;
}


int generateEncounter(int level, Creature *player) {
  int randomEncounter = rand() % 100 + 1;

  if (randomEncounter <= 50) { // will be 50% or soemthing later but other interactions arent added yet
    printf("You encounter an enemy!\n");
    printf("Fight or sneak? (f/s): ");
    char choice;
    while(1){
      scanf(" %c", &choice);
      choice = tolower(choice);
      if(choice == 'f' || choice == 's'){
        break;
      }else{
        printf("Invalid input. Please enter 'f' or 's': \n");
      }
    }
    Creature enemy = goblinTemplate;
    enemy.weapon = goblinAttack;   // ← always do this!

    if (choice == 'f') {
      int difficulty = rand() % 10 + 1 + level;
      if (difficulty < 100) {  // temporary
        return combat(player, &enemy);   // return 0=lose, 1=win
      }
    } else if (choice == 's') {
      int sneakChance = rand() % 100 + 1;
      if (sneakChance <= player->stealth) {
        printf("You sneak past!\n");
        return 1;  // success = continue
      } else {
        printf("Sneak failed: fight!\n");
        return combat(player, &enemy);
      }
    }
    return 1; // default continue if invalid choice
  }else if(randomEncounter <= 100){ // change back to 80 when i add the shop and other interactions
    printf("You find a treasure chest!\n");
    int rarity = rand() % 10 + level;
    if(rarity <= 50){
      printf("You found a ring of strength!\n");
      printf("would you like to equip it? (y/n): ");
      char equipChoice;
      scanf(" %c", &equipChoice);
      if(tolower(equipChoice) == 'y'){
        equipItem(player, &ringofstrength);
      }  
    }
    return 1;  // non-combat = continue
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
  printf("\nCombat starts:  %s vs %s\n", player->name, enemy->name);

  while (player->health > 0 && enemy->health > 0) {
    Sleep(600);  // a bit longer feels better

    // Player turn
    double pdmg = calculate_damage(player, enemy);
    if (rand() % 100 + 1 > enemy->dodge) {
      enemy->health -= pdmg;
      if (enemy->health < 0) enemy->health = 0;
      printf("  You hit for %.1f -> %s HP: %.0f\n", pdmg, enemy->name, enemy->health);
    } else {
      printf("  %s dodges!\n", enemy->name);
    }

    if (enemy->health <= 0) break;

    // Enemy turny
    double edmg = calculate_damage(enemy, player);
    if (rand() % 100 + 1 > player->dodge) {
      player->health -= edmg;
      if (player->health < 0) player->health = 0;
      printf("  %s hits for %.1f -> Your HP: %.0f\n", enemy->name, edmg, player->health);
    } else {
      printf("  You dodge!\n");
    }
  }

  if (player->health <= 0) {
    printf("You have been defeated...\n");
    return 0;  // loss / game over
  } else {
    printf("You defeated the %s!\n", enemy->name);
    return 1;  // victory
  }
}

void printInventory(Creature *c) {
    printf("\n=== Inventory ===\n");
    for (int i = 0; i < 10; i++) {
        if (c->inventory[i].name != NULL) {
            printf("  %2d: %s (val:%d, wt:%.1f)\n",
                   i+1, c->inventory[i].name,
                   c->inventory[i].value, c->inventory[i].weight);
        } else {
            printf("  %2d: (empty)\n", i+1);
        }
    }
    printf("=================\n");
}

void adjustStats(Creature *c, item *it, int addBuffs) {   // 1 = add, 0 = remove
    int multiplier = addBuffs ? 1 : -1;
    c->strength     += it->strengthbuff * multiplier;
    c->strength += it->strengthbuff * multiplier;
    c->intelligence += it->intelbuff * multiplier;
    c->agility += it->agilitybuff * multiplier;
    c->armour += it->armourbuff * multiplier;
    c->dodge += it->dodgebuff * multiplier;
    c->stealth += it->stealthbuff * multiplier;
    c->speed += it->speedbuff * multiplier;
}

int equipItem(Creature *c, item *newItem) {
    if (newItem == NULL || newItem->name == NULL) {
        printf("Cannot equip: invalid item.\n");
        return 0;
    }

    int slot = -1;
    for (int i = 0; i < 10; i++) {
        if (c->inventory[i].name == NULL) {
            slot = i;
            break;
        }
    }

    if (slot == -1) {
        printf("Inventory full! Cannot equip %s.\n", newItem->name);
        return 0;
    }

    c->inventory[slot] = *newItem;
    adjustStats(c, &c->inventory[slot], 1);

    printf("Equipped %s (slot %d)\n", newItem->name, slot+1);
    printStats(c);   // ← show effect immediately

    return 1;
}

void unequipItem(Creature *c, int slot) {
    if (slot < 1 || slot > 10) {
        printf("Invalid slot (1-10).\n");
        return;
    }

    int idx = slot - 1;
    if (c->inventory[idx].name == NULL) {
        printf("Slot %d is already empty.\n", slot);
        return;
    }

    printf("Unequipping %s from slot %d...\n", c->inventory[idx].name, slot);

    // Remove buffs (multiplier -1)
    adjustStats(c, &c->inventory[idx], 0);

    // Clear the slot completely
    memset(&c->inventory[idx], 0, sizeof(item));
    // or just: c->inventory[idx].name = NULL; but memset is cleaner

    printStats(c);   // ← show what changed
}
void printStats(const Creature *c) {
    printf("\nCurrent Stats:\n");
    printf("  Health: %.0f / %.0f\n", c->health, c->maxHealth);
    printf("  STR: %d   INT: %d   AGI: %d\n", c->strength, c->intelligence, c->agility);
    printf("  Armour: %d   Dodge: %d   Stealth: %d   Speed: %d\n",
           c->armour, c->dodge, c->stealth, c->speed);
    printf("\n");
}