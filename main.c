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
  int gold;
  int xp;
  int level;
  int xpToNextLevel;
} Creature;

weapon bronzeDagger = {
  .name = "bronze dagger",
  .type = 's',
  .damage = 5,
  .weight = 10,
};

weapon ironSword = {
  .name = "iron sword",
  .type = 's',
  .damage = 10,
  .weight = 20,
};

weapon steelLongsword = {
  .name = "steel longsword",
  .type = 's',
  .damage = 20,
  .weight = 30,
};

weapon mythrilGreatsword = {
  .name = "mythril greatsword",
  .type = 's',
  .damage = 40,
  .weight = 50,
};

weapon woodenBow = {
  .name = "wooden bow",
  .type = 'a',
  .damage = 5,
  .weight = 10,
};

weapon longBow = {
  .name = "long bow",
  .type = 'a',
  .damage = 10,
  .weight = 20,
};

weapon crossbow = {
  .name = "crossbow",
  .type = 'a',
  .damage = 20,
  .weight = 30,
};

weapon masterworklongbow = {
  .name = "masterwork longbow",
  .type = 'a',
  .damage = 40,
  .weight = 50,
};

weapon basicStaff = {
  .name = "basic staff",
  .type = 'i',
  .damage = 5,
  .weight = 10,
};

weapon enchantedStaff = {
  .name = "enchanted staff",
  .type = 'i',
  .damage = 10,
  .weight = 20,
};

weapon arcaneStaff = {
  .name = "arcane staff",
  .type = 'i',
  .damage = 20,
  .weight = 30,
};

