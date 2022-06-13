//ONLY SINGLE THREAD
use std::cell::Cell;
use std::rc::Rc;

pub trait Observer {
    fn update(&self, value: u16);
}

pub trait Observable {
    fn subscribe(&mut self, observer: Rc<dyn Observer>);
    fn unsubscribe(&mut self, observer: Rc<dyn Observer>);
    fn notify_all(&self);
}

struct StockPrice {
    data: Cell<u16>,
    observers: Vec<Rc<dyn Observer>>,
}

struct Investor {
    expected_price: u16,
    is_happy: Cell<bool>,
}

impl StockPrice {
    pub fn update_price(&mut self, value: u16) {
        self.data.set(value);
        self.notify_all();
    }
}

impl Observable for StockPrice {
    fn subscribe(&mut self, observer: Rc<dyn Observer>) {
        self.observers.push(observer.clone());
    }

    fn unsubscribe(&mut self, observer: Rc<dyn Observer>) {
        todo!();
    }

    fn notify_all(&self) {
        self.observers
            .iter()
            .for_each(|x| x.update(self.data.get()));
    }
}

impl Investor {
    pub fn check_happiness(&self, value: u16) {
        self.is_happy.set(value >= self.expected_price);
    }
}

impl Observer for Investor {
    fn update(&self, value: u16) {
        self.check_happiness(value);
    }
}

fn main() {
    let mut stock_price = StockPrice {
        data: Cell::new(50),
        observers: Vec::new(),
    };

    let tom = Rc::new(Investor {
        expected_price: 30,
        is_happy: Cell::new(true),
    });

    let john = Rc::new(Investor {
        expected_price: 40,
        is_happy: Cell::new(true),
    });

    stock_price.subscribe(john.clone());
    stock_price.subscribe(tom.clone());
    stock_price.update_price(20);

    println!("{} and {}", tom.is_happy.get(), john.is_happy.get());
}
