#ifndef H_Classes
#define H_Classes

struct Pair;

// Class List
class List
{
public:
    List(int *, int, int);
    virtual int removeElementFromSpecificPositionList(int = 0) = 0;
    virtual int firstRepeatingElement() = 0;
    virtual int firstNonRepeatingElement() = 0;
    virtual Pair *findPairs(int) = 0; // Accepts a target against which the pair is find.
    ~List();

    // private:
    int *arr;
    int maxSize;
    int currentSize;
};

// Class MyList
class MyList : public List
{
public:
    MyList(int * = nullptr, int = 100, int = 0);
    int removeElementFromSpecificPositionList(int = 0) override;
    int firstRepeatingElement() override;
    int firstNonRepeatingElement() override;
    Pair *findPairs(int) override;
    int *countFrequencyOfEachElement();
    void leftRotate(int);
    void rightRotate(int);
    ~MyList();
};

struct Pair
{
    int value1, value2;
};

#endif