weapon staffoftheelements = {
  .name = "staff of the elements",
  .type = 'i',
  .damage = 40,
  .weight = 50,
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
  .gold = 100,
  .level = 1,
  .xp = 0,
  .xpToNextLevel = 100,
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

Creature orcTemplate = {
  .name = "orc",
  .health = 100,
  .maxHealth = 100,
  .strength = 15,
  .intelligence = 5,
  .agility = 5,
  .armour = 15,
  .dodge = 5,
  .stealth = 5,
  .capacity = 100,
};

Creature darkScoutTemplate = {
  .name = "dark scout",
  .health = 150,
  .maxHealth = 150,
  .strength = 10,
  .intelligence = 10,
  .agility = 20,
  .armour = 10,
  .dodge = 15,
  .stealth = 20,
  .capacity = 75,
};

Creature darkSoldierTemplate = {
  .name = "dark soldier",
  .health = 200,
  .maxHealth = 200,
  .strength = 30,
  .intelligence = 10,
  .agility = 10,
  .armour = 20,
  .dodge = 5,
  .stealth = 5,
  .capacity = 150,
};

Creature darkWarriorTemplate = {
  .name = "dark warrior",
  .health = 300,
  .maxHealth = 300,
  .strength = 50,
  .intelligence = 20,
  .agility = 20,
  .armour = 30,
  .dodge = 10,
  .stealth = 10,
  .capacity = 200,
};

Creature darkCommanderTemplate = {
  .name = "dark commander",
  .health = 500,
  .maxHealth = 500,
  .strength = 70,
  .intelligence = 30,
  .agility = 30,
  .armour = 50,
  .dodge = 20,
  .stealth = 20,
  .capacity = 300,
};

Creature darkEmperorTemplate = {
  .name = "dark emperor",
  .health = 1000,
  .maxHealth = 1000,
  .strength = 100,
  .intelligence = 50,
  .agility = 50,
  .armour = 70,
  .dodge = 30,
  .stealth = 30,
  .capacity = 500,
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

item amuletofstrength = {
  .name = "amulet of strength",
  .value = 200,
  .weight = 2.0,
  .strengthbuff = 20,
};

item artifactofstrength = {
  .name = "artifact of strength",
  .value = 500,
  .weight = 3.0,
  .strengthbuff = 50,
};

item ringofintellect = {
  .name = "ring of intellect",
  .value = 100,
  .weight = 1.0,
  .intelbuff = 10,
};

item amuletofintellect = {
  .name = "amulet of intellect",
  .value = 200,
  .weight = 2.0,
  .intelbuff = 20,
};

item artifactofintellect = {
  .name = "artifact of intellect",
  .value = 500,
  .weight = 3.0,
  .intelbuff = 50,
};

item ringofagility = {
  .name = "ring of agility",
  .value = 100,
  .weight = 1.0,
  .agilitybuff = 10,
};

item amuletofagility = {
  .name = "amulet of agility",
  .value = 200,
  .weight = 2.0,
  .agilitybuff = 20,
};

item artifactofagility = {
  .name = "artifact of agility",
  .value = 500,
  .weight = 3.0,
  .agilitybuff = 50,
};

item bootsofswiftness = {
  .name = "boots of swiftness",
  .value = 150,
  .weight = 2.0,
  .speedbuff = 30,
};

item ironArmour = {
  .name = "iron armour",
  .value = 150,
  .weight = 20.0,
  .armourbuff = 30,
};

item braceletofevasion = {
  .name = "bracelet of evasion",
  .value = 150,
  .weight = 1.0,
  .dodgebuff = 30,
};

item cloakofshadows = {
  .name = "cloak of shadows",
  .value = 150,
  .weight = 5.0,
  .stealthbuff = 30,
};

void printStats(const Creature *c);
void printInventory(Creature *c);
void adjustStats(Creature *c, item *it, int equip);
int equipItem(Creature *c, item *newItem);
void unequipItem(Creature *c, int slot);
int combat(Creature *player, Creature *enemy);
int generateEncounter(int level, Creature *player);
double calculate_damage(const Creature *attacker, const Creature *defender);
void discardItem(Creature *c, int slot);
void sellItem(Creature *c, int slot);
void gainXP(Creature *player, int amount);
void levelUp(Creature *player);

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
    while (level < 50) {
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
            } else if (input == 'd') {
                printf("Discard an item? (1-10): ");
                int slot;
                scanf(" %d", &slot);
                discardItem(&player, slot);
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

  if (randomEncounter <= 50) {  // Enemy encounter
    printf("You encounter an enemy!\n");
    printf("Fight or sneak? (f/s): ");
    char choice;
    while (1) {
        scanf(" %c", &choice);
        choice = tolower(choice);
        if (choice == 'f' || choice == 's') break;
        printf("Invalid input. Please enter 'f' or 's': \n");
    }

    // Calculate difficulty (scales with level)
    int difficulty = rand() % 60 + level * 5;

    Creature enemy;

    // Spawn logic: harder enemies appear at higher levels
    if (difficulty <= 50 || level < 5) {
        enemy = goblinTemplate;
        enemy.weapon = goblinAttack;
        printf("A goblin snarls and charges!\n");
    } else if (difficulty <= 100 || level < 10) {
        enemy = orcTemplate;
        enemy.weapon = ironSword;
        printf("An orc roars and swings its blade!\n");
    } else if (difficulty <= 150) {
        enemy = darkScoutTemplate;
        enemy.weapon = longBow;
        printf("A dark scout fires an arrow from the shadows!\n");
    } else if (difficulty <= 200) {
        enemy = darkSoldierTemplate;
        enemy.weapon = steelLongsword;
        printf("A dark soldier blocks your path with heavy steel!\n");
    } else if (difficulty <= 250) {
        enemy = darkWarriorTemplate;
        enemy.weapon = mythrilGreatsword;
        printf("A dark warrior raises a gleaming mythril blade!\n");
    } else if (difficulty <= 300) {
        enemy = darkCommanderTemplate;
        enemy.weapon = arcaneStaff;
        printf("A dark commander unleashes arcane energy!\n");
    } else {
        // Rare chance for final boss (level 40+ only)
        if (level >= 40) {
            enemy = darkEmperorTemplate;
            enemy.weapon = staffoftheelements;
            printf("!!! THE DARK EMPEROR HIMSELF APPEARS !!!\n");
        } else {
            enemy = darkCommanderTemplate;
            enemy.weapon = arcaneStaff;
            printf("A dark commander confronts you!\n");
        }
    }

    int result;
    if (choice == 'f') {
        result = combat(player, &enemy);
    } else {
        int sneakChance = rand() % 100 + 1;
        if (sneakChance <= player->stealth) {
            printf("You successfully sneak past!\n");
            gainXP(player, (int)(enemy.maxHealth * 0.4));  // small XP for stealth
            return 1;
        } else {
            printf("Sneak failed — forced to fight!\n");
            result = combat(player, &enemy);
        }
    }

    if (result == 1) {
        // XP based on enemy difficulty
        int baseXP = (int)(enemy.maxHealth / 3 + enemy.strength * 8 + level * 20);
        gainXP(player, baseXP);
    }

    return result;
    }else if (randomEncounter <= 75) {  // Treasure chest
    printf("\nYou find a treasure chest half-buried in the path!\n");

    // Gold drop (always)
    int goldFound = (rand() % 40 + 20) + level * 10;  // 20–60 + scaling
    printf("Inside you find %d gold pieces!\n", goldFound);
    player->gold += goldFound;

    // Now pick ONE random item from ALL possible items + weapons
    // We'll use a big array of pointers to make random selection easy

    // List of ALL possible drops (add more here if you create new items)
    void *allDrops[] = {
        &bronzeDagger, &ironSword, &steelLongsword, &mythrilGreatsword,
        &woodenBow, &longBow, &crossbow, &masterworklongbow,
        &basicStaff, &enchantedStaff, &arcaneStaff, &staffoftheelements,
        &ringofstrength, &amuletofstrength, &artifactofstrength,
        &ringofintellect, &amuletofintellect, &artifactofintellect,
        &ringofagility, &amuletofagility, &artifactofagility,
        &bootsofswiftness, &ironArmour, &braceletofevasion, &cloakofshadows  // keep test item for debugging if you want
    };

    int totalItems = sizeof(allDrops) / sizeof(allDrops[0]);

    // Slight bias: higher level = slightly higher chance of better items
    // But still fully random — just weighted toward the end of the list a bit
    int pickIndex = rand() % totalItems;
    if (level > 5)  pickIndex = (pickIndex + rand() % 8) % totalItems;   // mild bias

    void *droppedPtr = allDrops[pickIndex];
    char *itemName = NULL;
    int isWeapon = 0;

    // Detect what type it is and get name + handle equip
    if (droppedPtr == &bronzeDagger)        { itemName = "Bronze Dagger"; isWeapon = 1; }
    else if (droppedPtr == &ironSword)      { itemName = "Iron Sword"; isWeapon = 1; }
    else if (droppedPtr == &steelLongsword) { itemName = "Steel Longsword"; isWeapon = 1; }
    else if (droppedPtr == &mythrilGreatsword) { itemName = "Mythril Greatsword"; isWeapon = 1; }
    else if (droppedPtr == &woodenBow)      { itemName = "Wooden Bow"; isWeapon = 1; }
    else if (droppedPtr == &longBow)        { itemName = "Long Bow"; isWeapon = 1; }
    else if (droppedPtr == &crossbow)       { itemName = "Crossbow"; isWeapon = 1; }
    else if (droppedPtr == &masterworklongbow) { itemName = "Masterwork Longbow"; isWeapon = 1; }
    else if (droppedPtr == &basicStaff)     { itemName = "Basic Staff"; isWeapon = 1; }
    else if (droppedPtr == &enchantedStaff) { itemName = "Enchanted Staff"; isWeapon = 1; }
    else if (droppedPtr == &arcaneStaff)    { itemName = "Arcane Staff"; isWeapon = 1; }
    else if (droppedPtr == &staffoftheelements) { itemName = "Staff of the Elements"; isWeapon = 1; }
    else if (droppedPtr == &ringofstrength) { itemName = "Ring of Strength"; }
    else if (droppedPtr == &amuletofstrength) { itemName = "Amulet of Strength"; }
    else if (droppedPtr == &artifactofstrength) { itemName = "Artifact of Strength"; }
    else if (droppedPtr == &ringofintellect) { itemName = "Ring of Intellect"; }
    else if (droppedPtr == &amuletofintellect) { itemName = "Amulet of Intellect"; }
    else if (droppedPtr == &artifactofintellect) { itemName = "Artifact of Intellect"; }
    else if (droppedPtr == &ringofagility) { itemName = "Ring of Agility"; }
    else if (droppedPtr == &amuletofagility) { itemName = "Amulet of Agility"; }
    else if (droppedPtr == &artifactofagility) { itemName = "Artifact of Agility"; }
    else if (droppedPtr == &bootsofswiftness) { itemName = "Boots of Swiftness"; }
    else if (droppedPtr == &ironArmour) { itemName = "Iron Armour"; }
    else if (droppedPtr == &braceletofevasion) { itemName = "Bracelet of Evasion"; }
    else if (droppedPtr == &cloakofshadows) { itemName = "Cloak of Shadows"; }

    if (itemName) {
        printf("Inside the chest you find: **%s**!\n", itemName);

        printf("Would you like to equip it? (y/n): ");
        char equipChoice;
        scanf(" %c", &equipChoice);

        if (tolower(equipChoice) == 'y') {
            if (isWeapon) {
                equip_weapon(player, (weapon *)droppedPtr);
                printf("Weapon equipped!\n");
            } else {
                equipItem(player, (item *)droppedPtr);
            }
        } else {
            printf("You leave the %s behind.\n", itemName);
        }
    }

    printStats(player);
    return 1;
}else if (randomEncounter <= 100) {
    printf("\nYou stumble upon a traveling merchant's stall.\n");
    printf("The merchant grins and lays out three items for sale:\n\n");

    // === Weapon (always at least one) ===
    weapon *shopWeapon = NULL;
    int weaponPrice = 0;
    int weaponIndex = rand() % 12;  // 0-11 for your 12 weapon types

    switch (weaponIndex) {
        case 0:  shopWeapon = &bronzeDagger;       weaponPrice = 80 + level * 5;   break;
        case 1:  shopWeapon = &ironSword;          weaponPrice = 180 + level * 10;  break;
        case 2:  shopWeapon = &steelLongsword;     weaponPrice = 350 + level * 15;  break;
        case 3:  shopWeapon = &mythrilGreatsword;  weaponPrice = 700 + level * 25;  break;
        case 4:  shopWeapon = &woodenBow;          weaponPrice = 90 + level * 6;    break;
        case 5:  shopWeapon = &longBow;            weaponPrice = 200 + level * 12;  break;
        case 6:  shopWeapon = &crossbow;           weaponPrice = 380 + level * 18;  break;
        case 7:  shopWeapon = &masterworklongbow;  weaponPrice = 750 + level * 30;  break;
        case 8:  shopWeapon = &basicStaff;         weaponPrice = 85 + level * 5;    break;
        case 9:  shopWeapon = &enchantedStaff;     weaponPrice = 190 + level * 10;  break;
        case 10: shopWeapon = &arcaneStaff;        weaponPrice = 360 + level * 15;  break;
        default: shopWeapon = &staffoftheelements; weaponPrice = 800 + level * 35;  break;
    }

    printf("1. %s - %d gold (damage %d, %s)\n",
           shopWeapon->name, weaponPrice, shopWeapon->damage,
           (shopWeapon->type == 's') ? "strength" :
           (shopWeapon->type == 'a') ? "agility" : "intelligence");

    // === Item 2 & 3 (random accessories/armor) ===
    item *item2 = NULL;
    item *item3 = NULL;
    int price2 = 0, price3 = 0;

    // Pick item 2
    int roll2 = rand() % 8;
    if (roll2 == 0) { item2 = &ringofstrength;      price2 = 120 + level * 8; }
    else if (roll2 == 1) { item2 = &ringofagility;   price2 = 120 + level * 8; }
    else if (roll2 == 2) { item2 = &ringofintellect; price2 = 120 + level * 8; }
    else if (roll2 == 3) { item2 = &amuletofstrength; price2 = 220 + level * 12; }
    else if (roll2 == 4) { item2 = &ironArmour;      price2 = 180 + level * 10; }
    else if (roll2 == 5) { item2 = &braceletofevasion; price2 = 180 + level * 10; }
    else if (roll2 == 6) { item2 = &cloakofshadows;  price2 = 180 + level * 10; }
    else { item2 = &bootsofswiftness;                price2 = 180 + level * 10; }

    // Pick item 3 (different from item 2 if possible)
    int roll3 = rand() % 8;
    while (roll3 == roll2) roll3 = rand() % 8;  // avoid exact duplicate

    if (roll3 == 0) { item3 = &ringofstrength;      price3 = 120 + level * 8; }
    else if (roll3 == 1) { item3 = &ringofagility;   price3 = 120 + level * 8; }
    else if (roll3 == 2) { item3 = &ringofintellect; price3 = 120 + level * 8; }
    else if (roll3 == 3) { item3 = &amuletofstrength; price3 = 220 + level * 12; }
    else if (roll3 == 4) { item3 = &ironArmour;      price3 = 180 + level * 10; }
    else if (roll3 == 5) { item3 = &braceletofevasion; price3 = 180 + level * 10; }
    else if (roll3 == 6) { item3 = &cloakofshadows;  price3 = 180 + level * 10; }
    else { item3 = &bootsofswiftness;                price3 = 180 + level * 10; }

    printf("2. %s - %d gold\n", item2->name, price2);
    printf("3. %s - %d gold\n", item3->name, price3);

    printf("\nBuy something? (1, 2, 3 or n): ");
    char buyChoice[8];
    scanf(" %s", buyChoice);

    if (strcmp(buyChoice, "1") == 0) {
        if (player->gold >= weaponPrice) {
            printf("You buy the %s!\n", shopWeapon->name);
            equip_weapon(player, shopWeapon);
            player->gold -= weaponPrice;
            printf("Remaining gold: %d\n", player->gold);
        } else {
            printf("Not enough gold.\n");
        }
    }
    else if (strcmp(buyChoice, "2") == 0) {
        if (player->gold >= price2) {
            if (equipItem(player, item2)) {
                player->gold -= price2;
                printf("Purchased! Remaining gold: %d\n", player->gold);
            }
        } else {
            printf("Not enough gold.\n");
        }
    }
    else if (strcmp(buyChoice, "3") == 0) {
        if (player->gold >= price3) {
            if (equipItem(player, item3)) {
                player->gold -= price3;
                printf("Purchased! Remaining gold: %d\n", player->gold);
            }
        } else {
            printf("Not enough gold.\n");
        }
    }

    // Sell option
    printf("\nWould you like to sell an item? (y/n): ");
    char sellChoice;
    scanf(" %c", &sellChoice);
    if (tolower(sellChoice) == 'y') {
        printf("Which item? (1-10): ");
        int slot;
        scanf("%d", &slot);
        sellItem(player, slot);
    }

    printStats(player);
    return 1;
}

  return 1;
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
    gainXP(player, enemy->maxHealth + player->health);  // example XP reward
    player->health = player->maxHealth;  // heal after combat
    player->gold += enemy->maxHealth / 2;
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
    printf("  Level: %d | XP: %d / %d\n", c->level, c->xp, c->xpToNextLevel);  // ← NEW
    printf("  Health: %.0f / %.0f\n", c->health, c->maxHealth);
    printf("  STR: %d   INT: %d   AGI: %d\n", c->strength, c->intelligence, c->agility);
    printf("  Armour: %d   Dodge: %d   Stealth: %d   Speed: %d\n",
           c->armour, c->dodge, c->stealth, c->speed);
    if (c->gold >= 0) printf("  Gold: %d\n", c->gold);  // if you have gold
    printf("\n");
}

void discardItem(Creature *c, int slot){
    if (slot < 1 || slot > 10) {
        printf("Invalid slot (1-10).\n");
        return;
    }
    int idx = slot - 1;
    if (c->inventory[idx].name == NULL) {
        printf("Slot %d is already empty.\n", slot);
        return;
    }

    printf("Discarding %s from slot %d...\n", c->inventory[idx].name, slot);

    // Remove buffs first (while the item still exists)
    adjustStats(c, &c->inventory[idx], 0);   // 0 = remove

    // Then clear the slot
    memset(&c->inventory[idx], 0, sizeof(item));

    printStats(c);
    printInventory(c);   // nice to see it updated
}

void sellItem(Creature *c, int slot){
    if (slot < 1 || slot > 10) {
        printf("Invalid slot (1-10).\n");
        return;
    }
    int idx = slot - 1;
    if (c->inventory[idx].name == NULL) {
        printf("Slot %d is already empty.\n", slot);
        return;
    }

    printf("Selling %s from slot %d for %d gold...\n",
           c->inventory[idx].name, slot, c->inventory[idx].value);

    // Add gold to player
    c->gold += c->inventory[idx].value;

    // Remove buffs first (while the item still exists)
    adjustStats(c, &c->inventory[idx], 0);   // 0 = remove

    // Then clear the slot
    memset(&c->inventory[idx], 0, sizeof(item));

    printStats(c);
    printInventory(c);   // nice to see it updated
}

// Awards XP and handles level ups automatically
void gainXP(Creature *player, int amount) {
    if (amount <= 0) return;
    player->xp += amount;
    printf("Gained %d XP! (Total: %d / %d)\n", amount, player->xp, player->xpToNextLevel);

    // Level up loop (in case of massive XP gains)
    while (player->xp >= player->xpToNextLevel) {
        levelUp(player);
    }
}

// Handles single level up: boosts stats, heals, updates XP threshold
void levelUp(Creature *player) {
    player->level++;
    player->xp -= player->xpToNextLevel;  // subtract spent XP

    // Next level threshold (50% harder each time)
    player->xpToNextLevel = (int)(player->xpToNextLevel * 1.5f);

    // Stat boosts
    player->maxHealth += 10;
    player->strength += 2;
    player->intelligence += 2;
    player->agility += 2;
    player->armour += 1;
    player->dodge += 2;
    player->stealth += 1;
    player->speed += 1;

    // Full heal
    player->health = player->maxHealth;

    printf("\nLEVEL UP! You are now Level %d!\n", player->level);
    printf("Stats boosted + fully healed!\n");
    printStats(player);
}