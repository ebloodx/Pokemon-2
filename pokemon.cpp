
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Monster
{
public:
    std::string name, type;
    int health, attackPower, defense, level;

    Monster(std::string n, std::string t, int h, int a, int d, int l)
        : name(n), type(t), health(h), attackPower(a), defense(d), level(l) {}

    void attack(Monster &opponent)
    {
        int damage = (rand() % attackPower + 5) - (opponent.defense / 2);
        damage = (damage < 0) ? 1 : damage;
        opponent.health -= damage;
        std::cout << name << " attacks " << opponent.name << " for " << damage << " damage!\n";
    }

    void heal()
    {
        int healAmount = rand() % 15 + 5;
        health += healAmount;
        std::cout << name << " heals for " << healAmount << " HP!\n";
    }

    bool isDefeated() { return health <= 0; }
};

class Player
{
public:
    std::vector<Monster> team;
    int potions;

    Player() : potions(3) {}

    void catchMonster(Monster m)
    {
        team.push_back(m);
        std::cout << "You caught a wild " << m.name << "!\n";
    }

    void usePotion(Monster &m)
    {
        if (potions > 0)
        {
            m.heal();
            potions--;
        }
        else
        {
            std::cout << "No potions left!\n";
        }
    }
};

int main()
{
    srand(time(0));

    Player player;
    Monster wild("Bulbasaur", "Grass", 90, 18, 10, 1);

    std::cout << "A wild " << wild.name << " appeared!\n";
    std::cout << "Choose action: (1) Battle (2) Catch\n";
    int choice;
    std::cin >> choice;

    if (choice == 1)
    {
        Monster hero("Charmander", "Fire", 100, 20, 8, 1);
        while (!hero.isDefeated() && !wild.isDefeated())
        {
            hero.attack(wild);
            if (!wild.isDefeated())
            {
                wild.attack(hero);
            }
        }
        std::cout << (hero.isDefeated() ? "You lost!" : "You won!") << std::endl;
    }
    else
    {
        player.catchMonster(wild);
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class NPC
{
public:
    std::string name, role;

    NPC(std::string n, std::string r) : name(n), role(r) {}

    void interact()
    {
        if (role == "Shopkeeper")
        {
            std::cout << name << ": 'Welcome! Would you like to buy potions?'\n";
        }
        else if (role == "Trainer")
        {
            std::cout << name << ": 'Let's battle!'\n";
        }
        else
        {
            std::cout << name << ": 'Hello traveler!'\n";
        }
    }
};

class Monster
{
public:
    std::string name, type;
    int health, attackPower, defense;

    Monster(std::string n, std::string t, int h, int a, int d)
        : name(n), type(t), health(h), attackPower(a), defense(d) {}

    void attack(Monster &opponent)
    {
        int damage = (rand() % attackPower + 5) - (opponent.defense / 2);
        opponent.health -= damage;
        std::cout << name << " attacks " << opponent.name << " for " << damage << " damage!\n";
    }

    bool isDefeated() { return health <= 0; }
};

int main()
{
    srand(time(0));

    NPC trainer("Ash", "Trainer");
    NPC shopkeeper("Mart Owner", "Shopkeeper");

    std::cout << "You encountered " << trainer.name << "!\n";
    trainer.interact();

    std::cout << "\nYou visited the shop.\n";
    shopkeeper.interact();

    return 0;
}
