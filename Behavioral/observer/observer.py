
class Observer:
    def update(self, value):
        pass


class Observable:
    def subscribe(self, observer: Observer):
        pass

    def unsubscribe(self, observer: Observer):
        pass

    def notify_all(self):
        pass


class StockPrice(Observable):
    def __init__(self, price):
        self.__price = price
        self.__observers = set()

    @property
    def price(self):
        return self.__price

    @price.setter
    def price(self, value):
        self.__price = value
        self.notify_all()

    def subscribe(self, observer: Observer):
        self.__observers.add(observer)

    def unsubscribe(self, observer: Observer):
        self.__observers.remove(observer)

    def notify_all(self):
        for item in self.__observers:
            item.update(self.price)
            

class Investor(Observer):
    def __init__(self, expected_price: int):
        self.expected_price = expected_price
        self.is_happy = True

    def update(self, price):
        if price >= self.expected_price:
            self.is_happy = True
        else:
            self.is_happy = False
    

stock = StockPrice(price=40)
john = Investor(expected_price=30)
tom = Investor(expected_price=40)

stock.subscribe(john)
stock.subscribe(tom)

print(f"John {john.is_happy} and Tom {tom.is_happy}")
stock.price = 10
print(f"John {john.is_happy} and Tom {tom.is_happy}")
