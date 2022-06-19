import copy

class Record:
    def __init__(self, data: str, nums: list):
        self.data = data
        self.nums = copy.deepcopy(nums)
        self.snapshots = list()

    def create_snapshot(self, id: int):
        self.snapshots.append(Memento(id, self.data, self.nums))

    def restore_last(self):
        if last := self.snapshots[-1]:
            self.data = last.data
            self.nums = copy.deepcopy(last.nums)

    def restore_by_id(self, id: int):
        for snapshot in self.snapshots:
            if snapshot.id == id:
                self.data = snapshot.data
                self.nums = copy.deepcopy(snapshot.nums)
                break


class Memento:
    def __init__(self, id: int, data: str, nums: list):
        self.id = id
        self.data = data
        self.nums = copy.deepcopy(nums)


record = Record("Hello World", [5, 20, 30])
record.create_snapshot(3)

record.data += "Another string"
record.nums.append(500)

record.create_snapshot(5)

record.data += "Last string"
record.nums.append(1000)
print(f"{record.data} {record.nums}")
record.restore_by_id(3)
print(f"{record.data} {record.nums}")
record.restore_last()
print(f"{record.data} {record.nums}")