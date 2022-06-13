//ONLY SINGLE THREAD

#include <set>
#include <memory>
#include <string>
#include <iostream>

template<typename T>
class Observer
{
public:
    virtual ~Observer() = default;
    virtual void update(T value) = 0;
};

template<typename T>
class Observable
{
public:
    virtual ~Observable() = default;
    virtual void subscribe(std::shared_ptr<Observer<T>> observer) = 0;
    virtual void unsubscribe(std::shared_ptr<Observer<T>> observer) = 0;
    virtual void notifyAll() = 0;
};

class StockPrice : public Observable<int>
{
public:
    StockPrice(int price):
        price(price)
        {}
    int get_latest_value() const
    {
        return price;
    }

    void set_price(int value)
    {
        price = value;
        notifyAll();
    }

    void subscribe(std::shared_ptr<Observer<int>> observer) override
    {
        observers.insert(observer);
    }

    void unsubscribe(std::shared_ptr<Observer<int>> observer) override
    {
        observers.erase(observer);
    }

    void notifyAll() override
    {
        for (auto& item : observers)
        {
            item->update(get_latest_value());
        }
    }
    
private:
    int price;
    std::set<std::shared_ptr<Observer<int>>> observers;
};

class Person : public Observer<int>
{
public:
    Person(int expectedValue):
        expectedValue(expectedValue),
        isHappy(true)
    {}

    void update(int value)
    {
        checkHappiness(value);
    }

    bool getIsHappy() const
    {
        return isHappy;
    }
private:
    const int expectedValue;
    bool isHappy;

    void checkHappiness(int value)
    {
        isHappy = value < expectedValue ? false : true;
    }
};

int main()
{
    StockPrice stock{50};
    auto John = std::make_shared<Person>(40);
    auto Tom = std::make_shared<Person>(30);
    
    stock.subscribe(John);
    stock.subscribe(Tom);

    stock.set_price(20);
    std::cout<<John->getIsHappy()<<" and "<<Tom->getIsHappy()<<std::endl;
    stock.set_price(35);
    std::cout<<John->getIsHappy()<<" and "<<Tom->getIsHappy()<<std::endl;
    stock.unsubscribe(Tom);

    stock.set_price(10);
    std::cout<<John->getIsHappy()<<" and "<<Tom->getIsHappy()<<std::endl;
}