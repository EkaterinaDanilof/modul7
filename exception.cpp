#include "exception.h"

const char* Bad_Range::what() const noexcept
{
	return "������: ��� ��������� ����������.";
    
}

const char* Bad_Length::what() const noexcept
{
	return "������: ������������ ����� �������.";
}

const char* Bad_insertBefore::what() const noexcept
{
	return "������: ������������ �����������.";
}
