#include "Reference.h"


Reference::Reference(void)
{
	this->m_iCounter = 0;
}


Reference::~Reference(void)
{

}


void Reference::AddReference(void)
{
	this->m_iCounter++;
}

void Reference::DeleteReference(void)
{
	this->m_iCounter--;
}

int Reference::GetReferenceCount(void)
{
	return this->m_iCounter;
}
