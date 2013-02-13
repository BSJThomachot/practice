#pragma once
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

