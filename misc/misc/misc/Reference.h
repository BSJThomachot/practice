#ifndef __REFCOUNT_H_
#define __REFCOUNT_H_
// class is used to keep track of how many times a smart pointer is being referenced 
class Reference
{
private:
	int m_iCounter;
public:
	Reference(void);
	~Reference(void);

	void AddReference(void);
	void DeleteReference(void);
	int GetReferenceCount(void);
};

#endif 

