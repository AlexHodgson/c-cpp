#include <stdexcept>
#include <iostream>
#include <chrono>

class Wagon
{
public:

    int wagonID;
    Wagon* to_the_left;
    Wagon* to_the_right;

    Wagon(int wagonID)
    {
        this->wagonID = wagonID;
    }

};

class TrainComposition
{

private:
    Wagon* left_wagon; // Leftmost and rightmost wagons
    Wagon* right_wagon; 

    int train_length = 0;

    // If this is the first wagon added to the train
    void initialise_train(int wagonID)
    {
        Wagon* wagon = new Wagon(wagonID);

        this->left_wagon = wagon;
        this->right_wagon = wagon;

        this->train_length++;
    }

public:
    void attachWagonFromLeft(int wagonId)
    {
        // Check if there is already a wagon on the train, if yes update the leftmost wagon
        if(this->train_length == 0)
        {
            this->initialise_train(wagonId);
        }
        else
        {
            Wagon* old_left_wagon = this->left_wagon;
            old_left_wagon->to_the_left = new Wagon(wagonId);
            this->left_wagon = old_left_wagon->to_the_left;

            // Update new leftmost wagon's properties
            this->left_wagon->to_the_right = old_left_wagon;

            this->train_length++; 
        }
        
    }

    void attachWagonFromRight(int wagonId)
    {
        // Check if there is already a wagon on the train, if yes update the rightmost wagon
        if(this->train_length == 0)
        {
            this->initialise_train(wagonId);
        }
        else
        {
            Wagon* old_right_wagon = this->right_wagon;
            old_right_wagon->to_the_right = new Wagon(wagonId);
            this->right_wagon = old_right_wagon->to_the_right;

            // Update new rightmost wagon's properties
            this->right_wagon->to_the_left = old_right_wagon;

            this->train_length++;
        }
        
    }

    int detachWagonFromLeft()
    {
        if(this->train_length == 0)
        {
            throw std::logic_error("Cannot remove wagon from train of length 0");
        }
        else
        {
            Wagon* removed_wagon = this->left_wagon;
            this->left_wagon = removed_wagon->to_the_right;
            int wagonID = removed_wagon->wagonID;

            delete removed_wagon;
            this->train_length--;

            return wagonID;
        }

    }

    int detachWagonFromRight()
    {
        if(this->train_length == 0)
        {
            throw std::logic_error("Cannot remove wagon from train of length 0");
        }
        else
        {
            Wagon* removed_wagon = this->right_wagon;
            this->right_wagon = removed_wagon->to_the_left;
            int wagonID = removed_wagon->wagonID;

            delete removed_wagon;
            this->train_length--;

            return wagonID;
        }

    }

    // void listWagons() // List from left to right
    // {
    //     Wagon* wagon = this->left_wagon;

    //     while(wagon->to_the_right != NULL)
    //     {
    //         std::cout << wagon->wagonID << " ";

    //         wagon = wagon->to_the_right;
    //     }
    // }
};


// Test execution time vs deque version
#ifndef RunTests
int main()
{
    TrainComposition train;

    int no_wagons = 1000000;

    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 1; i<no_wagons ; i++)
    {
        train.attachWagonFromLeft(i);
    }

    for(int i = no_wagons; i < no_wagons*2; i++)
    {
        train.attachWagonFromRight(i);
    }

    for(int i = 1; i<no_wagons ; i++)
    {
        //std::cout << train.detachWagonFromRight() << "\n";
    }

    for(int i = 0; i < no_wagons; i++)
    {
        //std::cout << train.detachWagonFromLeft() << "\n";
    }

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); 
  
    // To get the value of duration use the count() 
    // member function on the duration object 
    std::cout << duration.count() << std::endl; 

    // The original test case
    train.attachWagonFromLeft(7);
    train.attachWagonFromLeft(13);
    train.attachWagonFromRight(15);
    std::cout << train.detachWagonFromRight() << "\n"; // 15 
    std::cout << train.detachWagonFromRight(); // 7
}
#endif