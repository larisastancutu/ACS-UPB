//implementarea design pattern-ului Adapter

/**PROS:
 * - se pot introduce noi clase care actioneaza ca un adaptor intre interfata si clasa, fara a schimba clasa sau interfata existenta  **/
/**CONS: 
 * - complexitatea generala a codului creste, deoarece trebuie introduse un set de noi interfete si clase**/

#include <iostream>
#include <string>

using namespace std;

class Dog
{
public:
    virtual ~Dog() {}
    virtual void bark() = 0;
};

class RealDog : public Dog
{
private:
    string name;

public:
    RealDog(string n)
    {
        this->name = n;
    }
    virtual ~RealDog() {}

    virtual void bark()
    {
        cout << this->name << " is barking." << endl;
    }
};

class RobotDog
{
private:
    string name;

public:
    RobotDog(string n)
    {
        this->name = n;
    }
    virtual ~RobotDog() {}

    void play_barking_sound()
    {
        cout << name << " is playing barking sound." << endl;
    }
};

class RobotDogAdapter : public Dog
{
private:
    RobotDog *robot_dog;

public:
    RobotDogAdapter(RobotDog *rd)
    {
        this->robot_dog = rd;
    }
    virtual ~RobotDogAdapter() {}

    virtual void bark()
    {
        robot_dog->play_barking_sound();
    }
};

int main()
{
    cout << endl
         << "ADAPTER:" << endl
         << endl;

    Dog *real_dog = new RealDog("Max");
    real_dog->bark();

    RobotDog *robot_dog = new RobotDog("Rex Robot");
    Dog *robot_dog_adapter = new RobotDogAdapter(robot_dog);
    robot_dog_adapter->bark();

    delete robot_dog_adapter;
    delete robot_dog;
    delete real_dog;

    return 0;
}