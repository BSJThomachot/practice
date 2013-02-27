#ifndef __REFCOUNT_H_
#define __REFCOUNT_H_
class Reference
{
private:
	// Reference counter
	int m_iCounter;
public:
	Reference(void);
	~Reference(void);

	void AddReference(void);
	void DeleteReference(void);
	int GetReferenceCount(void);
};

#endif 

