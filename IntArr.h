#pragma once


class IntArr
{
private:
    int m_length{};
    int* m_data{};
public:
    IntArr();
    IntArr(int length);
    IntArr(const IntArr& a);

    ~IntArr();

    void erase();
    int& operator[](int index);
    void reallocate(int newLength); // уничтожит все существующие элементы в массиве при изменении его размера
    
    void resize(int newLength);// сохранит все существующие элементы в массиве
    IntArr& operator=(const IntArr& a);//перегрузка оператора

    void insertBefore(int value, int index);   //заменяет элемент
    void remove(int index);   //удаляет элемент

    void insertAtBeginning(int value);
    
    void insertAtEnd(int value);
   
    int getLength() const;
 };




