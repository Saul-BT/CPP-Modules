#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main( void ) {
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    std::cout << "---" << std::endl;

    const Cat* michi = new Cat("Michi");
    AAnimal* mochi = new Cat(*michi);

    michi->getBrain().setIdea(1, " 🐱 ");

    AAnimal* mechi = new Cat(*michi);

    michi->showThinking();
    dynamic_cast<Cat*>(mochi)->showThinking();
    dynamic_cast<Cat*>(mechi)->showThinking();

    delete michi;
    delete mochi;
    delete mechi;

    std::cout << "---" << std::endl;

    AAnimal* animals[4];

    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }

    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0)
            dynamic_cast<Cat*>(animals[i])->showThinking();
        else
            dynamic_cast<Dog*>(animals[i])->showThinking();
    }

    for (int i = 0; i < 4; i++)
        delete animals[i];

    return 0;
}
