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
    void reallocate(int newLength); // ��������� ��� ������������ �������� � ������� ��� ��������� ��� �������
    
    void resize(int newLength);// �������� ��� ������������ �������� � �������
    IntArr& operator=(const IntArr& a);//���������� ���������

    void insertBefore(int value, int index);   //�������� �������
    void remove(int index);   //������� �������

    void insertAtBeginning(int value);
    
    void insertAtEnd(int value);
   
    int getLength() const;
 };




