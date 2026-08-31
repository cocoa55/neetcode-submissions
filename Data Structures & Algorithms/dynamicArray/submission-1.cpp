class DynamicArray {
public:

    DynamicArray(int capacity) :
    _array {new int[capacity]},
    _capacity {capacity}
    {}

    int get(int i) const {
        return _array[i];
    }

    void set(int i, int n) { _array[i] = n; }

    void pushback(int n) { 

        if (_size == _capacity) //if size == capacity double capacity
            resize();
        _array[_size] = n; 
        ++_size;     
    }

    int popback() {
    
    return _array[--_size];
    }

    void resize() {
        _capacity *= 2;
        int* temp{ new int[_capacity]};
        for(int i{0}; i < _size; i++)
            temp[i] = _array[i];

        delete[] _array;
        _array = temp;
    }

    int getSize() const{
        return _size;
    }

    int getCapacity() const{
        return _capacity;
    }

private:
int* _array {nullptr};
int _capacity{0}; //the amount of elements that can be in the array
int _size {0}; //the last element in the array
};

