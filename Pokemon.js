class Monster {
    constructor(name, type, health, attackPower, defense, level) {
        this.name = name;
        this.type = type;
        this.health = health;
        this.attackPower = attackPower;
        this.defense = defense;
        this.level = level;
    }

    attack(opponent) {
        const damage = Math.max((Math.floor(Math.random() * this.attackPower) + 5) - (opponent.defense / 2), 1);
        opponent.health -= damage;
        console.log(`${this.name} attacks ${opponent.name} for ${damage} damage!`);
    }

    heal() {
        const healAmount = Math.floor(Math.random() * 15) + 5;
        this.health += healAmount;
        console.log(`${this.name} heals for ${healAmount} HP!`);
    }

    isDefeated() {
        return this.health <= 0;
    }

    displayStats() {
        console.log(`${this.name} [Type: ${this.type}, HP: ${this.health}, Level: ${this.level}]`);
    }
}

class Player {
    constructor() {
        this.team = [];
        this.potions = 3;
    }

    catchMonster(m) {
        this.team.push(m);
        console.log(`You caught a wild ${m.name}!`);
    }

    usePotion(m) {
        if (this.potions > 0) {
            m.heal();
            this.potions--;
        } else {
            console.log("No potions left!");
        }
    }
}

class NPC {
    constructor(name, role) {
        this.name = name;
        this.role = role;
    }

    interact() {
        if (this.role === "Shopkeeper") {
            console.log(`${this.name}: 'Welcome! Would you like to buy potions?'`);
        } else if (this.role === "Trainer") {
            console.log(`${this.name}: 'Let's battle!'`);
        } else {
            console.log(`${this.name}: 'Hello traveler!'`);
        }
    }
}

// Main Game Loop
function main() {
    const player = new Player();
    const wild = new Monster("Bulbasaur", "Grass", 90, 18, 10, 1);
    const trainer = new NPC("Ash", "Trainer");
    const shopkeeper = new NPC("Mart Owner", "Shopkeeper");

    console.log(`A wild ${wild.name} appeared!`);
    console.log("Choose action: (1) Battle (2) Catch (3) Visit Trainer (4) Visit Shop");
    
    const choice = parseInt(prompt("Enter your choice:"));

    if (choice === 1) {
        const hero = new Monster("Charmander", "Fire", 100, 20, 8, 1);
        while (!hero.isDefeated() && !wild.isDefeated()) {
            hero.attack(wild);
            if (!wild.isDefeated()) {
                wild.attack(hero);
            }
        }
        console.log(hero.isDefeated() ? "You lost!" : "You won!");
    } else if (choice === 2) {
        player.catchMonster(wild);
    } else if (choice === 3) {
        trainer.interact();
    } else if (choice === 4) {
        shopkeeper.interact();
    } else {
        console.log("Invalid choice!");
    }
}

main();

