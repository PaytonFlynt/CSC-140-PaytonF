#include <iostream>
#include <vector>
#include <string>

// - Diet and Habitat -
// Setting up supporting classes for part of composition ("has-a") relationship in Animal

class Diet {
private:
    std::string type; // Type of diet
public:
    Diet(const std::string& type) : type(type) {} // Constructor to set diet type
    std::string getType() const { return type; } // Getter for diet type
};

// Represent where animals live
class Habitat {
private:
    std::string description; // Habitat description
public:
    Habitat(const std::string& description) : description(description) {} // Constructor to set description
    std::string getDescription() const { return description; } // Getter for habitat description
};

// Creating base Animal class; name, age, species, and "has-a" diet and habitat object
// Inheritance and composition
// - Abstract Animal Class -

class Animal {
protected:
    std::string name; // Animal name
    int age; // Age
    const std::string species; // Constant species string
    Diet diet; // "has-a" Diet -- composition
    Habitat habitat; // "has-a" Habitat -- composition

public:
    // Constructor initializing attributes
    Animal(const std::string& name, int age, const std::string& species,
        const Diet& diet, const Habitat& habitat)
        : name(name), age(age), species(species), diet(diet), habitat(habitat) {
    }

    virtual ~Animal() {} // Virtual destructor

    // Pure virtual functions to be implemented by derived classes
    virtual void makeSound() const = 0;
    virtual void eat() const = 0;

    // Default trick behavior; can be overridden in subclasses
    virtual void performTrick() const {
        std::cout << name << " looks at the zookeeper but doesn't know any tricks yet.\n";
    }

    // Info for each animal, marked 'final' so subclasses cannot override
    virtual void displayInfo() const final {
        std::cout << "\nName: " << name
            << "\nAge: " << age
            << "\nSpecies: " << species
            << "\nDiet: " << diet.getType()
            << "\nHabitat: " << habitat.getDescription()
            << "\n";
    }
};

// Specific animal class, override makeSound(), eat(), and optionally performTrick()
// - Specific Animals -

// Lion class inheriting from Animal
class Lion : public Animal {
private:
    std::string sound; // Sound the lion makes
    std::string meal;  // What the lion eats
public:
    // Constructor setting name, age, and custom sound and meal
    Lion(const std::string& name, int age, const std::string& sound, const std::string& meal)
        : Animal(name, age, "Lion", Diet("Carnivore"), Habitat("Savanna enclosure")),
        sound(sound), meal(meal) {
    }

    void makeSound() const override {
        std::cout << name << " " << sound << "\n";
    }

    void eat() const override {
        std::cout << name << " " << meal << "\n";
    }

    void performTrick() const override {
        std::cout << name << " sprints up the tree to catch his ball!\n";
    }
};

// Elephant class inheriting from Animal
class Elephant : public Animal {
private:
    std::string sound;
    std::string meal;
public:
    Elephant(const std::string& name, int age, const std::string& sound, const std::string& meal)
        : Animal(name, age, "Elephant", Diet("Herbivore"), Habitat("Grassy enclosure")),
        sound(sound), meal(meal) {
    }

    void makeSound() const override {
        std::cout << name << " " << sound << "\n";
    }

    void eat() const override {
        std::cout << name << " " << meal << "\n";
    }

    void performTrick() const override {
        std::cout << name << " sprays water at the crowd with its trunk!\n";
    }
};

// Gnu class inheriting from Animal
class Gnu : public Animal {
private:
    std::string sound;
    std::string meal;
public:
    Gnu(const std::string& name, int age, const std::string& sound, const std::string& meal)
        : Animal(name, age, "Gnu", Diet("Herbivore"), Habitat("Wide open plain")),
        sound(sound), meal(meal) {
    }

    void makeSound() const override {
        std::cout << name << " " << sound << "\n";
    }

    void eat() const override {
        std::cout << name << " " << meal << "\n";
    }

    void performTrick() const override {
        std::cout << name << " trots in a funny zigzag pattern!\n";
    }
};

