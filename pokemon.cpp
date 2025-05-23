#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Monster Class
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

    void displayStats()
    {
        std::cout << name << " [Type: " << type << ", HP: " << health << ", Level: " << level << "]\n";
    }
};

// Player Class
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

// NPC Class
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

// Main Game Loop
int main()
{
    srand(time(0));

    Player player;
    Monster wild("Bulbasaur", "Grass", 90, 18, 10, 1);
    NPC trainer("Ash", "Trainer");
    NPC shopkeeper("Mart Owner", "Shopkeeper");

    std::cout << "A wild " << wild.name << " appeared!\n";
    std::cout << "Choose action: (1) Battle (2) Catch (3) Visit Trainer (4) Visit Shop\n";
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
    else if (choice == 2)
    {
        player.catchMonster(wild);
    }
    else if (choice == 3)
    {
        trainer.interact();
    }
    else if (choice == 4)
    {
        shopkeeper.interact();
    }
    else
    {
        std::cout << "Invalid choice!\n";
    }

    return 0;
}
