#[derive(Clone)]
pub struct Record {
    data: String,
    nums: Vec<u32>,
    snapshots: Vec<Memento>,
}

#[derive(Clone)]
struct Memento {
    id: u32,
    data: String,
    nums: Vec<u32>,
}

impl Record {
    pub fn new(data: String, nums: Vec<u32>) -> Self {
        Record{data, nums, snapshots: vec![]}
    }

    pub fn create_snapshot(&mut self, id: u32) {
        self.snapshots.push(Memento {
            id,
            data: self.data.clone(),
            nums: self.nums.clone(),
        })
    }

    pub fn restore_last(&mut self) {
        match self.snapshots.last() {
            Some(value) => {
                self.data = value.data.clone();
                self.nums = value.nums.clone();
            }
            None => {}
        }
    }

    pub fn restore_by_id(&mut self, id: u32) {
        match self.snapshots.iter().position(|x| x.id == id) {
            Some(index) => {
                self.data = self.snapshots[index].data.clone();
                self.nums = self.snapshots[index].nums.clone();
            }
            None => {}
        }
    }
}

fn main() {
    let mut data = Record::new(String::from("Start"), vec![10, 20 ,30]);
    data.create_snapshot(1);

    data.data.push_str("Additional data");
    data.nums.push(60);

    data.create_snapshot(3);

    data.data.push_str("Last data");
    data.nums.push(70);

    println!("{} {:?}", data.data, data.nums);

    data.restore_by_id(1);
    println!("{} {:?}", data.data, data.nums);

    data.restore_last();
    println!("{} {:?}", data.data, data.nums);
}
