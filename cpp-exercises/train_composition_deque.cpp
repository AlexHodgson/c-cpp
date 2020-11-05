#include <stdexcept>
#include <iostream>
#include <deque>
#include <chrono>

class TrainComposition
{
private:
    std::deque <int> train;

public:
    void attachWagonFromLeft(int wagonId)
    {
        this->train.push_back(wagonId);
    }

    void attachWagonFromRight(int wagonId)
    {
        this->train.push_front(wagonId);
    }

    int detachWagonFromLeft()
    {
        int wagonID = this->train.back();
        this->train.pop_back();

        return wagonID;
    }

    int detachWagonFromRight()
    {
        int wagonID = this->train.front();
        this->train.pop_front();

        return wagonID;
    }
};

#ifndef RunTests
int main()
{
    TrainComposition train;
    train.attachWagonFromLeft(7);
    train.attachWagonFromLeft(13);
    std::cout << train.detachWagonFromRight() << "\n"; // 7 
    std::cout << train.detachWagonFromLeft(); // 13
}
#endif