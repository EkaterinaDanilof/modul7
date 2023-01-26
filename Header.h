#pragma once


class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default; //пустой

    IntArray(int length) : //создаем массив заданной длины
        m_length{ length }
    {
        if (length <= 0)
        throw "bad_length";
        else
            m_data = new int[length] {};
    }

    IntArray(const IntArray& a) //новый размер массива
    {
        
        reallocate(a.getLength());

        
        for (int index{ 0 }; index < m_length; ++index)
            m_data[index] = a.m_data[index];
    }

    ~IntArray() 
    {
        delete[] m_data;
        
    }

    void erase()
    {
        delete[] m_data;
        
        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int index)
    {
        if (index < 0 || index > m_length)
            throw "bad_range";
        else  return m_data[index];
    }

    // уничтожит все существующие элементы в массиве при изменении его размера
    void reallocate(int newLength)
    {
        
        erase();   //обнуляем и задаем новую длину 

        
        if (newLength <= 0)
            throw "bad_length";
        else
        {
            m_data = new int[newLength];
            m_length = newLength;
        }
    }

    // сохранит все существующие элементы в массиве
    void resize(int newLength)
    {
        
        if (newLength == m_length)
            return;

        
        if (newLength <= 0)
        {
            erase();
            return;
        }
            
                
        int* data{ new int[newLength] };

        
        if (m_length > 0)
        {
            int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

            
            for (int index{ 0 }; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        
        delete[] m_data;

        
        m_data = data;
        m_length = newLength;
    }

    IntArray& operator=(const IntArray& a)
    {
        
        if (&a == this)
            return *this;

        
        reallocate(a.getLength());

        
        for (int index{ 0 }; index < m_length; ++index)
            m_data[index] = a.m_data[index];

        return *this;
    }

    void insertBefore(int value, int index)   //заменяет элемент
    {
        
        if (index < 0 || index > m_length)
            throw "Bad_insertBefore()";
        else {

            int* data{ new int[m_length + 1] };


            for (int before{ 0 }; before < index; ++before)
                data[before] = m_data[before];


            data[index] = value;


            for (int after{ index }; after < m_length; ++after)
                data[after + 1] = m_data[after];


            delete[] m_data;
            m_data = data;
            ++m_length;
        }
    }

    void remove(int index)   //удаляет элемент
    {
        if (index < 0 || index > m_length)
            throw "bad_range";

        
        if (m_length == 1)
        {
            erase();
            return;
        }

        
        int* data{ new int[m_length - 1] };

        
        for (int before{ 0 }; before < index; ++before)
            data[before] = m_data[before];

        
        for (int after{ index + 1 }; after < m_length; ++after)
            data[after - 1] = m_data[after];

        
        delete[] m_data;
        m_data = data;
        --m_length;
    }

    
    void insertAtBeginning(int value) { insertBefore(value, 0); }
    void insertAtEnd(int value) { insertBefore(value, m_length); }

    int getLength() const { return m_length; }
};