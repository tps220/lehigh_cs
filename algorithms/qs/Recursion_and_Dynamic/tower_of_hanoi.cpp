//Implement and solve the tower of hanoi problem

class Tower {
private:
    Stack<Integer> disks;
    int index;
public:
    Tower(int i) {
        index  = i;
    }
    int index() const {
        return index;
    }
    void moveToTop(Tower t) {
        int mover = disks.top();
        disks.pop();
        t.add(mover);
    }
    bool add(int d) {
        if (!disks.size() == 0 && disks.peek() <= d) {
            return false;
        }
        disks.push(d);
    }
    void moveDisks(int n, Tower Buffer, Tower Destination) {
        if (n <= 0) {
            return;
        }
        moveDisks(n - 1, Destination, Buffer);
        moveToTop(Destination);
        moveDisks(n - 1, Destination, this);
    }



}

//If outside a class
void movedisks(int n, Tower origin, Tower destination, Tower buffer) {
    if (n <= 0) {
        return;
    }
    movedisks(n - 1, origin, buffer, destination);
    moveTop(origin, destination);
    movedisks(n - 1, buffer, destination, origin);

}
