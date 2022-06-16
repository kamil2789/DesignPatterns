#include <memory>
#include <string>
#include <iostream>

class CarFactory;
class FurnitureFactory;
class TireFactory;

class IndustryVisitor
{
public:
    virtual ~IndustryVisitor() = default;
    virtual void visit(const CarFactory& carFactory) = 0;
    virtual void visit(const FurnitureFactory& FurnitureFactory) = 0;
    virtual void visit(const TireFactory& TireFactory) = 0;
};

class IndustryObject
{
public:
    virtual void accept(std::shared_ptr<IndustryVisitor> visitor) = 0;
    virtual int work() const = 0;
};

class CarFactory : public IndustryObject
{
public:
    CarFactory(std::string name, int carPerDay):
        name(name),
        carPerDay(carPerDay)
    {}

    int work() const override
    {
        return 100;
    }

    void accept(std::shared_ptr<IndustryVisitor> visitor) override
    {
        visitor->visit(*this);
    }

private:
    std::string name;
    int carPerDay;
};

class FurnitureFactory : public IndustryObject
{
public:
    FurnitureFactory(std::string name, int furniturePerDay):
        name(name),
        furniturePerDay(furniturePerDay)
    {}

    int work() const override
    {
        return 200;
    }

    void accept(std::shared_ptr<IndustryVisitor> visitor) override
    {
        visitor->visit(*this);
    }

private:
    std::string name;
    int furniturePerDay;
};

class TireFactory : public IndustryObject
{
public:
    TireFactory(std::string name, int tirePerDay):
        name(name),
        tirePerDay(tirePerDay)
    {}

    int work() const override
    {
        return 1000;
    }

    void accept(std::shared_ptr<IndustryVisitor> visitor) override
    {
        visitor->visit(*this);
    }

private:
    std::string name;
    int tirePerDay;
};

class PrinterIndustryVisitor : public IndustryVisitor
{
public:
    void visit(const CarFactory& carFactory) override
    {
        std::cout<<"This car factory can create "<<carFactory.work()<<" cars per day"<<std::endl;
    }

    void visit(const FurnitureFactory& furnitureFactory) override
    {
        std::cout<<"This furniture factory can create "<<furnitureFactory.work()<<" furnitures per day"<<std::endl;
    }

    void visit(const TireFactory& tireFactory) override
    {
        std::cout<<"This tire factory can create "<<tireFactory.work()<<" tires per day"<<std::endl;
    }
};

int main() 
{
    CarFactory fiat {"fiat", 300};
    std::shared_ptr<IndustryVisitor> ptr = std::make_shared<PrinterIndustryVisitor>();
    fiat.accept(ptr);
    return 0;
}