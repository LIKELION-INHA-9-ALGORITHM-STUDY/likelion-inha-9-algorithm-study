class Queue:
    def __init__(self, progresses, speeds):
        self.q = progresses
        self.speeds = speeds

    def __len__(self):
        return len(self.q)

    def dequeue(self):
        self.speeds.pop(0)
        self.q.pop(0)

    def peek(self):
        if len(self.q) > 0:
            return self.q[0]
        return -1

    def do_work(self):
        new_progresses = []
        for i, p in enumerate(self.q):
            new_progress = p + self.speeds[i]
            if new_progress >= 100: new_progress = 100

            new_progresses.append(new_progress)

        self.q = new_progresses

def solution(progresses, speeds):
    q = Queue(progresses, speeds)

    ret = []
    while len(q) > 0:
        q.do_work()

        count = 0
        while q.peek() >= 100:
            q.dequeue()
            count += 1

        if count > 0:
            ret.append(count)

    return ret