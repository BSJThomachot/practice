#pragma once
#include "Reference.h"
// template for smart pointer
template <class T> class SmartPtr
{
private: 
	// the raw pointer used by the smart pointer
	T * m_pPointer;
	// Reference counter to check how many times the raw pointer is being referenced 
	Reference * m_pRef; 
public:

	// Defaut constructor
	SmartPtr(void)
	{
		m_pPointer = NULL;
		m_pRef = new Reference();
		m_pRef->AddReference();
	}

	// Constructor
	SmartPtr(T* pPointer)
	{
		m_pPointer = pPointer;
		m_pRef = new Reference();
		m_pRef->AddReference();
	}

	// Copy Constructor
	SmartPtr(SMART_PTR<T>& smart_ptr)
    {
		m_pPointer = smart_ptr.m_pPointer;
		m_pRef = smart_ptr.m_pRef;
		m_pRef->AddReference();
    }

	// Destructor
	~SmartPtr(void)
	{
		// loses a reference 
		m_pRef->DeleteReference();
		if (m_pRef->GetReferenceCount() == 0)
		{
			delete m_pRef;
			delete m_pPointer;
		}
	}

	// overload * operator
    T& operator * ()
    {
        return *m_pPointer;
    }

	// overload -> operator
    T* operator -> ()
    {
        return m_pPointer;
    }

	// overload = operator
	SmartPtr<T>&  operator = (const SmartPtr<T>& smart_ptr)
	{
		// if not already the same
        if (this != &smart_ptr) 
        {
			// loses a reference
			m_pRef->DeleteReference();
			if(m_pRef->GetReferenceCount() == 0)
            {
                delete m_pPointer;
                delete m_pRef;
            }

            // copy everything
			m_pPointer = smart_ptr.m_pPointer;
			m_pRef = smart_ptr.m_pRef;
			// another reference 
			m_pRef->AddReference();
        }
        return *this;
    }

	// overload ! operator
	bool operator ! ()
	{
		if (m_pPointer == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// return the raw pointer pointer
	T * GetPtr()
	{
		return m_pPointer;
	}

	Reference GetReference()
	{
		return this->m_pRef;
	}

	void AddReference()
	{
		this->m_iRefCount++;
	}

	void DeleteReference()
	{
		this->m_iRefCount--;
	}

};

