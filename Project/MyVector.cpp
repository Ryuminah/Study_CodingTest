#include <iostream>
#include "MyVector.h"

MyVector::MyVector()
{
    m_Size = 0;
    m_Capacity = 0;
    m_pArray = new Node[0];
}

MyVector::MyVector(int capacity)
{
	m_Size = 0;
	m_Capacity = capacity;
    m_pArray = new Node[m_Capacity];
}

MyVector::MyVector(const MyVector& other)
{
    m_pArray = new Node[other.m_Capacity];
    m_Size = other.m_Size;
    m_Capacity = other.m_Capacity;

    for (size_t i = 0; i < m_Size; ++i)
    {
        m_pArray[i] = other.m_pArray[i];
    }
}

MyVector& MyVector::operator=(const MyVector& other)
{
    if (this != &other) 
    {
        m_Size= other.m_Size;
        m_Capacity = other.m_Capacity;
        delete[] m_pArray;
        m_pArray = new Node[other.m_Capacity];
        for (size_t i = 0; i < m_Size; i++)
        {
            m_pArray[i] = other.m_pArray[i];
        }
    }
    return *this;
}

MyVector::~MyVector()
{
    delete[] m_pArray;
}

void MyVector::Add(int id)
{
    if (m_Size == m_Capacity)
    {
        m_Capacity = m_Capacity == 0 ? 1 : m_Capacity;
        m_Capacity *= 2;
        PNode pArray = new Node[m_Capacity];

        // 기존 데이터 복사
        for (size_t i = 0; i < m_Size; ++i)
        {
            pArray[i] = m_pArray[i];
        }
        delete[] m_pArray;
        m_pArray = pArray;
    }

    // 데이터 추가
    MyObject myObject;
    myObject._id = id;
    m_pArray[m_Size] = myObject;
    ++m_Size;
}

MyObject* MyVector::FindById(int MyObjectId) const
{
    for (size_t i = 0; i < m_Size; ++i)
    {
        if (MyObjectId == m_pArray[i]._id)
        {
            return &m_pArray[i];
        }
    }

    return nullptr;
}

void MyVector::TrimToSize()
{
    if (m_Size == m_Capacity)
    {
        return;
    }

    PNode pArray = new Node[m_Size]{};
    m_Capacity = m_Size;

    for (size_t i = 0; i < m_Size; ++i)
    {
        pArray[i] = m_pArray[i];
    }

    delete[] m_pArray;
    m_pArray = pArray;
}

MyObject& MyVector::operator[](size_t index)
{
    if (index >= m_Size)
    {
        std::cout << "Out of Range ! " << std::endl;
    }

    return m_pArray[index];
}

// 문자열
std::string MyVector::ToString() const
{
    std::string value = "";

    if (m_Size == 0)
    {
        std::cout << "There is No Element In Container!";
    }

    for (size_t i = 0; i < m_Size; ++i)
    {
        value += std::to_string(m_pArray[i]._id) + " ";
    }

    return value;
}

void MyVector::RemoveAll(int MyObjectId)
{
    PNode pArray = new Node[m_Size]{};
    int index = 0;
    int count = 0;
    for (size_t i = 0; i < m_Size; ++i)
    {
        if (MyObjectId == m_pArray[i]._id)
        {
            ++count;
            continue;
        }
        pArray[index] = m_pArray[i];
        ++index;
    }

    int copyId = m_pArray[GetSize() - 1]._id;
    for (int i = index; i < m_Size; ++i)
    {
        pArray[i]._id = copyId;
    }

    delete[] m_pArray;
    m_pArray = pArray;
}

MyVector* MyVector::GroupById(int* numGroups)
{
    *numGroups = 0;
    if (m_Size == 0)
    {
        return nullptr;
    }

    MyVector sortVector(*this);
    for (size_t i = 1; i < sortVector.m_Size; ++i)
    {
        int j = 0;
        MyObject saveObject = sortVector[i];

        for (j = i - 1; j >= 0; --j)
        {
            if (sortVector.m_pArray[j]._id > saveObject._id)
            {
                sortVector[j + 1] = sortVector[j];
            }

            else
            {
                break;
            }
        }
        sortVector[j + 1] = saveObject;
   
    }

    int idValue = sortVector.m_pArray[0]._id;
    (*numGroups) = 1;
    for (size_t i = 1; i < sortVector.m_Size; ++i)
    {
        if (idValue != sortVector[i]._id)
        {
            idValue = sortVector[i]._id;
            ++(*numGroups);
        }
    }

    idValue = sortVector.m_pArray[0]._id;
    MyVector* resultVector = new MyVector[*numGroups];
    int index = 0;
    for (size_t i = 0; i < sortVector.m_Size; ++i)
    {
        if (idValue != sortVector[i]._id)
        {
            idValue = sortVector[i]._id;
            ++index;
        }

        resultVector[index].Add(sortVector[i]._id);

    }

    return resultVector;
}
