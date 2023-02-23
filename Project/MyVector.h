#include <string>

struct MyObject
{
    int _id;
};

class MyVector
{
private: // 구현에 필요한 멤버 추가 함수/변수들을 자유롭게 아래에 정의 합니다.
    typedef MyObject Node;
    typedef MyObject* PNode;

private:
    PNode m_pArray;
    unsigned int m_Size;
    unsigned int m_Capacity;

public: // 생성자, 복사생성자, 할당연산자, 소멸자를 .cpp 파일에 구현합니다.
    // Constructor.
    MyVector();

    MyVector(int capacity);

    // Copy constructor.
    MyVector(const MyVector& other);
 
    // Assignment operator.
    MyVector& operator=(const MyVector& other);

    // Destructor.
    ~MyVector();

    // Returns current capacity of this vector.
    int GetCapacity()
    {
        return m_Capacity;
    }
 
    // Returns current size of this vector.
    int GetSize()
    {
        return m_Size;
    }

    // Creates a new MyObject instance with the given ID, and appends it to the end of this vector.
    void Add(int id);

    // Returns the first occurrence of MyObject instance with the given ID.
    // Returns nullptr if not found.
    MyObject* FindById(int MyObjectId) const;
 
    // Trims the capacity of this vector to current size.
    void TrimToSize();

    // Returns the MyObject instance at the specified index.
    MyObject& operator[](size_t index);
 
    // Returns string representation of the vector.
    std::string ToString() const;
 
    // Remove all MyObject instances with the given ID in this vector.
    void RemoveAll(int MyObjectId);
 
    // Returns a newly allocated array of MyVector objects,
    // each of whose elements have the same "_id" value of the MyObject struct.
    // The 'numGroups' is an out parameter, and its value should be set to
    // the size of the MyVector array to be returned.
    MyVector* GroupById(int* numGroups);
};