// Aardvark class inheriting from Animal
class Aardvark : public Animal {
private:
    std::string sound;
    std::string meal;
public:
    Aardvark(const std::string& name, int age, const std::string& sound, const std::string& meal)
        : Animal(name, age, "Aardvark", Diet("Insectivore"), Habitat("Dry burrow habitat")),
        sound(sound), meal(meal) {
    }

    void makeSound() const override {
        std::cout << name << " " << sound << "\n";
    }

    void eat() const override {
        std::cout << name << " " << meal << "\n";
    }

    void performTrick() const override {
        std::cout << name << " digs a mini tunnel on command!\n";
    }
};

// - Zoo Functions -
// Function for each animal in the zoo to do something specific with each choice

void makeAllAnimalsSound(const std::vector<Animal*>& zoo) {
    std::cout << "\n--- Animal Sounds ---\n";
    for (const auto& animal : zoo) {
        animal->makeSound(); // Call each animal's sound function
    }
}

void feedAllAnimals(const std::vector<Animal*>& zoo) {
    std::cout << "\n--- Feeding Time ---\n";
    for (const auto& animal : zoo) {
        animal->eat(); // Call each animal's eat function
    }
}

void showAllTricks(const std::vector<Animal*>& zoo) {
    std::cout << "\n--- Animal Tricks ---\n";
    for (const auto& animal : zoo) {
        animal->performTrick(); // Call each animal's trick function
    }
}

void showAllInfo(const std::vector<Animal*>& zoo) {
    std::cout << "\n--- Animal Info ---\n";
    for (const auto& animal : zoo) {
        animal->displayInfo(); // Call each animal's info function
    }
}

// Entry point where I set everything up
// - Main Program -

int main() {
    std::vector<Animal*> zoo; // Vector of pointers to Animal for polymorphism

    // 2 Lions
    zoo.push_back(new Lion("Tony", 5, "roars thunderously!", "devours a zebra leg."));
    zoo.push_back(new Lion("Karen", 4, "growls softly.", "nibbles on some ribs."));

    // 2 Elephants
    zoo.push_back(new Elephant("Bill", 10, "trumpets joyfully!", "snacks on a watermelon."));
    zoo.push_back(new Elephant("Edward", 8, "blows air loudly!", "chews on palm leaves."));

    // 2 Gnus
    zoo.push_back(new Gnu("Gary", 6, "snorts and stomps the ground.", "grazes with focus."));
    zoo.push_back(new Gnu("Gertrude", 7, "makes a nasal bleat.", "munches slowly on dry grass."));

    // 2 Aardvarks
    zoo.push_back(new Aardvark("Becky", 3, "snuffles gently.", "slurps up ants."));
    zoo.push_back(new Aardvark("Arnold", 2, "snorts with excitement.", "laps up termites."));

    int choice;
    do {
        // Main menu system loop
        std::cout << "\n= Welcome to Critter Planet =\n";
        std::cout << "Pick an option below:\n";
        std::cout << "1.) Show All Animal Info\n";
        std::cout << "2.) Feed All Animals\n";
        std::cout << "3.) Hear All Animal's Sounds\n";
        std::cout << "4.) Watch Animal Tricks\n";
        std::cout << "5.) Exit\n";
        std::cin >> choice;

        switch (choice) {
        case 1: showAllInfo(zoo); break;            // User wants to see info
        case 2: feedAllAnimals(zoo); break;         // User wants to feed animals
        case 3: makeAllAnimalsSound(zoo); break;    // User wants to hear their sounds
        case 4: showAllTricks(zoo); break;          // User wants to watch their tricks
        case 5: std::cout << "Thanks for visiting Critter Planet!\n"; break; // Exit 
        default: std::cout << "That’s not an option. Try again!\n";    // Incorrect input
        }
    } while (choice != 5); // Keep looping 

    // Clean up free all allocated memory
    for (auto animal : zoo) {
        delete animal; // Free each Animal object
    }

    return 0;
}
